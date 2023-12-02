#include <iostream>
#include <queue>

class RecentCounter {
public:
    RecentCounter() {
    }

    int ping(int t) {
        // 将新请求的时间加入队列
        requestQueue.push(t);

        // 移除时间在 [t-3000, t] 之前的请求
        while (!requestQueue.empty() && requestQueue.front() < t - 3000) {
            requestQueue.pop();
        }

        // 返回当前队列的大小，即 [t-3000, t] 内的请求数
        return static_cast<int>(requestQueue.size());
    }

private:
    std::queue<int> requestQueue;
};

int main() {
    RecentCounter recentCounter;

    std::cout << recentCounter.ping(1) << std::endl; // 返回 1，[1, 1] 内有一个请求
    std::cout << recentCounter.ping(100) << std::endl; // 返回 2，[1, 100] 内有两个请求
    std::cout << recentCounter.ping(3001) << std::endl; // 返回 3，[1, 100, 3001] 内有三个请求
    std::cout << recentCounter.ping(3002) << std::endl; // 返回 3，[100, 3001, 3002] 内有三个请求

    return 0;
}
