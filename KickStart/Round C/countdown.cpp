#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int i = 0 ; i < t ; i++)
    {
        int n , k;
        cin>>n>>k;

        vector<int> arr(n);
        for(int j = 0 ; j < n; j++)
        {
            cin>>arr[j];
        }

        int count = 0, kCounter = 0;
        int mainCtr = k;

        if(arr[0]==mainCtr)
        {
          kCounter = 1;
          mainCtr--;
        }

        for(int j = 1 ; j < n ; j++)
        {
            if(arr[j]==mainCtr)
            {
              mainCtr--;
              kCounter++;
            }
            else
            {
              if(arr[j]==k)
              {
                mainCtr = k-1;
                kCounter = 1;
              }
              else
              {
                mainCtr = k;
                kCounter = 0;
              }
            }

            if(kCounter == k)
            {
              count++;
              mainCtr = k;
              kCounter = 0;
            }
        }
        cout<<"Case #"<<i+1<<": "<<count<<endl;
    }
    return 0;
}
