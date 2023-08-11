class Solution {
public:
int findLUSlength(vector<string>& strs) {
        
      unordered_map<string,int>mpp;int ans = -1;
      for(auto it : strs)
      {
        int n = it.size();
        for(int i = 0; i<(1<<n); ++i)
        {
            string s;
            for(int j = 0;j<n;++j) if(i&(1<<j)) s.push_back(it[j]);
            mpp[s]++;
        }
      }
      for(auto it : mpp) if(it.second == 1) ans = max(ans,(int)it.first.size());
      return ans;
    }
};