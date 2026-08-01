#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int k=0,i,j;
        while (nums[k] <= 0 && k < nums.size()-2){
            i = k+1;
            j = nums.size()-1;
            while (i < j){
                if (nums[k] + nums[i] + nums[j] < 0){
                    int last_i = i;
                    do {i++;}
                    while (nums[i] == nums[last_i] && i<j);
                }
                else if (nums[k] + nums[i] + nums[j] > 0){
                    int last_j = j;
                    do {j--;}
                    while (nums[j] == nums[last_j] && i<j);
                }
                else{
                    ans.push_back(vector<int>{nums[k], nums[i], nums[j]});
                    int last_i = i;
                    do {i++;}
                    while (nums[i] == nums[last_i] && i<j);
                }
            }
            int last_k = k;
            do {k++;}
            while (k<nums.size()-1 && nums[k] == nums[last_k]);
        }
        return ans;
    }
};