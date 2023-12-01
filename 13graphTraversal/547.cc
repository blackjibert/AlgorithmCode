#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        int provinces = 0;              // 记录省份数量
        vector<bool> visited(n, false); // 用于记录城市是否已访问过

        for (int i = 0; i < n; ++i)
        {
            if (!visited[i])
            {
                // 如果当前城市未访问过，开始深度优先遍历
                dfs(i, isConnected, visited);
                provinces++;
            }
        }
        return provinces;
    }

private:
    void dfs(int city, vector<vector<int>> &isConnected, vector<bool> &visited)
    {
        stack<int> cityStack; // 用于存放已访问的城市

        // 将当前城市标记为已访问
        visited[city] = true;

        // 将当前城市入栈
        cityStack.push(city);

        while (!cityStack.empty())
        {
            int currentCity = cityStack.top();
            cityStack.pop();

            // 遍历当前城市的所有连接城市
            for (int neighbor = 0; neighbor < isConnected.size(); ++neighbor)
            {
                if (isConnected[currentCity][neighbor] == 1 && !visited[neighbor])
                {
                    // 如果相邻城市未访问过，标记并入栈
                    visited[neighbor] = true;
                    cityStack.push(neighbor);
                }
            }
        }
    }
};

int main()
{
    Solution solution;

    // 示例用法
    // vector<vector<int>> isConnected = {{1,1,0},{1,1,0},{0,0,1}};
    vector<vector<int>> isConnected = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};

    int result = solution.findCircleNum(isConnected);

    // 输出结果
    cout << "Number of provinces: " << result << endl;

    return 0;
}
