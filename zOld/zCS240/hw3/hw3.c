#include "hw3.h"
#include <stdio.h>
#include <string.h>

char g_loan_history[MAX_LOANS][3][MAX_BUF_LEN] = {};
char g_book_info[MAX_LOANS][3][MAX_BUF_LEN] = {};
float g_loan_stats[MAX_LOANS][4] = {};
int g_loan_count = 0;

/*
 * This function reads in the data from a given input file
 * then it stores the data into the 4 global variables accordingly.
 */

int read_tables(char *file_name) {
  g_loan_count = 0;
	FILE *fp = fopen(file_name, "r");
	if (fp == NULL) {
		return FILE_READ_ERR;
  }

  //printf("%s\n", file_name);

	char name[MAX_BUF_LEN] = {};
	char checkdate[MAX_BUF_LEN] = {};
	char duedate[MAX_BUF_LEN] = {};
	char barcode[MAX_BUF_LEN] = {};
	char title[MAX_BUF_LEN] = {};
	char author[MAX_BUF_LEN] = {};
	float daysloaned = 0.0;
	float rating = 0.0;
	float fee = 0.0;
	float condition = 0.0;

	int count = -1;
	int rows = 0;
	while (1) {
		count = fscanf(fp, " %99[^|]|%99[^|]|%99[^|]|%99[^,],%99[^,],%99[^|]|"
      "%f|%f|%f|%f", name, checkdate, duedate, barcode, title, author,
      &daysloaned, &rating, &fee, &condition);
    if (count == EOF) {
      break;
    }
		if (count != 10) {
        //printf("C1");
      fclose(fp);
      return BAD_DATA;
		}
    char next = "";
    if (fscanf(fp, "%c", &next) == 1 && next != '\n') {
      fclose(fp);
      return BAD_DATA;
    }
		if ((strlen(name) >= MAX_BUF_LEN) || (strlen(checkdate) >= MAX_BUF_LEN) || 
			(strlen(duedate) >= MAX_BUF_LEN) || (strlen(barcode) != 17) || 
			(strlen(title)  >= MAX_BUF_LEN) || (strlen(author) >= MAX_BUF_LEN) || 
      (daysloaned < 0.0) || (rating < 0.0) || (rating > 10.0) || 
      (fee < 0.0) || (condition < 0.0)) {
			fclose(fp);
      //printf("C2");
			return BAD_DATA;
		}   
    for (int i = 0; i < 17; i++) {
			if (barcode[i] < '0' || barcode[i] > '9') {
				fclose(fp);
				return BAD_DATA;
			}
		}

		int cyear;
		int cmonth; 
		int cday;
		int dyear;
		int dmonth;
		int dday;
		int temp1 = sscanf(checkdate, "%d-%d-%d", &cyear, &cmonth, &cday);
		int temp2 = sscanf(duedate, "%d-%d-%d", &dyear, &dmonth, &dday);

		if ((temp1 != 3) || (temp2 != 3) || (cyear < MIN_YEAR) || 
      (dyear < MIN_YEAR) || (cyear > MAX_YEAR) || (dyear > MAX_YEAR) || 
      (cmonth < 1) || (dmonth < 1) || (cmonth > 12) || (dmonth > 12) || 
      (cday < 1) || (dday < 1) || (cday > 30) || (dday > 30)) {
		  fclose(fp);		
      //printf("C3");
			return BAD_DATA;
		}
		int before = 0;
		if (cyear > dyear) {
			before = 1;
		} else if (cyear == dyear) {
			if (cmonth > dmonth) {
				before = 1;
			} else if (cmonth == dmonth) {
				if (cday > dday) {
					before = 1;
				}
			}
		}
		if (before == 1) {
      //printf("C4");
			fclose(fp);		
			return BAD_DATA;
		}
	
    if (rows >= MAX_LOANS) {
      fclose(fp);
      return OUT_OF_BOUNDS;
    }

    strcpy(g_loan_history[rows][0], name);
    strcpy(g_loan_history[rows][1], checkdate);
    strcpy(g_loan_history[rows][2], duedate);
    strcpy(g_book_info[rows][0], barcode);
    strcpy(g_book_info[rows][1], title);
    strcpy(g_book_info[rows][2], author);
    g_loan_stats[rows][0] = daysloaned;
    g_loan_stats[rows][1] = rating;
    g_loan_stats[rows][2] = fee;
    g_loan_stats[rows][3] = condition;
    rows++;
	}

  if (rows == 0) {
    fclose(fp);
    return NO_DATA_POINTS;
  }

	g_loan_count = rows;

	fclose(fp);
	return rows;

} /* read_tables() */

/*
 * This function returns the total days loaned for a single book.
 */

float get_total_days_loaned(char *barcode) {
  if (g_loan_count == 0) {
    return NO_DATA_POINTS;
  }
  float total = 0;
  int found = 0;
  for (int i = 0; i < g_loan_count; i++) {
    if (strcmp(g_book_info[i][0], barcode) == 0) {
      total += g_loan_stats[i][0];
      found = 1;
    }
  }
  if (found == 0) {
    return NOT_FOUND;
  }
  return total;

} /* get_total_days_loaned() */

/*
 * This function returns the average rating for a given author.
 */

float avg_author_satisfaction(char *author) {
  if (g_loan_count == 0) {
    return NO_DATA_POINTS;
  }
  float total = 0;
  int num = 0;
  int found = 0;
  for (int i = 0; i < g_loan_count; i++) {
    if (strcmp(g_book_info[i][2], author) == 0) {
      total += g_loan_stats[i][1];
      num++;
      found = 1;
    }
  }
  if (found == 0) {
    return NOT_FOUND;
  }
  float average = (float) total / (float) num;
  return average;

} /* avg_author_satisfaction() */

