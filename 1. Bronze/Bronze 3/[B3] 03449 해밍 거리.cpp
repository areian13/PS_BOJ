#include <iostream>
#include <cstdio>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    while (tc--)
    {
        string a, b;
        cin >> a >> b;

        int n = a.size();

        int result = 0;
        for (int i = 0; i < n; i++)
            result += (a[i] != b[i]);

        printf("Hamming distance is %d.\n", result);
    }
}