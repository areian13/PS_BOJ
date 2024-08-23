#include <iostream>
#include <cstdio>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    for (int ti = 1; ti <= tc; ti++)
    {
        int n, a, b;
        cin >> n >> a >> b;

        for (int i = 0; i < n; i++)
        {
            int u, v;
            cin >> u >> v;
        }

        printf("Material Management %d\n", ti);
        printf("Classification ---- End!\n");
    }
}