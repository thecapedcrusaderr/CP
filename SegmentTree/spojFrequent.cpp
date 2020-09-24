#include<bits/stdc++.h>
using namespace std;

struct node
{
  long max,lEC,rEC;
};

struct node queries(int start, int end, int data[],int left, int right, node segTree[], int index)
{
  struct node refer;
  if(end<left || start>right)
  {
    refer.max=0;
    refer.lEC=0;
    refer.rEC=0;
  }
  else if(left<=start && right>=end)
  {
    refer.max=segTree[index].max;
    refer.lEC=segTree[index].lEC;
    refer.rEC=segTree[index].rEC;
  }
  else
  {
    int mid = (start+end)/2;
    node refer2 = queries(start,mid,data,left,right,segTree,2*index+1);
    node refer3 = queries(mid+1,end,data,left,right,segTree,2*index+2);
    if(data[mid]==data[mid+1])
    {
      refer.max=max((refer2.rEC+refer3.lEC),max(refer2.max,refer3.max));
      if(data[start]==data[mid])
      {
        refer.lEC=refer2.lEC+refer3.lEC;
      }
      else
      {
        refer.lEC=refer2.lEC;
      }

      if(data[mid+1]==data[end])
      {
        refer.rEC=refer2.rEC+refer3.rEC;
      }
      else
      {
        refer.rEC=refer3.rEC;
      }
    }
    else
    {
      refer.max=max(refer2.max,refer3.max);
      refer.lEC=refer2.lEC;
      refer.rEC=refer3.rEC;
    }

  }
  return refer;
}
void build_tree(int start , int end, int data[], node segTree[],int index)
{
  if(start==end)
  {
    segTree[index].max=1;
    segTree[index].lEC=1;
    segTree[index].rEC=1;
  }
  else
  {
    int mid = (start+end)/2;
    build_tree(start,mid,data,segTree,2*index+1);
    build_tree(mid+1,end,data,segTree,2*index+2);

    if(data[mid]==data[mid+1])
    {
      segTree[index].max=max((segTree[2*index+1].rEC+segTree[2*index+2].lEC),max(segTree[2*index+1].max,segTree[2*index+2].max));
      if(data[start]==data[mid])
      {
        segTree[index].lEC=segTree[2*index+1].lEC+segTree[2*index+2].lEC;
      }
      else
      {
        segTree[index].lEC=segTree[2*index+1].lEC;
      }

      if(data[mid+1]==data[end])
      {
        segTree[index].rEC=segTree[2*index+1].rEC+segTree[2*index+2].rEC;
      }
      else
      {
        segTree[index].rEC=segTree[2*index+2].rEC;
      }
    }
    else
    {
      segTree[index].max=max(segTree[2*index+1].max,segTree[2*index+2].max);
      segTree[index].lEC=segTree[2*index+1].lEC;
      segTree[index].rEC=segTree[2*index+2].rEC;
    }
  }
}

int main()
{
  while(1)
  {
    vector<int> out;
    int n,q,l,r;
    cin>>n;
    if(n==0)
    {
      break;
    }
    cin>>q;
    int data[n];
    for(int i=0;i<n;i++)
    {
      cin>>data[i];
    }
    node segTree[4*n];
    build_tree(0,n-1,data,segTree,0);

    while(q--)
    {
      cin>>l>>r;
      node output = queries(0,n-1,data,l-1,r-1,segTree,0);
      out.push_back(output.max);
    }
    for(int i =0;i<out.size();i++)
    {
      cout<<out[i]<<endl;
    }
  }
}
