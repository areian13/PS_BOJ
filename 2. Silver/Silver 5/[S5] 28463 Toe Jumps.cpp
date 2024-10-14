#include <iostream>
#include <unordered_map>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

void Spin(string& footprint)
{
    char temp = footprint[0];
    footprint[0] = footprint[2];
    footprint[2] = footprint[3];
    footprint[3] = footprint[1];
    footprint[1] = temp;
}
int main()
{
    FastIO;

    unordered_map<string, string> UMP;
    UMP[".OP."] = "T";
    UMP["I..P"] = "F";
    UMP["O..P"] = "Lz";

    char dir;
    cin >> dir;

    string footprint;
    for (int i = 0; i < 4; i++)
    {
        char foot;
        cin >> foot;

        footprint += foot;
    }

    string senw = "SENW";
    int cnt = 0;
    while (senw[cnt] != dir)
        cnt++;

    for (int i = 0; i < cnt; i++)
        Spin(footprint);

    string result = (UMP[footprint] != "" ? UMP[footprint] : "?");
    cout << result << '\n';
}
