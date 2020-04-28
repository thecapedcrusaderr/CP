/* C++ program for DFS */
#include<bits/stdc++.h>
using namespace std;

int c = 0;
int start[50000] = {0};
int finish[50000] = {0};

void addEdge(vector<int> adj[],int u,int v)
{
	adj[u].push_back(v);
}


/* void printGraph(vector<int> adj[], int V)
{
	for (int v = 0; v < V; ++v) 
    { 
        cout << "\n Adjacency list of vertex "
             << v << "\n head "; 
        for (auto x : adj[v]) 
           cout << "-> " << x; 
        printf("\n"); 
    } 	
} */

void DFS(vector<int> adj[], int origin,int start[],int finish[], int c1,bool visited[])
{
   
   visited[origin] = true;
   c=c1+1;
   start[origin] = c;
   for(auto x : adj[origin])
   {
     if(visited[x] == false)
     DFS(adj,x,start,finish, c, visited);
   } 
   c++;
   finish[origin] = c;

}



int main()
{	
	int a,b,m,V;
	int init;
	cout<<"enter number of vertices";
	cin>>V;
	bool visited[V+1] = {true};
	vector<int> adj[V+1];
	cout<<"enter the number of edges of the graph";
	cin>>m;

	cout<<"Enter the edges of the graph"; /* Will add weight of the edges later.*/
	for(int i = 0; i < m ; i++)
	{
		cin>>a>>b;
		addEdge(adj, a, b);	
	}
       cout<<"Enter the vertex from which you want to start DFS from";
       cin>>init;
       DFS(adj,init, start, finish, c, visited);
       for(int i = 1; i<V ; i++)
       {
	if(visited[i] == false)
        DFS(adj,i, start, finish, c, visited); 
       }

     for(int i = 1; i < V+1; i++)
     {
	cout<<"The time at which vertex"<<i<<"was visited:"<<start[i]<<endl;
     }
       
return 0;
}
