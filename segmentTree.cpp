#include<bits/stdc++.h>
using namespace std;

int build(int data[],int segment_array[],int left, int right, int index)
{
  if(left==right)
  {
    segment_array[index]=data[left];
  }
  else
  {
    int mid = (left+right)/2;
    int x = build(data,segment_array,left,mid,2*index+1);
    int y = build(data,segment_array,mid+1,right,2*index+2);
    segment_array[index]=min(x,y);
  }
  return segment_array[index];
}

int perform_query(int segment_array[],int left,int right,int start, int end, int index)
{
  if(right<start || left>end)
  {
    //cout<<right<<" "<<start<<" "<<left<<" "<<end;
    return INT_MAX;
  }
  else if(left<=start && right>=end)
  {
    return segment_array[index];
  }
  else
  {
    int mid=(start+end)/2;
    int x = perform_query(segment_array,left,right,start,mid,2*index+1);
    //cout<<" x is "<<x<<endl;
    int y = perform_query(segment_array,left,right,mid+1,end,2*index+2);
    return min(x,y);
  }
}

// If ever get any doubt in update refer geeks for geeks;
int update(int segment_array[],int left, int right, int index,int diff,int seg_index)
{
    if(index<left || index>right)
    {
      return segment_array[seg_index];
    }
    if(left==right)
    {
        segment_array[seg_index]=diff;
        return segment_array[seg_index];
    }
    else
    {
      int mid = (left+right)/2;
      int x = update(segment_array,left,mid,index,diff,2*seg_index+1);
      int y = update(segment_array,mid+1,right,index,diff,2*seg_index+2);
      segment_array[seg_index]=min(x,y);
      return segment_array[seg_index];
    }

}

int main()
{
  int n,q,l,r,diff,seg_size;
  char p;
  cin>>n>>q;
  int data[n];
  for(int i=0;i<n;i++)
  {
    cin>>data[i];
  }
  seg_size=pow(2,ceil(log2(n)))*2-1;
  int segment_array[seg_size]={INT_MAX};
  for(int i=0;i<seg_size;i++)
  {
    cout<<segment_array[i]<<endl;
  }

  int x = build(data,segment_array,0,n-1,0);

  cout<<endl;

  for(int i =0;i<q;i++)
  {
    cin>>p>>l>>r;
    if(p=='q')
    {
      cout<<perform_query(segment_array,l-1,r-1,0,n-1,0)<<endl;
    }
    else
    {
        int x = update(segment_array,0,n-1,l-1,r,0);
    }
  }
  return 0;
}
