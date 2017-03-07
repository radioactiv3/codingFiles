#include<stack>
#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

bool matchBraces(char a , char b)
{
        if (a==')'&& b=='(')
        return 1;
    else if (a=='}'&& b=='{')
        return 1;
    else if (a==']'&& b=='[')
        return 1;

return 0 ;
}

bool isbalanced(char *str)
{
    std::stack<char> st; // = new stack<char> ;
    int i = 0;
    //cout<<strlen(str);
    while(str[i]!='\0')
    {
        cout<<i<<endl;
        if (str[i]=='(' ||str[i]=='{'||str[i]=='[')
                {
                    st.push(str[i]);
                    i++ ;
                }
        else if(str[i]==')' ||str[i]=='}'||str[i]==']')
        {
            if(st.empty())
                return 0 ;
            else
                {
                    if(matchBraces(str[i],st.top())==1)
                    {
                        st.pop() ;
                        i++ ;
                        continue;
                    }

                    else
                        return 0;

        }
        }

    }
    if(str[i]=='\0'&& st.empty())
        return 1;
    else
    return 0 ;


}

int main()
{
    char *str = new char[100] ;
    cin >> str;
   if(isbalanced(str))
     cout<<"balanced";
   else
    cout<<"not balanced";
   return 0 ;
}
