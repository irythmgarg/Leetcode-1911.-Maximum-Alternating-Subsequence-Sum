class Solution {
public:
    int n;
    long long t[100001][2]; // Memoization table for dp[index][iseven]
    typedef long long ll;

    // Recursive function to calculate max alternating sum
    long long answer(vector<int>& nums, int i, bool iseven) {
        if (i >= nums.size()) {
            return 0; // Base case: no more elements
        }

        if (t[i][iseven] != -1)
            return t[i][iseven]; // Return already computed state

        int val = nums[i];
        if (!iseven)
            val = -val; // Subtract value if iseven is false

        // Option 1: Include current element with its sign
        ll include = val + answer(nums, i + 1, !iseven);

        // Option 2: Skip current element
        ll exclude = answer(nums, i + 1, iseven);

        // Return the max of both options
        return t[i][iseven] = max(include, exclude);
    }

    long long maxAlternatingSum(vector<int>& nums) {
        bool iseven = true; // Start with addition
        n = nums.size();

        memset(t, -1, sizeof(t)); // Initialize dp array with -1

        // Call the recursive function starting from index 0
        return answer(nums, 0, iseven);
    }
};
