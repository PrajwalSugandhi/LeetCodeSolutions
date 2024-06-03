class Solution {
public:
    string addBinary(string a, string b) {
        string ans="";
        int i = a.length()-1,j=b.length()-1,carry=0,sum;
        int l,r;
        while(i >= 0 && j>=0){
            l = a[i] - '0';
            r = b[j] - '0';
            sum = carry + l + r;
            if(sum == 3){
                ans =  "1" + ans;
                carry = 1;
            }
            else if(sum == 2){
                ans = "0" + ans;
                carry = 1;
            }
            else if(sum == 1){
                ans =  "1" + ans;
                carry = 0;
            }
            else{
                ans = "0" + ans;
                carry = 0;
            }
            i--;
            j--;

        }
        while(i >= 0){
            l = a[i] - '0';
            sum = carry + l;
            if(sum == 2){
                ans = "0" + ans;
                carry = 1;
            }
            else if(sum == 1){
                ans =  "1" + ans;
                carry = 0;
            }
            else{
                ans = "0" + ans;
                carry = 0;
            }
            i--;
        }

        while(j >= 0){
            r = b[j] - '0';
            sum = carry + r;
            if(sum == 2){
                ans = "0" + ans;
                carry = 1;
            }
            else if(sum == 1){
                ans =  "1" + ans;
                carry = 0;
            }
            else{
                ans = "0" + ans;
                carry = 0;
            }
            j--;
        }

        if(carry == 1){
            ans = "1" + ans;
        }
        return ans;
    }
};