#include <vector>
using namespace std;

//动态规划拆解问题 考虑每个元素作为结尾的字串

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = nums[0];
        for (int i=1; i < nums.size(); i++){
            if (nums[i-1] > 0) nums[i] += nums[i-1];
            if (nums[i] > max_sum) max_sum = nums[i];
        }
        return max_sum;
    }
};
