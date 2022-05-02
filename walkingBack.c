#include <stdio.h>

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