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

int partition(int arr[], int low, int high) {
	// x = pivot
	int i = low - 1, x = arr[high]; 

	int j;

	for(j = low; j <= high - 1; j++) {
		if(arr[j] < x){
			i++;
			swap(arr[j], arr[i]);
		}
	}
	swap(arr[i+1], arr[high]);
	return i+1;
}

void printArray(int arr[], int size)  
{  
    int i;  
    for (i = 0; i < size; i++)  
        cout << arr[i] << " ";  
    cout << endl;  
}  


void quickSort(int arr[], int low, int high) {
	if(low <= high) {

		// arr[pos] is now at the right place;
		int pos = partition(arr, low, high);
		printArray(arr, 6);
		quickSort(arr, low, pos - 1);
		quickSort(arr, pos + 1, high);
		
	}
}

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int minJumps(int arr[], int n) {
	if(n == 0 || arr[0] == 0)
		return INT_MAX;
	int jumps[n];
	jumps[0] = 0;
	for(int i = 1; i < n; i++) {
		jumps[i] = INT_MAX;
		for(int j = 0; j < i; j++) {
			if(i <= j + arr[j] && jumps[j] != INT_MAX) {
				jumps[i] = min(jumps[i], jumps[j] + 1);
			}
		}
		if(jumps[i] == INT_MAX) {
			cout << "no solution";
			break;
		}

	}
	for (int i = 0; i < n; ++i)
	{
		cout << jumps[i] << " ";
	}
	cout << nl;
	return jumps[n-1];
}

int main( ) {
	timesaver;
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	cout << "Min jumps to reach array end: " << minJumps(arr, n);
	return 0;
}