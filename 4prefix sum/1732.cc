#include <cstdint>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
class Solution
{
   public:
      int largestAltitude(std::vector<int>& gain)
      {
         int res=0,height=0;
         for(int g=0;g<gain.size();g++)
         {
            height+=gain[g];
            res=std::max(res,height);
         }
         return res;
      }
};
int main() {
   Solution ss;
   std::vector<int> s ={-5,1,5,0,-7}; 
   int res = ss.largestAltitude(s);
   std::cout<<res<<std::endl;
   return 0;
}