// https://www.youtube.com/watch?v=GkW6CQ7XV_4&feature=youtu.be

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        vector<pair<int, int>> v;
        int len = nums.size();
        for(int i = 0; i < len; i++)
            v.push_back({nums[i], i});
        
        sort(v.begin(), v.end());
        
        for(int i = 0; i < len; i++) {
            for(int j = i + 1; j < len; j++) {
                if(v[i].first + t >= v[j].first) {
                    if(abs(v[i].second - v[j].second) <= k)
                        return true;
                }
                else
                    break;
            }
        }
        return false;
    }
};


2nd Solution:


    int n = nums.size();
    vector<pair<int,int> > data;
    for(int i=0;i<n;i++)
        data.push_back(make_pair(nums[i],i));
    sort(data.begin(),data.end());
    int p1=0;
    int p2=1;
    while(p2<n)
    {
        long long int d1=data[p1].first;
        long long int d2=data[p2].first;
        if(abs(data[p1].second-data[p2].second)<=k && abs(d1-d2)<=t)
            return true;
        if(abs(data[p1].second-data[p2].second)>k)
            p2++;
        if(abs(d1-d2)>t)
            p1++;
        if(p1==p2)
            p2++;
    }
    return false;