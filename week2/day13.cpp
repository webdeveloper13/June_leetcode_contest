/*Largest Divisible Subset

Solution
Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies:

Si % Sj = 0 or Sj % Si = 0.

If there are multiple solutions, return any subset is fine.

Example 1:

Input: [1,2,3]
Output: [1,2] (of course, [1,3] will also be ok)
Example 2:

Input: [1,2,4,8]
Output: [1,2,4,8]
*/
//steps followed
//step 1: sort the array TC - O(nlogn)
//step 2: find the max subset length  TC - O(n2)
//step 3: find the subset   TC - O(n)

// so total TC will be O(nlogn + N^2 + N)

auto i1 = [](){
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      cout.tie(NULL);
      return 0;  
} ();
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
            ios_base::sync_with_stdio(false);
            cin.tie(NULL);
            cout.tie(NULL);
            int n = nums.size();
            vector<int> ans;
            if(n==0)
                    return ans;
            
            sort(nums.begin(),nums.end());
            int max = 1;
            vector<int> dp(n+1,1);
            for(int i=1;i<n;i++)
            {
                    for(int j=0;j<i;j++)
                    {
                            if(nums[i]%nums[j]==0 && 1+dp[j]>dp[i])
                            {
                                    dp[i] = 1+dp[j];
                                    if(max<dp[i])
                                            max = dp[i];
                            }
                    }
            }
            int prev = -1;
            for(int i=n-1;i>=0;i--)
            {
                    if(dp[i]==max && ((prev%nums[i]==0)||prev==-1))
                    {
                            ans.push_back(nums[i]);
                            max--;
                            prev = nums[i];
                            
                    }
            }
            
            return ans;
        
    }
};