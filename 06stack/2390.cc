#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
class Solution
{
public:
   std::string removeStars(std::string &s)
   {
      std::stack<char> charStack;
      for (char c : s)
      {
         if (c == '*') // 如果当前字符是星号，弹出栈顶的非星号字符
         {
            if (!charStack.empty())
            {
               charStack.pop();
            }
         }
         else // 如果当前字符不是星号，将其入栈
         {
            charStack.push(c);
         }
      }
      // 构建最终的字符串
      std::string result;
      while (!charStack.empty())
      {
         result = charStack.top() + result;
         charStack.pop();
      }
      return result;
   }
};
int main()
{
   Solution ss;
   // std::string s="leet**cod*e"; //"lecoe"
   std::string s = "erase*****"; //""
   std::string res = ss.removeStars(s);
   std::cout << res << std::endl;
   return 0;
}