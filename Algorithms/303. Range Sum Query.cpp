class NumArray {
public:
    NumArray(vector<int> &nums) {
        arr.push_back(0);
        for (int i = 1; i<=nums.size(); i++)
            arr.push_back(arr[i - 1] + nums[i-1]);
    }

    int sumRange(int i, int j) {
        return (arr[j + 1] - arr[i]);
    }
    vector<int> arr;
};