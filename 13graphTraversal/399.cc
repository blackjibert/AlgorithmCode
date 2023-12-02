#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>

class Solution
{
private:
    std::unordered_map<std::string, std::unordered_map<std::string, double>> graph; // 有向图，使用邻接表表示

    // 构建有向图
    void buildGraph(std::vector<std::vector<std::string>> &equations, std::vector<double> &values)
    {
        for (int i = 0; i < equations.size(); i++)
        {
            std::string &from = equations[i][0];
            std::string &to = equations[i][1];
            double value = values[i];

            // 添加正向边
            graph[from][to] = value;

            // 添加反向边
            graph[to][from] = 1.0 / value;
        }
    }

    // 深度优先遍历
    double dfs(std::string &start, std::string &end)
    {
        std::stack<std::pair<std::string, double>> dfsStack;
        std::unordered_set<std::string> visited;

        // 将起始变量入栈
        dfsStack.push({start, 1.0});
        visited.insert(start);

        while (!dfsStack.empty())
        {
            auto current = dfsStack.top();
            dfsStack.pop();

            std::string &currentNode = current.first;
            double currentProduct = current.second;

            // 如果到达目标变量, 返回累积的乘机
            if (currentNode == end)
            {
                return currentProduct;
            }

            // 遍历当前变量的所有邻接变量
            for (auto &neighbor : graph[currentNode])
            {
                const std::string &nextNode = neighbor.first;
                const double nextProduct = currentProduct * neighbor.second;

                // 如果邻接变量未访问过，入栈并标记为已访问
                if (visited.find(nextNode) == visited.end())
                {
                    dfsStack.push({nextNode, nextProduct});
                    visited.insert(nextNode);
                }
            }
        }
        // 如果遍历完图都没有到达目标变量，返回 -1.0
        return -1.0;
    }

public:
    std::vector<double> calcEquation(std::vector<std::vector<std::string>> &equations, std::vector<double> &values, std::vector<std::vector<std::string>> &queries)
    {
        // 构建有向图
        buildGraph(equations, values);

        // 处理查询
        std::vector<double> results;
        for (auto &query : queries)
        {
            std::string start = query[0];
            std::string end = query[1];

            // 如果查询中的变量不存在于图中, 结果为-1.0
            if (graph.find(start) == graph.end() || graph.find(end) == graph.end())
            {
                results.push_back(-1.0);
            }
            else
            {
                // 否则进行深度优先遍历
                results.push_back(dfs(start, end));
            }
        }
        return results;
    }
};

int main()
{
    Solution solution;

    // 示例用法
    std::vector<std::vector<std::string>> equations = {{"a", "b"}, {"b", "c"}};
    std::vector<double> values = {2.0, 3.0};
    std::vector<std::vector<std::string>> queries = {{"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}};

    std::vector<double> results = solution.calcEquation(equations, values, queries);

    // 输出结果
    std::cout << "Results: ";
    for (const double &result : results)
    {
        std::cout << result << " ";
    }
    std::cout << std::endl;

    return 0;
}
