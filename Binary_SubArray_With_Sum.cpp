class Solution {
    public:
        int SubarraysWithSum(vector<int>& nums, int goal) {
            if(goal < 0) return 0;
            int l = 0, r = 0, maxLen = 0, cnt = 0, sum = 0;
    
            while (r < nums.size()) {
                sum += nums[r];
                if(sum > goal){
                while (sum > goal) {
                    sum = sum - nums[l];
                    l = l + 1;
                }
                }
    
                if (sum <= goal) {
                    cnt = cnt + (r - l + 1);
                }
                r = r + 1;
            }
            return cnt;
        }
        int numSubarraysWithSum(vector<int>& nums, int goal) {
    
            int count = SubarraysWithSum(nums,goal) - SubarraysWithSum(nums, goal - 1);
            return count;
        }
    };