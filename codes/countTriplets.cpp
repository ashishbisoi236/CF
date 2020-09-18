#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int main() {
	//code
	int t;
	cin >> t;
	while(t--) {
	    int n;
	    cin >> n;
	    int a[n];
	    for(int i = 0; i < n; i++) 
	        cin >> a[i];
        sort(a, a + n);
        int count = 0;
        for(int i = n-1; i >= 0; i--) {
            int j = 0, k = i - 1;
            while(j < k) {
                if(a[j] + a[k] == a[i]) {
                    count++;
                    j++;
                    k--;
                }
                else if(a[j] + a[k] > a[i])
                    k--;
                else
                    j++;
            }
        }
        if(!count)
            cout << -1 << "\n";
        else
            cout << count << "\n";
	}
	return 0;
}