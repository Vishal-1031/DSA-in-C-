class Solution {
    public:
      int longestKSubstr(string &s, int k) {
          int l = 0, r = 0, maxLen = -1;
          map<char,int> m;
          while(r < s.size()){
              m[s[r]]++;
              if(m.size() > k){
                  if(m.size() > k){
                      m[s[l]]--;
                      if(m[s[l]] == 0){
                          m.erase(s[l]);
                      }
                      l++;
                  }
              }
              if(m.size() == k){
                  maxLen = max(maxLen, (r - l + 1));
              }
              r++;
          }
          
              return maxLen;
      }
      
  };