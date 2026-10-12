#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int quick_sort(vector<int>& nums, int l, int r, int k){
        if (l==r)
            return nums[k];
        int partition = nums[l], i = l - 1, j = r + 1;

        while (i<j){
            do i++; while (nums[i] < partition);
            do j++; while (nums[j] > partition);
            if (i < j)
            swap(nums[i],nums[j]);
        }

        if (k < j+1) return quick_sort(nums,l,j,k);
        else return quick_sort(nums, j + 1, r, k);
    }

    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        return quick_sort(nums, 0 , n - 1, n - k);
    }
};

//还可以用堆写
class Solution {
    public:
        int findKthLargest(vector<int>& nums, int k) {
            priority_queue<int> heap(nums.begin(), nums.end());
            for (int i = 1; i < k; i++) heap.pop();
            return heap.top();
        }
};