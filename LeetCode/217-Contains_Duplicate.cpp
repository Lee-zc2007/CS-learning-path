#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i=0; i<nums.size()-1; i++){
            if (nums[i] == nums[i+1]) return true;
        }
        return false;
    }
};
//时间O(nlogn) 空间O(logn)
//改成哈希一次遍历加入可以优化到时间O(n) 空间O(n)