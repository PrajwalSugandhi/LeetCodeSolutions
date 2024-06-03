class Solution {
public:
    int appendCharacters(string s, string t) {
        int j = 0,i=0;
        int ans=0;
        while(j<t.length()){
            if(i == s.length()){
                ans = t.length() - j;
                break;
            }
            if(s[i] == t[j]){
                j++;
            }
            i++;
        }
        return ans;
    }
};