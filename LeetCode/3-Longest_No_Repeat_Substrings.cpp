#include <unordered_map>
#include <string>
using namespace std;

//用滑动窗口写
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> count;
        int left = 0;
        int maxlength = 0;

        for (int right = 0; right < s.length(); right++){
            count[s[right]]++;
            while (count[s[right]] > 1){
                count[s[left]]--;
                left++;
            }

            maxlength = max(maxlength, right - left + 1);
        }

        return maxlength;
    }
};