/*
 * This function returns the average conditioning cost for a book.
 */

float avg_conditioning_cost(char *barcode) {
  if (g_loan_count == 0) {
    return NO_DATA_POINTS;
  }
  float total = 0;
  int num = 0;
  int found = 0;
  for (int i = 0; i < g_loan_count; i++) {
    if (strcmp(g_book_info[i][0], barcode) == 0) {
      total += g_loan_stats[i][3];
      num++;
      found = 1;
    }
  }
  if (found == 0) {
    return NOT_FOUND;
  }
  float average = (float) total / (float) num;
  return average;

} /* avg_conditioning_cost() */


/*
 * This function calculates the most popular books and stores them into the popular books array
 * It returns the number of books that were considered popular.
 */

int find_popular_books(float min_days, char popular_books[MAX_LOANS][MAX_BUF_LEN]) {
  if (g_loan_count == 0) {
    return NO_DATA_POINTS;
  }
  int idx = 0;
  int vis[205] = {0};
  for (int i = 0; i < g_loan_count; i++) {
    if (vis[i] == 1) {
      continue;
    }
    vis[i] = 1;
    int total = g_loan_stats[i][0];
    
    for (int j = 0; j < g_loan_count; j++) {
      if (vis[j] == 1) {
        continue;
      }
      if (strcmp(g_book_info[i][0], g_book_info[j][0]) == 0){
        vis[j] = 1;
        total += g_loan_stats[j][0];
      }
    }
    if (total > min_days) {
      //printf("%s %f\n", g_book_info[i][0], g_loan_stats[i][0]);
      strcpy(popular_books[idx], g_book_info[i][0]);
      idx++;
    }
  }
  //printf("tot: %d\n", idx);
  return idx;

} /* find_popular_books() */

/*
 * This function finds the most popular author based on how many lines of data
 * contained the authors book.
 */

int find_popular_author(void) {
  if (g_loan_count == 0) {
    return NO_DATA_POINTS;
  }
  int first = 0;
  int Max = 0;

  for (int i = 0; i < g_loan_count; i++) {
    int cur = 0;
    for (int j = 0; j < g_loan_count; j++) {
      if (strcmp(g_book_info[i][2], g_book_info[j][2]) == 0) {
        cur++;
      }
    }

    if (cur > Max) {
      Max = cur;
      first = i;
    }
  }
  return first;

} /* find_popular_author() */

/*
 * This function calculates the ROI for a given book.
 */

float calc_item_roi(char *barcode) {
  if (g_loan_count == 0) {
    return NO_DATA_POINTS;
  }
  int found = 0;
  float profit = 0;
  float cost = 0;

  for (int i = 0; i < g_loan_count; i++) {
    if (strcmp(g_book_info[i][0], barcode) == 0) {
      profit += g_loan_stats[i][2];
      cost += g_loan_stats[i][3];
      found = 1;
    }
  }

  if (found == 0) {
    return NOT_FOUND;
  }
  if (cost == 0) {
    return ZERO_FEES;
  }

  float roi = (1 - ((float) cost / (float) profit)) * 100;
  
  if (roi < 0) {
    return 0;
  } else {
    return roi;
  }

} /* calc_item_roi() */

/*
 * This function outputs all you need to know about a patron into the outfile.
 */

int generate_patron_report(char *out_file, char *patron_name) {
  if (g_loan_count == 0) {
    return NO_DATA_POINTS;
  }
  FILE *fp = fopen(out_file, "w");
  if (fp == NULL) {
    return FILE_WRITE_ERR;
  }
  fprintf(fp, "Loan History for %s:\n\n", patron_name);
  int found = 0;
  int loans = 0;
  float days = 0;
  float fees = 0;
  int Max = 0;
  char author[MAX_BUF_LEN];
  for (int i = 0; i < g_loan_count; i++) {
    if (strcmp(g_loan_history[i][0], patron_name) == 0) {
      found = 1;
      loans++;
      days += g_loan_stats[i][0];
      fees += g_loan_stats[i][2];

      int cur = 0;
      for (int j = 0; j < g_loan_count; j++) {
        if ((strcmp(g_loan_history[j][0], patron_name) == 0) &&
            (strcmp(g_book_info[i][2], g_book_info[j][2]) == 0)) {
          cur++;
        }
      }
      if (cur > Max) {
        Max = cur;
        strcpy(author, g_book_info[i][2]);
      }

      fprintf(fp, "Loan %d:\n%s to %s\nBook: %s | %s | %s\nDays Loaned: %.2f\nRating: %.2f\nLate Fees Paid: %.2f\n\n", loans, g_loan_history[i][1], g_loan_history[i][2], g_book_info[i][0], g_book_info[i][1], g_book_info[i][2], g_loan_stats[i][0], g_loan_stats[i][1], g_loan_stats[i][2]);
    }
  }
  fprintf(fp, "Overall Summary:\nTotal Loans: %d\nTotal Days Loaned: %.2f\nTotal Late Fees Paid: %.2f\nMost Commonly Borrowed Author: %s\n", loans, days, fees, author);

  fclose(fp);
  if (found == 0) {
    return NOT_FOUND;
  }
  return OK;

} /* generate_patron_report() */


int main () {
	int x = read_tables("input.txt");
	FILE *out = fopen("output.txt", "w");

  int popular_books[MAX_LOANS][MAX_BUF_LEN];
  //int x2 = find_popular_books(0.0, popular_books);
  int x3 = generate_patron_report("output.txt", "Jane Smith");
	fprintf(out, "%d", x3);
}
