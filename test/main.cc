#include <bits/stdc++.h>
#define INF 99999999;
using namespace std;

int n, m, idx;
int n_drill[1001];
int drill[1001][1001];

int solution(int idx)


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++){
        cin >> n_drill[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n_drill[i]; j++){
            cin >> drill[i][j];
            idx++;
        }
        sort(drill[i], drill[i] + n_drill[i]);
    }

    cout << solution() << endl;
}