#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
class Solution
{
   public:
    int maxArea(std::vector<int>& height)
    {
      int size = height.size();
      int left=0,right=size-1;
      int ans=0;
      while(left<right)
      {
         ans=std::max(ans, (right-left)*std::min(height[left],height[right]));
         if(height[left]>height[right]) right--;
         else left++;
      }
      return ans;
    }
};
int main() {
   Solution ss;
   std::vector<int> s ={1,8,6,2,5,4,8,3,7};
   int res = ss.maxArea(s);
   std::cout<<res<<std::endl;
   return 0;
}