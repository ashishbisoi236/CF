#include "bits/stdc++.h"
using namespace std;

#define timesaver ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
typedef long long ll ;
typedef long double ldb ;
const long mod=1e9+7;
 
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define nl "\n"
#define MAX_CHARS 256
 
#define all( x ) x.begin(),x.end()
#define sz( x ) ( int )( x ).size( )
#define mem( a, val ) memset(a, val, sizeof( a ) )
#define deci( x ) cout<<fixed<<setprecision( x );


void solve2() {
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; i++)
		cin >> v[i];

	for (int i = 0; i < n; ++i)
	{
		if(v[i] <= 0 || v[i] > n)
			v[i] = n+1;
	}

	for (int i = 0; i < n; ++i)
		{
			cout << v[i] << " ";
		}
		cout << nl;

	for(int i = 0; i < n; i++) {
		int num = abs(v[i]);
		if(num > n) continue;
		num--;
		if(v[num] > 0) {
			v[num] = -1 * v[num];
		}

		// print the array
		for (int i = 0; i < n; ++i)
		{
			cout << v[i] << " ";
		}
		cout << nl;
	}

	for (int i = 0; i < n; ++i)
	{
		if(v[i] > 0){
			cout << i + 1;
			break;
		}
	}
	cout << "jk" << n + 1;
}


string solve(string str){
	 int n = str.length(); 
  
    // Count all distinct characters. 
    int dist_count = 0; 
    bool visited[MAX_CHARS] = { false }; 
    for (int i = 0; i < n; i++) { 
        if (visited[str[i]] == false) { 
            visited[str[i]] = true; 
            dist_count++; 
        } 
    } 

    cout << dist_count << nl;
  
    // Now follow the algorithm discussed in below 
    // post. We basically maintain a window of characters 
    // that contains all characters of given string. 
    int start = 0, start_index = -1, min_len = INT_MAX; 
  
    int count = 0; 
    int curr_count[MAX_CHARS] = { 0 }; 
    for (int j = 0; j < n; j++) { 
        // Count occurrence of characters of string 
        curr_count[str[j]]++; 
  
        // If any distinct character matched, 
        // then increment count 
        if (curr_count[str[j]] == 1) 
            count++; 
  
        // if all the characters are matched 
        if (count == dist_count) { 
            // Try to minimize the window i.e., check if 
            // any character is occurring more no. of times 
            // than its occurrence in pattern, if yes 
            // then remove it from starting and also remove 
            // the useless characters. 
            while (curr_count[str[start]] > 1) { 
                if (curr_count[str[start]] > 1) 
                    curr_count[str[start]]--; 
                start++; 
            } 
  
            // Update window size 
            int len_window = j - start + 1; 
            if (min_len > len_window) { 
                min_len = len_window; 
                start_index = start; 
            } 
        } 
    } 
  
    // Return substring starting from start_index 
    // and length min_len 
    return str.substr(start_index, min_len); 

}
// 19 28 37 46 55 64 73 82 91 109 118 127 

int findLargestSumPair(int* arr, int n) 
{ 
    // Initialize first and second largest element 
    int first, second; 
    if (arr[0] > arr[1]) 
    { 
        first = arr[0]; 
        second = arr[1]; 
    } 
    else
    { 
        first = arr[1]; 
        second = arr[0]; 
    } 
  
    // Traverse remaining array and find first and second largest 
    // elements in overall array 
    for (int i = 2; i<n; i ++) 
    { 
        /* If current element is greater than first then update both 
          first and second */
        if (arr[i] > first) 
        { 
            second = first; 
            first = arr[i]; 
        } 
  
        /* If arr[i] is in between first and second then update second  */
        else if (arr[i] > second && arr[i] != first) 
            second = arr[i]; 
    } 
    return (first + second); 
}

int getMinSquares(unsigned int n)
{
	
	if (sqrt(n) - floor(sqrt(n)) == 0)
		return 1;
	if (n <= 3)
		return n;

	int res = n; 

	
	for (int x = 1; x <= n; x++) 
	{
		int temp = x * x;
		if (temp > n)
			break;
		else {
			int t = 1 + getMinSquares(n-temp);
			if( t < res)
				res = t;
		}
			// res = min(res, 1 + getMinSquares
			// 					(n - temp));
	}
	return res;
}

bool comp(pair<int, int> a, pair<int, int> b) {
	// return (a.second - a.first) <= (b.second - b.first);
	return a.second < b.second;
}

void solve(int n, int d) {
	map<int, vector<pair<int, int>>> m;

	int p[n];
	for(int i = 0; i < n; i++)
		cin >> p[i];

	int dv[d];
	for(int i = 0; i < d; i++)
		cin >> dv[i];

	for(int i = 0; i < n-1; i++) {
		for(int j = i + 1; j < n; j++) {
			int t = p[j] - p[i];
			if(t < 0)
				continue;
			// if(!m.count(t))
			// 	m.insert({t, make_pair(i+1, j+1)});
			// else
				m[t].push_back(make_pair(i+1, j+1));
		}
	}


	for(int i = 0; i < d; i++){
		if(m.find(dv[i]) != m.end()){
			sort(m[dv[i]].begin(), m[dv[i]].end(), comp);
			cout << m[dv[i]][0].first << " " << m[dv[i]][0].second << nl;
		}
		else
			cout << "not found";
	}
}


void sol(string s, vector<int>sI, vector<int>eI){
	int len = sI.size();
	int stars = 0, start, ans;
	for(int i = 0; i < len; i++){
		stars = 0;
		start = 0;
		ans = 0;
		for(int j = sI[i]-1; j < eI[i]; j++){
			if(s[j] == '|'){
				if(start == 0)
					start++;
				else if(start == 1){
					ans += stars;
					stars = 0;
				}

			}
			else{
				if(start == 0)
					continue;
				else if(start == 1)
					stars++;
			}
		}

		cout << ans << " ";
	}

}


int main() {
    timesaver;
    // string s;
    // cin >> s;
    // cout << solve(s);
    // int a[6] = {3, 2, 9, 30, 12, 18};
    // int* p = a;

    // cout << getMinSquares(40);

    // int p = 6, d = 2;
    // solve(p, d);
    vector<int> sI, eI;
    sI.push_back(1);
    // sI.push_back(1);
    eI.push_back(3);
    // eI.push_back(5);

    string a = "*|*|";
    sol(a, sI, eI);
	return 0;
} 




// int findLargestSumPair(int* arr, int n) 
// { 
//     int first, second; 
//     if (*(arr) > *(arr + 1)) 
//     { 
//         first = *(arr); 
//         second = *(arr + 1); 
//     } 
//     else
//     { 
//         first = *(arr + 1); 
//         second = *(arr); 
//     } 
  
//     for (int i = 2; i<n; i ++) 
//     { 
//         if (*(arr + i) > first) 
//         { 
//             second = first; 
//             first = *(arr + i); 
//         } 
//         else if (*(arr + i) > second && *(arr + i) != first) 
//             second = *(arr + i); 
//     } 
//     return (first + second); 
// }


// {
// 	if( (1+getMinSquares(n - temp)) < r)
// 		r = 1 + getMinSquares(n-temp);
// }
