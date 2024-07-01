class Solution {
public:
    int recur(vector<int>& prices,int index, int buy,int n, vector<vector<int>>& dp){
        if(index == n){
            return 0;
        }
        if(dp[index][buy] != -1){
            return dp[index][buy];
        }
        if(buy){
            dp[index][buy] = max(recur(prices, index + 1, 0, n, dp) - prices[index], 0 + recur(prices, index+1, 1, n, dp));
        }
        else{
            dp[index][buy] = max(recur(prices, index + 1, 1, n, dp) + prices[index], 0 + recur(prices, index+1, 0, n, dp));
        }
        return dp[index][buy];
    }


    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // vector<vector<int>> dp(n, vector<int>(2,-1));
        // int ans = recur(prices, 0, 1, n, dp);
        // vector<vector<int>> dp(n+1, vector<int>(2,-1));
        vector<int> next(2), curr(2);
        next[0] = 0;
        next[1] = 0;
        for(int i = n-1; i>=0; i--){
            for(int buy = 0; buy <=1; buy++){
                if(buy){
                    curr[buy] = max(-prices[i] + next[0], next[1]);
                }
                else{
                    curr[buy] = max(prices[i] + next[1], next[0]);
                }
            }
            next = curr;
        }
        return next[1];
    }
};