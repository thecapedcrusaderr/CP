// // // Codenation ka xor wala krna hai kuch bhi ho
// //
// // // Chutiya method hai gfg wala, isko ache se krenge
// //
// // #include<bits/stdc++.h>
// // using namespace std;
// // int a, b;
// // vector<int> out;
// //
// //
// // int main()
// // {
// //     int n, m;
// //     cin>>n;
// //     vector<vector<int>> graph(n);
// //     for(int i = 0 ; i < m ; i++)
// //     {
// //         cin>>a>>b;
// //         graph[a-1].push_back(b-1);
// //     }
// //     out.resize(n,0);
// //
// //     return 0;
// // }
//
// int main()
// {
//     int n;
//     cin>>n;
//     vector<int> arr(n);
//     for(int i = 0 ; i < n ; i++)cin>>arr[i];
//
//     int firstIndex = -1;
//     for(int i = 0 ; i < n-1 ; i++)
//     {
//         if(arr[i] > arr[i+1])
//         {
//             firstIndex = i;
//             break;
//         }
//     }
//     if(firstIndex==-1)
//     {
//         swap(arr[n-2],arr[n-1]);
//         for(int i = 0 ; i < n ; i++)
//         {
//             cout<<arr[i]<<" ";
//         }
//         cout<<endl;
//         return 0;
//     }
//
//     int smallIndex = firstIndex+1, smaller = arr[firstIndex+1];
//     for(int i = firstIndex+2 ; i < n ; i++)
//     {
//         if(arr[i] < smaller)
//         {
//           smaller = arr[i];
//           smallIndex = i;
//         }
//     }
//
//     int low = firstIndex, high = smallIndex;
//     while(low < high)
//     {
//       swap(arr[low], arr[high]);
//       low++;
//       high--;
//     }
//
//     for(int i = 0 ; i < n ; i++)
//     {
//         cout<<arr[i]<<" ";
//     }
//
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, q;
    cin>>n>>q;
    string s;
    cin>>s;

    int dirty = 0, first = n+1 , last = n+1;
    for(int i = 0 ; i < n ; i++)
    {
        if(s[i]=='D')dirty++;
        if(s[i]=='F')
        {
            if(first!=n+1)last = i;
            else first = i;
        }
    }

    int empty = 0;
    if(first==n+1 && last==n+1)
    {
        empty = 0;
    }
    else if(last==n+1)
    {
        empty = 1;
    }
    else
    {
        for(int i = first ; i <= last ; i++)
        {
            if(s[i]=='-' || s[i]=='D')empty++;
        }
    }
    cout<<" empty is "<<empty<<endl;
    cout<<" dirty is "<<dirty<<endl;
    while(q--)
    {
        int x, y;
        cin>>x>>y;
        if(first != n+1 && last!=n+1)
        {
            int sum = dirty * y + empty * x;
            cout<<sum<<endl;
        }
        else
        {
            cout<<0<<endl;
        }
    }

    return 0;
}
