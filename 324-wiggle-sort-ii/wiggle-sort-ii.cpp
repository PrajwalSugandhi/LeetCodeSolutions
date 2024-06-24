class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> ans(n);
        int i=1,mid = (n+1)/2, j = n-1;
        while(i < n){
            ans[i] = nums[j];
            i += 2;
            j--;
        }
        i=0;
        while(i < n){
            ans[i] = nums[j];
            i += 2;
            j--;
        }
        nums = ans;
    }
};