/*
 * Homework 13
 * Your Name
 * CS 240, Spring 2026
 * Purdue University
 */

#include <assert.h>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

#include "graphics.h"
#include "object.h"

object *read_object(const char *filename) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    return NULL;
  }
  printf("FILE: %s\n", filename);

  struct object *new_object = malloc(sizeof(struct object));
  assert(new_object != NULL);

  int n = 0;
  int m = 0;
  int count = fscanf(fp, "%*s\n%d %d\n", &n, &m);
  if (count != 2) {
    printf("bogus1...\n");
    free(new_object);
    return NULL;
  }
  //printf("got: %d %d %d\n", count, n, m);

  new_object->num_points = n;
  new_object->num_polygons = m;

  point *points = malloc(n * sizeof(point));
  assert(points != NULL);

  int one_indexed = 0;

  for (int i = 0; i < n; i++) {
    int idx = -1;
    double x = 0.0;
    double y = 0.0;
    double z = 0.0;

    count = fscanf(fp, "%d %lf %lf %lf\n", &idx, &x, &y, &z);
    if (count != 4) {
      printf("bogus2...\n");
      free(new_object);
      free(points);
      fclose(fp);
      fp = NULL;
      return NULL;
    }

    if (i == 0) {
      if (idx == 1) {
        one_indexed = 1;
      } else {
        one_indexed = 0;
      }
    }
  
    points[i].arr[0] = x;
    points[i].arr[1] = y;
    points[i].arr[2] = z;
    
  }
  new_object->points = points;

  struct polygon *polygons = malloc(m * sizeof(struct polygon));
  assert(polygons != NULL);

  for (int i = 0; i < m; i++) {
    char *color = malloc(80 * sizeof(char));
    int k = 0;

    assert(color != NULL);

    count = fscanf(fp, "%*s %s %d ", color, &k);
    if (count != 2) {
      printf("bogus3...\n");
      free(new_object);
      free(points);
      free(polygons);
      fclose(fp);
      fp = NULL;
      return NULL;
    }
    //printf("Got: %s %d\n", color, k);

    unsigned char r = '\0';
    unsigned char g = '\0';
    unsigned char b = '\0';
    name_to_rgb(color, &r, &g, &b);

    //printf("r: %u | g: %c | b: %c\n", r, g, b);
    
    point **point_arr = malloc(k * sizeof(point *));

    for (int j = 0; j < k; j++) {
      int p = 0;
      if (j < k - 1) {
        count = fscanf(fp, "%d ", &p);
      }
      else {
        count = fscanf(fp, "%d\n", &p);
      }
      
      if (count != 1) {
        printf("bogus4...\n");
        for (int x = 0; x < i; x++) {
          free(polygons[x].point_arr);
        }
        free(point_arr);
        free(color);

        free(polygons);
        free(new_object->points);
        free(new_object);

        fclose(fp);
        fp = NULL;
        return NULL;
      }
      
      if (one_indexed == 1) {
        point_arr[j] = &points[p - 1];
      } else {
        point_arr[j] = &points[p];
      }
    }
    free(color);

    polygons[i].point_arr = point_arr;
    polygons[i].r = r;
    polygons[i].g = g;
    polygons[i].b = b;
    polygons[i].num_points = k;

  }
  new_object->polygons = polygons;
  

  fclose(fp);
  fp = NULL;
  return new_object;
}

void free_object(object *obj) {
  if (obj == NULL) {
    return;
  }

  free(obj->points);

  for (int i = 0; i < obj->num_polygons; i++) {
    polygon poly = (obj->polygons)[i];

    free(poly.point_arr);
  }

  free(obj->polygons);
  free(obj);
}