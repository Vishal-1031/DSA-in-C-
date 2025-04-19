class Solution {
    public:
        int totalFruit(vector<int>& fruits) {
            int l = 0, r =0, maxLen = 0 ;
            map<int, int > myMap;
            while(r < fruits.size()){
                myMap[fruits[r]]++;
                // Using (myMap.size() > 2 ) in place of if is also an option 
                if(myMap.size() > 2 ){
                    if(myMap.size() > 2){
                        myMap[fruits[l]]--;
                        if(myMap[fruits[l]] == 0){
                            myMap.erase(fruits[l]);
                        }
                        l++;
                    }
                }
                if(myMap.size() <= 2){
                    maxLen = max(maxLen, (r - l + 1));
                }
                r++;
            }
            return maxLen;
        }
    };