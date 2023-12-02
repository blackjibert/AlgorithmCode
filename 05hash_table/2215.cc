#include <cstdint>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include <algorithm>
class Solution
{
   public:
      std::vector<std::vector<int>> findDifference(std::vector<int>&num1, std::vector<int>&num2)
      {
         std::unordered_set<int> n1, n2; //去重
         for(int n:num1) n1.insert(n);
         for(int n:num2) n2.insert(n);
         std::vector<int> v1, v2;
         for(int n:n1)
         {
            if(!n2.count(n)) v1.push_back(n);
         }
         for(int n:n2)
         {
            if(!n1.count(n)) v2.push_back(n);
         }
         std::vector<std::vector<int>> ans;
         ans.push_back(v1);
         ans.push_back(v2);
         return ans;
      }
};
int main() {
   Solution ss;
   std::vector<int> num1={1,2,3},num2={2,4,6}; 
   std::vector<std::vector<int>> res = ss.findDifference(num1, num2);
   for(std::vector<int> r: res)
   {  
         for(int a:r) std::cout<<a<<" ";
         std::cout<<std::endl;
   }
   return 0;
}