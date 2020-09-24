// I will solve it in O(logn)

class Solution {
public:

    void multiply(int first[2][2], int second[2][2])
    {
        int x = first[0][0] * second[0][0] + first[0][1] * second[1][0];
        int y = first[0][0] * second[0][1] + first[0][1] * second[1][1];
        int z = first[1][0] * second[0][0] + first[1][1] * second[1][0];
        int w = first[1][0] * second[0][1] + first[1][1] * second[1][1];

        first[0][0] = x, first[0][1] = y, first[1][0] = z, first[1][1] = w;
    }

    void fibonacci(int first[2][2], int n)
    {
        if(n==0 || n==1)return;

        int second[2][2] = {{1,1},{1,0}};

        fibonacci(first,n/2);
        multiply(first, first);

        if( (n%2) == 1)
        {
            multiply(first, second);
        }
    }

    int fib(int N)
    {
        if(N==0)return 0;
        if(N==1)return 1;

        int first[2][2] = {{1,1},{1,0}};

        fibonacci(first, N-1);
        return first[0][0];
    }
};
