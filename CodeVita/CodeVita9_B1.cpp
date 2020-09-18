#include "bits/stdc++.h"
using namespace std;

#define timesaver ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main() {
    timesaver;
	int n, k;
	cin >> n >> k;

	int a[n];
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	} 
	sort(a, a + n);
	int ans = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n ; j++) {
			if(abs(a[i] - a[j]) <= k && j != i){
				ans++;
				break;
			}
		}
	}
	cout << ans;
	return 0;
}