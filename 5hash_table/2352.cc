#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
class Solution
{
   public:
      int equalPairs(std::vector<std::vector<int>>& grid)
      {
         int ans=0;
         std::vector<std::vector<int>> grid2(grid.size(), std::vector<int>(grid.size())); //创建一个和grid具有相同行数和列数的二维整数向量，并用0初始化所有的元素。
         for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid.size(); j++)
                grid2[i][j] = grid[j][i];
         for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid.size(); j++)
                if (grid[i] == grid2[j])
                    ans++;
         return ans;
      }
};
int main() {
   Solution ss;
   std::vector<std::vector<int>> s={{3,1,2,2},{1,4,4,5},{2,4,2,2},{2,4,2,2}};
   int res = ss.equalPairs(s);
   std::cout<<res<<std::endl;
   return 0;
}