#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin >> t;
	while(t--) {
	    int x, y;
	    cin >> x >> y;
	    int a[x], b[y];
	    for(int i = 0; i < x; i++)
	        cin >> a[i];
	    for(int i = 0; i < y; i++)
	        cin >> b[i];
	    
	    int p1 = x-1, p2 = 0;
	    while(p1 >= 0 && p2 < y) {
	        if(a[p1] > b[p2]) {
	            int t = a[p1];
	            a[p1] = b[p2];
	            b[p2] = t;
	        }
	        p1--, p2++;
	    }
	    sort(a, a + x);
	    sort(b, b + y);
	    for(int i = 0; i < x; i++)
	        cout << a[i] << " ";
	    for(int i = 0; i < y; i++)
	        cout << b[i] << " ";
	    cout << " \n";
	}
	return 0;
}