/*Longest Duplicate Substring

Solution
Given a string S, consider all duplicated substrings: (contiguous) substrings of S that occur 2 or more times.  (The occurrences may overlap.)

Return any duplicated substring that has the longest possible length.  (If S does not have a duplicated substring, the answer is "".)

 

Example 1:

Input: "banana"
Output: "ana"
Example 2:

Input: "abcd"
Output: ""
 

Note:

2 <= S.length <= 10^5
S consists of lowercase English letters.

*/

// Writing the approach to revise for interview later

//This solution uses binary search + Rabin Carp algo (also called rolling hash)
//binary search is used to determine the longest length for common substring
//Rabin Carp algo
/*
   1.Calculate hash value for the pattern.
   2.Calculate hash value for the substring of window size obtained by binary search
   3. If hash values obtained from 1 and 2 are equal only then compare each character one by one .
   4. If equal,return.
    5. Else move the window by 1. For that subtract the hash value of MSB and left shift the value and then 
    add the hash value for new character.

    6. go to step 2.
*/

// Time complexity - O(logn + N + logN)
//logN for binary search
//N for window traversal
//logN for storing in unordered map

#define p 10000007
vector<int> roll;

class Solution {
    bool match(string s,int len,int size,string& ans)
    {
        unordered_map<int,vector<int>> m;   //Key->hashValue...Value->starting index of substring
        int hash=0;   //curr window hash
        for(int i=0;i<size;++i)
            hash = (hash*26 + (s[i]-'a'))%p;
        
        m[hash].push_back(0);
        //Rolling hash (sliding window)
        for(int j=size;j<len;++j)
        {
            hash = ((hash-roll[size-1]*(s[j-size]-'a'))%p + p)%p;
            hash = (hash*26 + (s[j]-'a'))%p;
            if(m.find(hash)!=m.end())
            {
                for(auto start: m[hash])
                {
                    string temp = s.substr(start,size);
                    string curr = s.substr(j-size+1,size);
                    if(temp.compare(curr)==0)
                    {
                        ans = temp;
                        return true;
                    }
                }
            }           
            m[hash].push_back(j-size+1);
        }
        return false;
    }

public:
    string longestDupSubstring(string S) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int len = S.size();
        if(len==0)
            return "";
        
        //Store all rolling hash values
        roll.resize(len);  //Allocating fixed space to array
        roll[0] = 1;    //Since 26^0 = 1
        for(int i=1;i<len;++i)
            roll[i] = (26*roll[i-1])%p;
        
        int low=1,high=len,mid;
        string ans = "",temp;
        while(low<=high)
        {
            temp="";
            mid = low+(high-low)/2;
            bool flag = match(S,len,mid,temp);
            if(flag)
            {
                if(temp.size()>ans.size())
                    ans=temp;
                low = mid+1;
            }
            else
                high = mid-1;
        }
        return ans;
    }
};