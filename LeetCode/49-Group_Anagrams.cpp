#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;


// class Solution {
// public:
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         vector<vector<string>> ans;
//         unordered_map<unordered_map<char, int>, int> ans_hash;
//         for (string s : strs){
//             unordered_map<char, int> s_hash;
//             for (char c : s) s_hash[c]++;
//             for (auto it = ans_hash.begin(); it != ans_hash.end(); it++){
//                 if (it->first == s_hash){
//                     int pos = ans_hash[*it];
//                     ans[pos].push_back(s);
//                 }
//                 else {
//                     ans_hash[s_hash] = ans_hash.size();
//                     ans.push_back(vector<string> {s});
//                 }
//             }
//         }
//         return ans;
//     }
// };
//上面写法不可行，unordered_map的key必须可以哈希化
//unordered_map支持==和!=比较

class Solution{
    public:
    vector<vector<string>> groupAnagrams(vector<string>& strs){
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> ans_hash;
        for (string s: strs){
            string tmp = s;
            sort(tmp.begin(), tmp.end());
            ans_hash[tmp].push_back(s);
        }

        for (auto& kv: ans_hash) ans.push_back(kv.second);
        return ans;
    }
};