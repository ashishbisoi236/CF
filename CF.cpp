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

bool solve(int n) {
	vector<vector<int>> trip(n, vector<int>(3));
	for(int i = 0; i < n; i++) {
		cin >> trip[i][0] >> trip[i][1] >> trip[i][2];
	}
	cout << nl;
	for(int i = 0; i < n; i++) {
		cout << trip[i][0] << " " << trip[i][1] << " " << trip[i][2] << nl;
	}
	cout << nl;
	int capacity;
	cin >> capacity;

	sort(trip.begin(), trip.end(), comp);

	cout << nl;
	for(int i = 0; i < n; i++) {
		cout << trip[i][0] << " " << trip[i][1] << " " << trip[i][2] << nl;
	}
	cout << nl;
	
	int fCap = 0, lStart = 0, lEnd = 0;
	map<int, vector<int>> m;
	m[trip[0][2]].push_back(0);
	fCap = trip[0][0];

	
	for(int i = 1; i < n; i++) {
		if(m.find(trip[i][1]) != m.end()) {
			for(int i = 0; i < m[trip[i][1]].size(); i++)
				fCap -= trip[m[trip[i][1]][i]][0];
		}

		fCap += trip[i][0];
		m[trip[i][2]].push_back(i);

		if(fCap > capacity)
			return false;
		cout << fCap;
		// if(fCap + trip)
		// fCap += trip[i][0];
		// lStart = trip[i][1];
		// lEnd = trip[i][2];

	}

	return true;

}



int main() {
    // timesaver;
    // int n;
    // solve();
	int n;
	cin >> n;
	if(solve(n))
		cout << "true";
	else
		cout << "false";
	return 0;
} 