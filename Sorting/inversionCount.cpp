class Solution {
public:

    void merge(vector<pair<int,int>> &arr, vector<int> &count, int left, int mid, int right)
    {
        vector<pair<int,int>> temp(right-left+1);

        int n = arr.size();

        int i = left, j = mid+1, k = 0;

        while( i <= mid && j <= right)
        {
            if(arr[i].first > arr[j].first)
            {
                count[arr[i].second] += right - j + 1;
                temp[k] = arr[i];
                i++;
            }
            else
            {
                temp[k] = arr[j];
                j++;
            }
            k++;
        }
        while( i <= mid)
        {
            temp[k++] = arr[i++];
        }
        while(j <= right)
        {
            temp[k++] = arr[j++];
        }
        for(int i = 0 ; i<= right-left ; i++)
        {
            arr[i+left] = temp[i];
        }
    }

    void mergeSort(vector<pair<int,int>> &arr, vector<int> &count, int left, int right)
    {
        if(left >= right)return;

        int mid = left + (right-left)/2;
        mergeSort(arr, count, left, mid);
        mergeSort(arr, count, mid+1, right);
        merge(arr, count, left, mid, right);
    }

    vector<int> countSmaller(vector<int>& nums)
    {
        int n = nums.size();
        vector<pair<int,int>> arr;

        for(int i = 0 ; i < n ; i++)
        {
            arr.push_back({nums[i],i});
        }
        vector<int> count(n,0);
        mergeSort(arr, count, 0, n-1);
        return count;
    }
};
