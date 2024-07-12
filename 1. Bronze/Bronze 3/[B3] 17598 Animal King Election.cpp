#include <iostream>
#include <array>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    array<int, 2> cnt = { 0, };
    for (int i = 0; i < 9; i++)
    {
        string animal;
        cin >> animal;

        cnt[animal == "Lion"]++;
    }

    string result = (cnt[0] > cnt[1] ? "Tiger" : "Lion");
    cout << result << '\n';
}