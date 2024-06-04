class Solution {
public:
    int longestPalindrome(string s) {
        map<char,int> m;
        for(char c : s){
            m[c]++;
        }
        int ans=0,k=0;
        for(auto it = m.begin(); it != m.end(); it++){
            if(it->second % 2 == 0){
                ans += it->second;
            }
            else{
                ans += it->second-1;
                k = 1;
            }
        }
        return ans + k;
    }
};