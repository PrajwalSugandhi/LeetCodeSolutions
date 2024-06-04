class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int rstart =0, colstart = 0;
        int n = grid.size();
        vector<vector<int>> ans(n-2, vector<int>(n-2));
        int temp=0;
        for(int i =1; i<n-1; i++){
            for(int j = 1; j<n-1; j++){
                temp = 0;
                for(int k = i-1; k < i+2; k++){
                    for(int l = j-1; l < j+2; l++){
                        temp = max(temp, grid[k][l]);
                    }
                }
                ans[i-1][j-1] = temp;
            }
        }
        return ans;
    }
};