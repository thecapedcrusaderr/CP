// Nice question isko samajhne me hi jamana lag gya
class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K)
    {
        int n = quality.size();
        vector<vector<double>> ratio;
        for(int i = 0 ; i < n ; i++)
        {
            double temp = double(wage[i]) / double(quality[i]);
            ratio.push_back({temp, double(quality[i])});
        }

        sort(ratio.begin(),ratio.end());
        priority_queue<double> pq;

        int qualitySum = 0;
        double ans = DBL_MAX;

        for(int i = 0 ; i < n ; i++)
        {
            pq.push(ratio[i][1]);
            qualitySum += ratio[i][1];

            if(i+1 >= K)
            {
                if((qualitySum * ratio[i][0])<ans)ans = qualitySum * ratio[i][0];
                qualitySum -= pq.top();
                pq.pop();
            }
        }

        return ans;

    }
};
