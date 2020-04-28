#include <bits/stdc++.h>
#include <iostream>
using namespace std;
long long int multModInv(long long int x, long long int m)
{
    if(x%m==1)return x;
    else
    {
        long long int y = x;
        while(x%m!=1)
        {
            x=x*y;
        }
        return (x/y);
    }
    return 0;
}
int main()
{
  cout<<multModInv(3,1000000007);
  return 0;
}

//Correct one
/*
Mine is calculating the lowest mulitiplicative modulo inverse
but to find multiplicative modulo inverse all we have to do is
calculate x^p-2 where x is number and p is modulo.
Program it so as it take complexity O(p-2).

But p has to be prime here.
That's all about mulitiplicative inverse.

*/
