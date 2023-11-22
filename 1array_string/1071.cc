/*
辗转相除法，也称为欧几里德算法，是用于计算两个整数的最大公约数（GCD）的一种常见方法。
基本原理是根据欧几里德定理，如果两个整数a和b满足b不为零，
则它们的最大公约数等于 b和 a除以b的余数的最大公约数。
这个过程不断迭代，直到余数为零，此时的除数即为最大公约数。
*/
#include <iostream>
#include <string.h>
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
};
int main() {
   Solution ss;
   string aa = "ABABAB";
   string bb = "ABAB";
   string a = ss.gcdOfStrings(aa, bb);
   cout<<a<<endl;
   return 0;
}