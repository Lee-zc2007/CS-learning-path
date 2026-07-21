#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> frequency;
        for (int i : nums){
            frequency[i]++;
        }
        vector<pair<int, int>> v(frequency.begin(), frequency.end());
        sort(v.begin(), v.end(), [](auto &a, auto &b){
            return a.second > b.second;
        });
        vector<int> ans;
        for (int i = 0; i < k; i++){
            ans.push_back(v[i].first);
        }//用lambda表达式
        return ans;
    }
};