class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set;
        for (const int num : nums){
            num_set.insert(num);
        }

        int longest_chain = 0;

        for (const int num : num_set){
            if (!num_set.count(num-1)){
                int currentNum = num;
                int currentChain = 1;

            while (num_set.count(currentNum + 1)){
                currentNum += 1;
                currentChain += 1;
            }
            

            longest_chain = max(longest_chain, currentChain);
            }
        }

        return longest_chain;
    }
};

//存入哈希直接查找