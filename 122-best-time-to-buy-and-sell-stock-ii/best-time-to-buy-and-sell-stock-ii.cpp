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
        vector<vector<int>> dp(n, vector<int>(2,-1));
        int ans = recur(prices, 0, 1, n, dp);
        return ans;
    }
};