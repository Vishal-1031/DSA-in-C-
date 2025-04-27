class Solution {
    public:
        int jump(vector<int>& nums) {
            int  l = 0, r = 0, jump = 0;
            // Here r is also a Checking condition besides looping condition 
            while ( r < nums.size()-1){
                int maxRange = 0 ;
                for(int i = l; i <= r; i++){
                    maxRange = max(maxRange, (i + nums[i]));
                }
                    l = r + 1;
                    r = maxRange;
                    jump = jump + 1;
                
            }
            return jump;
        }
    };