class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            nums.push_back(nums[i]);
        }
        return nums;
    }
};

// class Solution {
// public:
//     vector<int> getConcatenation(vector<int>& nums) {

//         int n = nums.size();
//         vector<int> ans(2 * n);

//         for(int i = 0; i < 2 * n; i++){
//             ans[i] = nums[i % n];
//         }

//         return ans;
//     }
// };