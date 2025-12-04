class Solution {
public:
    int countCollisions(string directions) {
        stack<char> st;
        int collisions = 0;
        int n = directions.size();
        int i=0;
        while(i<n) {
            if (!st.empty()) {
                if (st.top() == 'R') {
                    if (directions[i] == 'L') {
                        collisions += 2;
                    } else if (directions[i] == 'S') {
                        collisions++;
                    }
                    else{
                        st.push('R');
                        i++;
                        continue;
                    }
                    st.pop();
                    while (!st.empty() && st.top() == 'R') {
                        collisions++;
                        st.pop();
                    }
                    st.push('S');
                }
                else if(st.top()=='S')
                {
                    if(directions[i]=='L')
                    {
                        while(i<n && directions[i]=='L') {
                            collisions++;
                            i++;
                        }
                        i--;
                    } else st.push(directions[i]);
                }else st.push(directions[i]);
            }else st.push(directions[i]);
            i++;
        }
        return collisions;
    }
};
