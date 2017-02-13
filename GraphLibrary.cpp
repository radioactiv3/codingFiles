#include<stdlib.h>
#include<iostream>
#include<list>
#include <queue>

using namespace std;
class graph{
    int v ;
    list<int> *adj ;
    //void bfs_util(int a, bool visited[]);
public:
    graph(int v);
    void add_edge(int v, int w);
    void bfs(int a);

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

    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.bfs(2);
    }
