#include <bits/stdc++.h>
 
using namespace std;
 
//#pragma GCC optimize("Ofast,unroll-loops") 
//#pragma GCC target("avx,avx2,avx512,fma") 
 
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif
 
#define ll long long
#define ld long double
 
#define PI 3.1415926535897932384626433832795l 

// -------------------------<rng>------------------------- 
// RANDOM NUMBER GENERATOR
mt19937 RNG(chrono::steady_clock::now().time_since_epoch().count());  
#define SHUF(v) shuffle(all(v), RNG); 
// Use mt19937_64 for 64 bit random numbers.
 
struct Result {
    string set_name;
    vector<string> selected_cards;
};

unordered_map<char, int> rank_map = {{'2', 2}, {'3', 3}, {'4', 4}, {'5', 5}, {'6', 6}, {'7', 7}, {'8', 8}, {'9', 9}, 
                                     {'J', 10}, {'Q', 11}, {'K', 12}, {'A', 13}, {'1', 14}}; // 10 as "1"

unordered_map<char, int> suit_map = {{'S', 4}, {'H', 3}, {'D', 2}, {'C', 1}};

pair<int, char> parse_card(const string& card) {
    int rank;
    char suit;
    if (card.size() == 3) { 
        rank = 10;
        suit = card[2];
    } else {
        rank = rank_map[card[0]];
        suit = card[1];
    }
    return {rank, suit};
}

bool is_five_in_a_row(const vector<int>& ranks) {
    for (int i = 1; i < ranks.size(); i++) {
        if (ranks[i] != ranks[i - 1] + 1) return false;
    }
    return true;
}

Result solution(vector<string>& cards) {
    unordered_map<int, vector<string>> rank_cards;
    unordered_map<char, vector<string>> suit_cards;
    set<pair<int, string>> all_cards; 
    
    for (const string& card : cards) {
        auto [rank, suit] = parse_card(card);
        rank_cards[rank].push_back(card);
        suit_cards[suit].push_back(card);
        all_cards.insert({rank, card});
    }
    
    for (auto& [rank, card_list] : rank_cards) {
        if (card_list.size() == 3) {
            return {"triple", card_list};
        } else if (card_list.size() == 2) {
            return {"pair", card_list};
        }
    }

    if (all_cards.size() >= 5) {
        vector<int> ranks;
        vector<string> selected_cards;
        for (const auto& [rank, card] : all_cards) {
            ranks.push_back(rank);
            selected_cards.push_back(card);
            if (ranks.size() == 5 && is_five_in_a_row(ranks)) {
                return {"five in a row", selected_cards};
            } else if (ranks.size() > 5) {
                ranks.erase(ranks.begin());
                selected_cards.erase(selected_cards.begin());
            }
        }
    }
    
    for (auto& [suit, card_list] : suit_cards) {
        if (card_list.size() >= 5) {
            return {"suit", vector<string>(card_list.begin(), card_list.begin() + 5)};
        }
    }

    return {"single card", {(*all_cards.rbegin()).second}};
}
 
void solve() {
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; ++t){
//        cout << "# Case " << i << " : ";
        solve();
    }
    
    return 0;
}
 
