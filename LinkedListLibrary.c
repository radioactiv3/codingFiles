#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node
{
   int data;
   struct node* next ;

};
struct node* newnode(int data)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next= NULL;
    return newnode;

};
void printlist(struct node*head)
{
    struct node* temp =head ;
    while (temp!= NULL)
    {
         printf("  %d",temp->data);
        temp = temp->next;
    }
    printf("\n");
    return ;
}
int length(struct node* head)
{
    struct node* temp;
    int counter=0;
    temp = head;
    while(temp!=NULL)
    {

        temp = temp->next;
        counter++;
    }
    return counter ;

}
struct node *reverse(struct node* head1)
{
    struct node* current ,*next ,*prev;
    current = head1;
    next=NULL;
    prev= NULL ;
    while(current!=NULL)
    {
        next = current->next ;
        current->next = prev;
        prev= current;
        current = next ;
}
    return prev ;
}
bool compareLists(struct node* head1, struct node *head2)
{
    struct node* temp1 = head1;
    struct node* temp2 = head2;

    while (temp1 && temp2)
    {
        if (temp1->data == temp2->data)
        {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else return 0;
    }
    if (temp1 == NULL && temp2 == NULL)
        return 1;
    return 0;
}
bool palindrome(struct node* head)
{
    int len =length(head);
    int mid ;
    if (len%2==0)
        mid = len/2 ;
    else
        mid = len/2+1 ;
   //printf("len%d mid%d ",len,mid);
    struct node *temp = head ;
    int i = 0 ;
    for(i=0;i<mid-1;i++)
    {
        temp = temp->next;

    }
   //printf("\n hi%d",temp->data);
    struct node *temp2_rev;
    temp2_rev = reverse(temp->next);
    temp->next = NULL;
    //printf("\n rev %d",temp2_rev->data);
    //printlist(temp2_rev);
    temp = head;
   // printlist(head);
    struct node *temp2 = temp2_rev;
    int j = 0;
    if(compareLists(temp,temp2))
    {
    temp2_rev=reverse(temp2_rev);
    //temp->next = temp2_rev;
    //printlist(temp2_rev);
    //printlist(head);
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next = temp2_rev;
    printlist(head);
    return true;
    }
    else
    {
         while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next = temp2_rev;
    printlist(head);
    return false;
    }

}
void insert(struct node** head,int data)
{
        struct node* fresh =newnode(data);
    if (*head==NULL)
        {
        *head= fresh;
        return;
    }

    struct node* temp = *head ;
    while(temp->next!=NULL)
    {
        temp= temp->next;

    }
    temp->next = fresh;
    return;
}




struct node* merge(struct node* head1 , struct noode* head2)
{
    int len1, len2 ,difference ,i;
    len1  =length(head1);
    len2 = length(head2);
    struct node* temp1 ,*temp2 ;
    if(len1>=len2)
    {
        difference = len1-len2;
        temp1= head1;
        for(i=0;i<difference;i++)
        {
           temp1 = temp1->next;
        }
        temp2= head2;
        while(temp1!=temp2)
        {

            temp1= temp1->next;
            temp2=temp2->next;
        }
        return temp1;
    }
    else
    {
        difference = len2-len1;
        temp2= head2;
        for(i=0;i<difference;i++)
        {
           temp2 = temp2->next;
        }
        temp1= head1;
        while(temp1!=temp2)
        {

            temp1 = temp1->next;
            temp2=temp2->next;
        }
        return temp1;
    }
}

int main()
{
   /* struct node *head1 ,*head2 ;
    head1= NULL ;
    head2=NULL ; */
    struct node* newNode;
  struct node* head1 =
            (struct node*) malloc(sizeof(struct node));
  head1->data  = 10;

  struct node* head2 =
            (struct node*) malloc(sizeof(struct node));
  head2->data  = 3;

  newNode = (struct node*) malloc (sizeof(struct node));
  newNode->data = 6;
  head2->next = newNode;

  newNode = (struct node*) malloc (sizeof(struct node));
  newNode->data = 9;
  head2->next->next = newNode;

  newNode = (struct node*) malloc (sizeof(struct node));
  newNode->data = 15;
  head1->next = newNode;
  head2->next->next->next  = newNode;

  newNode = (struct node*) malloc (sizeof(struct node));
  newNode->data = 30;
  head1->next->next= newNode;

  head1->next->next->next = NULL;

  //printf("\n The node of intersection is %d \n",merge(head1, head2)->data);
   printlist(head1);
  head1 = reverse(head1);
  printlist(head1);
  head1= reverse(head1);
  printlist(head1);
  struct node* head3 =NULL;
  insert(&head3,1);
  insert(&head3,2);
  insert(&head3,3);
  insert(&head3,3);
  insert(&head3,2);
  insert(&head3,1);
  printlist(head3);
  if(palindrome(head3)==1)
    printf("List 3 is palindrome");


  getchar();
  return 0;
}
