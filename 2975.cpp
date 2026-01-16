//cpp
class Solution {
public:
    const int MOD = 1e9 + 7;
    int maximizeSquareArea(int m, int n, vector<int>& hFences,
                           vector<int>& vFences) {
        vFences.push_back(1);
        vFences.push_back(n);
        hFences.push_back(1);
        hFences.push_back(m);
        sort(begin(hFences), end(hFences));
        sort(begin(vFences), end(vFences));
        unordered_map<int, int> vSide;
        unordered_map<int, int> hSide;
        for (int i = 0; i < vFences.size(); i++) {
            for (int j = i + 1; j < vFences.size(); j++) {
                vSide[vFences[j] - vFences[i]]++;
            }
        }
        for (int i = 0; i < hFences.size(); i++) {
            for (int j = i + 1; j < hFences.size(); j++) {
                hSide[hFences[j] - hFences[i]]++;
            }
        }
        int maxside = -1;
        for (auto& temp : hSide) {
            if (vSide.count(temp.first))
                maxside = max(maxside, temp.first);
        }
        return maxside!=-1 ? (1LL*maxside * maxside)%MOD : -1;
    }
};

//java
class Solution {
static final int MOD = 1_000_000_007;
    public void storeSide(HashSet<Integer> set, int[] arr, int n) {
        for (int i = -1; i < arr.length; i++) {
            int start = i == -1 ? 1 : arr[i];
            for (int j = i + 1; j < arr.length; j++) {
                set.add(arr[j] - start);
            }
            set.add(n - start);
        }
    }

    public int maximizeSquareArea(int m, int n, int[] hFences, int[] vFences) {
        int maxside = -1;
        HashSet<Integer> hSet = new HashSet<Integer>();
        HashSet<Integer> vSet = new HashSet<Integer>();
        Arrays.sort(hFences);
        Arrays.sort(vFences);
        storeSide(vSet, vFences, n);
        storeSide(hSet, hFences, m);
        for (Integer num : vSet) {
            if (hSet.contains(num))
                maxside = Math.max(maxside, num);
        }
        return maxside == -1 ? -1 : (int)(((1L * maxside * maxside) % MOD + MOD) % MOD);
    }
}
