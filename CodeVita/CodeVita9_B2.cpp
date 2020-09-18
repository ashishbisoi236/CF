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

int main() {
    timesaver;
	int n, k;
	cin >> n >> k;
	if(n == 1)
		cout << 1;
	else { 
		int a[n];
		for(int i = 0; i < n; i++) {
			cin >> a[i];
		} 
		sort(a, a + n);
		int b[n];
		b[0] = a[1] - a[0];
		b[n-1] = a[n-1] - a[n - 2];
		for(int i = 1; i <= n-2; i++)
			b[i] = min(abs(a[i] - a[i-1]), abs(a[i] - a[i+1]));

		int ans = 0;
		for(int i = 0; i < n; i++){
			cout << b[i] << " ";
			if(b[i] <= k)
				ans++;
		}
		
		cout << nl << ans;
	}
	return 0;
}