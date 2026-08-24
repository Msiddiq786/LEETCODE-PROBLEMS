class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int N = nums.size();
        int sum = N*(N+1)/2;
        int s1=0;

        for(int i=0;i<N;i++){
            s1 = s1 + nums[i];
        }
return sum - s1;
    }
};