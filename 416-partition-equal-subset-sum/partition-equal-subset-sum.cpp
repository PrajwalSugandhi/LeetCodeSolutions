class Solution {
public:
    int recur(vector<int>& nums, int i, int sum1, vector<vector<int>> & dp){
        if(sum1 == 0){
            dp[i][sum1] = 1;
            return 1;
        }
        if(i == 0){
            if(sum1 == nums[0]){
                dp[i][sum1] = 1;
                return 1;
            }
            dp[i][sum1] = 0;
            return 0;
        }

        if(dp[i][sum1] != -1){
            return dp[i][sum1];
        }
        else{
            int pick=0,nopick=0;
            nopick = recur(nums, i-1, sum1, dp);
            if(nopick == 1){
                dp[i][sum1] = 1;
                return 1;
            }
            else if(sum1 >= nums[i]){
                sum1 -= nums[i];
                pick = recur(nums, i-1, sum1, dp);
                sum1 += nums[i];
            }
            if(pick == 1){
                dp[i][sum1] = 1;
                return 1;
            }
            dp[i][sum1] = 0;
            return 0;
            
            // return dp[i][sum1];
        }
    }

    bool canPartition(vector<int>& nums) {
        int target = 0;
        for(auto it : nums){
            target += it;
        }
        if(target % 2 == 1){
            return false;
        }
        target /= 2;
        // vector<vector<int>> dp(nums.size(), vector<int>(target+1, -1));
        int n = nums.size();
        // cout<<target<<" ";
        // int ans = recur(nums, n-1,target, dp);
        // for(auto i : dp){
        //     for(int j : i){
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;
        // }
        // if(ans == 1){
        //     return true;
        // }
        // return false;
        vector<vector<bool>> dp(nums.size(), vector<bool>(target+1, -1));
        for(int i = 0; i<n; i++){
            dp[i][0] = true;
        }
        bool pick=0, nopick=0;
        for(int left = 1; left<= target; left++){
            if(left == nums[0]){
                dp[0][left] = true;
            }
            else{
                dp[0][left] = false;
            }
        }
        for(int i = 1; i<n; i++){
            for(int left = 1; left<=target; left++){
                pick = 0;
                nopick = dp[i-1][left];
                if(left >= nums[i]){
                    pick = dp[i-1][left - nums[i]];
                }
                dp[i][left] = nopick | pick;
            }
        }
        return dp[n-1][target];

    }
};