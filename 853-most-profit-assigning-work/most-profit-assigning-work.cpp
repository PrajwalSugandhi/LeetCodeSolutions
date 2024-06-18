class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = profit.size();
        vector<pair<int,int>> v(n);
        for(int i = 0; i<n; i++){
            v[i] = {difficulty[i], profit[i]};
        }
        sort(v.begin(), v.end());
        int ans=0,k;

        map<int,int> maxdif;
        for(int i = 0; i<n; i++){
            if(i == 0){
                maxdif[v[i].first] = v[i].second;
            }
            else{
                maxdif[v[i].first] = max(maxdif[v[i-1].first], v[i].second);
            }
        }
        for(int i = 0; i<worker.size(); i++){
            k = upper_bound(v.begin(), v.end(), make_pair(worker[i], INT_MAX)) - v.begin();
            if(k > 0) ans += maxdif[v[k-1].first];
        }
        return ans;
    }
};