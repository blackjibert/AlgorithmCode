#include <cstdint>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
class Solution
{
   public:
      int longestOnes(std::vector<int>& nums, int k)
      {
         int left=0, right=0;
         int res=0;
         while(right<nums.size())
         {
            if(nums[right] == 0) k--;
            right ++;
            while(k < 0)
            {
               //左边需要收缩
               if(nums[left] == 0) k++;
               left++;
            }
            res = std::max(res, right-left);
         }
         return res;
      }
      
};
int main() {
   Solution ss;
   std::vector<int> s ={1,1,1,0,0,0,1,1,1,1,0}; 
   int k= 2;
   int res = ss.longestOnes(s,k);
   std::cout<<res<<std::endl;
   return 0;
}