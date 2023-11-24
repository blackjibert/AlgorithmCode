#include <cstdint>
#include <iostream>
#include <string.h>
#include <vector>
#include<algorithm>
using namespace std;
class Solution
{
   public:
      int increasingTriplet(vector<int>& nums)
      {
         int a=INT16_MAX;
         int b=INT16_MAX;
         for(auto e:nums)
         {
            if(e<=a)
            {
               a=e;
            }
            else if(e<=b)
            {
               b=e;
            }
            else {
            return true;
            }
         }
         return false;
      }
      
};
int main() {
   Solution ss;
   vector<int> s = {2,1,5,0,4,6};
   bool res = ss.increasingTriplet(s); 
   cout<<res<<endl;
   return 0;
}