class Solution {
public:

    bool kyare = false;

    int findBox(int i, int j)
    {
        int row = i/3;
        int box = row*3 + j/3;
        return box;
    }

    void dfs(vector<vector<char>> &board, vector<vector<int>> &row, vector<vector<int>> &column, vector<vector<int>> &box, int i, int j)
    {
        int r = j/9 ? i+1 : i;
        int c = j/9 ? 0 : j;

        if(r==9 && c==0)
        {
            kyare = true;
            return;
        }

        if(board[r][c]!='.')
        {
            dfs(board,row,column,box,r,c+1);
            return;
        }

        int b = findBox(r,c);

        for(int k = 1; k <= 9; k++)
        {
            if(row[r][k] || column[c][k] || box[b][k])continue;
            board[r][c] = char(k+48);
            row[r][k] = 1;
            column[c][k] = 1;
            box[b][k] = 1;

            dfs(board,row,column,box,r,c+1);
            if(kyare)return;

            board[r][c] = '.';
            row[r][k] = 0;
            column[c][k] = 0;
            box[b][k] = 0;
        }

    }


    void solveSudoku(vector<vector<char>>& board)
    {
        vector<vector<int>> row(9,vector<int> (10,0));
        vector<vector<int>> column(9,vector<int> (10,0));
        vector<vector<int>> box(9,vector<int> (10,0));
        for(int i = 0 ; i < 9 ; i++)
        {
            for(int j = 0 ; j < 9; j++)
            {
                if(board[i][j]!='.')
                {
                    int fb = findBox(i,j);
                    int index = board[i][j]-'0';
                    box[fb][index] = 1;
                    row[i][index] = 1;
                    column[j][index] = 1;
                }
            }
        }

        dfs(board,row,column,box,0,0);
        return;
    }
};
