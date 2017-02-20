#include <stdlib.h>
#include <iostream>
#include <limits.h>
 
using namespace std; 
#define V 9
 
int mindistance(bool set[],int dist[]){
	int i =0 ,v ; 
	int min =INT_MAX; 
	for (i=0;i<V;i++)
	{
		if(!set[i]&& dist[i]<=min){
 
 
			min = dist[i] ;
			v = i;
		}
	}
	return v; 
}
void print_dist(int dist[])
{
	for (int i =0;i<V;i++)
		 cout<< dist[i]<<endl; 
}
void dijkstra(int graph[V][V], int s)
{
bool set[V]; 	
int dist[V] ;
for(int i =0; i<V;i++)
{
	dist[i] = INT_MAX;
	set[i] = false; 
}
dist[s] =0 ; 

for(int count=0;count<V-1;count++)
{
	int u = mindistance(set,dist);
	set[u]= true;
for (int j =0;j<V;j++)
 
{
	if(!set[j]&&graph[u][j]!=0&&dist[j]>=dist[u]+graph[u][j]&&dist[u]!=INT_MAX)
		dist[j] = dist[u]+graph[u][j];
 

}
}
print_dist(dist);
}
 
int main()
{
 
	int graph[V][V] = {
					  {0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 14, 10, 0, 2, 0, 0},
                      {0, 0, 0, 0, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };
 
   // dijkstra(graph, 0);
	dijkstra(graph,0);
	return 0 ;
}