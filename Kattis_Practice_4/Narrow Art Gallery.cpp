#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX_N = 205;
const int MAX_K = 205; 
const int INF = -1e9;  



            /*
            6 4
            3 1
            2 1
            1 2
            1 3
            3 3
            0 0
            0 0
            */

int main() {

    int N;
    int k_max;

    while (cin >> N >> k_max && (N != 0 || k_max != 0)) {
        vector<int> v_left(N + 1), v_right(N + 1);
        for (int i = 1; i <= N; ++i) {
            cin >> v_left[i] >> v_right[i];
        }

        int dp[MAX_N][3][MAX_K];
        for (int i = 0; i <= N; i++){

            for (int s = 0; s < 3; s++){

                for (int k = 0; k <= k_max; k++){

                    dp[i][s][k] = INF;

                }
            }
        }

        dp[0][0][0] = 0; //base case

        bool is_valid_transition[3][3];
        memset(is_valid_transition, true, sizeof(is_valid_transition));
        is_valid_transition[1][2] = false;
        is_valid_transition[2][1] = false;

        int rooms_closed_in_state[3] = {0, 1, 1};

        for (int i = 1; i <= N; ++i) {
            int value_of_open_rooms_in_state[3];

            value_of_open_rooms_in_state[0] = v_left[i] + v_right[i];
            value_of_open_rooms_in_state[1] = v_right[i];
            value_of_open_rooms_in_state[2] = v_left[i];

            for (int curr_state = 0; curr_state < 3; curr_state++) {

                for (int prev_state = 0; prev_state < 3; prev_state++) {

                    if (!is_valid_transition[prev_state][curr_state]){
                        continue;
                    }

                    int rooms_closed = rooms_closed_in_state[curr_state];

                    for (int k_prev = 0; k_prev <= k_max - rooms_closed; k_prev++) {

                        if (dp[i - 1][prev_state][k_prev] == INF){
                            continue;
                        }

                        int k_new = k_prev + rooms_closed;

                        int total_value = dp[i - 1][prev_state][k_prev] + value_of_open_rooms_in_state[curr_state];

                        dp[i][curr_state][k_new] = max(dp[i][curr_state][k_new], total_value);
                    }
                }
            }
        }

        int ans = INF;
        for (int state = 0; state < 3; state++) {

            ans = max(ans, dp[N][state][k_max]);

        }

        cout << ans << endl;
    }



    return 0;
}
