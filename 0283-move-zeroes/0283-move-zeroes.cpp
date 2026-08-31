class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int N = nums.size();
    //      int j = 0; // index for placing non-zero elements
    // // Move all non-zero elements to front                             
    // //   for (int i = 0; i < N; i++) {
    // //     if (arr[i] != 0) {
    // //         swap(arr[j] , arr[i]);
    // //         j++;
    // //     }
    // // 
    // }             
    // // Fill remaining positions with 0
    // while (j < N) {
    //     nums[j] = 0;
    //     j++;
    // }  



        int j = 0;  // pointer for placing non-zero elements

        // Move all non-zero elements forward
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                swap(nums[i], nums[j]);
                j++;
            }
        }
    }
};








