#include <cstdint>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
class Solution
{
   public:
      int pivotIndex(std::vector<int>& nums)
      {
         int sum=0;
         int sumleft=0;
         for(int i=0;i<nums.size();i++)
         {
            sum+=nums[i];
         }
         for(int i=0;i<nums.size();i++)
         {
            if(sumleft*2 + nums[i] == sum) return i;
            sumleft+=nums[i];
         }
         return -1;
      }  
};
int main() {
   Solution ss;
   std::vector<int> s ={1,7,3,6,5,6}; 
   int res = ss.pivotIndex(s);
   std::cout<<res<<std::endl;
   return 0;
}