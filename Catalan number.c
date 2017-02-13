
#include<stdio.h>
#include<stdlib.h>

unsigned long int catalan (int n){

    int i = 0 ;
    unsigned long int arr[n+1] ;
    arr[0]=1;
    arr[1] = 1;
    for(i=2;i<=n;i++)
    {
        int  j = 0 ;
       arr[i]= 0;
       for(j=0;j<i;j++)
            arr[i]+=arr[j]*arr[i-j-1];

    }
    return arr[n];
}

int main()
{

    int n ;
    scanf("%d",&n);
    printf("%d",catalan((n)));
    return 0 ;
}
