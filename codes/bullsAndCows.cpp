string getHint(string secret, string guess) {
        int bull = 0, cow = 0;
        int len = secret.size();
        vector<int> vs(26, 0); // 10 for numbers only
        vector<int> vg(26, 0);
        for(int i = 0; i < len; i++) {
            if(secret[i] == guess[i])
                bull++;
            else {
                vs[secret[i] - '0'] += 1;
                vg[guess[i] - '0'] += 1;
            }
        }
        string ans = "";
        for(int i = 0; i < 26; i++) {
            cow += min(vs[i], vg[i]);
        }
            
        ans += to_string(bull) + "A" + to_string(cow) + "B";
        return ans;
    }

// Efficient sol.

    string getHint(string secret, string guess) {
        unordered_map<char, int> s_map;
        unordered_map<char, int> g_map;
        int n = secret.size();
        int A = 0, B = 0;
        for (int i = 0; i < n; i++)
        {
            char s = secret[i], g = guess[i];
            if (s == g)
                A++;
            else
            {
                (s_map[g] > 0) ? s_map[g]--, B++ : g_map[g]++;
                (g_map[s] > 0) ? g_map[s]--, B++ : s_map[s]++; 
            }
        }
        return to_string(A) + "A" + to_string(B) + "B";;
    } 