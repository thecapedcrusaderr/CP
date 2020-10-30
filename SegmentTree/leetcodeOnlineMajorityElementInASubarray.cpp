class MajorityChecker {
public:
    unordered_map<int, vector<int>> mapp;
    vector<int> nums;
    int seg_size;
    int n ;
    vector<int> seg_tree;


    int countOccurence(int num, int left, int right)
    {
        if(mapp.count(num)==0)return 0;
        vector<int> &here = mapp[num];

        auto lb = lower_bound(here.begin(), here.end(), left);
        if(lb==here.end())return 0;
        auto rb = upper_bound(here.begin(), here.end(), right);
        return rb-lb;
    }

    pair<int,int> perform_query(int left, int right, int start, int end, int index)
    {
        if(left > end || right < start)return {-1,-1};
        // cout<<" left is "<<left<<" and right is "<<right<<" and start is "<<start<<" and end is "<<end<<endl;

        if(left <= start && right >= end)
        {
            if(seg_tree[index]==-1)return {-1,-1};
            int count = countOccurence(seg_tree[index], left, right);
            // cout<<" count kya hai bhai "<<count<<endl;
            if(2 * count > right - left + 1)
            {
                // cout<<" ha bhai ise to aaoge is "<<endl;
                // cout<<" first return is "<<seg_tree[index]<<" and its count is "<<count<<endl;
                return {seg_tree[index], count};
            }
            else
            {
                return {-1,-1};
            }
        }
        int mid = start + (end-start)/2;
        int a = 2*index + 1;
        int b = 2*index + 2;
        // cout<<" a is "<<a<<" and b is "<<b<<endl;
        pair<int,int> l = perform_query(left, right, start, mid, a);
        pair<int,int> r = perform_query(left, right, mid+1, end, b);
        // cout<<"l.first is "<<l.first<<endl;
        if(l.first!=-1)return {l.first, l.second};
        // cout<<"r.first is "<<r.first<<endl;
        if(r.first != -1)return {r.first, r.second};
        return {-1,-1};
    }


    void buildTree(int left, int right, int segIndex)
    {
        if(left==right)
        {
            seg_tree[segIndex] = nums[left];
            return;
        }
        int mid = left + (right - left)/2;

        int lIndex = 2*segIndex + 1, rIndex = 2*segIndex +2;

        buildTree(left, mid, lIndex);
        buildTree(mid+1, right, rIndex);

        int num1 = seg_tree[lIndex];
        if(num1!=-1 && countOccurence(num1, left, right) * 2 >  (right-left+1))
        {
            seg_tree[segIndex] = seg_tree[lIndex];
        }

        int num2 = seg_tree[rIndex];
        if(num2!=-1 && countOccurence(num2, left, right) * 2 > (right-left+1))
        {
            seg_tree[segIndex] = seg_tree[rIndex];
        }
    }


    MajorityChecker(vector<int>& arr)
    {
        for(int i = 0 ; i < arr.size(); i++)
        {
            mapp[arr[i]].push_back(i);
            nums.push_back(arr[i]);
        }
        n = arr.size();
        seg_size = 2 * pow(2,ceil(log2(n))) - 1;
        // cout<<"seg_size is "<<seg_size<<endl;
        seg_tree.resize(seg_size,-1);
        buildTree(0, n-1, 0);

    }

    int query(int left, int right, int threshold)
    {
        // cout<<" first call hai "<<endl;
        pair<int, int> temp = perform_query(left, right, 0, n-1, 0);
        // cout<<" pehla hai "<<temp.first<<endl;
        // cout<<" dusra hai "<<temp.second<<endl;
        if(temp.second >= threshold) return temp.first;
        return -1;
    }
};
