class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long int, vector<long long int>,
                       greater<long long int>>
            pq(begin(nums), end(nums));
        int operations = 0;
        while (pq.top() < k) {
            long long int x = pq.top();
            pq.pop();

            long long int y = pq.top();
            pq.pop();

            long long int val = (min(x, y) * 2) + max(x, y);
            pq.push(val);

            operations++;
        }
        return operations;
    }
};