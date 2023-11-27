#include <iostream>
#include <queue>

class Solution {
public:
    std::string predictPartyVictory(std::string senate) {
        std::queue<int> radiant, dire;
        int n = static_cast<int>(senate.size());

        // 将 Radiant 和 Dire 分别加入队列
        for (int i = 0; i < n; ++i) {
            if (senate[i] == 'R') {
                radiant.push(i);
            } else {
                dire.push(i);
            }
        }

        while (!radiant.empty() && !dire.empty()) {
            int radiantFront = radiant.front();
            int direFront = dire.front();

            radiant.pop();
            dire.pop();

            // 如果 Radiant 的参议员编号小于 Dire 的参议员编号，则将 Radiant 参议员加入队列，否则将 Dire 参议员加入队列
            if (radiantFront < direFront) {
                radiant.push(radiantFront + n);
            } else {
                dire.push(direFront + n);
            }
        }

        // 根据队列是否为空判断哪一方最终获胜
        return radiant.empty() ? "Dire" : "Radiant";
    }
};

int main() {
    Solution ss;
    std::string senate = "RDD";
    std::string result = ss.predictPartyVictory(senate);
    std::cout << result << std::endl;

    return 0;
}
