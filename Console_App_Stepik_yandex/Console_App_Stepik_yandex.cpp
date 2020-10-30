// Console_App_Stepik_yandex.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main() {
    string s, w_now, s_eng;
    multimap<string, string> mp;
    int n;

    //ввод
    cin >> n;
    cin >> ws;
    for (int i = 0; i < n; i++) {
        getline(cin, s);
        int count_w = 0;
        for (int j = 0; j < s.size(); ++j) {
            if ((int)s[j] != 32 && (int)s[j] != 45 && (int)s[j] != 44) {
                w_now += s[j];
            }
            else if (count_w != 0 && w_now.size() != 0) {
                mp.insert(pair<string, string>(w_now, s_eng));
                w_now = "";
            }
            else if (w_now.size() != 0) {
                s_eng = w_now;
                w_now = "";
                ++count_w;
            }
            else continue;
        }
        mp.insert(pair<string, string>(w_now, s_eng));//словарь пар лат-анг
        w_now = "";
    }

    //словарь лат-англ
    map<string, vector<string>> rez;
    for (auto elm : mp) {
        rez[elm.first].push_back(elm.second);
    }

    //вывод
    cout << rez.size() << endl;
    for (auto elm : rez) {
        cout << elm.first << " - ";
        vector <string> inVect = elm.second;
        for (unsigned j = 0; j < inVect.size(); j++) {
            if (j != inVect.size() - 1) {
                cout << inVect[j] << ", ";
            }
            else cout << inVect[j];

        }
        cout << endl;
    }
    return 0;
}
