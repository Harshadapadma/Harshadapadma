# include <stdio.h>
# include <stdlib.h>

struct node
{
    struct node* left;
    struct node* right;
    int data;
};
struct node* createnode(int data){
    struct node* newnode=(struct node*)malloc (sizeof(struct node));
    newnode->data=data;
    newnode->right=NULL;
    newnode->left=NULL;
    return newnode;
}
int main(){
    struct node* root=createnode(10);
    root->right=createnode(20);
    root->right->left=createnode(18);
    root->left=createnode(5);
    printf("%d ",root->left->data);
    printf("%d ",root->data);
    printf("%d ",root->right->data);
    printf("%d ",root->right->left->data);
    return 0;

    
}