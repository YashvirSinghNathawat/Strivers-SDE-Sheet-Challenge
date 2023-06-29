bool isValid(int matrix[9][9],int row,int col,int x){
    for(int i=0;i<9;i++){
        if(matrix[i][col]==x or matrix[row][i]==x)  return false;

        if(matrix[3*(row/3)+i/3][3*(col/3)+i%3]==x) return false;    
    }
    return true;
}
bool isItSudoku(int matrix[9][9]) {
    // Write your code here.
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(matrix[i][j]==0){

                for(int x =1;x<=9;x++){
                    if(isValid(matrix,i,j,x)){
                        matrix[i][j] = x;
                        if(solve(matrix))   return true;
                        matrix[i][j] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}
