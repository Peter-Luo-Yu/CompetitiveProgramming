#ifndef HW4_H
#define HW4_H

/* Constant definitions */

#define MAX_ITERATIONS (255)

/* Structure declarations */

struct complex {
  double x;
  double y;
};

typedef struct complex complex_t;

/* Function prototypes */

complex_t add_complex(complex_t, complex_t);
complex_t neg_complex(complex_t);
complex_t sub_complex(complex_t, complex_t);
double dot_complex(complex_t, complex_t);
complex_t inv_complex(complex_t);
complex_t mul_complex(complex_t, complex_t);
complex_t div_complex(complex_t, complex_t);
double mag_complex(complex_t);
complex_t pow_complex(complex_t, int);
int newton(complex_t);

#endif // HW4_H
