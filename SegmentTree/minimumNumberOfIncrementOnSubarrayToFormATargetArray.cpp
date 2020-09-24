// Isko segment tree se krte hai
// Mtlb build to sahi se hora hai, ab aage debug krte hai;

class Solution {
public:
    int ans = 0;
    vector<int> arr;
    vector<int> segmentArray;

    int buildTree(int left, int right, int segIndex)
    {

        if(left == right)
        {
            segmentArray[segIndex] = left;
            // cout<<" left is "<<left<<" and right is "<<right<<" with value "<<segmentArray[segIndex]<<endl;
            return left;
        }

        int mid = left + (right - left)/2;

        int l = buildTree(left, mid, 2*segIndex + 1);
        int r = buildTree(mid+1, right,  2*segIndex + 2);

        if(arr[l] <= arr[r])
        {
            segmentArray[segIndex] = l;
        }
        else
        {
            segmentArray[segIndex] = r;
        }
        // cout<<" left is "<<left<<" and right is "<<right<<" with value "<<segmentArray[segIndex]<<endl;
        return segmentArray[segIndex];
    }

    int perform_query(int left, int right , int start, int end, int segIndex)
    {
        if(left > end || right < start)return INT_MAX;

        if(left <= start && right >= end)return segmentArray[segIndex];

        int mid = start + (end - start)/2;

        int l = perform_query(left, right, start, mid, 2*segIndex + 1);
        int r = perform_query(left, right, mid+1, end , 2*segIndex + 2);

        if(l == INT_MAX)return r;
        if(r == INT_MAX)return l;
        if(arr[l] <= arr[r])return l;
        else return r;
    }

    void solve(int left, int right, int start, int end, int diff)
    {
        int here  = perform_query(left, right, start, end, 0);

        // cout<<" left is "<<left<<" and right is "<<right<<" and min Index is "<<here<<" with diff as "<<diff<<endl;

        ans += (arr[here]-diff);

        // cout<<" answer for left = "<<left<<" and right = "<<right<<" is "<<ans<<endl;

        int k = arr[here]+diff;

        if(here -1 >= left)solve(left, here-1, start, end, arr[here]);
        if(here +1 <= right)solve(here+1, right, start, end, arr[here]);
    }


    int minNumberOperations(vector<int>& target)
    {
        int n = target.size();
        arr = target;
        int seg_size = pow(2, ceil(log2(n))) * 2 - 1;
        segmentArray.resize(seg_size, INT_MAX);
        int k = buildTree(0, n-1, 0);
        solve(0, n-1, 0, n-1, 0);
        return ans;
    }
};
