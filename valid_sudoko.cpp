bool isvalid(int row,int col,int number,int matrix[9][9]){
    for(int i=0; i<9; i++){
        if(matrix[row][i]==number) return false;

        if(matrix[i][col]==number) return false;

        if(matrix[3* (row/3) + i/3][3 * (col/3) + i%3]==number) return false; 
    }
    return true;

}
bool isItSudoku(int matrix[9][9]) {
    // Write your code here.
    for(int i = 0; i<9; i++){
        for(int j = 0; j<9; j++){
            if(matrix[i][j]==0){
                for(int c = 1; c<=9; c++){
                    if(isvalid(i,j,c,matrix)){
                        matrix[i][j]=c;
                        if(isItSudoku(matrix)) return true;
                        else matrix[i][j] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}
