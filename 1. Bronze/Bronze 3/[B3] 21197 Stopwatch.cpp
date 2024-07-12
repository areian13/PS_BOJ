#include <iostream>
#include <vector>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

string RunningTime(vector<int>& time)
{
    int n = time.size();

    if (n % 2 == 1)
        return "still running";

    int result = 0;
    for (int i = 0; i < n; i += 2)
        result += time[i + 1] - time[i];
    return to_string(result);
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> time(n);
    for (int i = 0; i < n; i++)
        cin >> time[i];

    string result = RunningTime(time);
    cout << result << '\n';
}