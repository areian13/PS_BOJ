#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        int n;
        cin >> n;

        int result = 0;
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;

            result += (s == "sheep");
        }
        printf("Case %d: This list contains %d sheep.\n\n", tc, result);
    }
}