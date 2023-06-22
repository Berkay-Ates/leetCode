#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void scanTheWord(char matrix[][4],int row, int column,char* word);

int main(){

    char matrix[3][4] = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };

    scanTheWord(matrix,3,4,"ABCCEDASF");
    return 0;
}


void scanTheWord(char matrix[][4],int row, int column,char* word){

    int i = 0;
    int j = 0;
    int k = 0;
    int locked = 0;
    int exists[50][50] = {{0}};

    printf("matrix[i][j] %c\n",matrix[i][j]);    
    exists[i][j] = 1;
    k++;

    while( k != strlen(word) && !locked && i>=0 && j>= 0 && i<row && j<column){
        
        if( matrix[i][j+1] == word[k] && exists[i][j+1] == 0){
            printf("matrix[i][j+1] %c\n",matrix[i][j+1]);    
            exists[i][j+1] = 1;
            k++;
            j++;
        }else if( matrix[i+1][j] == word[k] && exists[i+1][j] == 0){
            printf("matrix[i+1][j] %c\n",matrix[i+1][j]); 
            exists[i+1][j] = 1;
            k++;
            i++;
        }else if(matrix[i][j-1] == word[k] && exists[i][j-1] == 0){
            printf("matrix[i][j-1] %c\n",matrix[i][j-1]);  
            exists[i][j-1] = 1;  
            k++;
            j--;
        }else if(matrix[i-1][j] == word[k] && exists[i-1][j] == 0){
            printf("matrix[i-1][j] %c\n",matrix[i-1][j]);    
            exists[i-1][j] = 1; 
            k++;
            i--;
        }else{
            locked = 1;
            printf("\n searching is locked\n");
        }
    }
    printf("i:%d",i);
    printf("j:%d\n",j);
    for(i =0;i<row;i++){
        for(j=0;j<column;j++){
            printf(" %d ", exists[i][j]);
        }
        printf("\n");
    }


    printf("%d",k);

}