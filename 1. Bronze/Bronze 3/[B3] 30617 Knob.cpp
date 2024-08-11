#include <iostream>
#include <vector>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int t;
    cin >> t;

    vector<array<int, 2>> knob(t);
    for (int i = 0; i < t; i++)
    {
        int l, r;
        cin >> l >> r;

        knob[i] = { l,r };
    }

    int result = 0;
    for (int i = 0; i < t; i++)
    {
        result += (knob[i][0] != 0 && knob[i][0] == knob[i][1]);
        if (i == 0)
            continue;

        result += (knob[i][0] != 0 && knob[i][0] == knob[i - 1][0]);
        result += (knob[i][1] != 0 && knob[i][1] == knob[i - 1][1]);
    }
    cout << result << '\n';
}