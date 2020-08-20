// One of the thing i learnt from this question is how to generate different substrings from a bit string, like for size = n . There could be 2^n subsets which we could generate from this.

class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles)
    {
        unordered_map<int,int> mapp;

        for(auto &w : words)
        {
            int mask = 0;
            for(int i = 0 ; i < w.size(); i++)
            {
                mask |= 1<<(w[i]-'a');
            }
            mapp[mask]+=1;
        }

        int n = puzzles.size();
        vector<int> out(n,0);

        int num = 0;
        for(auto &p : puzzles)
        {
            int mask = 0;
            for(int i =0 ; i < p.size(); i++)
            {
                mask |= 1 << (p[i]-'a');
            }

            int curr = 0;
            int cover = mask;

            int first = 1 << (p[0]-'a');

            while(true)
            {
                if( (cover&first)==first && mapp[cover])
                {
                    curr += mapp[cover];
                }
                if(cover==0)break;

                cover = (cover-1) & mask; // This is the main thing which i learnt today, how to generate different substrings.
            }
            out[num++]  = curr;

        }
        return out;

    }
};
