#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    int dir = 1;
    int time = 1;
    for (int i = 0; i < n; i++)
    {
        string s;
        int x;
        cin >> s >> x;

        bool isRevTime = (s == "HOURGLASS");
        bool isSynchro = (time == x);
        bool isOverload = (isRevTime && isSynchro);

        string clap = "NO";
        if (isOverload)
            goto IS_OVERLOAD;
        if (isRevTime)
            dir *= -1;
        if (isSynchro)
            clap = "YES";

    IS_OVERLOAD:

        cout << time << ' ' << clap << '\n';

        if (time == 12 && dir == 1)
            time = 0;
        else if (time == 1 && dir == -1)
            time = 13;

        time += dir;
    }
}