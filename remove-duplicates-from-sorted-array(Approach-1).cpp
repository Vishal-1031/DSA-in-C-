class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            set<int> mySet;
            for(int i = 0; i < nums.size();i++){
                mySet.insert(nums[i]);
            }
            int j = 0;
            for(auto i : mySet){
                nums[j] = i;
                j++;
            
            }
            return mySet.size();
        }
    };