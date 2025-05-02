class Solution {
    public:
        int missingNumber(vector<int>& nums) {
            vector<bool> m(nums.size() + 1, false );
            for(int i = 0; i < nums.size(); i++){
                m[nums[i]] = true; 
            }
            for(int j = 0; j <= m.size(); j++){
                if(m[j] == false)
                return j;
            }
            return -1;
        }
    };