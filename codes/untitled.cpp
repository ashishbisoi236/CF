
int gcd(int a, int b) {
	if(b == 0)
		return a;
	return gcd(b, a%b);
}



vector<int> connected(int numCities, int threshold, vector<int> originCities, vector<int> destinationCities) {
	vector<int> ans;
	for(int i = 0; i < originCities.size(); i++) {
		if(gcd(originCities[i], destinationCities[i] >= threshold))
			ans.push_back(1);
		else
			ans.push_back(0);
	}

	return ans;
}