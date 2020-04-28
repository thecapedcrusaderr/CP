#include<bits/stdc++.h>
#define m 1000000007
using namespace std;

struct refer_structure
{
  long long nZ;
  long long nO;
};

void query(struct refer_structure** seg_tree,long long start, long long end, long long left, long long right, long long index,long long nZero[], long long nOnes[])
{
  if(right<start || left>end)
  {
    return;
  }
  else if(left<=start && right>=end)
  {
    for(long long i = 41; i>=0;i--)
    {
      nZero[i] += seg_tree[index][i].nZ;
      nOnes[i] += seg_tree[index][i].nO;
    }
  }
  else
  {
    long long mid = (start+end)/2;
    query(seg_tree,start,mid,left,right,2*index+1, nZero, nOnes);
    query(seg_tree,mid+1,end,left,right,2*index+2, nZero, nOnes);
  }
}

void build_tree(long long data[],struct refer_structure** seg_tree,long long left,long long right,long long index)
{
  //cout << left << " hello " << right << endl;
  if(left==right)
  {
    for(long long i = 41;i>=0;i--)
    {
      if(data[left]!=0)
      {
        if((data[left]%2)==0)
        {
          seg_tree[index][i].nZ=1;
          seg_tree[index][i].nO=0;
        }
        else
        {
          seg_tree[index][i].nZ=0;
          seg_tree[index][i].nO=1;
        }
        data[left]/=2;
      }
      else
      {
        seg_tree[index][i].nZ=1;
        seg_tree[index][i].nO=0;
      }
    }
  }
  else
  {
    long long mid = (left+right)/2;
    build_tree(data,seg_tree,left,mid,2*index+1);
    build_tree(data,seg_tree, mid+1,right,2*index+2);
    for(long long i = 41;i>=0;i--)
    {
      seg_tree[index][i].nZ=seg_tree[2*index+1][i].nZ+seg_tree[2*index+2][i].nZ;
      seg_tree[index][i].nO=seg_tree[2*index+1][i].nO+seg_tree[2*index+2][i].nO;
    }
  }
}

int main()
{
  freopen("input.txt", "r", stdin);
  //cout << long(pow(2,(41))+0.5);
  long long n,q,t,l,r;
  long long seg_size;
  cin>>n;

  // n's maximum value is 10^5 . So, it could be represented in 20 bits max
  long long data[n];
  for(long long i =0;i<n;i++)
  {
    cin>>data[i];
  }
  cin>>q>>t;
  seg_size = (pow(2,ceil(log2(n)))*2)-1;
  //cout << seg_size << endl;
  struct refer_structure** seg_tree = new refer_structure*[seg_size];
  for(long long i = 0; i < seg_size; i++)seg_tree[i] = new refer_structure[42];
  //cout << "hello" << endl;
  // struct refer_structure** seg_tree = new long long*[seg_size];
  // for(long long i = 0; i < seg_size; i++)seg_tree[i] = new long long[42];
  build_tree(data,seg_tree,0,n-1,0);
  // for(long long i =0;i<seg_size;i++)
  // {
  //   // cout<<endl;
  //   // for(long long j =41;j>=0;j--)
  //   // {
  //   //   cout<<seg_tree[i][j].nZ<<" "<<seg_tree[i][j].nO<<" "<<endl;
  //   // }
  //   // cout<<endl;
  // }
//cout << "hello" << endl;
  for(long long i = 0;i<1;i++)
  {
    cin>>l>>r;
    long long nZero[42]={0},nOnes[42]={0};
    query(seg_tree,0,n-1,l-1,r-1,0,nZero,nOnes);
    unsigned long long sum=0,ref = 0;
    //cout<<endl;
    // for(long long i=41;i>=0;i--)
    // {
    //   cout<<nZero[i]<<" "<<nOnes[i]<<endl;
    // }
    for(long long i = 41;i>=0;i--)
    {
          ref = 0;
          ref+=((((nZero[i]*(nZero[i]-1))/2)%m)*(nOnes[i]%m))%m;
          ref=ref%m+(((((nOnes[i]*(nOnes[i]-1)%m)%m)*(nOnes[i]-2))%m)/6)%m;
          sum=(sum+(ref%m * ((long long)(pow(2,(41-i))+0.5)%m))%m)%m;
          //cout << "l: " << l << " r: "<<  r << " bit_no: " << i << " zeroes: " << nZero[i] << " ones: " << nOnes[i] << " sum: " << sum << endl;
    }
    //cout<< l << " " << r << " " << sum<<endl;
  }
  return 0;
}
