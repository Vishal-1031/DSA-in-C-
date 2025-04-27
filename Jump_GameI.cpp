class Solution {
    public:
        bool canJump(vector<int>& nums) {
            int value = 0, maxlen = 0;
            int size = nums.size();
            for (int i = 0; i < size; i++) {
                if (i > maxlen) {
                    return false;
                }
                maxlen = max(maxlen, (i + nums[i]));
    
                if (maxlen >= size - 1) {
                    return true;
                }
            }
    
            return false;
        }
    };