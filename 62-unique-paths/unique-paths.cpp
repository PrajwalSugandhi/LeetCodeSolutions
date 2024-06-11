class Solution {
public:
    int memo(vector<vector<int>> & dp, int m , int n){
        if(m == 0 && n == 0){
            return 1;
        }
        if(m < 0 || n<0){
            return 0;
        }

        if(dp[m][n] != -1){
            return dp[m][n];
        }
        else{
            dp[m][n] = memo(dp, m-1, n) + memo(dp, m , n-1);
        }
        return dp[m][n];
    }



    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        // for(int i = 0; i<m+1; i++){
        //     dp[i][0] = 0;
        // }
        // for(int i = 0; i<n+1; i++){
        //     dp[0][i] = 0;
        // }
        // dp[1][1] = 1;
        int ans = memo(dp, m-1, n-1);
        return ans;
        // if(m == 1 && n == 1){
        //     return 1;
        // }
        // vector<int> prev(n+1, 0), curr(n+1, 0);
        // curr[1] = 1;
        // for(int i = 1; i<m+1; i++){
        //     for(int j = 1; j<n+1; j++){
        //         if(i != 1 || j != 1){
        //             curr[j] = prev[j] + curr[j-1];
        //             //cout<<i<<" "<<j<<" "<<dp[i-1][j]<<" "<<dp[i-1][j]<<" "<<dp[i-1][j]<<endl;
        //         }
        //     }
        //     prev = curr;
        // }
        // for(auto i : dp){
        //     for(int j : i){
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;
        // }
        // return prev[n];
    }
};