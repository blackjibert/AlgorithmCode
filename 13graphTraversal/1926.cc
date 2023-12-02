#include <iostream>
#include <vector>
#include <queue>

class Solution {
public:
    int nearestExit(std::vector<std::vector<char>>& maze, std::vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();
        int entranceRow = entrance[0];
        int entranceCol = entrance[1];

        // 用于表示四个方向的偏移量
        std::vector<std::pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        // 创建一个队列，用于广度优先遍历
        std::queue<std::pair<int, int>> bfsQueue;
        bfsQueue.push({entranceRow, entranceCol});

        // 创建一个二维数组，用于记录节点是否被访问过
        std::vector<std::vector<bool>> visited(m, std::vector<bool>(n, false));
        visited[entranceRow][entranceCol] = true;

        // 调用广度优先遍历函数
        int result = bfs(maze, entranceRow, entranceCol, bfsQueue, visited, directions);

        return result;
    }

private:
    // 广度优先遍历的函数
    int bfs(std::vector<std::vector<char>>& maze, int entranceRow, int entranceCol, std::queue<std::pair<int, int>>& bfsQueue,
            std::vector<std::vector<bool>>& visited, const std::vector<std::pair<int, int>>& directions) {
        int m = maze.size();
        int n = maze[0].size();

        int steps = 0;
        while (!bfsQueue.empty()) {
            int size = bfsQueue.size();

            // 遍历当前层的所有节点
            for (int i = 0; i < size; ++i) {
                int currentRow = bfsQueue.front().first;
                int currentCol = bfsQueue.front().second;
                bfsQueue.pop();

                // 如果当前节点位于迷宫边界且不是入口，则返回步数
                if ((currentRow != entranceRow || currentCol != entranceCol) &&
                    (currentRow == 0 || currentRow == m - 1 || currentCol == 0 || currentCol == n - 1)) {
                    return steps;
                }

                // 尝试四个方向移动
                for (const auto& dir : directions) {
                    int newRow = currentRow + dir.first;
                    int newCol = currentCol + dir.second;

                    // 检查新位置是否有效且未访问过
                    if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n &&
                        maze[newRow][newCol] == '.' && !visited[newRow][newCol]) {
                        bfsQueue.push({newRow, newCol});
                        visited[newRow][newCol] = true;
                    }
                }
            }

            // 步数增加
            ++steps;
        }

        // 如果遍历完整个迷宫都没有找到出口，则返回 -1
        return -1;
    }
};

int main() {
    Solution solution;

    // 示例用法
    std::vector<std::vector<char>> maze = {
        {'+', '+', '.', '+'},
        {'.', '.', '.', '+'},
        {'+', '+', '+', '.'},
    };
    std::vector<int> entrance = {1, 2};

    int result = solution.nearestExit(maze, entrance);

    // 输出结果
    std::cout << "Minimum steps to nearest exit: " << result << std::endl;

    return 0;
}
