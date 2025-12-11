class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        int covered = 0;
        int len = buildings.size();
        unordered_map<int, pair<int,int>> ymp; //store each x given y
        unordered_map<int, pair<int,int>> xmp; //store each y given x
        for (int i = 0; i < len; i++) {
            int x1 = buildings[i][0];
            int y1 = buildings[i][1];
            if(ymp.count(y1)) //store the min x and max x for each y
            {
                int minx=ymp[y1].first;
                int maxx=ymp[y1].second;
                minx=min(minx,x1);
                maxx=max(maxx,x1);
                ymp[y1]={minx,maxx};
            }else{
                ymp[y1]={x1,x1};
            }

            if(xmp.count(x1)) //store the min y and max y for each x
            {
                int miny=xmp[x1].first;
                int maxy=xmp[x1].second;
                miny=min(miny,y1);
                maxy=max(maxy,y1);
                xmp[x1]={miny,maxy};
            }else{
                xmp[x1]={y1,y1};
            }
        }
        for (int i = 0; i < len; i++) {
            int x1 = buildings[i][0];
            int y1 = buildings[i][1];
            bool left = false, right = false, up = false, down = false;
            auto temp=ymp[y1];
            if(temp.first<x1) left=true;
            if(temp.second>x1) right=true;
            
            temp=xmp[x1];
            if(temp.first<y1) down=true;
            if(temp.second>y1) up=true;
            if (left && right && down && up)
                covered++;
        }
        return covered;
    }
};
