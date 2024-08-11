#include <iostream>
#include <array>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

string VoteState(int n, array<int, 3>& vote)
{
    if (vote[1] >= (n + 1) / 2)
        return "INVALID";
    if (vote[2] > vote[0])
        return "APPROVED";
    return "REJECTED";
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    array<int, 3> vote = { 0, };
    for (int i = 0; i < n; i++)
    {
        int v;
        cin >> v;

        vote[v + 1]++;
    }

    string result = VoteState(n, vote);
    cout << result << '\n';
}