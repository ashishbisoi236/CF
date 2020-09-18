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

int areaM(vector<vector<int>> &a, int i, int j, int r, int c) {
	if(i < 0 || i >= r || j < 0 || j >= c || a[i][j] != 1)
		return 0;
	a[i][j] = 2;
	int sum = 1;
	sum += areaM(a, i, j + 1, r, c);
	sum += areaM(a, i - 1, j, r, c);
	sum += areaM(a, i, j - 1, r, c);
	sum += areaM(a, i + 1, j, r, c);
	return sum;
}

int main( ) {
	timesaver;
	vector<vector<int>> a = {{0, 0, 0, 1}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 0, 1}};
	vector<int> ans;
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 4; j++) {
			if(a[i][j] == 1) {
				ans.push_back(areaM(a, i, j, 4, 4));
			}
		}
	}

	for(int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
	return 0;
}