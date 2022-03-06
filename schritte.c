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
	for (i=0; i<condition; i++){
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
	int coordinats[4]={0,0,0,0}; // 0=-x, 1=-y, 2=x, 3=y

	printf("STARTE ROBOTTER!\n\n");
	coordinats[0] = measuring(0, 0);
	coordinats[1] = measuring(0, 0);
	coordinats[2] = measuring(1, coordinats[0]);
	coordinats[3] = measuring(1, coordinats[1]);
    int xSub = coordinats[2]-coordinats[0], ySub = coordinats[3]-coordinats[1];

	printf("\nDer Raum hat folgende Groesse:\nx=%d y=%d\nDein Startpunkt:\nx=%d y=%d\n\n", coordinats[2], coordinats[3], xSub, ySub);

    if(coordinats[2]==0 && coordinats[3]==0) {
        /* not walked */
        char room[3][3] = {
                {'O', '-', 'O'},
                {'I', 'X', 'I'},
                {'O', '-', 'O'}
        };
        int i;
        int j;
        for(i=0; i<3; i++) {
            for(j=0; j<3; j++){
                printf("%c", room[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    } else if (coordinats[2]==0 && coordinats[3]>0) {
        /* walked x==0 */
        room = malloc2dCharArray(3, coordinats[3]+3);
        for(int i=0; i<3; i++) {
            for(int j=0; j<coordinats[3]+3; j++){
                if (i==1 && j==ySub+1){
                    room[i][j] = 'X';
                } else if (i==0 && j==0 || i==3 && j==0 || i==0 && j==coordinats[3]+2 || i==3 && j==coordinats[3]+2){
                    room[i][j] = 'O';
                } else if ((j==0 || j==coordinats[3]+2) && (i!=0 || i!= 2) {
                    room[i][j] = '-';
                } else if ((j>0 || j<coordinats[3]+2) && (i==0 || i== 2)) {
                    room[i][j] = 'I';
                } else {
                    room[i][j] = '.';
                }
            }
        }

        for(i=0; i<3; i++) {
            for(j=0; j<coordinats[3]+3; j++){
                printf("%c", room[i][j]);
            }
            printf("\n");
        }
        printf("\n");

        free2dCharArray(room, 3)
    } else if (coordinats[2]>0 && coordinats[3]==0) {
        /* walked y==0 */
        room = malloc2dCharArray(coordinats[2]+3, 3);
    } else {
        /* both walked */
        room = malloc2dCharArray(coordinats[2]+3, coordinats[3]+3);
    }


	if(xSub<coordinats[2] && xSub>0 && ySub<coordinats[3] && ySub>0) {
        // Fall 3
        walkingBack(coordinats[2], 1);
        walkingBack(ySub, 1);
        walkingBack(coordinats[0], 0);
    } else if(xSub<coordinats[2] && xSub>0 && ySub==coordinats[3]) {
        // Fall 2.5
        walkingBack(coordinats[2], 1);
        walkingBack(coordinats[3], 1);
        walkingBack(coordinats[0], 0);
    } else if(xSub==coordinats[2] && ySub==coordinats[3] && coordinats[2]>0 && coordinats[3]>0){
        // Fall 2
        walkingBack(coordinats[2], 1);
        walkingBack(coordinats[3], 0);
    } else if(xSub==coordinats[2] && ySub<coordinats[3] && ySub>0) {
        // Fall 1.5
        walkingBack(coordinats[2], 1);
        walkingBack(ySub, 0);
    } else if(xSub==coordinats[2] && ySub==0 && coordinats[2]>0) {
        // Fall 1
        walkingBack(coordinats[2], 0);
    } else if(xSub<coordinats[2] && xSub>0 && ySub==0) {
        // Fall 0.5
        walkingBack(xSub, 0);
    } else {
        // Fall 0
        printf("Der Robotter steht bereits am Ausgangspunkt!\n");
    }

	printf("\nAUFGABE ERFUELLT!\n Schalte Robotter aus!\n");
    return 0;
}
