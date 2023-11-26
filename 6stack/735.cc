#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <vector>
class Solution
{
   public:
      std::vector<int> asteroidCollision(std::vector<int>& asteroids)
      {
         std::stack<int> asteroidStack;
         for(int asteroid: asteroids)
         {
            //处理右向行星, 直接入栈
            if(asteroid > 0) asteroidStack.push(asteroid);
            else
            {
               //处理左向行星
               while(!asteroidStack.empty() && asteroidStack.top()>0)
               {
                  //发生碰撞,较小的行星爆炸
                  int rightAsteroid = asteroidStack.top();
                  asteroidStack.pop();
                  if(rightAsteroid + asteroid == 0)
                  {
                     //相等大小的行星都会爆炸
                     break;// 左向行星也会爆炸, 结束内循环
                  }
                  else if(rightAsteroid + asteroid > 0)
                  {
                     // 右向行星较大，左向行星爆炸
                     asteroidStack.push(rightAsteroid);
                     break;  // 左向行星爆炸，结束内循环
                  }
                  // 右向行星较小，继续弹出栈中的右向行星
               }
            }
         }
         //构建结果向量
         std::vector<int> result;
         while(!asteroidStack.empty())
         {
            result.insert(result.begin(), asteroidStack.top());
            asteroidStack.pop();
         }
         return result;
      }
};
int main() {
   Solution ss;
   std::vector<int> s = {5,10,-5};
   std::vector<int> res = ss.asteroidCollision(s);
   for(int r:res) std::cout<<r<<" ";
   return 0;
}