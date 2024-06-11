class Solution {
public:
    vector<int> relativeSortArray(vector<int>& ar1, vector<int>& arr2) {
        vector<int> arr1(ar1.size(), -1);
        map<int,int> m;
        for(auto num : ar1){
            m[num]++;
        }
        int j = 0;
        int time;
        // for(auto it = m.begin(); it != m.end(); it++){
        //     cout<<it->first<<" "<<it->second<<endl;
        // }
        for(int i = 0; i<arr2.size(); i++){
            time = m[arr2[i]];
            m[arr2[i]] = 0;
            while(time){
                arr1[j] = arr2[i];
                j++;
                time--;
            }
        }
        // cout<<j;
        // for(int p: arr1){
        //     cout<<j<<" ";
        // }
        // cout<<endl;
        // int time;
        for(auto it = m.begin(); it != m.end(); it++){
            time = it->second;
            while(time){
                arr1[j] = it->first;
                j++;
                time--;
            }
        }
        return arr1;
    }
};