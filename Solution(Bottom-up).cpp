class Solution {
public:
    int n;
    typedef long long ll;

    // Function to compute the maximum alternating sum using bottom-up dynamic programming
    long long maxAlternatingSum(vector<int>& nums) {
        bool iseven = true;          // Start with an addition (even index)
        n = nums.size();             // Size of the input array

        ll t[n + 1][2];              // DP table: t[i][0] stores even index sum, t[i][1] stores odd index sum

        t[0][0] = 0;                 // Base case: no element included as subtraction
        t[0][1] = nums[0];           // Base case: first element included as addition

        for (int i = 1; i < n; i++) {
            // For even indexed sum: skip or subtract current element from previous odd
            t[i][0] = max(t[i - 1][0], t[i - 1][1] - nums[i]);

            // For odd indexed sum: skip or add current element to previous even
            t[i][1] = max(t[i - 1][1], t[i - 1][0] + nums[i]);
        }

        // Return the maximum alternating sum at the end of array
        return max(t[n - 1][0], t[n - 1][1]);
    }
};
