#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MAX 20

bool CanDeliver(vector<string>& cmds, array<bool, MAX + 1>& isDelivered)
{
    int p = stoi(cmds[0]);
    isDelivered[p] = true;

    for (string& cmd : cmds)
    {
        if (cmd[0] != 'U' && cmd[0] != 'D')
            continue;

        int np = p + (cmd[1] - '0') * (cmd[0] == 'U' ? +1 : -1);
        
        if (np <= 0 || np > MAX)
            return false;
        if (isDelivered[np])
            return false;

        isDelivered[np] = true;
        p = np;
    }
    return true;
}

int main()
{
    FastIO;

    while (true)
    {
        string s;
        getline(cin, s);

        if (s == "#")
            break;

        vector<string> cmds;
        stringstream ss(s);
        string cmd;
        while (ss >> cmd)
            cmds.push_back(cmd);

        array<bool, MAX + 1> isDelivered = { false, };
        if (CanDeliver(cmds, isDelivered))
        {
            bool isAll = true;
            for (int i = 1; i <= MAX; i++)
                isAll &= isDelivered[i];

            if (isAll)
                cout << "none" << '\n';
            else
            {
                for (int i = 1; i <= MAX; i++)
                {
                    if (!isDelivered[i])
                        cout << i << ' ';
                }
                cout << '\n';
            }
        }
        else
            cout << "illegal" << '\n';
    }
}