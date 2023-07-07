/*
Time Complexity = O(N*M)
Space Complexity = O(N) + O(M)
*/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size() , col = matrix[0].size();
        vector<int>rows(row , 1) , cols(col , 1);

        for(int i = 0 ; i < row ; i++) {
            for(int j = 0 ; j < col ; j++) {
                if(matrix[i][j] == 0 ) {
                    rows[i] = 0;
                    cols[j] = 0;
                }
            }
        }

        for(int i = 0 ; i < row ; i++) {
            if(rows[i] == 0 ) {
                for(int j = 0 ; j < col ; j++) {
                    matrix[i][j] = 0;
                }
            }
        }

        for(int i = 0 ; i < col ; i++) {
            if(cols[i] == 0 ) {
                for(int j = 0 ; j < row ; j++) 
                matrix[j][i] = 0;
            }
        }
        return;
    }
};


/*
Time Complexity = O(N*M)
Space Complexity = O(1)
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size() , col = matrix[0].size();
        int column = 1;

        for(int i = 0; i < row; i++){
            for(int j = 0 ; j < col ;j++) {
                if(matrix[i][j] == 0 ) {
                    matrix[i][0] = 0 ;
                    if(j == 0 ) column = 0;
                    else
                    matrix[0][j] = 0;
                }
            }
        }


       for(int i = 1 ; i < col ;i++) {
           if(matrix[0][i] == 0) {
               for(int j = 0 ; j < row ; j++) {
                   matrix[j][i] = 0;
               }
           }
       }

       for(int i = 0 ; i < row ; i++) {
           if(matrix[i][0] == 0 ) {
               for(int j = 0 ; j < col ; j++) {
                   matrix[i][j] = 0;
               }
           }
       }


       if(column == 0) {
           for(int i = 0 ; i < row ; i++) {
               matrix[i][0] = 0;
           }
       }

        return;
    }
};