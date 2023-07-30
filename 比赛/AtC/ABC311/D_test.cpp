#include <iostream>
#include <vector>
#include <bitset>
int main() {
    using namespace std;
    unsigned N, T, M;
    cin >> N >> T >> M;
    vector<unsigned> hate(N);
    for(unsigned i{}, a, b; i < M; ++i){
        cin >> a >> b;
        hate[--b] |= 1U << --a;
    }
    // possible_team[S] := The team with players in S does not have an incompatible pair
    // O(2^N N^2/w) time
    bitset<1024> possible_team;
    for(unsigned i{}; i < 1U << N; ++i){
        unsigned m{};
        for(unsigned j{}; j < N; ++j)if(1U & (i >> j))m |= hate[j];
        if(!(i & m))
            possible_team[i] = true;
    }
    vector dp(1U << N, vector<unsigned>(T + 1));
    dp.front().front() = 1;
    for(unsigned i{}; i < 1U << N; ++i)
        // brute-force over all possible teams that the remaining player with the minimum integer belongs
        for(unsigned c{i + 1 | i}, j{c}; j < 1U << N; ++j |= c)
            if(possible_team[j ^ i]){
                cout << "i:" << bitset<10>(i) << " j:" << bitset<10>(j) << " c:" << bitset<10>(c) << endl;
                for(unsigned k{}; k < T; ++k) {
                    
                    dp[j][k + 1] += dp[i][k];
                }
            }
    cout << dp.back().back() << endl;
    return 0;
}