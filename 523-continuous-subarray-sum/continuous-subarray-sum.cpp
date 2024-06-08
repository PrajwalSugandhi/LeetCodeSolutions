class Solution {
public:
    inline static int hash_map(vector<int>& nums, int k, int n){
        unordered_set<int> mod_k;// 1 <= k <= 2^31 - 1
        int prefix=0, last=0;
        mod_k.reserve(n);
        for(int i=0; i<n; i++){
            prefix+=nums[i];
            prefix%=k;
            if (mod_k.count(prefix))
                return 1;
            mod_k.insert(last);
            last=prefix;
        }
        return 0;
    }
    inline static int array(vector<int>& nums, int k, int n){
        bitset<1000000> mod_k=0;// mod k=0,1,...,k-1
        int prefix=0, last=0;
        for(int x: nums){
            prefix+=x;
            prefix%=k;
            if (mod_k[prefix])
                return 1;
            mod_k[last]=1;
            last=prefix;
        }
        return 0;
    }
    static bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        if (n<2) return 0; //its length is at least two
        if (k>=1e6) return hash_map(nums, k, n);
        return array(nums, k, n);
    }     
};




auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();