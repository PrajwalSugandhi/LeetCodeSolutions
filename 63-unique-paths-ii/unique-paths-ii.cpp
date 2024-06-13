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
        vector<vector<int>> dp(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), -1));
        int ans = recur(obstacleGrid, dp,obstacleGrid.size()-1, obstacleGrid[0].size() -1  );
        return ans;
    }
};