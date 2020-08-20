// I will do it with the help of bitMasking, backtracking se krna koi badi thodi hai.

class Solution {
public:

    vector<int> calculate(string &str)
    {
        vector<int> arr(26,0);
        for(int i = 0 ; i < str.size(); i++)
        {
            arr[str[i]-'a']+=1;
        }
        return arr;
    }

    bool isValid(vector<int> &cal, vector<int> &orig)
    {
        for(int i = 0 ; i < 26 ; i++)
        {
            if(cal[i]!=0 && cal[i] > orig[i])
            {
                return false;
            }
        }
        return true;
    }

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score)
    {
        vector<int> count(26,0);
        for(int i = 0 ; i < letters.size(); i++)
        {
            count[letters[i]-'a']+=1;
        }

        int n = words.size();

        vector<int> wordCount(n,0);

        for(int i = 0 ; i < n ; i++)
        {
            int m = words[i].size();
            int here = 0;
            for(int j = 0; j < m ; j++)
            {
                here += score[words[i][j]-'a'];
            }
            wordCount[i] = here;
        }

        int ans = 0;

        for(int i = 1 ; i < (1<<n); i++)
        {
            string str = "";
            int yahan = 0;

            for(int j = 0 ; j < n ; j++)
            {
                if(i & 1<<j)
                {
                    str += words[j];
                    yahan += wordCount[j];
                }
            }
            vector<int> arr = calculate(str);
            if(isValid(arr,count))
            {
                ans = max(ans, yahan);
            }
        }
        return ans;
    }
};
