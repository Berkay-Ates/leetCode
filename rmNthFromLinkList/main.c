#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}NODE;

NODE* newNode(int value);
NODE* removeNode(NODE** head,int order);
void addToList(NODE** head,int value);
void printList(NODE* head);
 
int main(){
    NODE* head = NULL;
    addToList(&head,0);
    addToList(&head,1);
    addToList(&head,2);
    addToList(&head,3);
    addToList(&head,4);
    addToList(&head,5);
    addToList(&head,6);
    addToList(&head,7);
    addToList(&head,8);
    printList(head);

    NODE* tmp;
    tmp = removeNode(&head,3);
    printList(head);

    printf("removed element head is : %d\n",tmp->data);

    return 0;
}

void printList(NODE* head){
    while(head->next!=NULL){
        printf("%d",head->data);
        head= head->next;
    }
    printf("\n");
}

NODE* removeNode(NODE** head,int order){
    NODE* tmp = *head;
    NODE* tmp2 = NULL;
    int j = 0;
    if(tmp == NULL){
        printf("linked list is null ");
        return NULL;
    }
    if(order == 0){
        (*head) = (*head)->next;
        printf("head just removed so return value is removed head");
    }
    while(j<order && tmp->next != NULL){
        tmp2 = tmp;
        tmp = tmp->next;
        j++;
    }

    if(j==order){
        tmp2->next = tmp->next;
        free(tmp);
        return tmp2; 
    }

    printf("there is not enough node in the linked list. You should try to remove smaller order elements\n");
    return NULL;

}

void addToList(NODE** head,int value){
    if(*head == NULL){
        *head = newNode(value);
        return;
    }
    NODE* tmp = *head;
    while(tmp->next != NULL){
        tmp = tmp->next;
    }
    
    tmp->next = newNode(value);
}

NODE* newNode(int value){
    NODE* tmp = (NODE*) malloc(sizeof(NODE));
    if(tmp == NULL)
        exit(-1);
    tmp->next = NULL;
    tmp->data = value;
    return tmp;
}