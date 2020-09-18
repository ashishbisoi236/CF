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

void spiral(vector<vector<int>> &a, int r, int c) {
	int dir = 0;
	// dir = 0: left -> right; dir = 1: top-> bottom; dir = 2: right ->left; dir = 3: bottom->top 
	int left = 0, right = c - 1, top = 0, bottom = r - 1;
	while(left <= right && top <= bottom) {
		if(dir == 0) {
			for(int i = left; i <= right; i++)
				cout << a[top][i] << " ";
			cout << nl;
			// lowering top to next row
			top += 1;
		}
		else if(dir == 1) {
			for(int i = top; i <= bottom; i++)
				cout << a[i][right] << " ";
			cout << nl;
			// moving right to next column
			right -= 1;
		}
		else if(dir == 2) {
			for(int i = right; i >= left; i--)
				cout << a[bottom][i] << " ";
			cout << nl;
			// pushing bottom upwards
			bottom -= 1;
		}
		else if(dir == 3) {
			for(int i = bottom; i >= top; i--) 
				cout << a[i][left] << " ";
			cout << nl;
			// moving left
			left += 1;
		}

		dir = (dir + 1) % 4;
	}
}

int main( ) {
	timesaver;
	vector<vector<int>> a(4, vector<int> (4));
	int t;
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 4; j++) {
			cin >> t;
			a[i][j] = t;
		}
	}
	spiral(a, 4, 4);
	return 0;
}