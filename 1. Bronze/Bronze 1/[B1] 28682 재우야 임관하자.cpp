#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cout << "swimming" << ' ' << flush;

    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;

        string result = (str == "bowling" ? "soccer" : "bowling");
        cout << result << ' ' << flush;
    }
}
