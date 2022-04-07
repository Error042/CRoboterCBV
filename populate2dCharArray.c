void populate2dCharArray(char **room,int *x,int *y,int *xSub,int *ySub){
    int i, j;
    for(i=0; i<*y; i++) {
        for(j=0; j<*x; j++){
            if (i==*ySub+1 && j==*xSub+1){
                room[i][j] = 'X';
            } else if ((i==0 && j==0) || (i==0 && j==*x-1) || (i==*y-1 && j==0) || (i==*y-1 && j==*x-1)){
                room[i][j] = 'O';
            } else if ((i==0 || i==*y-1) && (j!=0 && j!= *x-1)){
                room[i][j] = '-';
            } else if ((i>0 || i<*y-1) && (j==0 || j== *x-1)) {
                room[i][j] = 'I';
            } else {
                room[i][j] = '.';
            }
        }
    }
}

