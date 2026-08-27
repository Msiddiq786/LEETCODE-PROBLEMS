class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        long long WinSum = 0;

        for(int i = 0; i < k; i++) {
            WinSum += nums[i];
        }

        long long maxiWin = WinSum;

        for(int i = k; i < nums.size(); i++) {
            WinSum += nums[i] - nums[i-k];
            maxiWin = max(maxiWin, WinSum);
        }

        return (double)maxiWin / k;
    }
};