#include <vector>
using namespace std;

#用DP写 拆成每格的存量
class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> leftMax;
        vector<int> rightMax;
        int n = height.size();
        int volume = 0;
        
        leftMax.push_back(height[0]);
        for (int i = 1; i < n; i++){
            leftMax.push_back(max(height[i], leftMax[i-1]));
            rightMax.push_back(0);
        }

        rightMax.push_back(height[n - 1]);
        for (int i = n - 2; i >= 0; i--){
            rightMax[i] = max(height[i], rightMax[i+1]);
            volume += min(rightMax[i], leftMax[i]) - height[i];
        }

        return volume;
    }
};