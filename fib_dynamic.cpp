#include<iostream>
const int SIZE = 60;

//return the sum of the n number of the fibbinacci sequence. EX. n = 6, will return 8
int fib(int ); //basic recursion is 2^n call with n space complexity


////// with dynamic now
//with memoization 
int fib2(int, int *);

int main()
{
    int memo[SIZE];
    //int sum = fib(50);
   int sum = fib2(7, memo);
    std::cout << sum << std::endl;

    //for (int i = 0; i < SIZE; i++)
       // std::cout << i << ": " << memo[i] << std::endl;
    return 0;
}

////// Dynamic////////////
int fib2( int n, int * memo )
{
    
    //base cases 
    memo[0] = 0;
    memo[1] = 1;

    for(int i = 2; i <= n ; ++ i)
    {
        memo[i] = memo[i -1] + memo[i - 2];
    }

    return memo[n];

}

//////////////////////////////////////Basic recursion ////////////////////////////////////////////
int fib(int n)
{
    if( n <= 2 )
        return 1;
    return  fib(n - 1) + fib(n - 2 );

}