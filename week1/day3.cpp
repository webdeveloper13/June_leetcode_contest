/*Two City Scheduling
Solution
There are 2N people a company is planning to interview. The cost of flying the i-th person to city A is costs[i][0], and the cost of flying the i-th person to city B is costs[i][1].

Return the minimum cost to fly every person to a city such that exactly N people arrive in each city.

 

Example 1:

Input: [[10,20],[30,200],[400,50],[30,20]]
Output: 110
Explanation: 
The first person goes to city A for a cost of 10.
The second person goes to city A for a cost of 30.
The third person goes to city B for a cost of 50.
The fourth person goes to city B for a cost of 20.

The total minimum cost is 10 + 30 + 50 + 20 = 110 to have half the people interviewing in each city.
 

Note:

1 <= costs.length <= 100
It is guaranteed that costs.length is even.
1 <= costs[i][0], costs[i][1] <= 1000
*/



class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
            ios_base::sync_with_stdio(false);
            cin.tie(NULL);
            cout.tie(NULL);
            int sum = 0;
            int N = costs.size();
            vector<pair<int,int>> diff;
            int i=0;
            for(auto c:costs)
            {
                    diff.push_back({c[0]-c[1],i});
                    i++;
            }
            
            sort(diff.begin(),diff.end());
            for(int j=0;j<N/2;j++)
            {
                    sum += costs[diff[j].second][0];
            }
            
            for(int j=N/2;j<N;j++)
            {
                 sum += costs[diff[j].second][1];
            }
            
            return sum;
                    
        
    }
};