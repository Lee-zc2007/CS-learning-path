#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int left = 0;
        int right = 0;
        unordered_map<char, int> count;
        unordered_map<char,int> target;
        vector<int> ans;

        if (s.size() < p.size() || s.size()==0) return ans;

        for (int i=0; i<p.length();i++){
            target[p[i]]++;
        }

        while (right < p.length()){
            count[s[right]]++;
            right++;
        }


        while (left < s.length() - p.length() + 1){
            if (count == target) ans.push_back(left);
            count[s[left]]--;
            if (count[s[left]] == 0) count.erase(s[left]);
            left++;
            count[s[right]]++;
            right++;
        }

        return ans;
    }
};