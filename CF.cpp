#include "bits/stdc++.h"
using namespace std;

#define timesaver ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
typedef long long ll ;
typedef long double ldb ;
const long mod=1e9+7;
 
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define nl "\n"
 
#define all( x ) x.begin(),x.end()
#define sz( x ) ( int )( x ).size( )
#define mem( a, val ) memset(a, val, sizeof( a ) )
#define deci( x ) cout<<fixed<<setprecision( x );

void solve1() {
	// string s = "We are at Ignite Solutions! Their email-id is careers@ignit.com";
	string s;
	getline(cin, s);
	string ans = "";
	// cin >> s;
	cout << s;

	int len = s.size();
	int i = 0, j = 0, k = 0;
	cout << len << nl;

	while(k < len) {
		if(isalpha(s[k]) || s[k] == '-')
			j++;
		else if(j != i){
			j -= 1;
			while(j >= i) {
				ans += s[j];
				j--;
			}
			ans += s[k];
			i = k + 1;
			j = k + 1;
		}
		else {
			i = k + 1;
			j = k + 1;
		}
		k++;
	}

	j -= 1;
	while(j >= i) {
				ans += s[j];
				j--;
			}

	cout << ans;

}

bool comp(vector<int> trip1, vector<int> trip2) {
	return trip1[1] < trip2[1];
}

void solve() {

}

class Solution {
public:
    char findTheDifference(string s, string t) {
        int len = s.size();
        int ans = 0;
        for(int i = 0; i < len; i++)
            ans += s[i] - t[i];
        
        return char(ans + t[len]);
    }
};



int main() {
    // timesaver;
    // int n;
    // solve();
	// solve();
	string s1 = "210", s2 = "102";
	cout << (s1+s2) >= (s2+s1);
	return 0;
} 