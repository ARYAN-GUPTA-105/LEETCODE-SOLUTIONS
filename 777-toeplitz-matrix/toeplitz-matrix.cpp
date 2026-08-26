class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        for (int i = matrix.size() - 1; i >= 0; i--) {
            int j = 0;
            int k = i;
            int val = matrix[k][j];
            while(j < matrix[0].size() && k < matrix.size()){
                if(matrix[k][j] != val) return false;
                else k++,j++;
            }
        }
        for (int j = 0; j < matrix[0].size(); j++) {
            int i = 0;
            int k = j;
            int val = matrix[i][k];
            while(k < matrix[0].size() && i < matrix.size()){
                if(matrix[i][k] != val) return false;
                else k++,i++;
            }
        }
        return true;
    }
};