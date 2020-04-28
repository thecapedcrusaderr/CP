#include<bits/stdc++.h>
using namespace std;

int find_Position(vector<int> arr, int number)
{
  int i, n = arr.size();
  for(i =0;i<n;i++)
  {
    if(arr[i]==number)break;
  }
  return i;
}

void partition(vector<int> &data ,int pivot, int low ,int high)
{
  int index = find_Position(data,pivot);
  // cout<<"index is "<<index<<endl;
  int temp = data[index];
  data[index] =  data[low];
  data[low] = temp;
  int temp2 = low;
  low+=1;
  int n = data.size();
  while(low<high)
  {
    if(data[low]<pivot && data[high]>pivot)
    {
      low++;
      high--;
    }
    else if(data[low]<pivot && data[high]<pivot)
    {
      low++;
    }
    else if(data[low]>pivot && data[high]>pivot)
    {
      high--;
    }
    else
    {
      int temp=data[low];
      data[low]=data[high];
      data[high]=temp;
      low++;
      high--;
    }
  }
  // cout<<"print checking "<< endl;
  // for(int i =0;i<data.size();i++)
  // {
  //   cout<<data[i]<<" ";
  // }
  // cout<<endl;
  int temp3=data[temp2];
  data[temp2]=data[high];
  data[high]=temp3;
  // cout<<"--------------------------------------------------------"<<endl;
  // for(int i =0;i<data.size();i++)
  // {
  //   cout<<data[i]<<" ";
  // }
  // cout<<endl;

}

int medianOfMedian(vector<int> arr, int low, int high)
{
  vector<int> medians;
  for (int i=low;i<=high;i+=5)
  {
    vector<int> temp;
    for(int j=i; j<i+5 && j<=high ;j++)
    {
      temp.push_back(arr[j]);
    }
    sort(temp.begin(),temp.end());
    int len = temp.size();
    medians.push_back(temp[len/2]);
  }
  int medianLength = medians.size();
  sort(medians.begin(),medians.end());
  return medians[medianLength/2];
}

int main()
{
  int n;
  cin>>n;
  vector<int> data(n);
  for (int i=0;i<n;i++)
  {
    cin>>data[i];
  }
  int pivot = medianOfMedian(data,0,n-1);
  // cout<<"pivot we got is "<<pivot<<endl;
  int low=0,high=n-1;
  partition(data,pivot,low,high);
  // for(int i =0;i<data.size();i++)
  // {
  //   cout<<data[i]<<" ";
  // }
  // cout<<endl;
  int pivotPosition = find_Position(data,pivot);
  // cout<<pivotPosition<<endl;
    // cout<<"yahan aaya kya"<<endl;
  while(pivotPosition!=n/2)
  {
      if(pivotPosition > (n/2))
      {
        high=pivotPosition-1;
        pivot = medianOfMedian(data,low,high);
        // cout<<"pivot here in the loop is "<<pivot<<endl;
        partition(data,pivot,low,high);
        pivotPosition = find_Position(data,pivot);
      }
      else
      {
        low = pivotPosition+1;
        pivot = medianOfMedian(data,low,high);
        partition(data,pivot,low,high);
        pivotPosition = find_Position(data,pivot);
      }
  }
  if(n%2==0)
  {
    cout<<"The median of the array is "<<(data[n/2]+data[n/2-1])/2.0<<endl;
  }
  else
  {
    cout<<"The median of the array is "<<data[n/2]<<endl;
  }
}
