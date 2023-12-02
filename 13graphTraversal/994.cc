#include <iostream>
#include <vector>
#include <queue>

class Solution
{
public:
    int orangesRotting(std::vector<std::vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        // 用于表示四个方向的偏移量
        std::vector<std::pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        // 创建一个队列，用于广度优先遍历
        std::queue<std::pair<int, int>> bfsQueue;

        // 统计新鲜橘子的数量
        int freshCount = 0;

        // 将所有腐烂橘子的位置入队，并统计新鲜橘子的数量
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 2)
                {
                    bfsQueue.push({i, j});
                }
                else if (grid[i][j] == 1)
                {
                    ++freshCount;
                }
            }
        }

        // 如果初始状态下没有新鲜橘子，直接返回0
        if (freshCount == 0)
        {
            return 0;
        }

        // 调用广度优先遍历函数
        int result = bfs(grid, bfsQueue, freshCount, directions);

        // 如果还有新鲜橘子剩余，返回-1；否则返回经过的分钟数
        return (freshCount == 0) ? result : -1;
    }

private:
    // 广度优先遍历的函数
    int bfs(std::vector<std::vector<int>> &grid, std::queue<std::pair<int, int>> &bfsQueue, int &freshCount,
            const std::vector<std::pair<int, int>> &directions)
    {
        int m = grid.size();
        int n = grid[0].size();

        int minutes = 0;
        while (!bfsQueue.empty())
        {
            int size = bfsQueue.size();

            // 遍历当前层的所有节点
            for (int i = 0; i < size; ++i)
            {
                int currentRow = bfsQueue.front().first;
                int currentCol = bfsQueue.front().second;
                bfsQueue.pop();

                // 尝试四个方向移动
                for (const auto &dir : directions)
                {
                    int newRow = currentRow + dir.first;
                    int newCol = currentCol + dir.second;

                    // 检查新位置是否有效且有新鲜橘子
                    if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n &&
                        grid[newRow][newCol] == 1)
                    {
                        // 腐烂新鲜橘子
                        grid[newRow][newCol] = 2;
                        --freshCount;
                        bfsQueue.push({newRow, newCol});
                    }
                }
            }

            // 如果这一轮有新鲜橘子腐烂，增加分钟数
            if (!bfsQueue.empty())
            {
                ++minutes;
            }
        }

        return minutes;
    }
};

int main()
{
    Solution solution;

    // 示例用法
    // std::vector<std::vector<int>> grid = {
    //     {2,1,1},
    //     {1,1,0},
    //     {0,1,1}
    // };
    std::vector<std::vector<int>> grid = {
        {2, 1, 1},
        {0, 1, 0},
        {1, 0, 1}};

    int result = solution.orangesRotting(grid);

    // 输出结果
    std::cout << "Minutes to rot all oranges: " << result << std::endl;

    return 0;
}
