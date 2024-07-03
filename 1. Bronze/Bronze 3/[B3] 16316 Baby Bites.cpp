#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    bool makeSense = true;
    for (int i = 1; i <= n; i++)
    {
        string cnt;
        cin >> cnt;

        makeSense &= (cnt == "mumble" || stoi(cnt) == i);
    }

    string result = (makeSense ? "makes sense" : "something is fishy");
    cout << result << '\n';
}