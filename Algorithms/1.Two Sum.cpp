class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        if (nums.size() == 0)
            return *new vector<int>(0, 0);
        map<int, size_t> hash;
        for (int i = 0; i < nums.size(); ++i) {
            int other = target - nums[i];
            if (hash[other] != 0) {
                vector<int> result;
                result.push_back(hash[target - nums[i]]-1);
                result.push_back(i);
                return result;
            }
            else
                hash[nums[i]] = i+1;
        }
        vector<int> tmp;
        return tmp;
    }