#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_set>

class Solution
{
public:
    // 深度优先遍历
    void dfs(int currentRoom, std::vector<std::vector<int>> &rooms, std::unordered_set<int>& visited, std::stack<int> &roomStack)
    {
        // 将当前房间标记为已访问
        visited.insert(currentRoom);
        std::vector<int> keys = rooms[currentRoom];
        for (int key : keys)
        {
            // 如果钥匙对应的房间未访问过, 则递归访问该房间
            if (visited.find(key) == visited.end())
            {
                dfs(key, rooms, visited, roomStack);
            }

            // 将当前房间入栈, 表示以及完成对该房间的访问
            roomStack.push(currentRoom);
        }
    }
    // 判断是否能够进入所有房间
    bool canVisitAllRooms(std::vector<std::vector<int>> &rooms)
    {
        int n = rooms.size();                   // 二维数组的行数
        std::unordered_set<int> visited;  // 用于记录已访问的房间
        std::stack<int> roomStack; // 用于存放已经访问完成的房间

        // 从0号房间开始深度优先遍历
        dfs(0, rooms, visited, roomStack);
        // 如果访问过的房间数量等于总房间数，说明可以访问所有房间
        return visited.size() == n;
    }
};

int main()
{

    Solution solution;

    // 示例用法
    // std::vector<std::vector<int>> rooms = {{1}, {2}, {3}, {}};
    std::vector<std::vector<int>> rooms = {{1, 3}, {3, 0, 1}, {2}, {0}};
    bool result = solution.canVisitAllRooms(rooms);

    // 输出结果
    std::cout << (result ? "true" : "false") << std::endl;

    return 0;
}