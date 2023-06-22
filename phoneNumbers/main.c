#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
void printValue(char* sayi,int order , char* toPrint );
char* getValues(int sayi);



int main(){

    char sayi[5];

    printf("enter the number as string: ");
   
    scanf("%s",sayi);
    char toPrint[10] = {'\0'};

    printValue(sayi,0,toPrint);
    return 0;
}

void printValue(char* sayi,int order , char* toPrint ){
    if(sayi[order] == '\0'){
        printf("%s\n",toPrint);
        free(toPrint);
        return;
    }
    char* values = NULL;
    values = getValues(sayi[order]-'0');
    char* printValues = NULL;
    int i=0 ,j= 0;
    while(values[i] != '\0'){
        printValues = (char*) malloc(sizeof(char)*6);
       
        j=0;
        while(toPrint[j] != '\0'){
            printValues[j] = toPrint[j];
            j++;
        }
        printValues[j] = values[i];
        printValues[j+1] = '\0';
        printValue(sayi,order+1,printValues);
        i++;
    }

}


char* getValues(int sayi){

    static char ch0[5] = {'\0'};
   static char ch1[5] = {'\0'};
   static char ch2[5] = {'a', 'b', 'c', '\0'};
   static char ch3[5] = {'d', 'e', 'f', '\0'};
   static char ch4[5] = {'g', 'h', 'i', '\0'};
   static char ch5[5] = {'j', 'k', 'l', '\0'};
   static char ch6[5] = {'m', 'n', 'o', '\0'};
   static char ch7[5] = {'p', 'q', 'r', 's', '\0'};
   static char ch8[5] = {'t', 'u', 'v', '\0'};
   static char ch9[5] = {'w', 'x', 'y', 'z', '\0'} ;

    switch(sayi){
        case 0:
        case 1:
            return ch0;
         case 2:
            return ch2;
         case 3:
            return ch3;
         case 4:
            return ch4;
         case 5:
            return ch5;
         case 6:
            return ch6;
         case 7:
            return ch7;
         case 8:
            return ch8;
         case 9:
            return ch9;

    }
}
