// My Soln.

class RecentCounter {
    vector<int> v;
public:
    RecentCounter() {
        v.clear();
    }
    
    int ping(int t) {
        v.push_back(t);
        vector<int>::iterator low, up;
        low = lower_bound(v.begin(), v.end(), t-3000);
        up = lower_bound(v.begin(), v.end(), t);
        return up - low + 1;
    }
};



class RecentCounter {

public:

queue<int> ans;

RecentCounter() {
    
    
}

int ping(int t) {
    
    
    ans.push(t);
    
    while(ans.front()<t-3000)
    {
        ans.pop();
    }
    
    return ans.size();
}
};