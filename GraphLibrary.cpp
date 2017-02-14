#include<stdlib.h>
#include<iostream>
#include<list>
#include <queue>
#include<stack>

using namespace std;
class graph{
    int v ;
    list<int> *adj ;
    //void bfs_util(int a, bool visited[]);
    bool dfs_util(int a,bool visited[]);
    bool topological_util(int a,bool visited[],stack<int>& st);

    bool cyclic_util(int a, bool visited[],bool rec[]);
public:
    graph(int v);
    void add_edge(int v, int w);
    void bfs(int a);
    void dfs(int a);
    void cyclic();
    void topological();

      };

      graph:: graph(int a)
      {

          this->v= a;
          adj = new list<int> [a];
      }
    void graph:: add_edge(int u , int w)
    {
        adj[u].push_back(w);

    }

bool graph:: cyclic_util(int a , bool visited[],bool rec[]){
    visited[a] = true;
    rec[a] = true;
    list<int>:: iterator i ;
    for(i= adj[a].begin();i!=adj[a].end();i++)
    {
       if(!visited[*i]&&cyclic_util(*i,visited,rec))
       {
           return true;
       }
        else if(rec[*i])
            return true;
    }
    rec[a] = false;
    return false;
}
void graph:: cyclic()
{

    bool* visited = new bool[v];
    bool* rec = new bool[v];
    for(int i = 0;i<v;i++)
    {

        visited[i]=false;
        rec[i]= false;
    }
    for(int i = 0;i<v;i++){


        if(cyclic_util(i,visited,rec)==true)
         cout<<"has a cycle" ;
         else
            cout<<"no cycle found" ;
    }

}
bool graph:: topological_util(int a, bool visited[],stack<int> &st)
{
    visited[a]=true;
    list<int>:: iterator i;
    for(i= adj[a].begin();i!=adj[a].end();i++)
    {
    if(!visited[*i])
     topological_util(*i,visited,st);
        }
    st.push(a);
}
void graph:: topological()
{

    stack<int> stack ;
    bool* visited =new bool[v];
    for(int i=0;i<v;i++)
        visited[i]= false;

    for(int i=0;i<v;i++)
    {
        if (visited[i]==false)
        topological_util(i,visited,stack);

    }
    while(!stack.empty())
    {
        int a = stack.top();
        cout <<a ;
        stack.pop();

    }
}
bool graph:: dfs_util(int a , bool visited[])
{
    visited[a] =true;
    list<int>::iterator i ;
    cout<<a;
    for( i =adj[a].begin();i!=adj[a].end();i++)
    {
        if(!visited[*i])
            dfs_util(*i,visited);

    }
    return false;

}
void graph:: dfs(int a)
{
    bool* visited = new bool[v];
    for(int i =0;i<v;i++)
        visited[i] = 0;

    visited[a]= true;
   // for(int i=0;i<v;i++)
        dfs_util( a, visited);
}

    void graph:: bfs(int a)
    {
        bool* visited = new bool[a];
        int j = 0 ;
        for (j=0;j<v;j++)
            visited[j] = false;

        list <int> q ;
        visited[a] = true;
        q.push_back(a);
        list<int>:: iterator i ;
        while(!q.empty())
        {
            int b ;
            b = q.front();
            cout<<b;
            q.pop_front();
            for(i=adj[b].begin();i!=adj[b].end();i++)
            {

                if(!visited[*i]){
                        visited[*i] =true;
                    q.push_back(*i);

            }
            }
        }

    }

    int main()
    {

         graph g(4);
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 2);
    g.add_edge(2, 0);
    g.add_edge(2, 3);
    g.add_edge(3, 3);
    g.topological();
     graph g2(4);
    g2.add_edge(0, 1);
     g2.add_edge(0, 2);
    g2.add_edge(1, 2);
     g2.add_edge(2, 0);
    g2.add_edge(2, 3);
    g2.add_edge(3, 3);
    //g2.cyclic();

   // cout << "Following is Breadth First Traversal "
        // << "(starting from vertex 2) \n";
    //g.bfs(2);
    }
