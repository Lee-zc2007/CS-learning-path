//单指针写法，复杂度n方
/*
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0, j;
        int max_area = -1;
        while (i < height.size() - 1){
            j = height.size() - 1;
            int max_area_i = min(height[i], height[j]) * (j - i);
            if (height[i] > height[j]){
                do{j--;}
                while (height[j] < height[i] && j > i);
                max_area_i = max(max_area_i, min(height[i], height[j]) * (j-i));
            }
            max_area = max(max_area, max_area_i);
            i++;
        }
        return max_area;
    }
};
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
    int count_area(int i, int j, vector<int>& height){
        return min(height[i], height[j]) * (j - i);
    }

    int maxArea(vector<int>& height) {
        int i=0, j=height.size()-1;
        int max_area = count_area(i,j,height);
        while (i < j){
            if (height[i] < height[j]) i++;
            else j--;
            int new_area = count_area(i,j,height);
            max_area = max(max_area, new_area);
        }
        return max_area;
    }
};