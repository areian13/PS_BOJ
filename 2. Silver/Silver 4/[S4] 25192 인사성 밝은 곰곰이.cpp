#include <iostream>
#include <unordered_map>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    unordered_map<string, bool> isUsed;
    int result = 0;
    while (n--)
    {
        string log;
        cin >> log;

        if (log == "ENTER")
        {
            unordered_map<string, bool>().swap(isUsed);
            continue;
        }

        result += !isUsed[log];
        isUsed[log] = true;
    }
    cout << result << '\n';
}