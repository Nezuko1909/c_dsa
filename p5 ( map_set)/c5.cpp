#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'twoStrings' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING s1
 *  2. STRING s2
 */

string twoStrings(string s1, string s2) {
    int ds1[200] = {};
    int ds2[200] = {};
    
    for (size_t i = 0; i < s1.size(); i++) {
        ds1[(int)s1[i]]++;
    }

    for (size_t i = 0; i < s2.size(); i++) {
        ds2[(int)s2[i]]++;
    }

    for (int i = 32; i < 127; i++) {
        if (ds1[i] == 0 && ds2[i] == 0) {
            continue;
        }
        if (ds1[i] != 0 && ds2[i] != 0) {
            return "YES";
        }
    }
    return "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        string result = twoStrings(s1, s2);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
