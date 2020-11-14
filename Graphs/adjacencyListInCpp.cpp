// https://www.techiedelight.com/graph-implementation-c-without-using-stl/
// Refer the above site for all sort of implementation of graph without using stl

// Ab agar ye aagya hai to, i think adjacency list wali dikkat chali gayi
// So dijkstra me ye lag jaega

#include<iostream>
using namespace std;

struct Edge
{
    int src, dest, wgt;
}

struct Node
{
    int val;
    int weight;
    Node *next;
    Node(int data, int wt)
    {
        val = data;
        weight = wt;
        next = NULL;
    }
};

class Graph
{
    Node* insertAdjacencyList(int destination, int weight, Node *ref)
    {
        Node* nw = new Node(destination, weight);
        nw->next = ref;
        return nw;
    }
    int size;

  public:
    Node **head;
    Graph(Edge edges[], int n, int totalEdges)
    {
        this.size = n;
        head = new Node*[n]();
        for(int i = 0 ; i < n ;i++)
        {
            head[i] = NULL;
        }

        for(int i =0 ; i < totalEdges; i++)
        {
            int source = edges[i].src;
            int destination = edges[i].dest;
            int weight = edges[i].wgt;

            Node *here = insertAdjacencyList(destination, weight, head[source]);
            head[source] = here;
        }
    }
    ~Graph()
    {
        for(int i = 0 ; i < size ; i++)
        {
            delete[] head[i];
        }
        delete[] head;
    }
}

// print all neighboring vertices of given vertex
void printList(Node* ptr, int i)
{
	while (ptr != nullptr)
	{
		cout << "(" << i << ", " << ptr->val
			<< ", " << ptr->cost << ") ";

		ptr = ptr->next;
	}

	cout << endl;
}

int main()
{
	// array of graph edges as per above diagram.
	Edge edges[] =
	{
		// (x, y, w) -> edge from x to y having weight w
		{ 0, 1, 6 }, { 1, 2, 7 }, { 2, 0, 5 }, { 2, 1, 4 },
		{ 3, 2, 10 }, { 4, 5, 1 }, { 5, 4, 3 }
	};

	// Number of vertices in the graph
	int N = 6;

	// calculate number of edges
	int n = sizeof(edges)/sizeof(edges[0]);

	// construct graph
	Graph graph(edges, N, n);

	// print adjacency list representation of graph
	for (int i = 0; i < N; i++)
	{
		// print all neighboring vertices of vertex i
		printList(graph.head[i], i);
	}

	return 0;
}
