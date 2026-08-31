class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int N = prices.size();
        int mini = prices[0];
        int profit = 0;
        for(int i=0;i<N;i++){
            int cost = prices[i]-mini;
            mini = min(mini,prices[i]);
            profit = max(cost,profit);
        }
         return profit;
        }
       
};