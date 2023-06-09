#include <bits/stdc++.h>

int findexp(int x, int n, int m)
{
    if (n == 0)
        return 1;
    long long res = findexp(x, n / 2, m);
    if (n & 1)
    { // if odd
        return (x * ((res * res) % m)) % m;
    }
    else
    { // if even
        return (res * res) % m;
    }
}
int modularExponentiation(int x, int n, int m)
{
    // Write your code here.
    int ans = findexp(x, n, m);
    return ans;
}