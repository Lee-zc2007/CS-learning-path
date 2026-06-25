#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int count[26] = {0};
        for (auto it = s.begin(); it != s.end(); it++) count[*it-97]++;
        for (auto it = t.begin(); it != t.end(); it++) count[*it-97]--;
        for (int i=0; i < 26; i++) if (count[i]) return false;
        return true;
    }
};

//可以增加长度判断 s.size() != t.size()直接为false
//for (char c: s) count[c - 'a'] 可以用于遍历,'a'可读性更好
//第二次遍历可以提前 if (--count[c - 'a'] < 0) return false;


//如果有unicode就必须用hash

class Solution {
    public:
        bool isAnagram_byhash(u32string s, u32string t){
            if (s.length() != t.length()) return false;

            unordered_map<char32_t, int> count;
            for (char32_t c: s) count[c]++;
            for (char32_t c: t) {
                if (--count[c] < 0) return false;
            }
            return true;
        }
};

//char32_t用于存放unicode码点，char通常存放一个字节，utf-8下遍历中文是遍历字节，char32_t固定4字节