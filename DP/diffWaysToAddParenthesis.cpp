class Solution {
public:

    vector<int> support(unordered_map<string, vector<int>> &mapp, string s)
    {
        vector<int> result;
        int n = s.size();

        for(int i = 0 ; i < n ; i++)
        {
            if(s[i] == '*' || s[i] == '+' || s[i] == '-')
            {
                string left  = s.substr(0,i);
                string right = s.substr(i+1);

                vector<int> l;
                vector<int> r;

                if(mapp.find(left) != mapp.end())
                {
                    l = mapp[left];
                }
                else
                {
                    l = support(mapp, left);
                }

                if(mapp.find(right)!=mapp.end())
                {
                    r = mapp[right];
                }
                else
                {
                    r = support(mapp, right);
                }

                for(auto &ln : l)
                {
                    for(auto &rn : r)
                    {
                        if(s[i]=='*')
                        {
                            result.push_back(ln*rn);
                        }
                        else if(s[i]=='+')
                        {
                            result.push_back(ln + rn);
                        }
                        else
                        {
                            result.push_back(ln - rn);
                        }
                    }
                }
            }
        }
        if(result.size()==0)
        {
            result.push_back(atoi(s.c_str()));
        }
        mapp[s] = result;
        return result;
    }

    vector<int> diffWaysToCompute(string input)
    {
        unordered_map<string, vector<int>> mapp;
        vector<int> out = support(mapp, input);
        return out;
    }
};
