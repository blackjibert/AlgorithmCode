#include <iostream>
#include <string.h>
#include <vector>
#include<algorithm>
using namespace std;
class Solution
{
   public:
      string reverseVowels(string s)
      {
         string str = "aeiouAEIOU";
         int l=0;             //左指针
         int r = s.size()-1;  //右指针
         while(l<r)           //str.find("a"),字符不在字符串中返回-1
         {
            if((str.find(s[l])!=-1) && (str.find(s[r]) != -1))
            {
               //两边都为元音字母
               swap(s[l],s[r]);
               l++;
               r--;
            }
            if((str.find(s[l]!=-1) && (str.find(s[r]) ==-1)))
            {
               //左边是，右边不是
               r--;
            }
            if((str.find(s[l]==-1) && (str.find(s[r]) !=-1)))
            {
               //左边不是，右边是
               l++;
            }
            if((str.find(s[l]==-1) && (str.find(s[r]) ==-1)))
            {
               //两边都不是
               l++;
               r--;
            }
         }
         return s;
      }
};
int main() {
   Solution ss;
   string  s= "hello";
   string res = ss.reverseVowels(s); //holle
   cout<<res<<endl;
   return 0;
}