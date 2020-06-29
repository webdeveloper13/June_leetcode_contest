/*
Unique Paths

Solution
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?


Above is a 7 x 3 grid. How many possible unique paths are there?

 

Example 1:

Input: m = 3, n = 2
Output: 3
Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Right -> Down
2. Right -> Down -> Right
3. Down -> Right -> Right
Example 2:

Input: m = 7, n = 3
Output: 28
*/
/*
Approach: A simple dp problem
so here we take a dp matrix which is initially marked one;
Now note that from top left if the robot wanna move to extreme right or bottom left
then there is only one path.so the first row and column will be 1 only
So now we use 2 for loops starting from 1
and we find unique paths by adding dp[i-1][j]+dp[i][j-1] as robot can move only right
or down.
*/
auto i1 = []()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        return 0;
} ();
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,1));
        for(int i=1;i<m;i++)
        {
                for(int j=1;j<n;j++)
                {
                        dp[i][j] = dp[i-1][j]+dp[i][j-1];
                }
        }
            
        return dp[m-1][n-1];    
    }
};