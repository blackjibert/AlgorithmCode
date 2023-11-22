#include <iostream>
#include <string.h>
using namespace std;

class Solution
{
   public:
      string mergeAlternately(string& word1, string& word2)
      {
         string res = "";
         int index=0;
         while(index<word1.length() || index<word2.length())
         {
            if(index<word1.length())
            {
               res+=word1[index];
            }
            if(index<word2.length())
            {
               res+=word2[index];
            }
            index++;
         }
         return res;
      }
};
int main() {
   Solution ss;
   string aa = "abckkkkk";
   string bb = "ef";
   string a = ss.mergeAlternately(aa, bb);
   cout<<a<<endl;
   return 0;
}