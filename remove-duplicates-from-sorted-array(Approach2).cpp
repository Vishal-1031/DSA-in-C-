class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            int j = 0, c = 1;
            for(int i = 0; i < nums.size(); i++){
                if(nums[i] != nums[j]){
                    j++;
                    swap(nums[i],nums[j]);
                    c = c + 1;
                }
            }
            return c;
        }
    };