#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;
    cin.ignore();

    for (int tc = 1; tc <= n; tc++)
    {
        string name;
        getline(cin, name);

        int cnt = 0;
        for (char c : name)
            cnt += ((c | 32) == 'g' ? +1 : ((c | 32) == 'b' ? -1 : 0));

        string result = (cnt == 0 ? "NEUTRAL" : (cnt > 0 ? "GOOD" : "A BADDY"));
        cout << name << " is " << result << '\n';
    }
}