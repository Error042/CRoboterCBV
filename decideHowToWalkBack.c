#include <stdio.h>
void walkingBack(int, int);

/* decide how to walk back to the beginning */
void decideHowToWalkBack(int minusX, int x, int y, int ySub, int xSub) {
    if (xSub < x && xSub > 0 && ySub < y && ySub > 0) {
        // Fall 3
        walkingBack(x, 1);
        walkingBack(ySub, 1);
        walkingBack(minusX, 0);
    } else if (xSub < x && xSub > 0 && ySub == y) {
        // Fall 2.5
        walkingBack(x, 1);
        walkingBack(y, 1);
        walkingBack(minusX, 0);
    } else if (xSub == x && ySub == y && x > 0 && y > 0) {
        // Fall 2
        walkingBack(x, 1);
        walkingBack(y, 0);
    } else if (xSub == x && ySub < y && ySub > 0) {
        // Fall 1.5
        walkingBack(x, 1);
        walkingBack(ySub, 0);
    } else if (xSub == x && ySub == 0 && x > 0) {
        // Fall 1
        walkingBack(x, 0);
    } else if (xSub < x && xSub > 0 && ySub == 0) {
        // Fall 0.5
        walkingBack(xSub, 0);
    } else {
        // Fall 0
        printf("Der Roboter steht bereits am Ausgangspunkt!\n");
    }
}