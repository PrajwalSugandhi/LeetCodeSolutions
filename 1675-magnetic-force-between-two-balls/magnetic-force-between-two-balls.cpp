class Solution {
public:
    int ispossible(vector<int>& position, int m, int minforce){
        int i = 1, count = 1, in= 0;
        while(i < position.size()){
            if(position[i] - position[in] >= minforce){
                in = i;
                count++;
            }
            i++;
        }
        if(count >= m){
            return 1;
        }
        return 0;
    }


    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int maxforce = position[position.size()-1] - position[0];
        int low = 0,high = maxforce,mid;
        int temp;
        int ans=-1;
        while(low <= high){
            mid = low + (high-low)/2;
            temp = ispossible(position, m, mid);
            if(temp == 1){
                ans = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        return high;
    }
};