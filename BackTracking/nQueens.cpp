class Solution {
public:

    vector<vector<string>> out;

    int total = 0;

    bool isValid(vector<string> &here, int row, int col)
    {
        for(int i = 0 ; i < row ; i++)
        {
            if(here[i][col]=='Q')return false;
        }
        for(int i = row-1, j = col-1; i >=0 && j>=0; i--, j--)
        {
            if(here[i][j]=='Q')return false;
        }
        for(int i = row-1, j = col+1; i >= 0 && j < total; i--, j++)
        {
            if(here[i][j]=='Q')return false;
        }
        return true;
    }
    void dfs(vector<string> &here,int num)
    {
        if(num==total)
        {
            out.push_back(here);
            return;
        }

        for(int i = 0 ; i < total ; i++)
        {
            if(isValid(here,num,i))
            {
                here[num][i] = 'Q';
                dfs(here,num+1);
                here[num][i] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        total = n;
        string str(n,'.');
        vector<string> here(n,str);
        dfs(here,0);
        return out;
    }
};
