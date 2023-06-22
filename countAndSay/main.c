#include<stdio.h>
#include<stdlib.h>
#define COUNT 15

int* countNumbers(int* numbers,int count);
void sayTheCounts(int* values,int count);
 
int main(){
    int values[COUNT] = {1,1,1,2,2,2,4,4,4,5,7,7,7,8,8};
    int* res = NULL;
    res = countNumbers(values,COUNT);
    sayTheCounts(res,COUNT);

}


int* countNumbers(int* numbers,int count){

    int* values = (int*) malloc(sizeof(int)*count);
    int i;
    for(i = 0;i<count;i++){
        values[numbers[i]]++;
    }
    return values;
}

void sayTheCounts(int* values,int count){

    int i =0;
    for(i =0;i<count;i++){
        if(values[i] != NULL){
            printf("%d%d",values[i],i);
        }
    }
}


