#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    while (true)
    {
        string cmd;
        getline(cin, cmd);

        if (cin.eof())
            break;

        string result = cmd;
        while (true)
        {
            int idx = cmd.find("BUG");
            if (idx == -1)
                break;
            result.replace(idx, 3, "");
        }
        cout << result << '\n';
    }
}