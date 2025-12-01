//brute force using priority queue
class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long maxTime=0;
        priority_queue<long long,vector<long long>>pq;
        for(int &bat:batteries) pq.push(1LL*bat);
        while(pq.size()>=n)
        {
            vector<long long>temp;
            int usedBattery=n;
            while(usedBattery--)
            {
                int top=pq.top();
                top--;
                temp.push_back(top);
                pq.pop();
            }
            for(auto &leftBattery:temp)
            {
                if(leftBattery==0) continue;
                pq.push(leftBattery);
            }
            maxTime++;
        }
        return maxTime;
    }
};

//brute force using multiset

class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long maxTime = 0;
        multiset<long long, greater<long long>> st;
        for (int &bat : batteries) st.insert(1LL * bat);
        while ((int)st.size() >= n) {
            vector<long long> temp;
            int usedBattery = n;
            while (usedBattery--) {
                auto it = st.begin();     
                long long newTime = *it - 1;
                st.erase(it);
                temp.push_back(newTime);
            }
            for (auto &leftBattery : temp) {
                if (leftBattery > 0)
                    st.insert(leftBattery);
            }
            maxTime++;
        }
        return maxTime;
    }
};

//better approach
class Solution {
public:
bool check(int n,vector<int>& batteries,long long mid){
    long long time=0;
    for(int &bat:batteries)
    {
        time+=min(mid,1LL*bat);
    }
    return time>=mid*n;
}
    long long maxRunTime(int n, vector<int>& batteries) {
        long long l = *min_element(begin(batteries), end(batteries));
        long long ans=0;
        long long r = (accumulate(begin(batteries), end(batteries), 0LL) / n);
        while (l <= r) {
            long long mid = l + (r - l) / 2;
            if (check(n, batteries,mid)) {
                ans=mid;
                l = mid + 1;
            } else
                r = mid - 1;
        }
        return ans;
    }
};
