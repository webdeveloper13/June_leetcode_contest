/*Unique Binary Search Trees

Solution
Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?

Example:

Input: 3
Output: 5
Explanation:
Given n = 3, there are a total of 5 unique BST's:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
 */

/*Approach
Assume n = 4;
[1,2,3,4]
so bs trees will be with each node as root as follows

1              2            3          4
 \            / \          / \        /  \
  {2,3,4}   {1}  {3,4}  {1,2} {4}  {1,2,3}   
 
So total trees will be C0*C3 + C1*C2 + C2*C4 + C3*C0 which is nothing but Catalan(4);

Now we can calculate catalan using DP;
initialise dp[0]=dp[1]=0
for(int i=2;i<=n;i++)
            {
                    dp[i] = 0;
                    for(int j=0;j<i;j++)
                    {
                            dp[i] += dp[j]*dp[i-j-1];
                    }
            }
*/
auto i1 = []()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        return 0;
} ();
class Solution {
    int catalanNum(int n)
    {
            int dp[n+1];
            dp[0] = 1;
            dp[1] = 1;
            for(int i=2;i<=n;i++)
            {
                    dp[i] = 0;
                    for(int j=0;j<i;j++)
                    {
                            dp[i] += dp[j]*dp[i-j-1];
                    }
            }
            
            return dp[n];
    }
public:
    int numTrees(int n) {
            return catalanNum(n);
        
    }
};