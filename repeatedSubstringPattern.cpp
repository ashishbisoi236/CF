bool repeatedSubstringPattern(string s) {
        bool ans = false;
        int len = s.size();
        for(int i = 1; i <= len / 2 + 1; i++) {
            int j, flag;;
            for(j = i; j < len; j += i) {
                flag = 1;
//                 abcabcabc
                string t = s.substr(0, i);
                // cout << t << nl;
                // cout << s.substr(j, i) << nl;
                if(t.compare(s.substr(j, i)) != 0){
                	flag = 0;
                    break;
                }
            }
            // cout << flag << nl;
            if(flag == 1)
                return true;
        }
        return false;
    }

// 2nd Solution
    // https://leetcode.com/explore/challenge/card/september-leetcoding-challenge/554/week-1-september-1st-september-7th/3447/discuss/826135/C++-O(N)-time-or-One-liner-without-KMP-Explained-or-Beats-99
bool repeatedSubstringPattern(string s) {
        return (s + s).substr(1, 2*s.size()-2).find(s) != -1;
    }