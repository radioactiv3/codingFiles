#include<iostream>
#include<bits/stdc++.h>

using namespace std;
void lpscal(char* pat, int lps[],int m)
{
    int len = 0;
   int i = 0;
   lps[i] = 0;
   i = 1;
   while(i<m)
   {
       if(pat[i]==pat[len])
       {
           len++;
           lps[i] = len;
           i++ ;

       }
       else
       {
           if(len==0)
           {
               lps[i]= 0;
               i++;
           }

       else
        {
        len = lps[len-1];
       }

   }
return ;

}

}
void kmp(char pat[],char text[])
{

    int m ,n ;
    m = strlen(pat);
    n = strlen(text);
    //cout<< m << " " <<n <<endl;
    int lps [m];
    lpscal(pat,lps,m);

    int i = 0 ;

    int j =0 ;
    while(i<n)
    {
        if(pat[j]==text[i])
        {

            j++;
            i++;

        }
        if(j==m)
        {

            cout<< "Pattern found at " << i-j<<endl;
            j = lps[j-1];
        }

        else if(i<n&& pat[j]!=text[i])
            {
                if(j!=0)
            {
                j = lps[j-1];

            }
            else
                i++ ;


        }
    }


}

int main()
{

    char *pat= "is";
    char *text = "This is a string in which you have to find is";

    kmp(pat, text);
    return 0;

}
