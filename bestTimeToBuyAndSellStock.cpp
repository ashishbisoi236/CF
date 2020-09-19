class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n = p.size();
        if(n == 1 or n == 0)
        	return 0;
        vector<int> mp(n, 0);
        mp[n-1] = p[n-1];
        for(int i = n-2; i >= 0; i--) {
            mp[i] = max(mp[i+1], p[i]);
        }
        int ans = 0;

        for(int i = 0; i < n; i++) {
            ans = max(ans, mp[i] - p[i]);
        }
        return ans;
    }
};