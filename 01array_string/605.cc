#include <iostream>
#include <string.h>
#include <vector>
#include<algorithm>
using namespace std;
class Solution
{
   public:
      bool canPlaceFlowers(vector<int>& flowerbed, int n)
      {
         int ans =0;
         //检查当前位置（flowerbed[i]）是否为空（等于 0）。如果当前位置的下一个位置越界或为空（i + 1 == flowerbed.size() || flowerbed[i + 1] == 0）。如果当前位置的前一个位置越界或为空（i == 0 |flowerbed[i - 1] == 0）。
         for(int i=0; i<flowerbed.size();i++)
         {
            if(flowerbed[i]==0 
            && (i+1 == flowerbed.size() || flowerbed[i+1] ==0)
            && (i == 0) ||flowerbed[i-1] ==0 ) 
            {
               flowerbed[i] =1;
               ans++;
            }
         }
      return ans>n;
      }
};
int main() {
   Solution ss;
   vector<int> flowerbed={1,0,0,0,1};
   int n = 1;
   bool res = ss.canPlaceFlowers(flowerbed, n);
   cout<<res<<endl;
   return 0;
}