//cpp
class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft,
                                vector<vector<int>>& topRight) {
        long long largestArea = 0;
        int n = bottomLeft.size();
        for (int i = 0; i < n; i++) {
            int x1 = bottomLeft[i][0];
            int y1 = bottomLeft[i][1];
            int x2 = topRight[i][0];
            int y2 = topRight[i][1];
            for (int j = i + 1; j < n; j++) {
                int x3 = bottomLeft[j][0];
                int y3 = bottomLeft[j][1];
                int x4 = topRight[j][0];
                int y4 = topRight[j][1];
                int newx1=max(x1,x3);
                int newy1=max(y1,y3);
                int newx2=min(x2,x4);
                int newy2=min(y2,y4);
                if (newx1 >= newx2 || newy1 >= newy2) continue;
                int height=abs(newy2-newy1);
                int width=abs(newx2-newx1);
                int side=min(height,width);
                long long area=1L*side*side;
                largestArea=max(largestArea,area);
            }
        }
        return largestArea;
    }
};

//java
class Solution {
    public long largestSquareArea(int[][] bottomLeft, int[][] topRight) {
        int n = bottomLeft.length;
        long largestArea = 0;
        for (int i = 0; i < n; i++) {
            int x1 = bottomLeft[i][0];
            int y1 = bottomLeft[i][1];
            int x2 = topRight[i][0];
            int y2 = topRight[i][1];
            for (int j = i + 1; j < n; j++) {
                int x3 = bottomLeft[j][0];
                int y3 = bottomLeft[j][1];
                int x4 = topRight[j][0];
                int y4 = topRight[j][1];
                if (x2 <= x3 || x4 <= x1 || y2 <= y3 || y4 <= y1)
                    continue;
                int newx1 = Math.max(x1, x3);
                int newy1 = Math.max(y1, y3);
                int newx2 = Math.min(x2, x4);
                int newy2 = Math.min(y2, y4);
                int height = Math.abs(newy2 - newy1);
                int width = Math.abs(newx2 - newx1);
                int side = Math.min(height, width);
                long area = 1L*side * side;
                largestArea = Math.max(largestArea, area);
            }
        }
        return largestArea;
    }
}
