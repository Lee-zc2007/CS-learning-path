#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0, j=0;
        while (i<nums.size()){
            if (nums[i] == 0) i++;
            else {
                nums[j] = nums[i];
                j++;
                i++;
            }
        }

        while (j < nums.size()) nums[j++] = 0;
    }
};