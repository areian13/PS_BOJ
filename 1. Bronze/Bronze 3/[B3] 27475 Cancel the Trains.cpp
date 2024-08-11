#include <iostream>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int tc;
    cin>>tc;

    while (tc--)
    {
        array<bool, 101> line = { false, };
        int n, m;
        cin>>n >> m;

        for (int i = 0; i < n; i++)
        {
            int num;
            cin>>num;

            line[num] = true;
        }

        int result = 0;
        for (int i = 0; i < m; i++)
        {
            int num;
            cin>>num;

            result += line[num];
        }
        cout << result << '\n';
    }
}