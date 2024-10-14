#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> score(n);
    for (int i = 0; i < n; i++)
        cin >> score[i];
    sort(score.begin(), score.end());

    int c = n * 0.15 + 0.5;
    int result = 0;
    for (int i = c; i < n - c; i++)
        result += score[i];
    result = (double)result / max(n - 2 * c, 1) + 0.5;
    cout << result << '\n';
}