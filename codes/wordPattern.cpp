bool wordPattern(string pattern, string str) {
        map<string, char> m;
        string ans = "";
        int len = str.size();
        int i = 0, j = 0;
        char ch = 'a';
        int c = 0;

        vector<char> cv;
        set<char> sv;
        for(int k = 0; k < pattern.size(); k++) {
        	if(sv.find(pattern[k]) == sv.end()) {
        		sv.insert(pattern[k]);
        		cv.push_back(pattern[k]);
        	}
        }

        for(int l = 0; l < cv.size(); l++)
        	cout << cv[l] << " ";
        cout << nl;

        while(i < len) {
            if(str[i] == ' ') {
                if(m.find(str.substr(j,i - j)) == m.end()) {
                	if(c == cv.size())
                		return false;
                    m[str.substr(j,i - j)] = cv[c];
                    ans += cv[c];
                    cout << j << " " << i << nl;
                    // ch++;
                     c++;  
                       
                }
                else ans += m[str.substr(j,i - j)];
                j = i + 1;  
                           
            }

            i++;
        }
        if(m.find(str.substr(j,i - j)) == m.end()) {
                    // m[str.substr(j,i - j)] = ch;
        	if(c == cv.size())
                		return false;
                    ans += cv[c];
                    cout << j << " " << i << nl;
                    c++;   
                }
        else ans += m[str.substr(j,i - j)];

        cout << ans << nl;
        if(pattern.compare(ans) == 0)
            return true;
        return false;
    }