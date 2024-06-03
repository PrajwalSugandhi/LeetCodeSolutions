class Solution {
public:
    void helper(int o, int c, string& s, vector<string>& ans){
        if(o < 0 || c < 0 || o > c){
            return;
        }
        if(o == 0 && c == 0){
            ans.push_back(s);
            return;
        }
        s += "(";
        helper(o-1, c, s, ans);
        s.pop_back();
        s += ")";
        helper(o, c-1, s, ans);
        s.pop_back();
    }

    vector<string> generateParenthesis(int n) {
        string s = "";
        vector<string> ans;
        helper(n,n,s,ans);
        return ans;
    }
};