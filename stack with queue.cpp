#include<iostream>
#include<queue>
#include<stdlib.h>

using namespace std;
void push(queue<int>Q1,queue<int>Q2,int num)
{
    Q1.push(num);

}
void pop(queue<int>Q1,queue<int>Q2){
    int temp ;
    if(Q2.empty())
    {
        while(!Q1.empty())
        {
            temp = Q1.front();
            Q2.push(temp);
            Q1.pop();

        }
    cout<<"popped element is "<<temp;
    }
    else
    {
          while(!Q2.empty())
        {
            temp = Q2.front();
            Q1.push(temp);
            Q2.pop();

        }
      cout<< "popped element is "<<temp;
    }

}
void top(queue<int>Q1,queue<int>Q2){
    int temp ;
    if(Q2.empty())
    {
        while(Q1.size()!=1)
        {
            temp = Q1.front();
            Q2.push(temp);
            Q1.pop();

        }
    cout<<"top element is "<<Q1.front();
    }
    else
    {
          while(Q2.size()!=1)
        {
            temp = Q2.front();
            Q1.push(temp);
            Q2.pop();

        }
      cout<< "popped element is "<<Q2.front();
    }

}
bool isEmpty(queue<int>Q1,queue<int>Q2){
}

void choose(int operation, queue<int>Q1, queue<int> Q2 )
{

   switch(operation)
   {
   case(1):
       {
           int a;
       cin>>a;
            push(Q1,Q2,a);
       }

   case(2):
    pop(Q1,Q2);
   case (3):
    top(Q1,Q2);
   case (4):
    top (Q1,Q2);
   }
}

int main()
{
    queue<int> Q1 ;
    queue<int> Q2;

    int num =0 ;
    while(num!=999)
    {


    cin>>num ;
    int operation ;
    cin >>operation;
     choose(operation,Q1,Q2);
    }



}
