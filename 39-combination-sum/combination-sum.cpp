class Solution {
public:
    void combination(int i, vector<int>& c, int& target,vector<int> & v, vector<vector<int>> &ans){
        if(i == c.size()){
            if(target == 0){
                ans.push_back(v);
            }
            return;
        }
        if(target < 0){
            return;
        }
        v.push_back(c[i]);
        target -= c[i];
        combination(i, c, target, v, ans);
        v.pop_back();
        target += c[i];
        combination(i+1, c, target, v, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> v;
        combination(0,candidates, target, v, ans);
        return ans;
    }
};