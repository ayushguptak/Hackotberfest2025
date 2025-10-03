class Solution {
public:
    int f(int index,vector<int>& cost,vector<int>& dp) {
        if(index < 0) return 0;
        if(index == 0 || index == 1) return cost[index];
        if(dp[index] != -1) return dp[index];
        int onestep = cost[index] + f(index-1,cost,dp);
        int twostep = cost[index] + f(index-2,cost,dp);        
        return dp[index] = min(onestep,twostep);
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1,-1);
        return min(f(n-1,cost,dp),f(n-2,cost,dp));
    }
};
