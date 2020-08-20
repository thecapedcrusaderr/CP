class Solution {
public:

    // This is the function that would be used for splitting a string around a character in c++. Unlike python we don't have        any existing libaray for the same.
    vector<string> split(string strToSplit, char c)
    {
        stringstream ss(strToSplit);
        string word;
        vector<string> out;
        while(getline(ss,word,c))
        {
            out.push_back(word);
        }
        return out;
    }

    string validIPAddress(string IP)
    {
         vector<string> splitted = split(IP,'.');
         if(splitted.size()==4)
         {
             int cnt = count(IP.begin(),IP.end(),'.');
             if(cnt > 3)
             {
                 return "Neither";
             }
             for(string word : splitted)
             {
                if(word.size() > 4 || word.size()<1 || (word.size()>1 && word[0]=='0'))
                {
                    return "Neither";
                }
                for(char c: word)
                {
                    if(!isdigit(c))
                    {
                        return "Neither";
                    }
                }
                if(stoi(word) > 255)
                {
                    return "Neither";
                }
             }
             return "IPv4";
         }
         else
         {
             vector<string> sp = split(IP,':');
             if(sp.size()==8)
             {
                 int cnt = count(IP.begin(),IP.end(),':');
                 if(cnt > 7)
                 {
                     return "Neither";
                 }
                 for(string word : sp)
                 {
                     if(word.size()>4 || word.size()<1)
                     {
                         return "Neither";
                     }
                     for(auto &chr : word)
                     {
                         if(!isdigit(chr))
                         {
                             if(!isalpha(chr))
                             {
                                 return "Neither";
                             }
                             else
                             {
                                 if(toupper(chr) > 'F')
                                 {
                                     return "Neither";
                                 }
                             }
                         }
                     }
                 }
                 return "IPv6";
             }
             else
             {
                 return "Neither";
             }
         }
    }
};
