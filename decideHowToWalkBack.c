#include <stdio.h>
void walkingBack(int*, int);

/* decide how to walk back to the beginning */
void decideHowToWalkBack(int *coordinates, int *ySub, int *xSub) {
    if (*xSub < coordinates[2] && *xSub > 0 && *ySub < coordinates[3] && *ySub > 0) {
        // Fall 3
        walkingBack(coordinates+2, 1);
        walkingBack(ySub, 1);
        walkingBack(coordinates, 0);
    } else if (*xSub < coordinates[2] && *xSub > 0 && *ySub == coordinates[3]) {
        // Fall 2.5
        walkingBack(coordinates+2, 1);
        walkingBack(coordinates+3, 1);
        walkingBack(coordinates, 0);
    } else if (*xSub == coordinates[2] && *ySub == coordinates[3] && coordinates[2] > 0 && coordinates[3] > 0) {
        // Fall 2
        walkingBack(coordinates+2, 1);
        walkingBack(coordinates+3, 0);
    } else if (*xSub == coordinates[2] && *ySub < coordinates[3] && *ySub > 0) {
        // Fall 1.5
        walkingBack(coordinates+2, 1);
        walkingBack(ySub, 0);
    } else if (*xSub == coordinates[2] && *ySub == 0 && coordinates[2] > 0) {
        // Fall 1
        walkingBack(coordinates+2, 0);
    } else if (*xSub < coordinates[2] && *xSub > 0 && *ySub == 0) {
        // Fall 0.5
        walkingBack(xSub, 0);
    } else {
        // Fall 0
        printf("Der Roboter steht bereits am Ausgangspunkt!\n");
    }
}