/*
Perfect Squares

Solution
Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

Example 1:

Input: n = 12
Output: 3 
Explanation: 12 = 4 + 4 + 4.
Example 2:

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.
*/
//Solution 1:Using dp
//TC: O(n*n^0.5)
//approach:
//dp[0]=0
//and n=1 to 3 will have n=1,2,3
//also initially for all it will be respective n because thats the max as 1^2+1^2+..
//after that we consider breakpoints and do.
class Solution {
public:
    int numSquares(int n) {
            int dp[n+1];
            dp[0] = 0;
            for(int i=1;i<=n;i++)
            {
                    dp[i] = i;
                    for(int j=1;j*j<=i;j++)
                    {
                        int sq = j*j;
                        dp[i] = min(dp[i],1+dp[i-sq]);    
                    }
            }
            
            return dp[n];
        
    }
};

//Solution 2: Recursion+memoization
class Solution {
    vector<int> dp;    
        
    int solveRecursion(int n)
    {
            if(n<=3)
                    return n;
            if(dp[n]!=-1)
                    return dp[n];
            int ans=n;
            for(int i=1;i*i<=n;i++)
            {
                ans = min(ans,1+solveRecursion(n-i*i));    
            }
            
            dp[n]=ans;
            return dp[n];
    }
public:
    int numSquares(int n) {
            dp.resize(n+1,-1);
            return solveRecursion(n);
        
    }
};

//Solution 3:Legendre's 3-square theorem
/*
according to the theorem,any number can be expressed as square of 3 numbers 
a^2 +b^2 +c^2 if it is not of the form 4^a(8b+7); If it is of the form then answer will
be four as according to theorem it can be expressed as square of 4 numbers.
If not then check for breakpoints if you get breakpoints and if it can be expressed
as sum of 2 perfect squares . else if none of the above then it will be 3. 
*/

class Solution {
public:
    int numSquares(int n) {
        if(ceil(sqrt(n))==floor(sqrt(n)))
            return 1;
        while(n%4==0)   //Remove 4^a term
            n/=4;
        
        if(n%8==7)      //check if the no now is in the form of (8b + 7)
            return 4;
        
        for(int i=1;i*i<=n;++i)
        {
            int base = sqrt(n-i*i);
            if(base*base==(n-i*i))
                return 2;
        }
        return 3;
    }
};