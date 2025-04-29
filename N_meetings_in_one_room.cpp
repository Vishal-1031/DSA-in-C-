class Solution {
    public:
      struct data{
          int start, end, pos;
      };
      static bool comp(data val1, data val2){
          return val1.end < val2.end;
      }
      int maxMeetings(vector<int>& start, vector<int>& end) {
          vector<data> v(start.size());
          
         for(int i = 0 ; i < start.size(); i++){
             v[i].start = start[i];
             v[i].end = end[i];
             v[i].pos = i + 1;
         }
         sort(v.begin(), v.end(), comp);
          
          int cnt = 1;
          int freeTime = v[0].end;
          vector<int> ds;
          ds.push_back(v[0].pos);
          for(int i = 1; i < start.size(); i++){
              if(freeTime < v[i].start){
                  cnt = cnt + 1;
                  freeTime = v[i].end;
                  ds.push_back(v[i].pos);
              }
              
          }
          return cnt;
          
      }
  };