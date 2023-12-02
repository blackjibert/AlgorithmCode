#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
class Solution
{
   public:
     bool isSubsequence(std::string& s, std::string& t)
     {
        int i=0;
        for(int j=0;i<s.length()&&j<t.length();j++)
        {
           if(s[i] == t[j])
           {
              i++;
           }
        }
        return i ==s.length();
     }   
};
int main() {
   Solution ss;
   std::string s = "abc";
   std::string t = "ahbgdc";
   bool res = ss.isSubsequence(s, t);
   std::cout<<res<<std::endl;
   return 0;
}