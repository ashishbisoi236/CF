#include "bits/stdc++.h"
using namespace std;

#define timesaver ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main() {
    timesaver;
	int n;
	cin >> n;

	int a[n], b[n];
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		cin >> b[i];
		b[i] += a[i];
	} 
	sort(a, a + n);
	sort(b, b + n);
	int p = 1, ans = 1, i = 1, j = 0;
	while(i < n && j < n) {
		if(a[i] <= b[j]) {
			p++, i++;
		}
		else if(a[i] > b[j]) {
			p--, j++;
		}
		if(p > ans)
			ans = p;
	}
	cout << ans ;
	return 0;
}