#include <iostream>
#include <array>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    array<int, 3> time = { 3,20,120 };

    int Max = 0;
    for (int i = 0; i < 3; i++)
    {
        int t;
        cin >> t;

        Max += t * time[i];
    }

    int Mel = 0;
    for (int i = 0; i < 3; i++)
    {
        int t;
        cin >> t;

        Mel += t * time[i];
    }

    string result = (Max == Mel ? "Draw" : (Max > Mel ? "Max" : "Mel"));
    cout << result << '\n';
}