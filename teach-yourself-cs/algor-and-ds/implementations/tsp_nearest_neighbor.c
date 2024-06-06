#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


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


struct point *read_points(FILE *file, size_t *size);
struct cycle *build_cycle(struct point *points, size_t n);
double cycle_length(struct cycle *cycle);


int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: %s filepath\n", argv[0]);
        return 1;
    }

    FILE *pfile = fopen(argv[1], "r");
    if (pfile == NULL) {
        printf("Couldn't open file\n");
        return 2;
    }
    
    size_t num_points;
    struct point *points = read_points(pfile, &num_points);
    if (points == NULL) {
        printf("File not understood\n");
        return 3;
    }
    
    struct cycle *cycle = build_cycle(points, num_points);
    double length = cycle_length(cycle);
    printf("Cycle length: %lf\n", length);

    fclose(pfile);
    free(points);
    free(cycle);
    return 0;
}

struct point *append_point(struct point *points, size_t n, struct point *point)
{
    if (points == NULL || n == 0) {
        struct point *points = malloc(sizeof(struct point));
        points[0] = *point;
        return points;
    }
    struct point *new_arr = calloc(n + 1, sizeof(struct point));
    new_arr[n] = *point;
    for (size_t i = 0; i < n; i++) {
        new_arr[i] = points[i];
    }
    return new_arr;
}

struct point *read_points(FILE *file, size_t *size)
{
    *size = 0;
    struct point *points = NULL;
    struct point *point;
    double coord;
    int result;
    while (true) {
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
        struct point *new_points = append_point(points, *size, point);
        (*size)++;
        free(points);
        points = new_points;
    }
    return points;
}

double point_dist(struct point *a, struct point *b)
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

struct cycle *build_cycle(struct point *points, size_t n)
{
    for (size_t i = 1; i < n - 1; i++) {
        size_t closest = i;
        double min_dist = point_dist(points + i - 1, points + i);
        for (size_t j = i + 1; j < n; j++) {
            double dist = point_dist(points + i - 1, points + j);
            if (dist < min_dist) {
                closest = j;
                min_dist = dist;
            }
        }
        swap_points(points + i, points + closest);
    }
    struct cycle *cycle = calloc(1, sizeof(struct cycle));
    cycle->size = n;
    struct node *anode = calloc(1, sizeof(struct node));
    anode->point = points;
    cycle->entry = anode;
    for (size_t i = 1; i < n; i++) {
        anode->next = calloc(1, sizeof(struct node));
        anode->next->point = points + i;
        anode = anode->next;
    }
    anode->next = cycle->entry;
    return cycle;
}

double cycle_length(struct cycle *cycle)
{
    if (cycle->entry == cycle->entry->next) {
        return 0.0;
    }
    double length = 0.0;
    struct node *current = cycle->entry;
    do {
        length += point_dist(current->point, current->next->point);
        current = current->next;
    }
    while (current != cycle->entry);
    return length;
}
