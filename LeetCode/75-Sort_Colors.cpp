#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int p0 = 0;
        int p1 = 0;
        for (int i=0; i<nums.size(); i++){
            if (nums[i] == 2){
                continue;
            }
            else if (nums[i] == 1){
                nums[i] = nums[p1];
                nums[p1] = 1;
                p1++;
            }
            else if (nums[i]==0){
                nums[i] = nums[p0];
                nums[p0] = 0;
                if (p0 < p1) {
                    nums[i] = nums[p1];
                    nums[p1] = 1;
                }
                p0++;
                p1++;
            }
        }
    }
};