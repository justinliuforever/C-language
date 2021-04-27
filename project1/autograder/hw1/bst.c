#include<stdio.h>

#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *left, *right;
}Node;


//create a new node, return it
struct Node *createNode(int data)
{
    //allocate space to new node
    struct Node *temp =  malloc(sizeof(struct Node));
    // add the value item
    temp->value = data;
    //assign both left and right pointers to null
    temp->left = temp->right = NULL;
    //return the node created
    return temp;
}


//if there is no that number, insert number
struct Node * insert(struct Node* node, int data)
{
    //If the tree is empty, use data to return a new node
    if (node == NULL)
    {
        node = createNode(data);
        return node;
    }
    
    // if the node same
    if(node->value == data)
    {
        return node;
    }
    

    //check  node‘position
    if (data < node->value)
    {
        node->left = insert(node->left, data);
    }
    else// if (data > node->value)
    {
        node->right = insert(node->right, data);
    }

    return node;

}

// traversal inorder recursive
void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d\t", root->value);
        inorder(root->right);
    }
}
  

//main function

int main(int argc, char **argv)

{

    struct Node *root = NULL;

    //check
    if(argc < 2)
    {

        printf("error\n");
        return 0;
    }

    int d;
    FILE *fp;

    //open file containing data in read mode
    //The file is either blank or contains successive lines of input.

    fp = fopen(argv[1], "r");

    if(fp == NULL)

    {

        printf("error\n");

        return 2;

    }

//This fscanf statement must be  the form of %*c%*c%c  which  means we expect two characters which we must ignore

// Like i and <space> the character after that is our data so we have %*c   %*c    %c  Just take the last c in variable ch

//after that comes a new line \n which we must ignore

    while(fscanf(fp,"%*c%*c%d\n",&d)== 1)
    {
        // call the insert function above, insert node into the tree
        root = insert(root, d);
    }

    
//print the root
    inorder(root);
//free space
    fclose(fp);

    return 0;
}

