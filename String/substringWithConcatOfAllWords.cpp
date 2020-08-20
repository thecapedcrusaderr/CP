// Idk why there is more dislike than likes in this. It looks amazing to me.

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words)
    {
        unordered_map<string,int> freq;
        for(auto &w : words)
        {
            freq[w]++;
        }

        vector<int> out;
        int m = words.size();
        int n = s.size();
        if(n==0 || m==0)return out;
        int wl = words[0].size();

        int originalWordCount = words.size();

        for(int i = 0 ; i < wl ; i++)
        {
            int low = i;

            unordered_map<string,int> temp;
            int wordCount = 0;

            for(int j = i ; j < n ; )
            {
                string here = s.substr(j,wl);
                if(freq.find(here)==freq.end())
                {
                    temp.clear();
                    j+=wl;
                    low = j;
                    wordCount = 0;
                }
                else
                {
                    temp[here]++;
                    wordCount++;

                    for(auto it : freq)
                    {
                        string now = it.first;
                        int count = it.second;
                        bool kyaji = false;
                        if(temp[now] > freq[now])
                        {
                            while(s.substr(low,wl)!=now)
                            {
                                temp[s.substr(low,wl)]--;
                                low+=wl;
                                wordCount--;
                            }
                            temp[now]--;
                            wordCount--;
                            low+=wl;
                            kyaji = true;
                        }
                        if(kyaji)break;
                    }

                    if(wordCount==originalWordCount)
                    {
                        out.push_back(low);
                        temp[s.substr(low,wl)]--;
                        low+=wl;
                        wordCount--;
                    }
                    j+=wl;
                }
            }
        }
        return out;
    }
};
