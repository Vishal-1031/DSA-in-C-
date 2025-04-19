class Solution {
    public:
        int longestOnes(vector<int>& nums, int k) {
            int l = 0, r = 0, maxLen = 0, zeros = 0, len = 0;
    
            while (r < nums.size()){
                if(nums[r] == 0){
                    zeros += 1 ;
                }
                if(zeros > k){
                    if(nums[l] == 0){
                        zeros -- ;
                    }
                    l += 1;
                }
                if(zeros <= k){
                    len = r - l + 1 ;
                    maxLen = max(maxLen, len);
                }
                r += 1;
            }
            return maxLen;
        }
    };