#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

string Scale(string& note)
{
    static string ade = "ADE";
    static string cfg = "CFG";

    int cnt = 0;
    int n = note.size();
    for (int i = 0; i < n; i++)
    {
        if (i == 0 || note[i - 1] == '|')
            cnt += (ade.find(note[i]) != -1 ? +1 : (cfg.find(note[i]) != -1 ? -1 : 0));
    }

    if (cnt == 0)
        cnt += ade.find(note.back()) != -1 ? +1 : -1;

    return cnt > 0 ? "A-minor" : "C-major";
}

int main()
{
    FastIO;

    string note;
    cin >> note;

    string result = Scale(note);
    cout << result << '\n';
}