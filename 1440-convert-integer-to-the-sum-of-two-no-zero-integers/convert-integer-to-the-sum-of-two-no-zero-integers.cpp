class Solution {
public:
    bool helper(int x){
       while(x > 0){
        if(x % 10 == 0) return false;
        x /= 10;
       }
       return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        for(int i = 1;i<n;i++){
            int j = n - i;
            if(helper(i) && helper(j)) return {i,j};
        }
        return {};
    }
};