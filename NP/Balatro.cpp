#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long ll;

const int MAXN = 200005;
const int MAXK = 205; // Since k can be up to n, and n can be up to 2e5
const ll INF = 1e18;

struct Card {
    char type;
    int value;
};

int main() {
    int n, k;
    cin >> n >> k;
    vector<Card> cards(n);
    for (int i = 0; i < n; ++i) {
        string s;
        int v;
        cin >> s >> v;
        cards[i].type = s[0];
        cards[i].value = v;
    }

    vector<vector<ll> > dp(k + 1, vector<ll>(n + 1, -INF));
    // dp[m][l] = max score using m multiply cards and l total cards
    dp[0][0] = 0;

    for (int idx = 0; idx < n; ++idx) {
        char s = cards[idx].type;
        int v = cards[idx].value;
        vector<vector<ll> > new_dp = dp;
        if (s == 'a') {
            for (int m = 0; m <= k; ++m) {
                for (int l = n; l >= 0; --l) {
                    if (dp[m][l] != -INF) {
                        if (l + 1 <= n) {
                            ll new_score = dp[m][l] + v;
                            if (new_dp[m][l + 1] < new_score) {
                                new_dp[m][l + 1] = new_score;
                            }
                        }
                    }
                }
            }
        } else { // s == 'm'
            for (int m = k; m >= 1; --m) {
                for (int l = n; l >= 0; --l) {
                    if (dp[m - 1][l] != -INF && dp[m - 1][l] > 0) {
                        if (l + 1 <= n) {
                            ll new_score = dp[m - 1][l] * v;
                            if (new_dp[m][l + 1] < new_score) {
                                new_dp[m][l + 1] = new_score;
                            }
                        }
                    }
                }
            }
        }
        dp = new_dp;
    }

    vector<ll> result(n + 1, -INF);
    for (int m = 0; m <= k; ++m) {
        for (int l = 1; l <= n; ++l) {
            if (dp[m][l] > result[l]) {
                result[l] = dp[m][l];
            }
        }
    }

    for (int l = 1; l <= n; ++l) {
        if (result[l] == -INF) {
            result[l] = 0;
        }
        cout << result[l] << endl;
    }

    return 0;
}
