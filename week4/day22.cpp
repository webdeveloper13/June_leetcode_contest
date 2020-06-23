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

//Solution 1 : Using sort+linear traversal;
//TC: O(nlogn+N) ; SC:O(1)  
//Since it is given N<=INT_MAX so logn<= 32
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

//Solution 2: Using Bit manipulation
//TC:O(n) and SC:O(1)
/*
basically the approach is to have two variables ones and twos(initially zero)
one by one do this
ones = (ones XOR a[i])&(complement(twos))
twos = (twos XOR a[i])&(complement(ones))
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
            int ones = 0;
            int twos = 0;
            for(auto n:nums)
            {
                    ones = (ones^n)&(~twos);
                    twos = (twos^n)&(~ones);
            }
            return ones;
    }
};


//Solution 3: Using set bits;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
           int n=nums.size();
        unsigned int ans=0,shift=1;
        for(int i=0;i<32;++i)
        {
            int count=0;
            for(auto ele: nums)
            {
                if(ele & shift)
                    count+=1;
            }
            if(count%3 != 0)
                ans += shift;
            shift*=2;
            
        }
        return ans;
    }
};