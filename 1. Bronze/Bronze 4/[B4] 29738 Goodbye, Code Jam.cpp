#include <iostream>
#include <cstdio>
#include <array>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    array<int, 4> rankCut = { 4'500,1'000,25,0 };
    array<string, 4> round = { "Round 1","Round 2","Round 3","World Finals" };

    int tc;
    cin >> tc;

    for (int t = 1; t <= tc; t++)
    {
        int n;
        cin >> n;

        int idx = 0;
        while (n <= rankCut[idx])
            idx++;
        printf("Case #%d: %s\n", t, round[idx].c_str());
    }
}