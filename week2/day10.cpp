/*Search Insert Position

Solution
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Example 1:

Input: [1,3,5,6], 5
Output: 2
Example 2:

Input: [1,3,5,6], 2
Output: 1
Example 3:

Input: [1,3,5,6], 7
Output: 4
Example 4:

Input: [1,3,5,6], 0
Output: 0

*/


//Solution 1 : Binary search
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
            ios_base::sync_with_stdio(false);
            cin.tie(NULL);
            cout.tie(NULL);
            int n = nums.size();
            int low = 0;
            int high = n-1;
            int ans;
            while(low<=high)
            {
                int mid = low + (high-low)/2;
                if(nums[high]<target)
                {
                    ans = high+1;
                    break;    
                } 
                else if(nums[low]>target)
                {
                    ans = low;
                    break;                          
                }
                else if(nums[mid]==target)
                {
                    ans = mid;
                    break;    
                }
                else if(nums[mid]>target)
                {
                        high = mid-1;
                }
                    
                else
                {
                        low = mid+1;
                }
            }
            
            return ans;
        }
};


//Solution 2: Brute force
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i = 0;
        while(i<nums.size() && target>nums[i])
        {
                ++i;
        }
            
        return i;    
    }
};