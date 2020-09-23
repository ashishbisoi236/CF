class Solution {
public:
    
    int overlapImg(vector<vector<int>>& A, vector<vector<int>>& B, int rowOffset, int colOffset) {
        int overlap = 0;
        for(int row = 0; row < A.size(); row++) {
            for(int col = 0; col < A[0].size(); col++) {
                if((row + rowOffset < 0 || row + rowOffset >= A.size()) || (col + colOffset < 0 || col + colOffset >= A.size()) || (A[row][col] + B[row + rowOffset][col + colOffset] != 2))
                   continue;
                overlap++;
            }
        }
        return overlap;
    }
    
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int largestOverlap = 0;
        int rowA = A.size(), colA = A[0].size();
        for(int i = -rowA + 1; i < rowA; i++) {
            for(int j = -colA + 1; j < colA; j++) {
                largestOverlap = max(largestOverlap, overlapImg(A, B, i, j));
            }
        } 
        return largestOverlap;
    }
    
};


// goldmansachs channel remote question


int lowest, highest, n;
int find_min (int x, int y, int pre []) {
    if (x> y) swap (x, y); 
    if (x == y) return 0; 
    int p = (y - x) - (pre [y] - pre [x - 1]); 
    p = min (p, (n - y + x - lowest + 1) - (pre [n] - pre [y - 1] + pre [x] - pre [lowest - 1])); 
    if (p <= 0) 
        return INT_MAX; 
    return p; 
} 
int remoteCast (int lowestChannel, int highestChannel, vector <int> blockedChannels, vector <int> channelsToView) {
    n = highestChannel; 
    lowest = lowestChannel;
    highest = highestChannel;
    int pre [n + 2];
    memset (pre, 0, sizeof (pre)); 
    for (auto it: blockedChannels) 
        pre [it] = 1; 
    for (int i = 1; i <= n + 1; i ++) {
        pre [i] + = pre [i-1]; 
    } 
   int ans = 0; 
   for (int i = 0; i <channelsToView.size (); i ++) {
    int minn = INT_MAX; 
    int curr = channelsToView [i]; 
    minn = log10 (curr) + 1; 
    int c = 0; 
    for (int j = i - 1; j> = 0; j--) {
        minn = min (minn, c + find_min (channelsToView [i], channelsToView [j], pre)); 
        c ++; 
    } 
   // cout << minn << endl; ans + = minn; } 
    return ans; 
}