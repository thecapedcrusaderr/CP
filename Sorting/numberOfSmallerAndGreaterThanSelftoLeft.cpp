#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> small, large;

void merge(vector<pair<int,int>> &arr, int left, int mid, int right)
{
    vector<pair<int,int>> temp(right-left+1);
    int i = mid, j = right, k = 0;
    while(i >= left && j > mid)
    {
        if(arr[j].first > arr[i].first)
        {
            small[arr[j].second]+=(i-left+1);
            j--;
        }
        else
        {
            i--;
        }
    }
    i = left, j = mid+1;
    while(i <= mid && j <= right)
    {
      if(arr[i].first > arr[j].first)
      {
          large[arr[j].second]+=(mid-i+1);
          temp[k++] = arr[j++];
      }
      else
      {
          temp[k++] = arr[i++];
      }
    }
    while(i <= mid)
    {
      temp[k++] = arr[i++];
    }
    while(j <= right)
    {
      temp[k++] = arr[j++];
    }
    for(int k = 0 ; k <= right-left ; k++)
    {
        arr[k+left] = temp[k];
    }
}

void mergeSort(vector<pair<int,int>> &arr, int left, int right)
{
    if(left>=right)return ;
    int mid = left + (right-low)/2;
    merge(arr, left, mid);
    merge(arr, right+1, high);
    mergeSort(arr, left, mid, right);
}

int result(vector<int> &nums)
{
    n = arr.size();
    small.resize(n,0);
    large.resize(n,0);

    vector<pair<int,int>> arr;

    for(int i = 0 ; i < n ; i++)
    {
      arr.push_back({nums[i],i});
    }

    int ans = 0;

    for(int i = 0 ;i < n ;i++)
    {
        ans = ans + 2 * min(small[i],large[i]) + 1;
    }
    return ans;
}
