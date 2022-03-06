#include <stdio.h>
#include <stdlib.h>

/* function responcible for measuring the distance walked until hit a wall */
int measuring(int condition, int checkingValue) {
	char decide[2];
	int counter=0, wall=0;

	while (wall==0) {
		printf("Ist eine Wand da? (y/n)\n");
		scanf("%s", decide);

		switch(decide[0]){
			case 'y':
			case 'Y':
				if (condition == 0) {
					printf("Drehe 90 Grad nach rechts!\n");
					wall=1;
				} else {
					if (counter < checkingValue) {
						printf("Du befindest dich nicht in einem rechteckigen Raum!\n");
						exit(0);
					} else {
						printf("Drehe 90 Grad nach rechts!\n");
						wall=1;
					}
				}
				break;
			case 'n':
			case 'N':
				printf("Schritt!\n");
				counter++;
				break;
			default:
				printf("Ungültige Eingabe!\n");
				break;
		}
	}
	return counter;
}

/* function responcible for the basic walking back after all the data is collected */
void walkingBack(int condition, int decide) {
    int i;
	for ( i=0; i<condition; i++){
		printf("Schritt\n");
	}
    if(decide==0){
        printf("Der Robotter steht am Ausgangspunkt!\n");
    } else {
        printf("Drehe 90 Grad nach rechts!\n");
    }
}

/* create a dynamicly allocated array for use in drawing the room in ascii */
char **malloc2dCharArray(int dim1, int dim2) {
    char **ipp;
    int i;
    ipp=(char**)malloc(dim1*sizeof(char*));
    for (i=0; i<dim1; i++){
        ipp[i]=(char*)malloc(dim2*sizeof(char));
    }
    return ipp;
}

/* free the used allocated space in the HEAP */
void free2dCharArray(char** ipp, int dim1){
    int i;
    for (i=0; i<dim1; i++){
        free(ipp[i]);
    }
    free(ipp);
}

int main() {
    /* create coordinates array for measuring the size of the room and where I'm standing */
	int coordinates[4]={0, 0, 0, 0}; /* 0=-x, 1=-y, 2=x, 3=y */

	printf("STARTE ROBOTTER!\n\n");
    coordinates[0] = measuring(0, 0);
    coordinates[1] = measuring(0, 0);
    coordinates[2] = measuring(1, coordinates[0]);
    coordinates[3] = measuring(1, coordinates[1]);
    int xSub = coordinates[2] - coordinates[0], ySub = coordinates[3] - coordinates[1];

	printf("\nDie begehbare Flaeche des Raumes ist:\nx=%d y=%d\nDein Startpunkt:\nx=%d y=%d\n\n", coordinates[2], coordinates[3], xSub, ySub);

    /* Start creating the 2d Array */

    int x,y;
    char **room;
    if(coordinates[2] == 0 && coordinates[3] == 0) {
        /* not walked */
        x=3,y=3;
        room = malloc2dCharArray(y,x);

    } else if (coordinates[2] == 0 && coordinates[3] > 0) {
        /* walked x==0 */
        x=3, y= coordinates[3] + 3;
        room = malloc2dCharArray(y, x);

    } else if (coordinates[2] > 0 && coordinates[3] == 0) {
        /* walked y==0 */
        x= coordinates[2] + 3, y=3;
        room = malloc2dCharArray(y, x);
    } else {
        /* both walked */
        x= coordinates[2] + 3, y= coordinates[3] + 3;
        room = malloc2dCharArray(y, x);
    }
    
    /* start to populate the array with chars */
    for(int i=0; i<y; i++) {
        for(int j=0; j<x; j++){
            if (i==ySub+1 && j==xSub+1){
                room[i][j] = 'X';
            } else if ((i==0 && j==0) || (i==0 && j==x-1) || (i==y-1 && j==0) || (i==y-1 && j==x-1)){
                room[i][j] = 'O';
            } else if ((i==0 || i==y-1) && (j!=0 && j!= x-1)){
                room[i][j] = '-';
            } else if ((i>0 || i<y-1) && (j==0 || j== x-1)) {
                room[i][j] = 'I';
            } else {
                room[i][j] = '.';
            }
        }
    }
    
    /* print the array to the console */
    for(int i=0; i<y; i++) {
        for(int j=0; j<x; j++){
            printf("%c", room[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    /* free the memory in the HEAP */
    free2dCharArray(room, y);
    printf("Bitte druecke eine Taste um zurzueck zu laufen!");
    getchar();
    getchar();
    
    /* decide how to walk back to the beginning */
	if(xSub < coordinates[2] && xSub > 0 && ySub < coordinates[3] && ySub > 0) {
        // Fall 3
        walkingBack(coordinates[2], 1);
        walkingBack(ySub, 1);
        walkingBack(coordinates[0], 0);
    } else if(xSub < coordinates[2] && xSub > 0 && ySub == coordinates[3]) {
        // Fall 2.5
        walkingBack(coordinates[2], 1);
        walkingBack(coordinates[3], 1);
        walkingBack(coordinates[0], 0);
    } else if(xSub == coordinates[2] && ySub == coordinates[3] && coordinates[2] > 0 && coordinates[3] > 0){
        // Fall 2
        walkingBack(coordinates[2], 1);
        walkingBack(coordinates[3], 0);
    } else if(xSub == coordinates[2] && ySub < coordinates[3] && ySub > 0) {
        // Fall 1.5
        walkingBack(coordinates[2], 1);
        walkingBack(ySub, 0);
    } else if(xSub == coordinates[2] && ySub == 0 && coordinates[2] > 0) {
        // Fall 1
        walkingBack(coordinates[2], 0);
    } else if(xSub < coordinates[2] && xSub > 0 && ySub == 0) {
        // Fall 0.5
        walkingBack(xSub, 0);
    } else {
        // Fall 0
        printf("Der Robotter steht bereits am Ausgangspunkt!\n");
    }

	printf("\nAUFGABE ERFUELLT!\nSchalte Robotter aus!\n");
    return 0;
}
