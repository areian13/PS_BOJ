#include <iostream>
#include <unordered_map>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    unordered_map<string, string> classroom;
    classroom["Algorithm"] = "204";
    classroom["DataAnalysis"] = "207";
    classroom["ArtificialIntelligence"] = "302";
    classroom["CyberSecurity"] = "B101";
    classroom["Network"] = "303";
    classroom["Startup"] = "501";
    classroom["TestStrategy"] = "105";

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string seminar;
        cin >> seminar;

        string result = classroom[seminar];
        cout << result << '\n';
    }
}