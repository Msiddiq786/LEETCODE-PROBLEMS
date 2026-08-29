class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int mini =0;
        int maxi = 0;
        for(int i =0;i<gain.size();i++){
            mini = mini + gain[i];
            maxi = max(mini,maxi);
            
        }
        return maxi;
    }
};