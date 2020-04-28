/* DFS program to find number of connected components */

#include<bits/stdc++.h>
#include<algorithm> /* For using the function std::remove */
using namespace std;

int c = 0;
int indegree[50000] = {0};



void addEdge(vector<int> adj[],int u,int v)
{
	adj[u].push_back(v);
        indegree[v]++;
	      
}

void partition(vector<int> adj[], bool visited[], int V, vector<int> part[])
{

  bool flag = false;


  for(int i=1; i<V+1; i++)
  {
	if((visited[i]==false) && (indegree[i]==0))
        {
         flag = true;
         part[c].push_back(i);
        }
  }
 
  if(c>=V)
	return;
  for(auto i: part[c])
  {
           for(auto x : adj[i])
           {
		indegree[x]--;
	   } 
	   visited[i]=true;
  }
  c++;

  if(flag)
  partition(adj, visited, V, part);
}
 

int main()
{	
	int a,b,m,V;
	int init;
	cout<<"enter number of vertices";
	cin>>V;
	bool visited[V+1] = {false};
	vector<int> adj[V+1];
	cout<<"enter the number of edges of the graph";
	cin>>m;
        vector<int> part[V];


	cout<<"Enter the edges of the graph"; /* Will add weight of the edges later.*/
	for(int i = 0; i < m ; i++)
	{
		cin>>a>>b;
		addEdge(adj, a, b);	
	}
 	
        partition(adj, visited, V, part);


        for(int i=0; i<V; i++)
        {
          if(part[i].size() == 0)
          break;
          else
          {
	    for(auto x : part[i])
           {
                
 		cout<<x<<" ";
           } 
          }
          cout<<endl;
        }
     
return 0;
}
