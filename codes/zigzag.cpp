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
	timesaver ;
	int arr[5][21] = {-1};
	int k = 4;
	// string s;
	char s[] = "thisisazigzagformula";
	// cout << "k = ";
	// cin >> k;
	// cin >> s;
	int gap = 5; // 7 for k == 5 2(k-1) -1
	int j;

	int temp, m;
	for(int i = 1; i <= k; i++) {
		m = 0;
		for(j = 1; j <=20; j++) {


			if((i == j || (j == i + (gap + 1) * m)) ) {
				arr[i][j] = (s[j-1] - 'a');
				m++;
			}
			else {
				arr[i][j] = (32 - 'a');
			}
		}
	}

	int start;
	for(int i = 2; i <= k-1; i++) {
		m = 0;
		start = 2* k - 2 - i + 2;
		for(j = 1; j <=20; j++) {


			if(((j == start + (gap + 1) * m)) ) {
				arr[i][j] = (s[j-1] - 'a');
				m++;
			}
		}
	}

	for(int i = 1; i <= k; i++) {
		for(int j = 1; j <= 20; j++) {
			cout << char(arr[i][j] + 'a')<< " ";
		}
		cout << nl;
	}

    return 0; 
}