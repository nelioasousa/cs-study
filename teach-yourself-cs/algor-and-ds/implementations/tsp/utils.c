#include "utils.h"
#include <math.h>
#include <stdlib.h>


struct point *extend_points_array(struct point *points, size_t n, struct point *new_point)
{
    if (points == NULL || n == 0) {
        struct point *points = malloc(sizeof(struct point));
        points[0] = *new_point;
        return points;
    }
    struct point *extended = calloc(n + 1, sizeof(struct point));
    extended[n] = *new_point;
    for (size_t i = 0; i < n; i++) {
        extended[i] = points[i];
    }
    return extended;
}

struct point *read_points(FILE *file, size_t *num_points)
{
    *num_points = 0;
    struct point *points = NULL;
    struct point *point;
    double coord;
    int result;
    while (1) {
        point = malloc(sizeof(struct point));
        result = fscanf(file, "%lf ", &coord);
        if (!result || result == EOF) {
            free(point);
            break;
        }
        point->x = coord;
        result = fscanf(file, "%lf\n", &coord);
        if (!result || result == EOF) {
            free(point);
            break;
        }
        point->y = coord;
        struct point *new_points = extend_points_array(points, *num_points, point);
        (*num_points)++;
        free(points);
        points = new_points;
    }
    return points;
}

double points_distance(struct point *a, struct point *b)
{
    return sqrt(pow(b->x - a->x, 2) + pow(b->y - a->y, 2));
}

void swap_points(struct point *a, struct point *b)
{
    double tmp = a->x;
    a->x = b->x;
    b->x = tmp;
    tmp = a->y;
    a->y = b->y;
    b->y = tmp;
}

double cycle_length(struct cycle *cycle)
{
    if (cycle->entry == cycle->entry->next) {
        return 0.0;
    }
    double length = 0.0;
    struct node *current = cycle->entry;
    do {
        length += points_distance(current->point, current->next->point);
        current = current->next;
    }
    while (current != cycle->entry);
    return length;
}
