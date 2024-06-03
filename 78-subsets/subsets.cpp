class Solution {
public:
    vector<vector<int>> bitsubsets(vector<int>& nums) {
        int n = nums.size();
        int total = pow(2,n);
        vector<int> v;
        vector<vector<int>> ans;
        for(int i = 0; i< total; i++){
            v.clear();
            for(int j = 0; j< nums.size(); j++){
                if(i & (1<<j)){
                    v.push_back(nums[j]);
                }
            }
            ans.push_back(v);
        }
        return ans;
    }

    void recursion(int i, vector<int>& nums, vector<int>& v, vector<vector<int>>& ans){
        if(i == nums.size()){
            ans.push_back(v);
            return;
        }

        v.push_back(nums[i]);
        recursion(i+1, nums, v, ans);
        v.pop_back();
        recursion(i+1, nums, v, ans);
    }


    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> v;
        vector<vector<int>> ans;
        recursion(0, nums, v, ans);
        return ans;
    }
};