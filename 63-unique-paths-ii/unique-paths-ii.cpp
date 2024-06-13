class Solution {
public:
    int recur(vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp, int i, int j){
        if(i<0 || j<0){
            return 0;
        }
        if(i == 0 && j ==0){
            if(obstacleGrid[i][j] == 1){
                return 0;
            }
            return 1;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }
        else{
            if(obstacleGrid[i][j] == 1){
                dp[i][j] = 0;
            }
            else{
                dp[i][j] = recur(obstacleGrid, dp, i-1, j) + recur(obstacleGrid, dp, i, j-1);
            }
            return dp[i][j];
        }
    }


    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        // int ans = recur(obstacleGrid, dp,obstacleGrid.size()-1, obstacleGrid[0].size() -1  );
        if(obstacleGrid[0][0] == 1){
            dp[0][0] = 0;
        }
        else{
            dp[0][0] = 1;
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j<n; j++){
                if(i == 0 && j == 0){
                    continue;
                }
                if(obstacleGrid[i][j] == 1){
                    dp[i][j] = 0;
                }
                else{
                    if(i > 0){
                        dp[i][j] += dp[i-1][j];
                    }
                    if(j > 0){
                        dp[i][j] += dp[i][j-1];
                    }
                }
            }
        }
        return dp[m-1][n-1];
    }
};