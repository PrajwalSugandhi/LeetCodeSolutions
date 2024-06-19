class Solution {
public:
    int fun(vector<int>& bloomDay, int mid, int m, int k){
        int flower = 0, bouque=0;
        for(int i = 0; i<bloomDay.size(); i++){
            if(bloomDay[i] <= mid){
                flower++;
            }
            else{
                flower = 0;
            }
            if(flower == k){
                bouque++;
                flower = 0;
            }
            if(bouque == m){
                return 1;
            }
        }
        
        return 0;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long long)m * k > bloomDay.size()){
            return -1;
        }
        int start = *min_element(bloomDay.begin(),bloomDay.end()),mid,end = *max_element(bloomDay.begin(),bloomDay.end());
        int val,ans=-1;
        while(start <= end){
            mid = start + (end-start)/2;
            val = fun(bloomDay, mid, m, k);
            if(val == 1){
                ans = mid;
                end = mid - 1;    
            }
            else{
                start = mid + 1;
            }
        }
        return ans;
    }
};