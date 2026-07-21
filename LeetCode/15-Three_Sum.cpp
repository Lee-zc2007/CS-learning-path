#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int last_k, k, i, last_i, last_j, j;
        sort(nums.begin(), nums.end());
        last_k = *nums.begin();
        k = 0;
        while (k < nums.size()-1) {
            i = k + 1;
            j = nums.size()-1;
            while (i != j){
                int sum = nums[k] + nums[i] + nums[j];
                last_i = nums[i];
                last_j = nums[j];
                if (sum > 0) {
                    while (nums[j] == last_j) j--;
                }
                else if (sum < 0){
                    while (nums[i] == last_i) i++;
                }
                else {
                    ans.push_back(vector<int> {nums[k], nums[i], nums[j]});
                    while (nums[k] == last_k) k++;
                    last_k = nums[k];
                    break;
                }
            }
        }
        return ans;
    }
};