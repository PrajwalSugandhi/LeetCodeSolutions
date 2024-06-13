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
        // vector<vector<int>> dp(m, vector<int>(n, 0));
        vector<int> prev(n);
        // int ans = recur(obstacleGrid, dp,obstacleGrid.size()-1, obstacleGrid[0].size() -1  );
        
        //  = dp[0][0];
        for(int i = 0; i < m; i++){
            vector<int> temp(n, 0);
            for(int j = 0; j<n; j++){
                if(i == 0 && j == 0){
                    if(obstacleGrid[0][0] == 1){
                        temp[0] = 0;
                    }
                    else{
                        temp[0] = 1;
                    }
                    continue;
                }
                if(obstacleGrid[i][j] == 1){
                    // dp[i][j] = 0;
                    temp[j] = 0;
                }
                else{
                    if(i > 0){
                        temp[j] += prev[j];

                    }
                    if(j > 0){
                        temp[j] += temp[j-1];
                    }
                }
            }
            prev = temp;
        }
        return prev[n-1];
    }
};