#include "bits/stdc++.h"
using namespace std;

#define timesaver ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
typedef long long ll ;
typedef long double ldb ;
 
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define nl "\n"
 
#define all( x ) x.begin(),x.end()
#define sz( x ) ( int )( x ).size( )
#define mem( a, val ) memset(a, val, sizeof( a ) )
#define deci( x ) cout<<fixed<<setprecision( x );

int main( ) {
	timesaver;
	string s;
	cout << "Enter String: ";
	cin >> s;
	int strLen = s.size();

	int dp[strLen][strLen]; // i = startIndex, j = endIndex
	mem(dp, 0);

	// init
	for(int i = 0; i < strLen; i++)
		dp[i][i] = 1;

	int maxStart, maxEnd, maxLength = 1;

	for(int i = 0; i < strLen - 1; i++) {
		if(s[i] == s[i+1]) {
			dp[i][i+1] = 1;
			maxLength = 2;
			maxStart = i;
			maxEnd = i + 1; 
		}
		else
			dp[i][i+1] = 0;
	}

	
	// int end
	// iterate diagonally with new start and same length of substring
	for(int len = 2; len < strLen; len++) {
		for(int start = 0; start < strLen - len; start++) {

			if(s[start] == s[start + len] && dp[start + 1][start + len - 1] == 1) {
				dp[start][start + len] = 1;
				// new length = start + len - start + 1
				if(len + 1 > maxLength) {
					maxLength = len + 1;
					maxStart = start;
					maxEnd = start + len; 
				}
			}
		}
	}

	// print dp
	for(int i = 0; i < strLen; i++) {
		for(int j = 0; j < strLen; j++)
			cout << dp[i][j] << " ";
		cout << nl;
	}

	cout << "Max Substring length: " << maxLength << nl;
	cout << "Start Index: " << maxStart << nl << "End Index: " << maxEnd << nl;
	cout << "Longest Palindromic Substring: " << s.substr(maxStart, maxEnd);

	return 0;
}