class Solution {
    public:
        int candy(vector<int>& ratings) {
            vector<int> l(ratings.size());
            vector<int> r(ratings.size());
            l[0] = 1;
            for(int i =1; i < ratings.size(); i++){
                if(ratings[i] > ratings[i-1]){
                    l[i] = l[i-1] + 1;
                }
                else{
                    l[i] = 1;
                }
            }
            r[ratings.size()-1] = 1;
            for(int j = ratings.size() - 2; j >= 0; j--){
                if(ratings[j] > ratings[j + 1])
                r[j] = r[j+1] + 1;
                else
                r[j] = 1;
            }
            int sum = 0;
            for(int i =0; i < ratings.size(); i++){
                sum = sum + max(l[i],r[i]);
            }
            return sum;
        }
    };