class Solution {
public:
    int recur(vector<int>& prices,int index, int buy,int left,int n, vector<vector<vector<int>>>& dp){
        if(index == n){
            return 0;
        }
        if(left == 0){
            return 0;
        }
        if(dp[index][buy][left] != -1){
            return dp[index][buy][left];
        }
        if(buy){
            dp[index][buy][left] = max(recur(prices, index + 1, 0, left, n, dp) - prices[index], 0 + recur(prices, index+1, 1,left, n, dp));
        }
        else{
            dp[index][buy][left] = max(recur(prices, index + 1, 1,left-1, n, dp) + prices[index], 0 + recur(prices, index+1, 0,left, n, dp));
        }
        return dp[index][buy][left];
    }

    int maxProfit(vector<int>& prices){
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1 , vector<vector<int>>(2, vector<int>(3, -1)));
        int ans = recur(prices, 0, 1, 2, n, dp);
        return ans;
    }

    int spaceopti_maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        // vector<vector<vector<int>>> dp(n+1 , vector<vector<int>>(2, vector<int>(3, -1)));
        vector<vector<int>> next(2, vector<int>(3, -1)), curr(2, vector<int>(3, -1));
        for(int i = 0; i<2; i++){
            for(int left = 0; left <=2; left++){
                // dp[n][i][left] = 0;
                next[i][left] = 0;
            }
        }
        // for(int i = 0; i<n; i++){
        //     for(int buy = 0; buy<=1; buy++){
        //         dp[i][buy][0] = 0;
        //     }
        // }

        for(int i = n-1; i>=0; i--){
            for(int buy = 0; buy<=1; buy++){
                next[buy][0] = 0;
            }
            for(int buy = 0; buy<=1; buy++){
                for(int left = 1; left<=2; left++){
                    if(buy){
                        // dp[i][1][left] = max(-prices[i] + dp[i+1][0][left], dp[i+1][1][left]);
                        curr[1][left] = max(-prices[i] + next[0][left], next[1][left]);
                    }
                    else{
                        // dp[i][0][left] = max(prices[i] + dp[i+1][1][left - 1], dp[i+1][0][left]);
                        curr[0][left] = max(prices[i] + next[1][left - 1], next[0][left]);
                    }
                }
            }
            next = curr;
        }
        // return dp[0][1][2];
        return next[1][2];
    }
};