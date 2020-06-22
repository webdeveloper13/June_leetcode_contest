/*Single Number II

Solution
Given a non-empty array of integers, every element appears three times except for one, which appears exactly once. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,3,2]
Output: 3
Example 2:

Input: [0,1,0,1,0,1,99]
Output: 99
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
    int singleNumber(vector<int>& nums) {
            sort(nums.begin(),nums.end());
            int n = nums.size();
            if(n<=1)
                    return nums[0];
            if(nums[0]!=nums[1])
                    return nums[0];
            if(nums[n-1]!=nums[n-2])
                    return nums[n-1];
            int ans;
            int i=1;
            while(i<n)
            {
                    if(nums[i]==nums[i-1])
                    {
                        i = i+3;
                    }
                    else
                    {
                           ans = nums[i-1];
                            break;
                    }   

            }
    
            
            return ans;
            
        
    }
};