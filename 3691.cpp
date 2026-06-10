//brute force
class Solution {
public:
    typedef long long ll;
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<ll, vector<ll>, greater<ll>> values;
        ll maxval = 0;
        for (int i = 0; i < n; i++) {
            ll maxnum = nums[i];
            ll minnum = nums[i];
            values.push(maxnum - minnum);
            if (values.size() > k)
                values.pop();
            for (int j = i + 1; j < n; j++) {
                maxnum = max(maxnum, 1LL * nums[j]);
                minnum = min(minnum, 1LL * nums[j]);
                values.push(maxnum - minnum);
                if (values.size() > k)
                    values.pop();
            }
        }
        while (!values.empty()) {
            maxval += values.top();
            values.pop();
        }
        return maxval;
    }
};

//better approach
class SegmentTree {
public:
    vector<int> segmentTree;
    bool isMin;
    SegmentTree(vector<int>& nums, bool flag) {
        int n = nums.size();
        segmentTree.resize(4 * n);
        this->isMin = flag;
        build(0, 0, n - 1, nums);
    }
    void build(int i, int l, int r, vector<int>& nums) {
        if (l == r) {
            segmentTree[i] = nums[l];
            return;
        }
        int mid = l + (r - l) / 2;
        build(2 * i + 1, l, mid, nums);
        build(2 * i + 2, mid + 1, r, nums);
        if (isMin)

            segmentTree[i] =
                min(segmentTree[2 * i + 1], segmentTree[2 * i + 2]);
        else
            segmentTree[i] =
                max(segmentTree[2 * i + 1], segmentTree[2 * i + 2]);
    }
    int queryTree(int start, int end, int l, int r, int i) {
        if (l > end || r < start) {
            return isMin == true ? INT_MAX : INT_MIN;
        }
        if (l >= start && r <= end) {
            return segmentTree[i];
        }

        int mid = l + (r - l) / 2;
        int left = queryTree(start, end, l, mid, 2 * i + 1);
        int right = queryTree(start, end, mid + 1, r, 2 * i + 2);
        if (isMin)
            return min(left, right);
        return max(left, right);
    }
    int query(int l, int r, int n) { return queryTree(l, r, 0, n - 1, 0); }
};
class Solution {
public:
    typedef long long ll;
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        SegmentTree minSt(nums, true);
        SegmentTree maxSt(nums, false);
        priority_queue<tuple<ll, int, int>> pq;
        for (int i = 0; i < n; i++) {
            int minval = minSt.query(i, n - 1, n);
            int maxval = maxSt.query(i, n - 1, n);
            pq.push({(ll)maxval - minval, i, n - 1});
        }
        ll result = 0;
        while (!pq.empty() && k--) {
            auto [value, l, r] = pq.top();
            pq.pop();
            result += value;
            int minval = minSt.query(l, r - 1, n);
            int maxval = maxSt.query(l, r - 1, n);
            pq.push({(ll)maxval - minval, l, r - 1});
        }
        return result;
    }
};
