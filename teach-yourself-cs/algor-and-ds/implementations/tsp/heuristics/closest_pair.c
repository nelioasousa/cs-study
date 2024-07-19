#include "utils.h"
#include <stdio.h>
#include <stdlib.h>


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

    fclose(pfile);
    free(points);
    return 0;
}

struct cycle *closest_pair_cycle(struct point *points, size_t num_points)
{
    ;
}
