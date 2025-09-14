class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        int n=queries.size();
        unordered_set<string>st(begin(wordlist),end(wordlist));
        vector<string>ans(n,"");
        for(int i=0;i<n;i++)
        {
            string wrd=queries[i];
            if(st.find(wrd)!=st.end())
            {
                ans[i]=wrd;
            }else{
                for(auto &actualwrd:wordlist)
                {
                    bool notequal=false;
                    if(wrd.size()!=actualwrd.size()) continue;
                    int len=wrd.size();
                    bool notpossible=false;
                    for(int j=0;j<len;j++)
                    {
                        int idx1=(wrd[j]>='a') ? wrd[j]-97 : wrd[j]-65;  
                        int idx2=(actualwrd[j]>='a') ? actualwrd[j]-97 : actualwrd[j]-65;  
                        if(idx1==idx2) continue;
                        if((idx1!=0 && idx1!=4 && idx1!=8 && idx1!=14 && idx1!=20 && idx2!=0 && idx2!=4 && idx2!=8 && idx2!=14 && idx2!=20) || (idx1!=0 && idx1!=4 && idx1!=8 && idx1!=14 && idx1!=20) || (idx2!=0 && idx2!=4 && idx2!=8 && idx2!=14 && idx2!=20)) {
                            notpossible=true;
                            break;
                        }
                        notequal=true;
                    }
                    if(ans[i]=="" && !notpossible) {
                        ans[i]=actualwrd;
                    }
                    if(ans[i]!="" && !notequal && !notpossible)
                    {
                        ans[i]=actualwrd;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};
