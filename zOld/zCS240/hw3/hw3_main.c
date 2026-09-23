/*
 * Homework 3 main program
 * CS 240, Spring 2026
 * Purdue University
 */

#include "hw3.h"

#include <stdio.h>
#include <string.h>

/* Helper function forward declarations */

static void print_return_float_value(float, const char *);
static void print_return_value(int, const char *);
static void print_book_names_from_barcodes(char barcodes[][MAX_BUF_LEN], int count);
static int read_int(const char *);
static float read_float(const char *);
static void read_line(const char *restrict, char *restrict, size_t);

/*
 * Convert an error code into its string representation.
 */

const char *get_msg(int val) {
  char *msg = NULL;
  switch (val) {
    case OK:
      msg = "OK";
      break;
    case FILE_READ_ERR:
      msg = "FILE_READ_ERR";
      break;
    case NO_DATA_POINTS:
      msg = "NO_DATA_POINTS";
      break;
    case BAD_DATA:
      msg = "BAD_DATA";
      break;
    case FILE_WRITE_ERR:
      msg = "FILE_WRITE_ERR";
      break;
    case OUT_OF_BOUNDS:
      msg = "OUT_OF_BOUNDS";
      break;
    case NOT_FOUND:
      msg = "NOT_FOUND";
      break;
  }

  return msg;
} /* get_msg() */

/*
 * Print the return value of a function which returns an integer.
 */

void print_return_value(int val, const char *function) {
  printf("The value returned by the %s() was: %d", function, val);
  const char *s = get_msg(val);
  if (s != NULL) {
    printf(" (%s)", s);
  }
  printf("\n");
} /* print_return_value() */

/*
 * Print the return value of a function which returns a float.
 */

void print_return_float_value(float val, const char *function) {
  printf("The value returned by the %s() was: %f", function, val);
  const char *s = get_msg(val);
  if (s != NULL) {
    printf(" (%s)", s);
  }
  printf("\n");
} /* print_return_float_value() */

/*
 * Print book names from an array of barcodes by looking up titles in
 * g_book_info.
 */

void print_book_names_from_barcodes(char barcodes[][MAX_BUF_LEN], int count) {
  for (int i = 0; i < count; i++) {
    char *title = NULL;
    for (int j = 0; j < g_loan_count; j++) {
      if (strncmp(g_book_info[j][0], barcodes[i], MAX_BUF_LEN) == 0) {
        title = g_book_info[j][1];
        break;
      }
    }
    if (title != NULL) {
      printf("%s - %s\n", barcodes[i], title);
    }
    else {
      printf("%s\n", barcodes[i]);
    }
  }
} /* print_book_names_from_barcodes() */

/*
 * This function is used to run the functions defined in hw1.c.
 * User input is used to determine the inputs to the functions.
 * Upon completion, returns 0.
 */

