char populate2dCharArray(int x,int y,int xSub,int ySub,int i, int j){
    if (i==ySub+1 && j==xSub+1){
        return 'X';
    } else if ((i==0 && j==0) || (i==0 && j==x-1) || (i==y-1 && j==0) || (i==y-1 && j==x-1)){
        return 'O';
    } else if ((i==0 || i==y-1) && (j!=0 && j!= x-1)){
        return '-';
    } else if ((i>0 || i<y-1) && (j==0 || j== x-1)) {
        return 'I';
    } else {
        return '.';
    }
}

