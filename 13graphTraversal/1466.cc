#include <iostream>
#include <vector>
#include <stack>

class Solution
{
public:
    int minReorder(int n, std::vector<std::vector<int>> &connections)
    {
        std::vector<std::vector<std::pair<int, bool>>> graph(n); // 邻接表，pair 中的 bool 表示是否需要改变方向(是否可达)
        std::vector<bool> visited(n, false);                     // 用于记录城市是否已访问过

        // 构建有向图的邻接表
        for (auto &connection : connections)
        {
            graph[connection[0]].emplace_back(connection[1], true);  // 0->1 正向路线，不需要改变方向
            graph[connection[1]].emplace_back(connection[0], false); // 1->0 反向路线，需要改变方向
        }

        // 开始深度优先遍历
        int result = 0;
        std::stack<int> cityStack;

        // 将城市 0 标记为已访问
        visited[0] = true;
        cityStack.push(0);

        while (!cityStack.empty())
        {
            int currentCity = cityStack.top();
            cityStack.pop();

            // 遍历当前城市的所有连接城市
            for (auto &neighbor : graph[currentCity])
            {
                int nextCity = neighbor.first;
                bool needReorder = neighbor.second;
                if (!visited[nextCity])
                { // 如果相邻城市未访问过，标记并入栈
                    visited[nextCity] = true;
                    cityStack.push(nextCity);

                    // 如果需要改变方向，增加计数
                    result += needReorder ? 1 : 0;
                }
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    // 示例用法
    int n = 6;
    std::vector<std::vector<int>> connections = {{0, 1}, {1, 3}, {2, 3}, {4, 0}, {4, 5}};

    int result = solution.minReorder(n, connections);

    // 输出结果
    std::cout << "Minimum number of reorderings: " << result << std::endl;

    return 0;
}
