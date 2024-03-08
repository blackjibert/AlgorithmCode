#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

// 通过矩阵转置后再将每行旋转;
class Solution {
public:
    vector<vector<int> > rotateMatrix(vector<vector<int>>& mat, int n) {
        // write code here
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                swap(mat[i][j],mat[j][i]);
            }
        }
        for(int i = 0; i < n; i++)
        {
            reverse(mat[i].begin(),mat[i].end());
        }
        return mat;
    }
};

int main() {
   Solution ss;
   vector<vector<int>> mat = {{9,8,7},{6,5,4},{3,2,1}};
   int n = 3;
   vector<vector<int>>res = ss.rotateMatrix(mat, n);

   for( int i=0; i<res.size(); i++ ) 
   {
        for( int j=0; j<res[0].size(); j++ ){
            cout<<res[i][j] << " ";
        }
        cout<<endl;
    }
   return 0;
}