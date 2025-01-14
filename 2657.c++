class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> maxindex(n, 0);
        for (int i = 1; i < n+1; i++) {
            int idxa = 0;
            for (int j = 0; j < n; j++) {
                if (A[j] == i) {
                    idxa = j;
                    break;
                }
            }
            int idxb=0;
            for (int j = 0; j < n; j++) {
                if (B[j] == i) {
                    idxb = j;
                    break;
                }
            }
            int maxi=max(idxa,idxb);
            maxindex[maxi]++;
        }
        for(int i=1;i<n;i++)
        {
            maxindex[i]+=maxindex[i-1];
        }
        return maxindex;
    }
};