/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        if(points.size() < 3) return points.size();
        map<int,map<int,int>> m;
        int max = 0;
        for(int i = 0;i < points.size();i++){
            m.clear();
            int overlap = 0;int localmax = 0;
            for(int j = i+1;j < points.size();j++){
                int x = points[j].x - points[i].x;
                int y = points[j].y - points[i].y;
                
                if(x == 0 && y == 0) 
                {
                    overlap++;
                    continue;
                }
                int a = gcd(x,y);
                if(a!=0){
                    x /= a;
                    y /= a;
                }
                int t = ++m[x][y];
                if(localmax < t) localmax = t;
            }
            if(max < localmax+1+overlap) max = localmax+1+overlap;
        }
        return max;
    }
    
    int gcd(int a, int b){
        if(b == 0) return a;
        return gcd(b,a%b);
    }
};
