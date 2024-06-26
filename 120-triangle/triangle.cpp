class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size(), vector<int>(triangle.size(), 1e8));
        int p;
        vector<int> prev(triangle.size()),curr(triangle.size());
        for(int i = 0; i<triangle.size(); i++){
            for(int j = 0; j<= i; j++){
                p = 1e8;
                if(i == 0 && j==0){
                    curr[j] = triangle[i][j];
                    continue;
                }
                
                if(j-1 <= i-1 && j > 0){
                    p = prev[j-1];
                }
                if(j <= i-1){
                    p = min(p , prev[j]);
                }
                curr[j] = triangle[i][j] + p; 
            }
            prev = curr;
        }
        p = INT_MAX;
        for(int j = 0; j<triangle.size(); j++){
            p = min(p,prev[j]);
        }
        // for(auto it : dp){
        //     for(auto k : it){
        //         cout<<k<<" ";
        //     }
        //     cout<<endl;
        // }
        return p;
    }
};




// class Solution {
// public:
//     void recur(vector<vector<int>>& triangle, vector<vector<int>>& dp, int i, int j){
//         if(i < 0 || j < 0){
//             return;
//         }
//         if(i == 0 && j == 0){
//             dp[0][0] = triangle[0][0];
//             return;
//         }
//         if(j > i){
//             return;
//         }

//         if(dp[i][j] != INT_MAX){
//             return;
//         }
//         else{
//             recur(triangle, dp, i-1, j);
//             recur(triangle, dp, i-1, j-1);
//             int p;
//             if(i > 0){
//                 if(j > 0){
//                     p = min(dp[i-1][j],dp[i-1][j-1]);
//                 }
//                 else{
//                     p = dp[i-1][j];
//                 }
//             }
//             dp[i][j] = triangle[i][j] + p ;
//             return; 
//         }
//     }
//     int min(int a, int b){
//         if(a < b){
//             return a;
//         }
//         return b;
//     }

//     int minimumTotal(vector<vector<int>>& triangle) {
//         int m = triangle.size();
//         // vector<vector<int>> dp(m, vector<int> (m,INT_MAX));
//         int ans=INT_MAX;
        
//         // for(int i = 0; i<m; i++){
//         //     recur(triangle, dp, m-1, i);
//         //     ans = min(ans, dp[m-1][i]);
//         // }
//         int p;
//         vector<int> prev(m);
//         for(int i = 0; i<m; i++){
//             vector<int> temp(m, INT_MAX);
//             for(int j = 0; j<m; j++){
//                 if(i == 0 && j == 0){
//                     temp[j] = triangle[i][j];
//                     continue;
//                 }
//                 if(j > i){
//                     break;
//                 }
//                 if(j > 0){
//                     p = min(prev[j],prev[j-1]);
//                 }
//                 else{
//                     p = prev[j];
//                 }
//                 temp[j] = triangle[i][j] + p ;
//             }
//             prev = temp;
//         }
//         for(int i = 0; i<m; i++){
//             ans = min(ans, prev[i]);
//         }
//         return ans;
//     }
// };