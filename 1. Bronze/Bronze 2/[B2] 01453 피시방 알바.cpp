#include <iostream>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MAX 100

int main()
{
    FastIO;

    int n;
    cin >> n;

    array<bool, MAX + 1> isSeated = { false, };
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        int s;
        cin >> s;

        result += isSeated[s];
        isSeated[s] = true;
    }
    cout << result << '\n';
}