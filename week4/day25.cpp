/*Find the Duplicate Number

Solution
Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.

Example 1:

Input: [1,3,4,2,2]
Output: 2
Example 2:

Input: [3,1,3,4,2]
Output: 3
Note:

You must not modify the array (assume the array is read only).
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n2).
There is only one duplicate number in the array, but it could be repeated more than once.
*/
//Solution 1 : Using floyd's cycle detection algo
//time COmplexity : O(n) and no extra space and no mutating arrays
auto i1 = []()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        return 0;
} ();
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
            int n = nums.size();
            if (n==0)
                    return 0;
            int slow_ptr = nums[0];
            int fast_ptr = nums[0];
            do
            {
                    slow_ptr = nums[slow_ptr];
                    fast_ptr = nums[nums[fast_ptr]];
            } while(slow_ptr!=fast_ptr);
            
            fast_ptr = nums[0];
            while(slow_ptr!=fast_ptr)
            {
                    slow_ptr = nums[slow_ptr];
                    fast_ptr = nums[fast_ptr];
            }
            
            return fast_ptr;
        
    }
};
/* 
[1,3,4,2,2]

fast = 1
slow = 1

fast = 2
slow = 3

fast = 2
slow = 2
----
fast = 1
slow = 2

fast = 3
slow = 4

fast = 2
slow = 2


*/




//Solution 2: Brute force method
//time complexity: O(n2) no change in array and no extra space

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
            int n = nums.size();
            int i;
            for(i=0;i<n;i++)
            {
                    for(int j=i+1;j<n;j++)
                    {
                            if(nums[i]==nums[j])
                                    return nums[i];
                    }
                            
            }
            
            return nums[i];
        
    }
};