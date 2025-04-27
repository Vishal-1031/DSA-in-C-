class Solution {
    public:
        int countSubarrays(vector<int>& nums) {
            int l = 0 , r = 0, cnt = 0;
            while(r < nums.size()){
                if((r - l + 1) > 3 )
                l = l + 1;
                if((r - l + 1) == 3){
                    
                    if((nums[l] + nums[r]) == (nums[l + 1]/2.0)){
                        cnt = cnt + 1;
                    }
                }
                r = r + 1;
            }
            return cnt;
        }
    };