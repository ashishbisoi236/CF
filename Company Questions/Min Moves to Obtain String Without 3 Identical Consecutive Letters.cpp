C++
there are fixed pattern we need to consider:
3 consecutive : baaab , replace the middle a
4 consecutive : baaaab, replace the third a
5 consecutive : baaaaab, replace the third a

for more than 5, replace the third char and it can be reduced as the above three conditions
6 consecutive : baaaaaab --> baabaaab ->trans to baaab with 1 replacement -> trans to bb with 2 replancement
10 consecutive : baaaaaaaaaab --> baabaaaaaaab ->trans to baaaaaaab with 1 replacement -> trans to baaaab with 2 replacement -> trans to baab with 3 replacement, done.

therefore, we can see the rule, counter += (consecutive char number)/3

int solution(string s){
	int res = 0;
	for(int i = 0 ; i < s.length() ;){
		int next = i+1;
		while(next < s.length() && s[i] == s[next]) next++;
		int distance = next - i;
		if(distance >= 3){
			while(distance > 5)
				res++,distance -= 3;
			if(distance <= 5)
				res++;
		}
		i = next;
	}
	return res;
}
or reduce more

int solution(string s){
	int res = 0;
	for(int i = 0 ; i < s.length() ;){
		int next = i+1;
		while(next < s.length() && s[i] == s[next]) next++;
		res += (next - i)/3;
		i = next;
	}
	return res;
}