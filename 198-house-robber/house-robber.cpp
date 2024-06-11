class Solution {
public:
    int best(vector<int>& nums, vector<int>& dp, int n){
        if(n == 0){
            return nums[0];
        }
        if(n < 0){
            return 0;
        }


        if(dp[n] != -1){
            return dp[n];
        }
        else{
            int pick = nums[n] + best(nums, dp, n-2);
            int notpick = best(nums, dp, n-1);
            dp[n] = max(pick,notpick);
            return dp[n];
        }
    }


    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        int ans;
        ans = best(nums, dp, nums.size()-1);
        return ans;
    }
};