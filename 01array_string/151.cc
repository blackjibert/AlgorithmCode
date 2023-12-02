#include <iostream>
#include <string.h>
#include <vector>
#include<algorithm>
using namespace std;
class Solution
{
   public:
      string reversWords(string s)
      {  
         int p1 = s.size()-1;
         int p2 = s.size()-1;
         string t="";
         while(p2>=0)
         {
            while(p1>=0&&s[p1]==' ')
            {  
               //清除左端的空格
               p1--;
            }
            p2=p1;
            while(p2>=0 && s[p2]!= ' ')
            {
               //清楚右端的空格
               p2--;
            }
            for(int i=p2+1;i<=p1;i++)
            {
               t+=s[i];
            }
            t+=' ';
            p1= p2;
            //cout<<t<<endl;
         }
         while(t[t.size()-1]==' ')
         {
            t.erase(t.size()-1);
         }
         return t;
      }
      
};
int main() {
   Solution ss;
   string  s= " hello word "; 
   string res = ss.reversWords(s); //holle
   cout<<res<<endl;
   return 0;
}