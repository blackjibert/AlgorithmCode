#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
class Solution
{
   public:
      int maxOperations(std::vector<int>& nums, int k)
      {
         //排序
         std::sort(nums.begin(), nums.end());
         int ans=0;
         int l=0,r=nums.size()-1;//左右指针指向两边
         while(l<r)
         {
            if(nums[l] + nums[r] <k)
            {
               l++;
            }
            else if(nums[l] + nums[r]>k)
            {
               r--;
            }
            else 
            {
               ans++, l++, r--;
            }
         }
         return ans;
      }
};
int main() {
   Solution ss;
   std::vector<int> s ={3,1,3,4,3};
   int k= 6;
   int res = ss.maxOperations(s,k);
   std::cout<<res<<std::endl;
   return 0;
}