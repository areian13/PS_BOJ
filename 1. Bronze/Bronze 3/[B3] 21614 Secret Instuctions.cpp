#include <iostream>
#include <string>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    bool preDir = false;
    while (true)
    {
        string cmd;
        cin >> cmd;

        if (cmd == "99999")
            break;

        int sum = (cmd[0] - '0') + (cmd[1] - '0');
        bool dir;
        if (sum == 0)
            dir = preDir;
        else
            dir = (sum % 2 == 0);

        array<string, 2> result = { dir ? "right" : "left",cmd.substr(2, 3) };
        cout << result[0] << ' ' << result[1] << '\n';
        preDir = dir;
    }
}