int main() {
  int choice = 0;
  char file[1000] = {};
  char patron[MAX_BUF_LEN] = {};
  char author[MAX_BUF_LEN] = {};
  char barcode[MAX_BUF_LEN] = {};
  float min_days = 0;
  int val = 0;
  float float_val = 0.0;

  /* Main loop */

  while (1) {
    printf("-----------------------------------------\n");
    printf("0) Quit\n"
           "1) read_tables()\n"
           "2) get_total_days_loaned()\n"
           "3) avg_author_satisfaction()\n"
           "4) avg_conditioning_cost()\n"
           "5) find_popular_books()\n"
           "6) find_popular_author()\n"
           "7) calc_item_roi()\n"
           "8) generate_patron_report()\n"
           "9) Print Loan Record\n\n");
    choice = read_int("Select a function: ");

    /* Prompt for file name when needed */

    if (choice == 1) {
      read_line("Enter the input file name: ", file, sizeof(file));
    }

    if (choice == 8) {
      read_line("Enter the output file name: ", file, sizeof(file));
    }

    /* Prompt for barcode when needed */

    if ((choice == 2) || (choice == 4) || (choice == 7)) {
      read_line("Enter the book's barcode: ", barcode, sizeof(barcode));
    }

    /* Prompt for author when needed */

    if (choice == 3) {
      read_line("Enter the author name: ", author, sizeof(author));
    }

    if (choice == 5) {
      min_days = read_float("Enter the minimum days loaned: ");
    }

    if (choice == 8) {
      read_line("Enter patron name: ", patron, sizeof(patron));
    }

    int index = 0;
    if (choice == 9) {
      index = read_int("Enter the index: ");
    }

    /* Call appropriate functions based on user selection */

    char popular_books[MAX_LOANS][MAX_BUF_LEN] = {""};
    switch (choice) {
      case 0:
        printf("Goodbye.\n");
        return 0;

      case 1:
        val = read_tables(file);
        print_return_value(val, "read_tables");
        break;

      case 2:
        float_val = get_total_days_loaned(barcode);
        print_return_float_value(float_val, "get_total_days_loaned");
        break;

      case 3:
        float_val = avg_author_satisfaction(author);
        print_return_float_value(float_val, "avg_author_satisfaction");
        break;

      case 4:
        float_val = avg_conditioning_cost(barcode);
        print_return_float_value(float_val, "avg_conditioning_cost");
        break;

      case 5:
        val = find_popular_books(min_days, popular_books);
        print_return_value(val, "find_popular_books");
        if (val >= 0) {
          printf("There are %d popular books:\n", val);
          print_book_names_from_barcodes(popular_books, val);
        }
        break;

      case 6:
        val = find_popular_author();
        print_return_value(val, "find_popular_author");
        if (val >= 0) {
          printf("Most popular author: %s\n", g_book_info[val][2]);
        }
        break;

      case 7:
        float_val = calc_item_roi(barcode);
        print_return_float_value(float_val, "calc_item_roi");
        break;

      case 8:
        val = generate_patron_report(file, patron);
        print_return_value(val, "generate_patron_report");
        break;

      case 9:
        if (g_loan_count == 0) {
          printf("Error: No data loaded. Please call read_tables() first.\n");
        }
        else if ((index < 0) || (index >= g_loan_count)) {
          printf("Error: Invalid index. Valid range is 0 to %d.\n",
                 g_loan_count - 1);
        }
        else {
          printf("\n=== Loan Record at Index %d ===\n", index);
          printf("Patron Name:       %s\n", g_loan_history[index][0]);
          printf("Checkout Date:     %s\n", g_loan_history[index][1]);
          printf("Due Date:          %s\n", g_loan_history[index][2]);
          printf("Barcode:           %s\n", g_book_info[index][0]);
          printf("Title:             %s\n", g_book_info[index][1]);
          printf("Author:            %s\n", g_book_info[index][2]);
          printf("Days Loaned:       %.2f\n", g_loan_stats[index][0]);
          printf("Rating:            %.2f\n", g_loan_stats[index][1]);
          printf("Late Fee:          $%.2f\n", g_loan_stats[index][2]);
          printf("Conditioning Cost: $%.2f\n", g_loan_stats[index][3]);
          printf("==============================\n");
        }
        break;

      default:
        printf("Invalid choice. Please select one of the options.\n");
        break;
    }
  }

  return 0;
} /* main() */

/*
 * Prints the prompt, then reads a line containing a single integer from
 * standard input. Repeats the prompt/input stage until a valid input is read.
 * Returns the integer read.
 */

int read_int(const char *prompt) {
  do {
    int num = 0;
    fputs(prompt, stdout);
    scanf("%d", &num);
    if (getchar() == '\n') {
      return num;
    }
    else {
      while (getchar() != '\n') {
      }
      printf("Invalid input. Try again.\n");
    }
  } while (1);
} /* read_int() */

/*
 * Prints the prompt, then reads a line containing a single float from
 * standard input. Repeats the prompt/input stage until a valid input is read.
 * Returns the float read.
 */

float read_float(const char *prompt) {
  do {
    float num = 0;
    fputs(prompt, stdout);
    scanf("%f", &num);
    if (getchar() == '\n') {
      return num;
    }
    else {
      while (getchar() != '\n') {
      }
      printf("Invalid input. Try again.\n");
    }
  } while (1);
} /* read_float() */

/*
 * Prints the given prompt, then reads a line from standard input, and stores it
 * in the given buffer. Truncates the stored string to the given size, including
 * the NUL terminator.
 */

void read_line(const char *restrict prompt, char *restrict buf, size_t size) {
  fputs(prompt, stdout);
  fgets(buf, size - 1, stdin);
  size_t len = strlen(buf);
  if (buf[len - 1] == '\n') {
    buf[len - 1] = '\0';
  }
  else {
    while (getchar() != '\n') {
    }
  }
} /* read_line() */
