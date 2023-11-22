#include <iostream>
#include <string>
#include <vector>
#include<algorithm>
using namespace std;

class Solution
{
   public:
      string gcdOfStrings(string str1, string str2)
      {
         if(str1+str2!= str2+str1)
         {
            return "";
         }
         else 
         {
            return str1.substr(0, gcd(str1.size(), str2.size()));
         }
      }
      int gcd(int a, int b)
      {
         return b==0 ?a:gcd(b, a%b);
      }

      vector<bool> kidsWithCandies(vector<int>&  candies, int extraCandies)
      {
         int Max=0;
         vector<bool> res;
         Max =*max_element(candies.begin(), candies.end());
         for(int i=0; i<candies.size();i++)
         {
            res.insert(res.end(), candies[i]+extraCandies>=Max?true:false);
         }
         return res;
      }
};
int main() {
   Solution ss;
   vector<int> candies={2,3,5,1,3};
   int extraCan = 3;
   vector<bool>res = ss.kidsWithCandies(candies, extraCan);
   cout<<res<<endl;
   return 0;
}