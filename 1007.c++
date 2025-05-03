class Solution {
public:
    int check(vector<int>& tops, vector<int>& bottoms,int num) {
        bool flag = true;
        int flip = 0;
        int n = tops.size();
        for (int i = 0; i < n; i++) {
            if (tops[i] != num && bottoms[i] == num)
                flip++;
            else if (tops[i] != num && bottoms[i] != num) {
                flag = false;
                break;
            }
        }
        if(flag) return flip;
        else return -1;
    }
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int rotations = INT_MAX;
        vector<int> freq(7, 0);
        int num = 0, maxcount = 0;
        for (int val : tops) {
            freq[val]++;
            if (freq[val] > maxcount) {
                num = val;
                maxcount = freq[val];
            }
        }
        int flip=check(tops,bottoms,num);
        if (flip!=-1)
            rotations = min(rotations, flip);
        num = 0, maxcount = 0;
        freq=vector<int>(7,0);
        for (int val : bottoms) {
            freq[val]++;
            if (freq[val] > maxcount) {
                num = val;
                maxcount = freq[val];
            }
        }
        int bottomflip=check(bottoms,tops,num);
        if (bottomflip!=-1)
            rotations = min(rotations, bottomflip);
        return rotations != INT_MAX ? rotations : -1;
    }
};
