#include <stdio.h>

void measuring(int*);
char **malloc2dCharArray(int, int);
void populate2dCharArray(char**, int*, int*, int*, int*);
void free2dCharArray(char**, int);
void decideHowToWalkBack(int*, int*, int*);

int main() {
    /* create coordinates array for measuring the size of the room and where I'm standing */
    int coordinates[5]={0, 0, 0, 0, 0}; /* 0=-x, 1=-y, 2=x, 3=y, 4=how often walked*/
    int i;

	printf("STARTE ROBOTTER!\n\n");
    for(i=0; i<4; i++) measuring(coordinates);
    int xSub = coordinates[2] - coordinates[0], ySub = coordinates[3] - coordinates[1];

	printf("\nDie begehbare Flaeche des Raumes ist:\nx=%d y=%d\nDein Startpunkt:\nx=%d y=%d\n\n", coordinates[2]+1, coordinates[3]+1, xSub, ySub);

    /* Start creating the 2d Array */
    int x,y;
    if (coordinates[2] == 0 && coordinates[3] == 0) x=3,y=3;                        /* not walked */
    else if (coordinates[2] == 0 && coordinates[3] > 0) x=3, y= coordinates[3] + 3; /* walked x==0 */
    else if (coordinates[2] > 0 && coordinates[3] == 0) x= coordinates[2] + 3, y=3; /* walked y==0 */
    else x= coordinates[2] + 3, y= coordinates[3] + 3;                              /* both walked */

    char **room = malloc2dCharArray(y, x);
    
    /* start to populate the array with chars */
    populate2dCharArray(room, &x, &y, &xSub, &ySub);

    /* print the array to the console */
    for(i=0; i<y; i++) {
        for(int j=0; j<x; j++){
            printf("%c", room[i][j]);
        }
        printf("\n");
    }
    
    /* free the memory in the HEAP */
    free2dCharArray(room, y);
    printf("\nO = Ecken des Raumes\nI & - = Waende eines Raumes\n. = Begehbare Flaeche\nX = Startpunkt des Roboters\n\nBitte druecke Enter um zurzueck zu laufen!");
    getchar();
    getchar();

    /* decide how to walk back to the beginning */
    decideHowToWalkBack(coordinates, &ySub, &xSub);

	printf("\nAUFGABE ERFUELLT!\nSchalte Roboter aus!\n");
    return 0;
}
