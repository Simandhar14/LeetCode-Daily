//without extra space
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i1 = 0;
        int i2 = 0;
        int n1 = version1.length();
        int n2 = version2.length();
        int num1 = 0;
        int num2 = 0;
        while (i1 < n1 && i2 < n2) {
            while (i1 < n1 && version1[i1] != '.') {
                if (version1[i1] != '0' || version1[i1] == '0' && num1 > 0)
                    num1 = num1 * 10 + (version1[i1] - '0');
                i1++;
            }
            while (i2 < n2 && version2[i2] != '.') {
                if (version2[i2] != '0' || version2[i2] == '0' && num2 > 0)
                    num2 = num2 * 10 + (version2[i2] - '0');
                i2++;
            }

            if (num1 > num2)
                return 1;
            else if (num1 < num2)
                return -1;
            num1 = 0;
            num2 = 0;
            i1++;
            i2++;
        }
        while (i1 < n1) {
            while (i1 < n1 && version1[i1] != '.') {
                if (version1[i1] != '0' || version1[i1] == '0' && num1 > 0)
                    num1 = num1 * 10 + (version1[i1] - '0');
                i1++;
            }
            i1++;
        }
        while (i2 < n2) {
            while (i2 < n2 && version2[i2] != '.') {
                if (version2[i2] != '0' || version2[i2] == '0' && num2 > 0)
                    num2 = num2 * 10 + (version2[i2] - '0');
                i2++;
            }
            i2++;
        }
      
        if (num1 > num2)
            return 1;
        else if (num1 < num2)
            return -1;
        return 0;
    }
};

//with space and using stringstream

class Solution {
public:
vector<string>getTokens(string version)
{
    stringstream ss(version);
    string token="";
    vector<string>tokens;
    while(getline(ss,token,'.'))
    {
        tokens.push_back(token);
    }
    return tokens;
}
    int compareVersion(string version1, string version2) {
        vector<string>v1=getTokens(version1);
        vector<string>v2=getTokens(version2);
        int m=v1.size();
        int n=v2.size();
        int i=0;
        while(i<m || i<n)
        {
            int a=i<m ? stoi(v1[i]):0;
            int b=i<n ?stoi(v2[i]):0;
            if(a<b) return -1;
            else if(a>b) return 1;
            else i++;
        }
        return 0;
    }
};
