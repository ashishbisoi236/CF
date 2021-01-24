#include<bits/stdc++.h>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
	// return (a.second - a.first) <= (b.second - b.first);
	if(a.second == b.second)
		return a.first > b.first;
	return a.second < b.second;
}

string find_min_days(int p[], int dv[], int n, int d){
	
	map<int, vector<pair<int, int>>> m;

	for(int i = 0; i < n-1; i++) {
		for(int j = i + 1; j < n; j++) {
			int t = p[j] - p[i];
			if(t < 0)
				continue;
			m[t].push_back(make_pair(i+1, j+1));
		}
	}

	string s = "";

	for(int i = 0; i < d; i++){
		if(m.find(dv[i]) != m.end()){
			sort(m[dv[i]].begin(), m[dv[i]].end(), comp);
			s += to_string(m[dv[i]][0].first) + " " + to_string(m[dv[i]][0].second);
		}
		else
			s += -1;

		s += ",";
	}
	s.pop_back();
	return s;
}

int main ()
{
	int n,d,i;
	string answer="";
	cin>>n>>d;
	int price[n];
	int profit[d];
	for (i=0;i<n;i++)
		cin>>price[i];
	for (i=0;i<d;i++)
	    cin>>profit[i];
    answer = find_min_days(profit,price, n, d);

    // Do not remove below line
	cout<<answer<<endl;
    // Do not print anything after this line

	return 0;
}