class Solution {
    public:
      // Function to return the count of number of elements in union of two arrays.
      int findUnion(vector<int>& a, vector<int>& b) {
          set<int> unionn ;
          for(int i = 0; i < a.size(); i++){
              unionn.insert(a[i]);
          }
          for(int j = 0; j < b.size(); j++){
              unionn.insert(b[j]);
          }
          return unionn.size();
      }
  };