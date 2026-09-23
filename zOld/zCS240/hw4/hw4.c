/*
 * Homework 4
 * Your Name
 * CS 240, Spring 2026
 * Purdue University
 */

#include "hw4.h"

#include<math.h>
#include<stdio.h>

/*
 * This function returns the sum of two complex numbers
 */

complex_t add_complex(complex_t z1, complex_t z2) {
  complex_t sum = {};
  sum.x = z1.x + z2.x;
  sum.y = z1.y + z2.y;
  return sum;

} /* add_complex() */

/*
 * This function returns the complex number times negative one
 */

complex_t neg_complex(complex_t z) {
  complex_t neg = {};
  neg.x = -z.x;
  neg.y = -z.y;
  return neg;

} /* neg_complex() */

/*
 * This function returns the difference of two complex numbers
 */

complex_t sub_complex(complex_t z1, complex_t z2) {
  complex_t sub = {};
  sub.x = z1.x - z2.x;
  sub.y = z1.y - z2.y;
  return sub;

} /* sub_complex() */

/*
 * This function returns the squared magnitude of two complex numbers
 */

double dot_complex(complex_t z1, complex_t z2) {
  double dot = z1.x * z2.x + z1.y * z2.y;
  return dot;

} /* dot_complex() */

/*
 * This function returns the inverse of a complex number (1/z)
 * same as: 1 divided by z
 */

complex_t inv_complex(complex_t z) {
  complex_t inv = {};
  inv.x = z.x / dot_complex(z, z);
  inv.y = -z.y / dot_complex(z, z);
  return inv;

} /* inv_complex() */

/*
 * This function returns the product of two complex numbers
 */

complex_t mul_complex(complex_t z1, complex_t z2) {
  complex_t mul = {};
  mul.x = z1.x * z2.x - z1.y * z2.y;
  mul.y = z1.x * z2.y + z1.y * z2.x;
  return mul;

} /* mul_complex() */

/*
 * This function returns the quotient of two complex numbers
 */

complex_t div_complex(complex_t z1, complex_t z2) {
  complex_t div = {};
  div = mul_complex(z1, inv_complex(z2));
  return div;

} /* div_complex() */

/*
 * This function returns the magnitude of a complex number
 */

double mag_complex(complex_t z) {
  return sqrt(dot_complex(z, z));

} /* mag_complex() */

/*
 * This function returns the result when a complex number is raised to a power
 */

complex_t pow_complex(complex_t z, int power) {
  complex_t pow = {1.0, 0};
  if (power == 0) {
    return pow;
  }
  pow = z;
  if (power > 0) {
    for (int i = 1; i < power; i++) {
      pow = mul_complex(pow, z);
    } 
    return pow;
  } 
  else {
    power *= -1;
    for (int i = 1; i < power; i++) {
      pow = mul_complex(pow, z);
    } 
    complex_t temp = {1.0, 0};
    return div_complex(temp, pow);
  }

} /* pow_complex() */

/*
 * This function calculates the newton fractal of a given complex number
 */

int newton(complex_t c) {
  //printf("New: %f %f \n", c.x, c.y);

  complex_t z = c;

  complex_t denom = mul_complex(z, z);
  denom.x *= 3; 
  denom.y *= 3;

  complex_t num = pow_complex(z, 3);
  num.x -= 1;

  complex_t right = div_complex(num, denom);
  
  int ops = 0;
  while (ops < MAX_ITERATIONS && dot_complex(denom, denom) > 1e-20 &&
         dot_complex(right, right) > 1e-12) {
    z = sub_complex(z, right);
    //printf("ops: %d | %f %f \n", ops, Z.x, Z.y);
    ops++;
    denom = mul_complex(z, z);
    denom.x *= 3; 
    denom.y *= 3;
    num = pow_complex(z, 3);
    num.x -= 1;
    right = div_complex(num, denom);
  }
  return ops;

} /* newton() */


