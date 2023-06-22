
#include<stdio.h>
#include<stdlib.h>

int** threeSum(int* nums, int numsSize, int* returnSize, int*** returnColumnSizes);
 
int main(){

    int numbers[6] = {-1,0,1,2,-1,-4};
    int returnSize = 0;
    int** returnValue = NULL;

    int** res = threeSum(numbers,6,&returnSize,&returnValue);
    int i = 0;
    for(int i = 0;i<returnSize;i++){
            printf("%d, %d, %d\n",res[i][0],res[i][1],res[i][2]);

    }
}


int** threeSum(int* nums, int numsSize, int* returnSize, int*** returnColumnSizes){

    int i;
    int key;
    int j = 0;
    int sum = 0;

   (*returnColumnSizes)= (int**) malloc(sizeof(int*)*numsSize);
    for(i=0;i<numsSize;i++){
        (*returnColumnSizes)[i] = (int*) malloc(sizeof(int)*3);
        (*returnColumnSizes)[i][0] = 0;
        (*returnColumnSizes)[i][1] = 0;
        (*returnColumnSizes)[i][2] = 0;
    }
    (*returnSize) = 0;

    for(i=0;i<numsSize;i++){
        key = nums[i];
        j=i-1;
        while(j>=0&&nums[j]>key){
            nums[j+1] = nums[j];
            j=j-1;
        }
        nums[j+1] = key;
    }

    int k = numsSize-1;

    for(i =0;i<numsSize;i++){
        j = i+1;

        while(j<k){
            sum = nums[i] + nums[j] + nums[k];

            if(sum == 0){
                (*returnColumnSizes)[*returnSize][0] = nums[i];
                (*returnColumnSizes)[*returnSize][1] = nums[j];
                (*returnColumnSizes)[*returnSize][2] = nums[k];
                (*returnSize)++;
                j++;
                k--;
            }else if(sum<0){
                j++;
            }else{
                k--;
            }
        }
    }
    return *returnColumnSizes;
}