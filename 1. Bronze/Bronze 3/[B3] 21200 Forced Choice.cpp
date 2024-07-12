#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, p, s;
    cin >> n >> p >> s;
    for (int i = 0; i < s; i++)
    {
        int m;
        cin >> m;

        bool isRemove = true;
        for (int j = 0; j < m; j++)
        {
            int k;
            cin >> k;
            isRemove &= (k != p);
        }

        string result = (isRemove ? "REMOVE" : "KEEP");
        cout << result << '\n';
    }
}