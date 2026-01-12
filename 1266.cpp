//brute force
class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int totalsteps = 0;
        int x1 = points[0][0];
        int y1 = points[0][1];
        int i = 1;
        while (i < points.size()) {
            int x2 = points[i][0];
            int y2 = points[i][1];
            if (x1 == x2 && y1 == y2) {
                i++;
                continue;
            }
            if (x1 == x2) {
                totalsteps += abs(y1 - y2);
                y1 = y2;
                i++;
            } else if (y1 == y2) {
                totalsteps += abs(x1 - x2);
                x1 = x2;
                i++;
            } else {
                int xsteps = abs(x1 - x2);
                int ysteps = abs(y1 - y2);
                int diag = min(xsteps, ysteps);
                totalsteps += diag;
                if (x1 < x2)
                    x1 += diag;
                else
                    x1 -= diag;
                if (y1 < y2)
                    y1 += diag;
                else
                    y1 -= diag;
                if (x1 == x2 && y1 == y2) {
                    i++;
                    continue;
                }
                totalsteps += abs(x1 - x2) + abs(y1 - y2);
                x1 = x2;
                y1 = y2;
                i++;
            }
        }
        return totalsteps;
    }
};

//simple approach

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int x1=points[0][0];
        int y1=points[0][1];
        int totalsteps=0;
        for(int i=1;i<points.size();i++)
        {
            int x2=points[i][0];
            int y2=points[i][1];
            int dx=abs(x2-x1);
            int dy=abs(y2-y1);

            totalsteps+=min(dy,dx) + abs(dy-dx);
            x1=x2;
            y1=y2;
        }
        return totalsteps;
    }
};
