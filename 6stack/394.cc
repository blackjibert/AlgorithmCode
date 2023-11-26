#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <vector>
class Solution
{
   public:
      std::string decodeString(std::string& s)
      {
         std::stack<int> numStack;
         std::stack<std::string> strStack;
         int num=0;
         std::string currentStr;
         for(char c:s)
         {
            //处理数字, 构建重复次数
            if(std::isdigit(c))
            {
               num = num * 10 + (c-'0');
            }
            else if(c == '[')
            {
               //遇到左括号, 将当前数字和字符串入栈, 并重置变量
               numStack.push(num);
               strStack.push(currentStr);
               num=0;
               currentStr.clear();
            }
            else if (c == ']') {
            // 遇到右括号，出栈数字和字符串，构建重复后的字符串
            int repeatTimes = numStack.top();
            numStack.pop();

            std::string repeatedStr;
            for (int i = 0; i < repeatTimes; ++i) 
            {
                repeatedStr += currentStr;
            }
            // 拼接得到的重复字符串和上一个字符串
            currentStr = strStack.top() + repeatedStr;
            strStack.pop();
            } else {
                  // 处理字母，构建当前字符串
                  currentStr += c;
            }
         }
         return currentStr;
      }
};
int main() {
   Solution ss;
   // std::string s = "3[a2[c]]"; //accaccacc
   std::string s = "3[a]2[bc]"; //aaabcbc
   std::string res = ss.decodeString(s);
   std::cout<<res<<std::endl;
   for(int r:res) std::cout<<r<<" ";
   return 0;
}