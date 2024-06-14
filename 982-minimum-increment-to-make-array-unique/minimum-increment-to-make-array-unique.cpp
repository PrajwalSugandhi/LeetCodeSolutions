class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        map<int,int> m;
        for(auto it : nums){
            m[it]++;
        }
        int ans=0;
        for(auto itr = m.begin(); itr != m.end(); itr++){
            if(itr->second > 1){
                ans += itr->second - 1;
                m[itr->first + 1] += itr->second - 1;
            }
        }
        return ans;
    }
};