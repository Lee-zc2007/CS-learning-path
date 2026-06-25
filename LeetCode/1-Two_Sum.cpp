#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        for (int i = 0; i < nums.size()-1; i++){
            for (int j = i+1; j < nums.size(); j++){
                if (nums[i] + nums[j] == target){
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
            }
        }
    return ans;//必须有，否则编译器认为在没有找到ans的时候无返回值，会报错
    }
};


#include <unordered_map>
class Solution{
    public:
        vector<int> twoSum_byhash(vector<int>& nums, int target) {
            unordered_map<int, int> pos;
            for (int i = 0; i < nums.size(); i++){
                int need = target - nums[i];
                if (pos.find(need) != pos.end()){
                    return {pos[need], i};
                }

                pos[nums[i]] = i;
            }

            return {};
        }
};
//使用哈希表时间和空间都是O(n)，其中把下标作为value，nums中值作为key，逐个添加到pos，因为只有一个答案，所以每次添加一个搜一次，找到就可以停止