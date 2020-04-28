#include<bits/stdc++.h>
using namespace std;

struct support
{
  int sum,suffixMax,prefixMax,Max;
};

support queries(int start, int end, int left, int right, struct support segmentTree[],int index)
{
  support infun;
  if(end<left || start>right)
  {
    infun.sum=0;
    infun.suffixMax=INT_MIN;
    infun.prefixMax=INT_MIN;
    infun.Max=INT_MIN;
  }
  else if(left<=start && right>=end)
  {
    infun.sum=segmentTree[index].sum;
    infun.suffixMax=segmentTree[index].suffixMax;
    infun.prefixMax=segmentTree[index].prefixMax;
    infun.Max=segmentTree[index].Max;
  }
  else
  {
    int mid = (start+end)/2;
    support ll = queries(start,mid,left,right,segmentTree,2*index+1);
    support rr = queries(mid+1,end,left,right,segmentTree,2*index+2);
    //cout<<"segmentTree "<<index<<" : "<<segmentTree[index].Max<<endl;
    infun.sum = ll.sum+rr.sum;
    if(ll.suffixMax==INT_MIN)infun.suffixMax=rr.suffixMax;
    else if(rr.suffixMax==INT_MIN)infun.suffixMax=ll.suffixMax;
    else infun.suffixMax = max((ll.suffixMax+rr.sum),rr.suffixMax);

    if(ll.prefixMax==INT_MIN)infun.prefixMax=rr.prefixMax;
    else if(rr.prefixMax==INT_MIN)infun.prefixMax=ll.prefixMax;
    else infun.prefixMax = max((rr.prefixMax+ll.sum),ll.prefixMax);

    if(ll.suffixMax==INT_MIN)infun.Max=rr.Max;
    else if(rr.prefixMax==INT_MIN)infun.Max=ll.Max;
    else
    {
      infun.Max = max(max(ll.Max,rr.Max),(ll.suffixMax+rr.prefixMax));
    }
  }
  return infun;
}

void build_tree(int start, int end, int data[], struct support segmentTree[], int index)
{
  if(start==end)
  {
    segmentTree[index].sum=data[start];
    segmentTree[index].suffixMax=data[start];
    segmentTree[index].prefixMax=data[start];
    segmentTree[index].Max=data[start];
  }
  else
  {
    int mid = (start+end)/2;
    build_tree(start,mid,data,segmentTree,2*index+1);
    build_tree(mid+1,end,data,segmentTree,2*index+2);
    segmentTree[index].sum = segmentTree[2*index+1].sum+segmentTree[2*index+2].sum;
    segmentTree[index].suffixMax=max((segmentTree[2*index+1].suffixMax+segmentTree[2*index+2].sum),segmentTree[2*index+2].suffixMax);
    segmentTree[index].prefixMax=max((segmentTree[2*index+1].sum+segmentTree[2*index+2].prefixMax),segmentTree[2*index+1].prefixMax);
    segmentTree[index].Max = max(max(segmentTree[2*index+1].Max,segmentTree[2*index+2].Max),(segmentTree[2*index+1].suffixMax+
    segmentTree[2*index+2].prefixMax));
  }
}
int main()
{
    int n,m,l,r;
    cin>>n;
    int data[n];
    for(int i=0;i<n;i++)
    {
      cin>>data[i];
    }
    //cout<<"hello"<<endl;
    support segmentTree[4*n];
    //cout<<"hey there"<<endl;
    build_tree(0,n-1,data,segmentTree,0);
    //cout<<"yahan be bakchodi"<<endl;
    cin>>m;
    while(m--)
    {
      cin>>l>>r;
      support refer = queries(0,n-1,l-1,r-1,segmentTree,0);
      cout<<refer.Max<<endl;
    }
  return 0;
}
