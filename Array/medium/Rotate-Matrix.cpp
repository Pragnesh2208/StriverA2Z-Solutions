/*
Time Complexity = O(N^2) as problem statement stats that there will square matrix
Space Complexity = O(N^2)
*/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> duplicateMatrix( n , vector<int>(m , 0));
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ;j++) {
                int calcIndex = m - 1 - i;
                duplicateMatrix[j][calcIndex] = matrix[i][j];
            }
        }
        matrix = duplicateMatrix;
    }
};

/*
Find Transpose of matrix now revrese row
Time Complexity = O(N^2) 
Space Complexity = O(1)
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        for(int i = 0 ; i < n ; i++) {
            for(int j = i ; j < m ; j++) {
                swap(matrix[i][j] , matrix[j][i]);
            }
        } 

        for(int i = 0 ; i < n ; i++) {
            int startCol = 0 , endCol =  n -1;

            while(startCol < endCol) {
                swap(matrix[i][startCol++] , matrix[i][endCol--]);
            }
        } 
    }
};