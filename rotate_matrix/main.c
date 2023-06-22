#include<stdio.h>
#include<stdlib.h>

#define XSize 10
#define YSize 10

void rotate(int*** matrix ,int xSize, int ySize);
int** getRandomArray(int row, int column);

int main(){
    srand(0);
    int i ,j;
    int ** matrix;
    matrix = getRandomArray(XSize,YSize);
    
    rotate(&matrix,XSize,YSize);

    printf("\n matrisin son hali\n");
    for(i=0;i<XSize;i++){
        for(j=0;j<YSize;j++){
            printf(" %d ",matrix[i][j]);
        }
        printf("\n");
    }

    for(i=0;i<XSize;i++){
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}

void rotate(int*** matrix ,int xSize, int ySize){

    int i = 0;
    int j = 0;
    scanf("%d",&i);

    int** tmp = (int**) malloc(sizeof(int*)*xSize);
    if(tmp == NULL){
        printf("there is no enough space for allocation");
        exit(-1);
    } 

    for(i =0;i<xSize;i++){
        tmp[i] = (int*) malloc(sizeof(int)*ySize);
    }


    for(i=0;i<xSize;i++){
        for(j=0;j<ySize;j++){
            tmp[i][j] = (*matrix)[xSize-j-1][i];
        }
    }

    for(i =0;i<xSize;i++){
        for(j=0;j<ySize;j++){
            printf(" %d ",tmp[i][j]);
        }
        printf("\n");
    }

    for(i=0;i<xSize;i++){
        free((*matrix)[i]);
    }
    free((*matrix));

    (*matrix) = tmp;
}


int** getRandomArray(int row, int column){

    int** tmp = (int**) malloc(sizeof(int*)*row);
    if(tmp == NULL){
        printf("tmp was null");
        return NULL;
    }
    int i,j = 0;
    for(i =0;i<row;i++){
        tmp[i] = (int*) malloc(sizeof(int)*column);
    }

     for(i =0;i<row;i++){
        for(j=0;j<column;j++){
            tmp[i][j] = rand()%250+100;
        }
    }

     for(i =0;i<row;i++){
        for(j=0;j<column;j++){
            printf(" %d ",tmp[i][j]);
        }
        printf("\n");
    }

    return tmp;
}