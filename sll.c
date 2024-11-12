#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node * next;
    int data;
};

struct node* createnode(int data){
    struct node* newnode =(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
} 

struct node* insertatfirst(struct node* head,int data){
    struct node* newnode= createnode(data);
    newnode->next=head;
   return newnode;
}

int print(struct node* head){
    int count=0;
    struct node* current=head;
    while (current!=NULL)
    {
        printf("%d ",current->data);
        current=current->next;
        count++;
    }
    return count;
}
struct node* insertatend(struct node* head,int data ){
    struct node* temp=head;
    struct node* newnode=createnode(data);
    while (temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    return head;  
}

struct node* insertrandom(struct node* head,int data,int pos){
    struct node* newnode=createnode(data);
    struct node* temp=head;
    int n=1;
    if (pos==1)
    {
        return insertatfirst(head,data);
    }
    else{

        while (temp->next!=NULL && pos-1>n)
        {
            temp=temp->next;
            n++;
        }

        if(temp==NULL|| temp->next==NULL){
            printf("Out of bounds");
            return head;
    }
    newnode->next=temp->next;
    temp->next=newnode;
    return head;   
}
}

struct node* deletefirst(struct node* head){
    if (head==NULL)
    {
        return NULL;
    }
    
    struct node* temp=head;
    head=head->next;
    free(temp);
    return head;

}
struct node* deleteend(struct node* head){
    struct node* temp=head;
    if (head==NULL)
    {
       return NULL;
    }
    if (head->next==NULL)
    {
        free(head);

        return NULL;
    }
    
    
    while (temp->next->next!=NULL)
    {
        temp=temp->next;

    }
    free(temp->next);
    temp->next=NULL;
    return head;
}
struct node* deleterandom(struct node* head,int pos){
    if (pos==1)
    {
        return deletefirst(head);
    }
    struct node* temp=head;
    int n=1;
    while (temp->next!=NULL && pos-1>n)
    {
        temp=temp->next;
        n++;
    }
    if (temp==NULL || temp->next==NULL)
    {
       return head;
    }
    struct node* delete=temp->next;
    temp->next=delete->next;
    free(delete);
    return head;
    

    
}
int main(){
    struct node* head=createnode(5);
    struct node* first=createnode(4);
    struct node* second=createnode(6);
   
    head->next=first;
    first->next=second;
    print(head);
    printf("\n");
    head=insertatfirst(head,12);
    head=insertatend(head,90);
    print(head);
    printf("\n");
    
    head=insertrandom(head,22,3);
    print(head);
    printf("\n");
    head=deletefirst(head);
    print(head);
     printf("\n");
    head=deleteend(head);
       print(head);
     printf("\n");
     head=deleterandom(head,2);
       print(head);
     printf("\n");



    return 0;
}