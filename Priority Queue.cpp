#include<iostream>
#include <stdlib.h>
using namespace std;

struct heap{
    int *array ;
    int capacity;
    int min_max_type;
    int count;
};

struct heap* createHeap(int capacity, int type)
{
  struct heap *newheap = (struct heap*)malloc(sizeof(struct heap));
  newheap->capacity = capacity;
  newheap->min_max_type = type;
  newheap->count = 0 ;
  newheap->array = (int*) malloc(sizeof(int)*newheap->capacity);
  return newheap ;
}
int leftChild(struct heap*root , int i )
{

    int left = 2*i+1;
    if(left<root->capacity)
        return left ;
    else
        return -1 ;
}

int rightChild(struct heap*root , int i )
{
    //cout<<root->capacity<<endl;

    int right = 2*i+2;
    if(right < root->capacity)
        return right ;
    else
        return -1 ;
}
int heapify(struct heap* root, int i )
{
cout<<"in heapify begin"<<root->array[5]<<endl;

  int left = leftChild(root,i);
  int right = rightChild(root,i);
  cout<< left <<endl<<right <<endl;
  int max =i ;
  if (left!=-1&& root->array[left]>root->array[max])
    max = left;
  if(right!=-1&&root->array[right]>root->array[max])
  max = right;
  if (max!=i)
  {
      int temp = root->array[i];
      root->array[i]= root->array[max];
      root->array[max] = temp;

  }
  if(left==right&&left==-1)
    return 0;
  else
  heapify(root,max);

cout<<"in heapify"<<root->array[5]<<endl;
   return 0 ;
}
int deleteMax(struct heap* heap)
{

    int data;
   data= heap->array[0] ;
   cout<<data;
   heap->array[0] = heap->array[heap->count-1];
   heap->count-- ;
   heapify(heap,0) ;
   return 0 ;
}

void resiz(struct heap* root)
{
   int *array_old = root->array;
    root->array = (int*)malloc(sizeof(int)*root->capacity*2);
    if(root->array==NULL)
    {
        cout<<"Memory Error" ;
        return ;

    }
    int i =0 ;
    for(i=0;i<root->count;i++)
        root->array[i]=array_old[i];
    root->capacity = 2*root->capacity;
    free(array_old);

}

struct heap* insert(struct heap*root, int data )
{
  if(root->count==root->capacity)
    resiz(root);
  int i = root->capacity-1 ;
while(i>=0&&data > root->array[(i-1)/2])
{
    root->array[i] = root->array[(i-1)/2];
    i = (i-1)/2;
}
root->array[i] = data;
return root;
}

void BuildHeap(struct heap *h, int arr[], int n)
{
    if(h==NULL)
    {
        cout<< "Memory error";
        return ;
    }

while(n>h->capacity)
    resiz(h);
for(int i=0;i<n;i++)
    h->array[i]= arr[i];
h->count = n;

for(int i= 0;i<n;i++)
    cout<<h->array[i]<<endl;

for(int i= (n-1)/2; i>=0;i--)
   heapify(h,i);
cout<<"after heapify"<<endl<<endl;
for(int i= 0;i<n;i++)
    cout<<h->array[i]<<endl;
return ;

}




int main()
{
struct heap *h =createHeap(10 ,2);
//h = createHeap(10 ,2);
cout<<h->capacity <<endl;
int arr[6]  = {1,2,3,4,5,6} ;
BuildHeap(h,arr,6);
//deleteMax(h);
//heapify(h,0);
for(int i=0;i<6;i++)
cout<<endl<<h->array[i]<<endl;

return 0 ;
}

