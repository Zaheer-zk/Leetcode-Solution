class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int curSum = 0;
        int n = nums.size();
        
        for(auto i : nums) {
            if(curSum < 0){
                curSum = 0;
            }
            curSum += i;
            
            if(curSum > maxSum) {
                maxSum = curSum;
            }
        }
        
        return maxSum;
    }
};