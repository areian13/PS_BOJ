#include <iostream>
#include <vector>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define SIZE 3

bool IsSincereTeam(array<int, SIZE>& t)
{
    if (t[0] == -1)
        return false;

    for (int i = 0; i < SIZE - 1; i++)
    {
        if (t[i] == -1 && t[i + 1] != -1)
            return false;
        if (t[i + 1] != -1 && t[i] > t[i + 1])
            return false;
    }
    return true;
}

int CountSincereTeam(vector<array<int, SIZE>>& t)
{
    int n = t.size();

    int result = 0;
    for (int i = 0; i < n; i++)
        result += (IsSincereTeam(t[i]));
    return result;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<array<int, SIZE>> t(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < SIZE; j++)
            cin >> t[i][j];
    }

    int result = CountSincereTeam(t);
    cout << result << '\n';
}