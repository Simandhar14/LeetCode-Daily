//Using map


class Solution {
public:
    int calculate(int number) {
        int sum = 0;
        while (number > 0) {
            sum += number % 10;
            number = number / 10;
        }
        return sum;
    }

    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++) {
            int sumofdigits = calculate(nums[i]);

            if (mp[sumofdigits].size() < 2) {
                mp[sumofdigits] = vector<int>(2, -1);
            }

            int num1 = mp[sumofdigits][0];
            int num2 = mp[sumofdigits][1];

            if (nums[i] > num1) {

                mp[sumofdigits][1] = num1;
                mp[sumofdigits][0] = nums[i];
            } else if (nums[i] > num2) {

                mp[sumofdigits][1] = nums[i];
            }
        }

        int ans = -1;
        for (auto& temp : mp) {
            if (temp.second[1] != -1) {
                ans = max(ans, temp.second[0] + temp.second[1]);
            }
        }
        return ans;
    }
};




//Using priority_queue

class Solution {
public:
int calculate(int number)
{
    int sum=0;
    while(number>0)
    {
        sum+=number % 10;
        number=number/10;
    }
    return sum;
}
    int maximumSum(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,priority_queue<int,vector<int>>>mp;
        for(int i=0;i<n;i++)
        {
            int sumofdigits=calculate(nums[i]);
            mp[sumofdigits].push(nums[i]);
        }
        int ans=-1;
        for(auto temp:mp)
        {
            if(temp.second.size()>=2)
            {
               int num1=temp.second.top();
               temp.second.pop();
               int num2=temp.second.top();
               ans=max(ans,num1+num2);
            }
        }
        return ans;
    }
};