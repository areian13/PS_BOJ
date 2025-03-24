#include <iostream>
#include <cstdio>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    while (true)
    {
        string s;
        int f;
        cin >> s >> f;

        if (s == "#" && f == 0)
            break;

        int c;
        cin >> c;

        printf("%s Library\n", s.c_str());
        for (int tc = 1; tc <= c; tc++)
        {
            int w;
            string t;
            cin >> w >> t;

            bool result = (w >= t.size() * f + 2);
            printf("Book %d %s\n", tc, (result == true ? "horizontal" : "vertical"));
        }
    }
}