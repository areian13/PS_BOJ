#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MAX 1'200'000

int main()
{
    FastIO;

    int n, q;
    cin >> n >> q;

    vector<int> notes(MAX + 1);
    int beat = 0;
    for (int i = 0; i < n; i++)
    {
        int b;
        cin >> b;

        for (int j = 0; j < b; j++)
            notes[beat++] = i + 1;
    }

    while (q--)
    {
        int t;
        cin >> t;

        int result = notes[t];
        cout << result << '\n';
    }
}