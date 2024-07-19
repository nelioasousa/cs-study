#include "utils.h"
#include <stdlib.h>


struct cycle *nearest_neighbor_cycle(struct point *points, size_t num_points);


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
    
    struct cycle *cycle = nearest_neighbor_cycle(points, num_points);
    double length = cycle_length(cycle);
    printf("Cycle length: %lf\n", length);

    fclose(pfile);
    free(points);
    free(cycle);
    return 0;
}


struct cycle *nearest_neighbor_cycle(struct point *points, size_t num_points)
{
    for (size_t i = 1; i < num_points-1; i++) {
        size_t closest = i;
        double min_dist = points_distance(points + i - 1, points + i);
        for (size_t j = i + 1; j < num_points; j++) {
            double dist = points_distance(points + i - 1, points + j);
            if (dist < min_dist) {
                closest = j;
                min_dist = dist;
            }
        }
        swap_points(points + i, points + closest);
    }
    struct cycle *cycle = calloc(1, sizeof(struct cycle));
    cycle->size = num_points;
    struct node *anode = calloc(1, sizeof(struct node));
    anode->point = points;
    cycle->entry = anode;
    for (size_t i = 1; i < num_points; i++) {
        anode->next = calloc(1, sizeof(struct node));
        anode->next->point = points + i;
        anode = anode->next;
    }
    anode->next = cycle->entry;
    return cycle;
}
