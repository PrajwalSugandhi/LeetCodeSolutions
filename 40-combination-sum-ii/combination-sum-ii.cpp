class Solution {
public:
    void find(int index, vector<int>& c, int& target, vector<int> &v,vector<vector<int>>& ans){
    
        if(target == 0){
            ans.push_back(v);
            return;
        }
            
        

        for(int i = index; i<c.size(); i++){
            if(i > index && c[i] == c[i-1]){
                continue;
            }
            if(c[i] > target){
                return;
            }
            v.push_back(c[i]);
            target -= c[i];
            find(i+1, c, target,v,ans);
            v.pop_back();
            target += c[i];
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> v;
        vector<vector<int>> ans;
        find(0,candidates,target,v,ans);
        return ans;
    }
};