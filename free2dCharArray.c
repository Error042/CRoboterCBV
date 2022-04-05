#include <stdlib.h>

/* free the used allocated space in the HEAP */
void free2dCharArray(char** ipp, int dim1){
    int i;
    for (i=0; i<dim1; i++){
        free(ipp[i]);
    }
    free(ipp);
}