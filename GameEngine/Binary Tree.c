#include<stdlib.h>
#include<stdio.h>


typedef struct node
{
    int data;
   struct node* left;
   struct node* right;
}node;

node* getNewNode(int data)
{
    node* node = malloc(sizeof(data));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

int Search(node* root, int data)
{
    if(root == NULL)return 0;
    else if(root->data ==  data) return 1;
    else if(data <= root->data)return Search(root->left,data);
    else return Search(root->right,data);
}

node* Insert(node* root,int data)
{
    //If Empty tree
    if(root == NULL)
    {
        root = getNewNode(data);
    }
    //if data is less than current node
    //Assign it to left-most leaf
    else if(data < root->data)
    {
        root->left = Insert(root->left,data);
    }
    else
    {
        root->right = Insert(root->right,data);
    }

    return root;
}
int main(){

    node* root;//address of root Node

    //initially declare rootPtr as null
    root = NULL;

    root = Insert(root,15);    root = Insert(root,6);
    root = Insert(root,10);    root = Insert(root,0);
    root = Insert(root,20);    root = Insert(root,1);

    int number;

    printf("Enter a number to find in BST:");
    scanf("%d", &number);

    if(Search(root,number)==1) puts("Number Found! \n");
    else puts("Not Found \n");

    return 0;
}
