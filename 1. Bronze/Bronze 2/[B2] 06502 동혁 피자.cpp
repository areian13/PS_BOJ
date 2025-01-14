#include <iostream>
#include <cstdio>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int tc = 0;
    while (true)
    {
        int r;
        cin >> r;

        if (r == 0)
            break;

        int w, l;
        cin >> w >> l;

        bool result = sqrt(w * w + l * l) <= r * 2;
        printf("Pizza %d %s on the table.\n", ++tc, result == true ? "fits" : "does not fit");
    }
}