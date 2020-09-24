// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

void printInorder (struct Node* node)
{
    if (node == NULL)
    return;

    printInorder (node->left);
    printf("%d ", node->data);
    printInorder (node->right);
}

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
    return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));


            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    return root;
}


Node*  binaryTreeToBST (Node *root);

 // } Driver Code Ends


//User function template for C++

/* The Node structure is
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

void makeTree(Node* root, vector<int> &arr, int i, int j)
{
    if(!root || i > j)return;

    int l = 0, r = 0;
    if(root->left)l = root->left->data;
    if(root->right)r = root->right->data;

    int index = i+l;

    // cout<<" index is "<<index<<" for i = "<<i<<" and j = "<<j<<" with l as "<<l<<" and r as "<<r<<endl;
    root->data = arr[index];
    if(l!=0)makeTree(root->left, arr, i, index-1);
    if(r!=0)makeTree(root->right, arr, index+1, j);
}


int Traverse(Node *root, vector<int> &arr)
{
    if(!root)return 0;
    arr.push_back(root->data);
    int l = 0;
    int r = 0;
    if(root->left)l = Traverse(root->left, arr);
    if(root->right)r = Traverse(root->right, arr);
    // cout<<" root ka data initial "<<root->data<<endl;
    root->data = 1+l+r;
    // cout<<" root ka data after "<<root->data<<endl;
    return root->data;
}

Node *binaryTreeToBST (Node *root)
{
    vector<int> arr;
    int x = Traverse(root, arr);
    sort(arr.begin(),arr.end());
    int i = 0, j = arr.size()-1;
    // cout<<" array ka size hai "<<arr.size()<<endl;
    makeTree(root, arr, i , j);
    return root;
}

// { Driver Code Starts.


int main()
{
    int t;
    scanf("%d\n", &t);
    while (t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        Node *res = binaryTreeToBST (root);
        printInorder(res);
        cout<<endl;
    }
    return 0;
}
  // } Driver Code Ends
