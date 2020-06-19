/*Surrounded Regions

Solution
Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

Example:

X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
Explanation:

Surrounded regions shouldn’t be on the border, which means that any 'O' on the border of the board are not flipped to 'X'. Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. Two cells are connected if they are adjacent cells connected horizontally or vertically.
*/


auto i1 = []()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        return 0;
}();

class Solution {
        
    void dfs(vector<vector<char>>& board,int i,int j)
    {
            if(board[i][j]=='O')
            {
                    board[i][j]='1';
                    
                    if(i+1<board.size())
                            dfs(board,i+1,j);
                    if(i>1)
                            dfs(board,i-1,j);
                    if(j+1<board[i].size())
                            dfs(board,i,j+1);
                    if(j>1)
                            dfs(board,i,j-1);
            }
    }
public:
    void solve(vector<vector<char>>& board) {
            if(board.size()==0)
                    return;
            int m = board.size();
            int n = board[0].size();
            
            for(int i=0;i<m;i++)
            {
                    dfs(board,i,0);
                    dfs(board,i,n-1);
            }
            
            for(int j=1;j<n;j++)
            {
                    dfs(board,0,j);
                    dfs(board,m-1,j);
            }
            
            
            for(int i=0;i<m;i++)
            {
                    for(int j=0;j<n;j++)
                    {
                            if(board[i][j]=='O')
                                    board[i][j] = 'X';
                            else if(board[i][j]=='1')
                                    board[i][j] = 'O';
                    }
            }
            
        
    }
};