#include <bits/stdc++.h>
using namespace std;
bool primes[1000005];
vector <int> arr;
void sieve(){
    memset(primes,true,sizeof(primes));
    int n = 1000004;
    int sqrtn = sqrt(n);
    for(int i=2;i<=(sqrtn);i++){
        if(primes[i]){
            arr.push_back(i);
            for(int j=(i*i);j<=n;j+=i){
                primes[j] = false;
            }
        }
    }
    for(int i=(sqrtn+1);i<=n;i++){
        if(primes[i])
            arr.push_back(i);
    }
}
int main() {
    sieve();
	int T;cin>>T;
	while(T--){
	    int N;cin>>N;
	    if(primes[N])
	        cout<<N<<endl;
	    else{
	        int idx = lower_bound(arr.begin(),arr.end(),N) - arr.begin();
	        (abs(N-arr[idx])>=abs(N-arr[idx-1]))?(cout<<arr[idx-1]<<endl):(cout<<arr[idx]<<endl);
	    }
	}
	return 0;
}