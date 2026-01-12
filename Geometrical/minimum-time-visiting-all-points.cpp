/* 
diagonal moves = min(|dx|, |dy|)
Eg. (0,1)  --> (1, 10)   minimum diagonal moment will be dx = 1   
*/
class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size();

        int sum = 0;

        for(int i=1; i<n; i++){
            int x2 = points[i][0];
            int y2 = points[i][1];

            int x1 = points[i-1][0];
            int y1 = points[i-1][1];

            int ans = max(abs(x2-x1), abs(y2-y1));
            sum += ans;
        }

        return sum;
    }
};
