//optimised code
class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n=skill.size();
        int m=mana.size();
        vector<long long> finishTime(n,0);
        for(int j=0;j<m;j++)
        {
            finishTime[0]+=skill[0]*mana[j];
            for(int i=1;i<n;i++)
            {
                finishTime[i]=max(finishTime[i-1],finishTime[i])+1LL*skill[i]*mana[j];
            }
            for(int i=n-1;i>0;i--)
            {
                finishTime[i-1]=finishTime[i]-1LL*skill[i]*mana[j];
            }
        }
        return finishTime.back();
    }
};

//brute force 
class Solution {
public:
    bool check(vector<pair<long long, long long>>& prevTime, long long startTime, int manavalue,
               vector<int>& skill) {
        long long checkTime=startTime;
        for (int i = 0; i < skill.size(); i++) {
             if (checkTime < prevTime[i].second) return false;
            long long endtime = checkTime + (manavalue * skill[i]);
            checkTime = endtime;
        }
        return true;
    }
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size();
        vector<pair<long long, long long>>prevTime(n);
        long long starttime = 0;
        for (int i = 0; i < n; i++) {
            long long endtime = starttime + (mana[0] * skill[i]);
            prevTime[i] = {starttime, endtime};
            starttime = endtime;
        }
        for (int i = 1; i < mana.size(); i++) {
            long long left = prevTime[0].second;
            long long newstarttime=-1;
            long long right=prevTime.back().second;
            while (left<=right) {
                long long mid=left+(right-left)/2;
                if (check(prevTime, mid, mana[i], skill)) {
                    newstarttime=mid;
                    right=mid-1;
                }
                else left=mid+1;
            }
            for (int j = 0; j < n; j++) {
                long long endtime = newstarttime + (mana[i] * skill[j]);
                prevTime[j] = {newstarttime, endtime};
                newstarttime = endtime;
            }
        }
        return prevTime.back().second;
    }
};
