#include <iostream>
#include <cstdio>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    string str;
    cin >> str;

    int a = 0;
    int b = 0;
    for (char c : str)
    {
        a += (c == 'A');
        b += (c == 'B');
    }
    printf("%d : %d", a, b);
}