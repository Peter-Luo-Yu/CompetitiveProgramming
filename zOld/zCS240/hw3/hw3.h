#ifndef HW3_H
#define HW3_H

/* Constant definitions */

#define MAX_LOANS (200)
#define MAX_BUF_LEN (100)
#define MIN_YEAR (2000)
#define MAX_YEAR (2026)

/* Error codes */

#define OK (-1)
#define FILE_READ_ERR (-2)
#define NO_DATA_POINTS (-3)
#define BAD_DATA (-4)
#define FILE_WRITE_ERR (-5)
#define OUT_OF_BOUNDS (-6)
#define NOT_FOUND (-7)
#define ZERO_FEES (-8)

/* Global Variables */

// 0: Patron Name
// 1: Checkout Date
// 2: Due Date

extern char g_loan_history[MAX_LOANS][3][MAX_BUF_LEN];

// 0: Barcode
// 1: Title
// 2: Author

extern char g_book_info[MAX_LOANS][3][MAX_BUF_LEN];

// 0: Days Loaned
// 1: Rating
// 2: Late Fee
// 3: Conditioning Cost

extern float g_loan_stats[MAX_LOANS][4];
extern int g_loan_count;

/* Function prototypes */

int read_tables(char *file_name);
float get_total_days_loaned(char *barcode);
float avg_author_satisfaction(char *author);
float avg_conditioning_cost(char *barcode);
int find_popular_books(float min_days,
                    char popular_books[MAX_LOANS][MAX_BUF_LEN]);
int find_popular_author(void);
float calc_item_roi(char *barcode);
int generate_patron_report(char *out_file, char *patron_name);

#endif // HW3_H