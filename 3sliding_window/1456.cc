#include <cstdint>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
class Solution
{
   public:
      int maxVowels(std::string s, int k)
      {
         //双指针法, 滑动窗口, 快慢指针
         int maxVow = INT16_MIN;
         int mySize=0;//最大元音字母数
         int j=0;
         for(int i=0;i<s.length();i++) //string类的size和length没有区别,都是返回字节数
         {
            if(s[i] =='a' || s[i] == 'e' || s[i] =='i' || s[i] =='o' || s[i] =='u')
            {
               mySize++;
            }
            if(i-j+1 == k)
            {
               if(mySize>maxVow) maxVow = mySize;
               if(s[j] =='a' || s[j] == 'e' || s[j] =='i' || s[j] =='o' || s[j] =='u')
               {
                  mySize --;
                  j++;
               }
               else 
               {
                  j++;
               }

            }
         }
         return maxVow;
      }
};
int main() {
   Solution ss;
   std::string s ="leetcode"; 
   int k= 4;
   int res = ss.maxVowels(s,k);
   std::cout<<res<<std::endl;
   return 0;
}