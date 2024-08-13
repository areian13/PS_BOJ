#include <iostream>
#include <cstdio>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int a, b, c;
    scanf("%d + %d = %d", &a, &b, &c);

    string result = (a + b == c) ? "YES" : "NO";
    cout << result << '\n';
}