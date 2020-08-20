class Solution {
public:

    int findMedian(vector<int> &nums, int l, int size)
    {
      int number = min(5,size-l);
      sort(nums.begin()+l, nums.begin()+l+number);
      return nums[ l+number/2];
    }
    int kthSmallest(vector<int> &nums, int l, int r, int k)
    {
        if( k>0 && k<= r-l+1)
        {
          int n = r-l+1;
          vector<int> median;
          int ms = 0;
          for(int i = l ; i < r+1 ; i+=5)
          {
            int med = findMedian(nums,i,r+1);
            median.push_back(med);
            ms++;
          }
          int medOfMed = ms==1 ? median[ms/2] : kthSmallest(median, 0, ms-1 , ms/2);
          int pos = partition(nums, l, r, medOfMed);
          cout<<"pos we got is "<<pos<<endl;
          cout<<"pos - l is "<<pos-l<<"  and k-1 is "<<k-1<<endl;
          if(pos-l == k-1)
          {
            return nums[pos];
          }
          if(pos-l > k-1)
          {
              return kthSmallest(nums,l,pos-1, k);
          }
          return kthSmallest(nums,pos+1, r, k+l-1-pos);
        }
        return INT_MAX;
    }

     int partition(vector<int> &nums, int l, int r, int x)
    {
       int s = l;
       for(; s<r; s++)
       {
         if(nums[s]==x)break;
       }
       swap(nums[r], nums[s]);
       int i = l;
       for(int t = l; t<r ;t++)
       {
         if(nums[t] <= x)
         {
           swap(nums[t],nums[i]);
           ++i;
         }
       }
       swap(nums[i], nums[r]);
       return i;
    }
    int findKthLargest(vector<int>& nums, int k)
    {
        int n = nums.size();
        return kthSmallest(nums,0,n-1,n-k+1);
    }
};
