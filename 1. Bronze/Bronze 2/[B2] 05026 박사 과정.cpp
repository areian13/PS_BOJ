#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        string form;
        cin >> form;

        if (form == "P=NP")
            cout << "skipped" << '\n';
        else
        {
            int idx = form.find('+');

            int result = stoi(form.substr(0, idx)) + stoi(form.substr(idx + 1));
            cout << result << '\n';
        }
    }
}