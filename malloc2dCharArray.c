#include <stdlib.h>

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