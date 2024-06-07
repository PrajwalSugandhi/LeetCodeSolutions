class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        string s="", ans="";
        sentence += " ";
        int p = 0;
        map<string,int> m;
        for(int i =0; i<dictionary.size(); i++){
            m[dictionary[i]]++;
        }
        for(int i =0; i<sentence.length(); i++){
            if(sentence[i] == ' '){
                if(p == 0){
                    ans += s + " ";
                }
                s = "";
                p=0;
            }
            else{
                s += sentence[i];
                if(p != 1 && m.find(s) != m.end()){
                    ans += s + " ";
                    p = 1;
                }
            }
        }
        ans.pop_back();
        return ans;
    }
};