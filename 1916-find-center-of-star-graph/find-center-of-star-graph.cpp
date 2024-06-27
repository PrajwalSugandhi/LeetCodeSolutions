class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        vector<int> v(edges.size() + 2,0);
        for(auto itr : edges){
            v[itr[0]]++;
            v[itr[1]]++;
        }
        int ans,ans_count = 0;
        for(int i = 0; i< v.size(); i++){
            if(ans_count < v[i]){
                ans_count = v[i];
                ans = i;
            }
        }
        return ans;
    }
};