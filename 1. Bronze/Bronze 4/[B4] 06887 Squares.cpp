#include <iostream>
#include <cstdio>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    int result = sqrt(n);
    printf("The largest square has side length %d.", result);
}