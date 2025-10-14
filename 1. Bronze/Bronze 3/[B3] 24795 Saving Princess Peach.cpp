#include <iostream>
#include <cstdio>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, y;
    cin >> n >> y;

    vector<bool> check(n, false);
    for (int i = 0; i < y; i++)
    {
        int x;
        cin >> x;
        check[x] = true;
    }

    int result = 0;
    for (int i = 0; i < n; i++)
    {
        if (!check[i]) printf("%d\n", i);
        else result++;
    }
    printf("Mario got %d of the dangerous obstacles.\n", result);
}