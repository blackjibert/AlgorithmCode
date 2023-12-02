#include <cstdint>
#include <iostream>
#include <string.h>
#include <vector>
#include<algorithm>
using namespace std;
class Solution
{
   public:
      int compress(vector<char>& chars)
      {  
         int len=0;
         for(int i=0,cnt=1;i<chars.size();i++,cnt++)
         {
            if(i+1 ==chars.size() || chars[i] != chars[i+1])
            {
               chars[len++] = chars[i];
               if(cnt>1)
               {
                  for(char ch:to_string(cnt))
                  {//个数cnt可能为多位数
                     chars[len++]=ch;
                  }
               }
               cnt=0;
            }
         }
         return len;
      }
      
};
int main() {
   Solution ss;
   vector<char> s = {'a','b','b','b','b','b','b','b','b','b','b'};//{'a','b','1','2'}
   int res = ss.compress(s); 
   cout<<res<<endl;
   return 0;
}