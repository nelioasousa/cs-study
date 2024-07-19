#include <stddef.h>
#include <stdio.h>

struct point {
    double x, y;
};

struct node {
    struct point *point;
    struct node *next;
};

struct cycle {
    size_t size;
    struct node *entry;
};

struct point *read_points(FILE *file, size_t *num_points);
double points_distance(struct point *a, struct point *b);
void swap_points(struct point *a, struct point *b);
double cycle_length(struct cycle *cycle);
