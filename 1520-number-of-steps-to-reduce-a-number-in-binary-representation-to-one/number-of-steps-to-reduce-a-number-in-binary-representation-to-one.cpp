class Solution {
public:
    int numSteps(string s) {
        int cnt = 0;
        int n,i;
        while(s != "1"){
            cnt++;
            n = s.length();
            if(s[n-1] == '1'){
                i = n-1;
                while(i > -1 && s[i] == '1'){
                    s[i] = '0';
                    i--;
                }
                if(i == -1){
                    s = "1" + s;
                }
                else{
                    s[i] = '1';
                }
            }
            else{
                s.pop_back();
            }
        }
        return cnt;
    }
};