#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    vector<int> keyboard(127);
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            char key;
            cin >> key;

            keyboard[key] = i * 10 + j;
        }
    }

    vector<char> shoot(9);
    for (int i = 0; i < 9; i++)
        cin >> shoot[i];

    sort(shoot.begin(), shoot.end(),
        [&keyboard](const char a, const char b)
        {
            return keyboard[a] < keyboard[b];
        }
    );

    char result = shoot[4];
    cout << result << '\n';
}