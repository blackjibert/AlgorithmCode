#include <cstdint>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
class Solution
{
public:
   double findMaxAverate(std::vector<int> &nums, int k)
   {
      int sum = 0, maxi = INT16_MIN;
      for (int i = 0; i < nums.size(); i++)
      {
         sum += nums[i];
         if (i >= k)
         {
            sum -= nums[i - k];
         }
         if (i + 1 > k)
         {
            maxi = std::max(sum, maxi);
         }
      }
      return maxi / (double)k;
   }
};
int main()
{
   Solution ss;
   std::vector<int> s = {1, 12, -5, -6, 50, 3};
   int k = 4;
   double res = ss.findMaxAverate(s, k);
   std::cout << res << std::endl;
   return 0;
}