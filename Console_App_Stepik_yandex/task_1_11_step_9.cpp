#include <iostream>
#include <string>
#include <map>
#include <cctype>

using namespace std;

bool IsSingleUp(string& w) {
    bool rez = 0;
    int count_up = 0;
    for (auto elm : w) {
        if (isupper(elm)) {
            ++count_up;
        }
    }
    if (count_up == 1) rez = 1;
    return rez;
}

string ToLowStr(string& xx) {
    string r;
    for (auto elm : xx) {
        r.push_back(tolower(elm));
    }
    return r;
}

bool IsExistInMap(string& s_low, map<string, string>& mpp) {
    bool rr = 0;
    for (auto elm : mpp) {
        if (elm.second == s_low) rr = 1;
    }
    return rr;
}

bool IsError(string& ww, map<string, string>& mpp) {
    bool err = 0;
    if (mpp.find(ww) == mpp.end()) {
        string w_now_low = ToLowStr(ww);
        bool exist = IsExistInMap(w_now_low, mpp);
        if (!IsSingleUp(ww) || exist) {
            err = 1;
        }
    }
    return err;
}

int main() {
    map<string, string> mp;
    string s, w_now;
    int n, count = 0;

    cin >> n;
    for (int i = 0; i <= n; i++) {
        if (i < n) {
            string x;
            cin >> x;
            mp[x] = ToLowStr(x);
        }
        else {
            cin >> ws;
            getline(cin, s);
        }
    }
    if (s.size() > 0) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ') {
                w_now += s[i];
            }
            else {
                if (IsError(w_now, mp)) ++count;
                w_now = "";
            }
        }
        if (IsError(w_now, mp)) ++count;
    }
    else count = 0;
    cout << count;
    return 0;
}