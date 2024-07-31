#include <iostream>
#include <vector>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> keyboard(n);
    for (int i = 0; i < n; i++)
        cin >> keyboard[i];

    int m;
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int key;
        cin >> key;
        key--;

        keyboard[key]--;
    }
    for (int i = 0; i < n; i++)
    {
        string result = (keyboard[i] < 0 ? "yes" : "no");
        cout << result << '\n';
    }
}