#include <iostream>
#include <string.h>
#include <vector>
#include<algorithm>
using namespace std;
class Solution
{
   public:
      vector<int> productExceptSelf(vector<int>& nums)
      {
         int n=nums.size();
         int left=1, right=1; //left:从左边累乘, right:从右边累乘
         vector<int> res(n, 1);//定义长度为n的res, 默认值为1
         for(int i=0;i<n;i++)
         {
            res[i]*=left; //乘其左边的乘积
            left*=nums[i];

            res[n-1-i]*=right; //乘其右边的乘积
            right*=nums[n-1-i];
         }
         return res;
      }
      
};
int main() {
   Solution ss;
   vector<int> s = {4,3,2,1};
   vector<int> res = ss.productExceptSelf(s); 
   cout<<res<<endl;
   return 0;
}