#include <iostream>
#include <map>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

map<string, string> symbol = {
    { "animal", "Panthera tigris" },
    { "flower", "Forsythia koreana" },
    { "tree", "Pinus densiflora" }
};

int main()
{
    FastIO;

    while (true)
    {
        string s;
        cin >> s;

        if (s == "end")
            break;

        cout << symbol[s] << '\n';
    }
}