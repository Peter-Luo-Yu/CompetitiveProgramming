#ifndef HW5_H
#define HW5_H

#include <stdio.h>

/* Constant definitions */

#define MAX_LENGTH (30)

/* Error codes */

#define OK (0)
#define WRITE_ERR (-1)
#define MALFORMED_JOB (-2)
#define NO_JOB (-3)
#define DEPENDENCY_ERROR (-4)
#define DEPENDENCY_NOT_COMPLETE (-5)
#define NO_USER (-6)
#define TIME_ERROR (-7)
#define NO_RUNNABLE_JOB (-8)

#define BAD_JOB ((job_t){ .id = "" })

/* Enum declarations */

typedef enum {
  LOW = 0,
  MEDIUM = 1,
  HIGH = 2
} priority_t;

typedef enum {
  WAITING = 0,
  RUNNING = 1,
  COMPLETED = 2,
  EMPTY = 3
} status_t;

/* Structure declarations */

typedef struct {
  char id[MAX_LENGTH];
  char user_id[MAX_LENGTH];
  int required_cores;
  int required_time;
  priority_t priority_level;
  status_t status;
  char dependency_job_id[MAX_LENGTH];
  int submission_time;
} job_t;

/* Function prototypes */

job_t read_job(FILE *, int);
int write_job(FILE *, job_t, int);
int update_job_status(FILE *, int);
int add_job(FILE *, job_t);
int delete_job(FILE *, char *);
int run_job_for_user(FILE *, char *);
int clean_job_queue(FILE *, int);
int find_best_runnable_job(FILE *, int);

#endif // HW5_H
