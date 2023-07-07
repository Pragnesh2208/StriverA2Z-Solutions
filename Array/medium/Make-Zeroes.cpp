/*
Time Complexity = O(N * M)
Space Complexity = O(N*Ms)
*/

//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
     void MakeZeros(vector<vector<int> >& matrix) {
        // Code here
        
        int n = matrix.size();
        int m = matrix[0].size();
        vector<pair<int , pair<int,int>>> zeroPos;
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                if(matrix[i][j] == 0) {
                    int sum = 0;
                    if( j  - 1>=0) {
                        sum += matrix[i][j - 1];
                    } 
                    if( j + 1 < m) {
                        sum += matrix[i][j+1];
                    }
                    if(i - 1 >= 0  ) {
                        sum += matrix[i -1][j ];
                    }
                    if(i + 1 < n ) {
                        sum += matrix[i+1][j];
                    }
                     zeroPos.push_back({sum , {i , j}});
                }
            }
        }
        
        for(int i = 0 ; i < zeroPos.size() ; i++) {
            int firstIndex = zeroPos[i].second.first;
            int secondIndex = zeroPos[i].second.second;
            int sum = zeroPos[i].first;
            
            if(firstIndex - 1 >=0 ){
                matrix[firstIndex - 1][secondIndex] = 0;
            }
            
            if(firstIndex + 1 < n ) {
                matrix[firstIndex + 1][secondIndex] = 0;
            }
            
            if(secondIndex + 1 < m ) {
                matrix[firstIndex][secondIndex + 1] = 0;
            }
            
            if(secondIndex - 1 < m ) {
                matrix[firstIndex][secondIndex - 1] = 0;
            }
            
            matrix[firstIndex][secondIndex] = sum;
        }
        return ;
    }

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		ob.MakeZeros(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cout << matrix[i][j] <<" ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends