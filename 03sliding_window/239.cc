#include <iostream>
#include <vector>
#include <queue> 
#include <algorithm>
class Solution {
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
        int n = nums.size();
        std::priority_queue<std::pair<int, int>> q;
        for (int i = 0; i < k; ++i) {
            q.emplace(nums[i], i);
        }
        std::vector<int> ans = {q.top().first};
        for (int i = k; i < n; ++i) {
            q.emplace(nums[i], i);
            while (q.top().second <= i - k) {
                q.pop();
            }
            ans.push_back(q.top().first);
        }
        return ans;
    }
};
int main()
{   
    Solution ss;
    std::vector<int> s = {1,3,-1,-3,5,3,6,7};
    int k =3;
    std::vector<int> res = ss.maxSlidingWindow(s, k);
    for (auto i = res.begin(); i != res.end(); i++) 
    {
        std::cout << *i << ' ';
    }
    std::cout<<std::endl;
    return 0;
}