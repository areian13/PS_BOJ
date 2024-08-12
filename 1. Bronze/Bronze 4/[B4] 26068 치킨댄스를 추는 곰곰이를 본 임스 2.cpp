#include <iostream>
#include <cstdio>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    scanf("%d\n", &n);

    int result = 0;
    for (int i = 0; i < n; i++)
    {
        int d;
        scanf("D-%d\n", &d);
        result += (d <= 90);
    }
    cout << result << '\n';
}