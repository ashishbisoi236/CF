// Fastest solution

vector<int> partitionLabels(string S) {
        if(S.empty()) return {};
        vector<int> pos(26);
        int n = S.size();
        for(int idx = 0; idx < n; ++idx) {
            pos[S[idx]-'a'] = idx; 
        }
        vector<int> res;
        int end = 0;
        for(int idx = 0, start = 0; idx < n; ++idx) {
            end = max(end, pos[S[idx]-'a']);
            if(end == idx) {
                res.push_back(end-start+1);
                start = end+1;
            }
        }
        return res;
    }

// My solution
vector<int> partitionLabels(string S) {
        map<char, pair<int, int>> m;
        int len = S.size();
        for(int i = 0; i < len; i++) {
            if(m.find(S[i]) == m.end())
                m[S[i]] = make_pair(i, i);
            else{
                m[S[i]].second = i;
            }
        }
        vector<int> ans;
        int i = 0;
        while(i < len) {
            int j = i, l = m[S[j]].second;
            for(; j <= l; j++) {
                if(m[S[j]].second > l) {
                    l = m[S[j]].second;
                }
            }
            ans.push_back(j - i);
            i = j;
        }
        return ans;
    }