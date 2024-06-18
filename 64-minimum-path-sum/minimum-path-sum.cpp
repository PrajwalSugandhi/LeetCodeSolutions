class Solution {
public:
    int recur(vector<vector<int>>& grid, int i, int j, vector<vector<int>> dp){
        if(i == 0 && j==0){
            return grid[i][j];
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        else{
            int p=INT_MAX;
            if(i>0){
                p = recur(grid, i-1, j, dp);
            }
            if(j > 0){
                p = min(p, recur(grid, i, j-1, dp));
            }
            dp[i][j] = grid[i][j] + p;
            return dp[i][j];
        }
    }


    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // vector<vector<int>> dp(m, vector<int>(n,-1));
        // int ans = recur(grid, m-1,n-1,dp);
        int p = INT_MAX;
        vector<int> prev(n), curr(n);
        for(int i = 0; i<m; i++){
            for(int j = 0; j < n; j++){
                p = INT_MAX;
                if(i == 0 && j == 0){
                    curr[0] = grid[0][0];
                    continue;
                }
                if(i > 0){
                    p = prev[j];
                }
                if(j > 0){
                    p = min(p , curr[j-1]);
                }
                curr[j] = grid[i][j] + p;
            }
            prev = curr;
        }
        return prev[n-1];

    }
};