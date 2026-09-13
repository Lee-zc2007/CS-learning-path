#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp; //前缀和为key 值为出现次数
        mp[0] = 1;
        int count = 0;
        int pre = 0;
        for (auto& x : nums){
            pre += x;
            if (mp.find(pre - k) !=mp.end()){
                count += mp[pre - k];
            }
            mp[pre]++;
        }
        return count;
    }
};