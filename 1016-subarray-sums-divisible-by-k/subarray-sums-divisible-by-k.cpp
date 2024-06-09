class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> v(nums.size());
        v[0] = nums[0];
        int rem;
        unordered_map<int,int> m;
        rem = v[0] % k;
        if(rem < 0){
            rem += k;
        }
        m[rem]++;
        for(int i=1; i<nums.size(); i++){
            v[i] =  v[i-1] + nums[i];
            rem = v[i] % k;
            if(rem < 0){
                rem += k;
            }
            m[rem]++;
        }
        int n = nums.size();
        int ans=0;
        for(auto it = m.begin(); it != m.end(); it++){
            if(it->first == 0){
                ans += (it->second * (it->second+1))/2;
            }
            else{
                ans += (it->second * (it->second-1))/2;
            }
        }
        cout<<-11%5;
        return ans;

    }
};