class Solution {
public:

    void join(vector<int> &group , int num1 ,int num2)
    {
        int grp = group[num1];
        for(int i = 0 ; i < group.size(); i++)
        {
            if(group[i]==grp)
            {
                group[i] = group[num2];
            }
        }
    }

    int find(vector<int> &grp, int num)
    {
        return grp[num];
    }

    int minSwapsCouples(vector<int>& row)
    {
        int m = row.size();
        int n = m/2;
        vector<int> grp(m);
        for(int i = 0 ; i < n ; i++)
        {
            grp[2*i] = i;
            grp[2*i + 1] = i;
        }

        int ans = 0;

        for(int i = 0 ; i < n ; i++)
        {
            int a = find(grp,row[2*i]);
            int b = find(grp,row[2*i+1]);
            if(a!=b)
            {
                ans++;
                join(grp,row[2*i],row[2*i+1]);
            }
        }
        return ans;
    }
};
