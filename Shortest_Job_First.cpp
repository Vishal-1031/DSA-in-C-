class Solution {
    public:
      long long solve(vector<int>& bt) {
          float timeline = 0;
          float wt = 0;
          sort(bt.begin(),bt.end());
          for(int i =0; i < bt.size(); i++){
              wt += timeline;
              timeline += bt[i];
          }
          long long ans = wt / bt.size();
          return ans;
          
      }
  };