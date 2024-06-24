class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (2,-1));
        sort(nums.begin(),nums.end());
        dp[0][1] = nums[0];
        dp[0][0] = 0;
        int j;
        for(int i = 1; i<n; i++){
            j = i-1;
            while(j >= 0 && nums[j] == nums[i] - 1){
                j--;
            } 
            if(j < 0){
                dp[i][1] = nums[i];
            }
            else{
                if(nums[j] == nums[i]){
                    dp[i][1] = nums[i] + dp[j][1];
                }
                else{
                    dp[i][1] = nums[i] + max(dp[j][0], dp[j][1]);
                }
                
            }
            
            j = i-1;
            while(j > -1 && nums[j] == nums[i]){
                j--;
            }
            if(j == -1){
                dp[i][0] = 0;
            }
            else if(nums[j] == nums[i] - 1){
                dp[i][0] = dp[j][1];
            }
            else{
                dp[i][0] = 0;
            }

        }

        // for(auto itr : dp){
        //     for(int it : itr){
        //         cout<<it<<" ";
        //     }
        //     cout<<endl;
        // }
        int ans;
        ans = max(dp[n-1][0], dp[n-1][1]);
        return ans;

    }
};