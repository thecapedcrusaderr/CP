#include<bits/stdc++.h>
using namespace std;

// Dynamic Programming Solution

int longestValidParentheses(string s)
{
  int n = s.size();
  vector<int> dp(n,0);
  int ans = 0;
  for(int i = 1 ; i < n; i++)
  {
    if(s[i]=='(')
    {
      dp[i]=0;
    }
    else
    {
      if(s[i-1] == '(')
      {
        dp[i] = 2;
        if(i-2 >= 0)
        {
            dp[i] += dp[i-2];
        }
        // dp[i] = 2 + dp[i-2];
        if(dp[i] > ans) ans = dp[i];
      }
      else
      {
        if (i-dp[i-1]-1 >= 0)
        {
          // cout<<"yahan aa rha hai kay "<<endl;
          if(s[i-dp[i-1]-1] == '(')
          {
            dp[i] = dp[i-1];
            // cout<<"andar ghusne ke badd dp kya "<<dp[i]<<endl;
            dp[i]+=2;
            // cout<<"ab dp kya hai "<<dp[i]<<endl;
            if(i-dp[i-1]-2 >= 0)
            dp[i] += dp[i-dp[i-1]-2];
          }

        }
        // cout<<"bahar nikalne ke bbad dp kya hai "<<dp[i]<<endl;
        if(dp[i] > ans) ans = dp[i];

      }
    }
  }
  // cout<<"printing dp "<<endl;
  // for(int i = 0; i<dp.size();i++)
  // cout<<dp[i]<<" ";
  // cout<<endl;
  return ans;
}
// Stack Solution
// int longestValidParentheses(string s)
// {
//   // I will do it with 2 methods
//
//   // Stack one
//
//   stack<int> st;
//   st.push(-1);
//   for(int i = 0 ; i < s.size(); i++)
//   {
//     if(s[i] == '(')
//     {
//       st.push(i);
//     }
//     else
//     {
//       if(st.top()==-1)
//       {
//         st.push(i);
//       }
//       else if(s[st.top()] == '(')
//       {
//         st.pop();
//       }
//       else
//       {
//         st.push(i);
//       }
//     }
//   }
//
//   // Now it's time to find the output
//   int ans = 0;
//   st.push(s.size());
//   // cout<<"st.top is "<<st.top()<<endl;
//   while(st.top()!=-1)
//   {
//     int top = st.top();
//     st.pop();
//     // cout<<"top is "<<top<<endl;
//     ans = max(ans, (top-st.top()-1));
//   }
//   return ans;
// }
int main()
{ //"(((()())()()))"
  string s = ")()())()()(";
  int fi = longestValidParentheses(s);
  cout<<"Overall length of longestValidParentheses is "<<fi;
}
