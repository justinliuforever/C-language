#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
   int data;
   struct Node* next;
}Node;


void display(struct Node *head)//calculate the number of node
{
struct Node *curr = head;
int count = 0;
int checking[1000] = {};//creat a list, use the node's data as the index, to check whether it is already exist or not
    
while(curr != NULL)// how many node
{
count ++;
curr = curr->next;
}
printf("%d\n",count);

curr = head;
    

//printing the linked list values
while(curr!= NULL)
{
if(checking[curr->data]==0)
{
printf("%d\t",curr->data);
//setting current data to be visited
checking[curr->data] = -1;
}
curr = curr->next;
}
}


// function to create new node
struct Node* NewNode(int data)
{
    struct Node *newNode = (struct Node*)calloc(1,sizeof(struct Node));
   newNode->data = data;
   newNode->next = NULL;
    
return newNode;
free(newNode);
}


// Function to insert the data in sorted order
void Insert(struct Node ** head,int data)
{
struct Node *newNode = NewNode(data);

   // if it is first node or it is smaller than *head
   if (*head == NULL || newNode->data <= (*head)->data)
   {
       newNode->next = *head;
       *head = newNode;
       return;
   }

   // Locate the node before the point of insertion
   struct Node *curr = *head;
   while (curr->next != NULL && curr->next->data < newNode->data)
       {
       curr = curr->next;
       }
        // inserting the node
        newNode->next = curr->next;
        curr->next = newNode;
    
}


void Delete(struct Node ** head ,int data)
{
// if head is NULL
if( *head == NULL)
{
return ;
}

//if the first node be deleted
if( (*head)->data == data)
{
(*head) = (*head)->next;
return ;
}
    
// Find the node before the point of deletion
struct Node* curr = *head;
while(curr->next != NULL )
       {
       if(curr->next ->data == data)
           break;
       curr = curr->next;
       }
    
//if the node is present in linked list
if(curr->next->data == data)
{
curr->next = curr->next->next;
}
}


// main method
int main(int argc,char *argv[])
{

// create head node;
struct Node* head = NULL;
char fname ;
int data;
//scanf("%s",filemane);
    
FILE *fp;
// opening the file in read mode

fp = fopen (argv[1], "r");
    
// check file
if(fp == NULL)
{
printf("error\n");
exit(2);
}
    
//reading all inside the file
while( fscanf(fp,"%c %d\n",&fname,&data) != EOF )
{
if(fname == 'd')
{
Delete(&head,data);
}else
{
Insert(&head,data);
}
}
    

fclose(fp);
display(head);

return 0;
}
