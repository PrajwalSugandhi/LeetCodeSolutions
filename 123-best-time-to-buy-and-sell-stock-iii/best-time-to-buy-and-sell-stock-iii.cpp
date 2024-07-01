class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1 , vector<vector<int>>(2, vector<int>(3, -1)));
        for(int i = 0; i<2; i++){
            for(int left = 0; left <=2; left++){
                dp[n][i][left] = 0;
            }
        }
        for(int i = 0; i<n; i++){
            for(int buy = 0; buy<=1; buy++){
                dp[i][buy][0] = 0;
            }
        }

        for(int i = n-1; i>=0; i--){
            for(int buy = 0; buy<=1; buy++){
                for(int left = 1; left<=2; left++){
                    if(buy){
                        dp[i][1][left] = max(-prices[i] + dp[i+1][0][left], dp[i+1][1][left]);
                    }
                    else{
                        if(left == 1){
                            dp[i][0][1] = max(prices[i] , dp[i+1][0][1]);
                        }
                        else if(left == 2){
                            dp[i][0][2] = max(prices[i] + dp[i+1][1][1], dp[i+1][0][2]);
                        }
                    }
                }
            }
        }
        // cout<<dp[0][1][1];
        return dp[0][1][2];
    }
};