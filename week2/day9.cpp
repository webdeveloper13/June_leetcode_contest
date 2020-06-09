/*Is Subsequence

Solution
Given a string s and a string t, check if s is subsequence of t.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ace" is a subsequence of "abcde" while "aec" is not).

Follow up:
If there are lots of incoming S, say S1, S2, ... , Sk where k >= 1B, and you want to check one by one to see if T has its subsequence. In this scenario, how would you change your code?

Credits:
Special thanks to @pbrother for adding this problem and creating all test cases.

 

Example 1:

Input: s = "abc", t = "ahbgdc"
Output: true
Example 2:

Input: s = "axc", t = "ahbgdc"
Output: false
 

Constraints:

0 <= s.length <= 100
0 <= t.length <= 10^4
Both strings consists only of lowercase characters.
*/

//Solution 1: Iterative approach

class Solution {
public:
    bool isSubsequence(string s, string t) {
            ios_base::sync_with_stdio(false);
            cin.tie(NULL);
            cout.tie(NULL);
            if(s.length()>t.length())
                    return false;
            if(s.length()==t.length())
            {
                    if(s==t)
                    {
                            return true;
                    }
            }
            
            int i=0;
            for(int j=0;j<t.length();j++)
            {
                    if(s[i]==t[j])
                            i++;
                    
                    if(i==s.length())
                            break;
            }
            
            if(i==s.length())
                    return true;
            
            return false;
        
    }
};
//Solution 2: Recursive approach.

class Solution {
public:
    bool helper(string s,string t,int m,int n)
    {
          if(m==0)
                  return true;
          if(n==0)
                  return false;
            
          if(s[m-1]==t[n-1])
                 return helper(s,t,m-1,n-1);
          
          return helper(s,t,m,n-1);  
    }
        
    bool isSubsequence(string s, string t) {
            ios_base::sync_with_stdio(false);
            cin.tie(NULL);
            cout.tie(NULL);
            int m = s.length();
            int n = t.length();
            return helper(s,t,m,n);
    }
};



