#include <cstdint>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include <algorithm>
class Solution
{
   public:
      bool uniqueOccurrences(std::vector<int>& arr)
      {
         std::vector<int> v1;
         int count=0;
         std::sort(arr.begin(), arr.end());//排序, 从小到大
         for(int i=0;i<arr.size()-1;i++)//两两对比
         {
            count+=1;
            if(arr[i] != arr[i+1])
            {
               v1.push_back(count);
               count=0;
            }
         }
         std::sort(v1.begin(),v1.end());
         for (int i=0; i<v1.size()-1; i++) //两两对比
         {
            if(v1[i] == v1[i+1])
            {
               return false;
            }
         }
         return true;
      }
};
int main() {
   Solution ss;
   std::vector<int> s={1,2,2,1,1,3}; 
   bool res = ss.uniqueOccurrences(s);
   std::cout<<res<<std::endl;
   return 0;
}