class NumArray {
public:
    int n , seg_size;
    vector<int> arr;
    vector<int> segment_array;


    int perform_query(vector<int> &segment_array, int left, int right , int start , int end, int index)
    {
        if(left > end || right < start)return 0;

        if(left<=start && right>=end)
        {
          return segment_array[index];
        }

        int mid = (start+end)/2;
        int x = perform_query(segment_array,left,right,start,mid,2*index+1);
        int y = perform_query(segment_array,left,right,mid+1,end,2*index+2);
        return x+y;
    }

    void updateTree(vector<int> &segment_array, int left, int right, int index, int seg_index, int diff)
    {
        if(index < left || index > right)return ;

        segment_array[seg_index] += diff;
        // cout<<" for left = "<<left<<" and right = "<<right<<" updated value is "<<segment_array[seg_index]<<endl;

        if(left != right)
        {
            int mid = left + (right-left)/2;
            updateTree(segment_array, left, mid, index , 2*seg_index + 1, diff);
            updateTree(segment_array,mid+1, right, index, 2*seg_index + 2, diff);
        }
    }

    int build(vector<int> &nums, vector<int> &segment_array, int left, int right, int index)
    {
        if(left==right)
        {
            // cout<<" left and right same with left as "<<left<<" with value "<<nums[left]<<endl;
            segment_array[index] = nums[left];
        }
        else
        {
            int mid = left + (right - left)/2;
            int l = build(nums, segment_array, left, mid, 2*index+1);
            int r = build(nums, segment_array, mid+1, right, 2*index + 2);
            // cout<<" left and right with left as "<<left<<" and right as "<<right<<" with sum as "<<l+r<<endl;
            segment_array[index] = l+r;
        }
        return segment_array[index];
    }

    NumArray(vector<int>& nums)
    {
        n = nums.size();
        if(n==0)return;
        arr = nums;
        seg_size = pow(2 , ceil(log2(n))) * 2 - 1;
        segment_array.resize(seg_size, 0);
        for(int i = 0 ; i < seg_size; i++)segment_array[i] = 0;
        int x = build(nums, segment_array, 0, n-1, 0);
        // cout<<" total sum aaya "<<x<<endl;
    }

    void update(int i, int val)
    {
        if(n==0)return ;
        int diff = val - arr[i];
        arr[i] = val;
        // cout<<"*************************************************"<<endl;
        updateTree(segment_array, 0, n-1, i, 0, diff);
        // cout<<endl;
    }

    int sumRange(int i, int j)
    {
        if(n==0)return 0;
        int ans =  perform_query(segment_array, i, j , 0, n-1,0);
        // cout<<" ans we got for this query is "<<ans<<endl;
        return ans;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
