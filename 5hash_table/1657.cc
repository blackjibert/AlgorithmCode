#include <cstdint>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include <algorithm>
class Solution
{
   public:
      bool closeStrings(std::string word1, std::string word2)
      {
         int sz1 = word1.size();
         int sz2 = word2.size();
         std::vector<int> rc1(26, 0), rc2(26, 0); //每个位置对应字母的位置
         for(int i=0;i<sz1;i++)
         {
            rc1[word1[i]-'a']++;
            rc2[word2[i]-'a']++;
         }
         for(int i=0;i<26;i++)
         {
            if((rc1[i] ==0 && rc2[i]!=0) ||  (rc1[i] !=0 && rc2[i]==0)) return false;
         }
         std::sort(rc1.begin(), rc1.end());
         std::sort(rc2.begin(), rc2.end());
         return rc1 == rc2;
      }
};
int main() {
   Solution ss;
   // std::string s1="abcde", s2="aecdb"; //
   std::string s1="aacabb", s2="bbcbaa";
   bool res = ss.closeStrings(s1,s2);
   std::cout<<res<<std::endl;
   return 0;
}