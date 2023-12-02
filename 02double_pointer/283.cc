#include <iostream>
#include <string.h>
#include <vector>
#include<algorithm>
class Solution
{
   public:
      std::vector<int> moveZeroes(std::vector<int>& nums)
      {  //把当前零删除, 后面再补
         int slow = 0;;
         for(auto fast:nums)
         {
            if(fast != 0) nums[slow++] =fast;
         }
         for(;slow<nums.size();slow++)
         {
            nums[slow]=0;
         }
         return nums;
      }     
};
int main() {
   Solution ss;
   std::vector<int> s = {0,1,2,3,4,0,12};
   std::vector<int> res = ss.moveZeroes(s);
   for(std::vector<int>::iterator m = res.begin(); m != res.end(); m++)
   {
      std::cout<<*m<<" ";
   }
   return 0;
}