/*
  * Homework 5
  * Your Name
  * CS 240, Spring 2026
  * Purdue University
  */

 /* Write your code here */

 #include "hw5.h"

 #include <assert.h>
 #include <stdio.h>
 #include <string.h>

 /*
  *  This functions checks wether a job is malformed.
  */

 int check_job(job_t job) {
   int failed = 0;

   if ((strlen(job.id) >= MAX_LENGTH) || (strlen(job.id) == 0) ||
       (strlen(job.user_id) >= MAX_LENGTH) || (strlen(job.user_id) == 0)) {
     failed = 1;
   }
   if ((job.required_cores <= 0) || (job.required_time <= 0) ||
       (job.submission_time <= 0)) {
     failed = 1;
   }
   if ((job.priority_level != LOW) && (job.priority_level != MEDIUM) &&
       (job.priority_level != HIGH)) {
     failed = 1;
   }
   if ((job.status != WAITING) && (job.status != RUNNING) &&
       (job.status != COMPLETED) && (job.status != EMPTY)) {
     failed = 1;
   }
   if ((strlen(job.dependency_job_id) >= MAX_LENGTH) ||
       (strlen(job.dependency_job_id) == 0)) {
     failed = 1;
   }

   if (failed == 1) {
     return 1;
   }
   else {
     return 0;
   }
 } /* check_job() */

 /*
  *  This functions reads a specific job at index n from the file pointer
  */

 job_t read_job(FILE *fp, int n) {
   assert (fp != NULL);
   assert (n >= 0);

   fseek(fp, 0, SEEK_END);
   long end = ftell(fp);

   if (n * sizeof(job_t) >= end) {
     return BAD_JOB;
   }

   fseek(fp, n * sizeof(job_t), SEEK_SET);

   job_t job = {};
   int items_read = fread(&job, sizeof(job_t), 1, fp);
   if (items_read != 1) {
     return BAD_JOB;
   }

   return job;
 } /* read_job() */

 /*
  *  This function writes a given job to the file at a given index.
  */

 int write_job(FILE *fp, job_t job, int n) {
   assert (fp != NULL);
   assert (n >= 0);

   fseek(fp, 0, SEEK_END);
   long end = ftell(fp);

   if (n * sizeof(job_t) > end) {
     return WRITE_ERR;
   }

   int check = check_job(job);
   if (check == 1) {
     return MALFORMED_JOB;
   }
   if (job.status == EMPTY) {
     return MALFORMED_JOB;
   }

   fseek(fp, n * sizeof(job_t), SEEK_SET);

   int items_wrote = fwrite(&job, sizeof(job_t), 1, fp);
   if (items_wrote != 1) {
     return WRITE_ERR;
   }

   return OK;

 } /* write_job() */

 /*
  *  This function updates a jobs's status at a specified index.
  */

 int update_job_status(FILE *fp, int n) {
   assert (fp != NULL);
   assert (n >= 0);

   fseek(fp, 0, SEEK_END);
   long end = ftell(fp);

   // check if n exceeds file end
   if (n * sizeof(job_t) >= end) {
     return WRITE_ERR;
   }

   // check if malformed job
   job_t job = read_job(fp, n);

   int check = check_job(job);
   if (check == 1) {
     return MALFORMED_JOB;
   }
   if (job.status == EMPTY) {
     return MALFORMED_JOB;
   }

   // check dependency
   fseek(fp, 0, SEEK_SET);
   int found = 0;
   job_t dependency = {};
   int independent_job = 0;

   //printf("n: %d (%d) | ", n, n * 112); printjob(job);
   for (int i = 0; i < end; i += sizeof(job_t)) {
     fseek(fp, i, SEEK_SET);
     fread(&dependency, sizeof(job_t), 1, fp);

     if (i == n * sizeof(job_t)) {
       if (strcmp(job.dependency_job_id, job.id) == 0) {
         independent_job = 1;
       }
     }

     //printf("i: %d| ", i); printjob(dependency);
     if (strcmp(job.dependency_job_id, dependency.id) == 0) {
       if (dependency.status != EMPTY) {
         found = 1;
         break;
       }
     }
   }

   if (independent_job == 0) {
     if (found == 0) {
       //printf("not found!!!\n");
       return DEPENDENCY_ERROR;
     }
     if ((found == 1) &&
         ((dependency.status == WAITING) || (dependency.status == RUNNING))) {
       //printf("found\n");
       return DEPENDENCY_NOT_COMPLETE;
     }
   }

   // update job and write it
   if (job.status == WAITING) {
     job.status = RUNNING;
   }
   else if (job.status == RUNNING) {
     job.status = COMPLETED;
   }

   int write_result = write_job(fp, job, n);

   if (write_result == WRITE_ERR) {
     return WRITE_ERR;
   }
   return OK;

 } /* update_job_status() */

 /*
  *  This function adds a new job to the end of the given file.
  */

 int add_job(FILE *fp, job_t job) {
   assert(fp != NULL);

   int check = check_job(job);

   if (check == 1) {
     return MALFORMED_JOB;
   }
   if ((job.status == EMPTY) || (job.status == COMPLETED)) {
     return MALFORMED_JOB;
   }

   fseek(fp, 0, SEEK_END);
   int end = ftell(fp);

   job_t latest_job = {};
   if (end != 0) {
     fseek(fp, end - sizeof(job_t), SEEK_SET);
     fread(&latest_job, sizeof(job_t), 1, fp);

     //printf("JOB: "); printjob(job);
     //printf("latest: "); printjob(latest_job);

     if (job.submission_time < latest_job.submission_time) {
       return MALFORMED_JOB;
     }
   }

   int write_result = write_job(fp, job, end / sizeof(job_t));
   if (write_result == WRITE_ERR) {
     return WRITE_ERR;
   }

   return OK;

 } /* add_job() */

 /*
  *  This function deletes the job from the file with a specified ID.
  */

 int delete_job(FILE *fp, char *c) {
   assert(fp != NULL);
   assert((c != NULL) && (strlen(c) > 0));
   //printf("C: %s\n", c);

   int found = 0;
   int idx = 0;
   job_t job = {};
   fseek(fp, 0, SEEK_END);
   int end = ftell(fp);
   //printf("end: %d\n", end);

   for (int i = 0; i < end; i += sizeof(job_t)) {
     fseek(fp, i, SEEK_SET);
     fread(&job, sizeof(job_t), 1, fp);
     if ((strcmp (job.id, c) != 0) || (job.status == EMPTY)) {
       continue;
     }

     // pass the write err check
     //printf("found: %d | ", i); printjob(job);
     if (write_job(fp, job, i / sizeof(job_t)) == WRITE_ERR) {

       //printf("write err 1\n");
       return WRITE_ERR;
     }


     found = 1;
     idx = i / sizeof(job_t);
     job.status = EMPTY;

     fseek(fp, i, SEEK_SET);
     if (fwrite(&job, sizeof(job_t), 1, fp) != 1) {
       return WRITE_ERR;
     }

     break;
   }

   if (found == 0) {
     //printf("NO MATCHES!!!\n");
     return NO_JOB;
   }

   for (int i = 0; i < end; i += sizeof(job_t)) {
     fseek(fp, i, SEEK_SET);
     fread(&job, sizeof(job_t), 1, fp);

     if ((strcmp(job.dependency_job_id, c) == 0) && (job.status != EMPTY)) {
       strcpy(job.dependency_job_id, job.id);
       if (write_job(fp, job, i / sizeof(job_t)) == WRITE_ERR) {
         //printf("write err 3\n");
         return WRITE_ERR;
       }
     }

   }

   //printf("final idx: %d\n", idx);
   return idx;

 } /* delete_job() */

 /*
  *  This function runs all the jobs of a the specified user, which means
  *  changing the status for Waiting to Running.
  */

 int run_job_for_user(FILE *fp, char *c) {
   assert (fp != NULL);
   assert ((c != NULL) && (strlen(c) != 0));

   //printf("name: %s\n", c);

   fseek(fp, 0, SEEK_END);
   int end = ftell(fp);

   job_t cur = {};
   int found = 0;
   int count = 0;

   for (int i = 0; i < end; i += sizeof(job_t)) {
     fseek(fp, i, SEEK_SET);
     fread(&cur, sizeof(job_t), 1, fp);

     if ((strcmp (cur.user_id, c) != 0) ||
         (cur.status == EMPTY)) {
       continue;
     }

     //printf("found: "); printjob(cur);
     found = 1;

     if (cur.status != WAITING) {
       continue;
     }

     if (write_job(fp, cur, i / sizeof(job_t)) == WRITE_ERR) {
       return WRITE_ERR;
     }

     int depend_complete = 0;
     int depend_found = 0;
     job_t depend = {};

     if (strcmp(cur.dependency_job_id, cur.id) == 0) {
       depend_found = 1;
       depend_complete = 1;
     }
     else {
       for (int j = 0; j < end; j += sizeof(job_t)) {
         fseek(fp, j, SEEK_SET);
         fread(&depend, sizeof(job_t), 1, fp);

         if ((strcmp(depend.id, cur.dependency_job_id) == 0)
             && (depend.status != EMPTY)) {
           depend_found = 1;

           if (depend.status == COMPLETED) {
             depend_complete = 1;
           }
         }
       }
     }

     if (depend_found == 0) {
       return DEPENDENCY_ERROR;
     }
     if (depend_complete == 1) {
       cur.status = RUNNING;
       count++;
       if (write_job(fp, cur, i / sizeof(job_t)) == WRITE_ERR) {
         return WRITE_ERR;
       }
     }
   }

   if (found == 0) {
     return NO_USER;
   }

   return count;

 } /* run_job_for_user() */

 /*
  *  This function cleans up the job queue by removing all jobs
  *  that will be completed by time N.
  */

 int clean_job_queue(FILE *fp, int n) {
   assert(fp != NULL);
   assert(n >= 0);

   //printf("N: %d\n", n);

   fseek(fp, 0, SEEK_END);
   int end = ftell(fp);

   //printf("end: %d\n", end);
   if (end == 0) {
     return 0;
   }

   job_t cur = {};
   int count = 0;
   int time_err = 1;

   for (int i = 0; i < end; i += sizeof(job_t)) {
     fseek(fp, i, SEEK_SET);
     fread(&cur, sizeof(job_t), 1, fp);

     if (cur.submission_time <= n) {
       //printf("smaller than n: "); printjob(cur);
       time_err = 0;
     }

     if (cur.status == EMPTY) {
       //printf("EMPTY: "); printjob(cur);
       continue;
     }

     if ((cur.status == COMPLETED) || ((cur.status == RUNNING) &&
         (cur.submission_time + cur.required_time <= n))) {

       count++;

       cur.status = EMPTY;
       fseek(fp, i, SEEK_SET);
       if (fwrite(&cur, sizeof(job_t), 1, fp) != 1) {
         //printf("WRITE ERR 1\n");
         return WRITE_ERR;
       }

       job_t depend = {};
       for (int j = 0; j < end; j += sizeof(job_t)) {
         fseek(fp, j, SEEK_SET);
         fread(&depend, sizeof(job_t), 1, fp);

         if ((depend.status != EMPTY) &&
             (strcmp(depend.dependency_job_id, cur.id) == 0)) {
           strcpy(depend.dependency_job_id, depend.id);

           fseek(fp, j, SEEK_SET);
           if (fwrite(&depend, sizeof(job_t), 1, fp) != 1) {
             //printf("WRITE ERR 2\n");
             return WRITE_ERR;
           }
         }
       }
     }
   }

   //printf("count: %d\n", count);

   if (time_err == 1) {
     //printf("TIME ERR\n");
     return TIME_ERROR;
   }

   return count;

 } /* clean_job_queue() */

 /*
  *  This function finds the best runnable job that requires less than n cores.
  */

 int find_best_runnable_job(FILE *fp, int n) {
   assert(fp != NULL);
   assert(n >= 0);

   //printf("N: %d\n", n);

   fseek(fp, 0, SEEK_END);
   int end = ftell(fp);

   int found = 0;
   int max_cores = 0;
   int max_priority = 0;
   int earliest_time = 0;

   int idx = 0;
   job_t cur = {};
   for (int i = 0; i < end; i += sizeof(job_t)) {
     fseek(fp, i, SEEK_SET);
     fread(&cur, sizeof(job_t), 1, fp);

     if (cur.status != WAITING) {
       continue;
     }
     if (cur.required_cores > n) {
       continue;
     }

     int dependency_complete = 0;
     int dependency_found = 0;

     int independent = 0;
     if (strcmp(cur.dependency_job_id, cur.id) == 0) {
       independent = 1;
       dependency_found = 1;
       dependency_complete = 1;
     }

     // if cur is a dependent job
     if (independent == 0) {
       job_t dependency = {};

       for (int j = 0; j < end; j += sizeof(job_t)) {
         fseek(fp, j, SEEK_SET);
         fread(&dependency, sizeof(job_t), 1, fp);

         if ((strcmp(cur.dependency_job_id, dependency.id) == 0) &&
             (dependency.status != EMPTY)) {
           dependency_found = 1;
           if (dependency.status == COMPLETED) {
             dependency_complete = 1;
           }
         }
       }
     }

     if (dependency_found == 0) {
       return DEPENDENCY_ERROR;
     }

     if (dependency_complete == 1) {
       found = 1;

       if (cur.required_cores > max_cores) {
         max_cores = cur.required_cores;
         max_priority = cur.priority_level;
         earliest_time = cur.submission_time;
         idx = i / sizeof(job_t);
       }
       else if (cur.required_cores == max_cores) {
         if (cur.priority_level > max_priority) {
           max_priority = cur.priority_level;
           earliest_time = cur.submission_time;
           idx = i / sizeof(job_t);
         }
         else if (cur.priority_level == max_priority) {
           if (cur.submission_time < earliest_time) {
             earliest_time = cur.submission_time;
             idx = i / sizeof(job_t);
           }
         }
       }
     }
   }

   if (found == 0) {
     //printf("NOT FOUND\n");
     return NO_RUNNABLE_JOB;
   }

   //printf("idx: %d| cores: %d\n", idx, max_cores);

   int update_status = update_job_status(fp, idx);
   //printf("updatestatus: %d\n", update_status);

   if (update_status == WRITE_ERR) {
     return WRITE_ERR;
   }
   if (update_status == DEPENDENCY_ERROR) {
     return DEPENDENCY_ERROR;
   }
   if (update_status == DEPENDENCY_NOT_COMPLETE) {
     return DEPENDENCY_NOT_COMPLETE;
   }

   return OK;

 } /* find_best_runnable_job() */


 //int main() { printf("why"); return 0; }

