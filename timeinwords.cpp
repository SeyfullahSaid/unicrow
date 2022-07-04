#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'timeInWords' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. INTEGER h
 *  2. INTEGER m
 */

string timeInWords(int h, int m) {
    string times[] = {"o' clock", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty", "twenty one", "twenty two", "twenty three", "twenty four", "twenty five", "twenty six", "twenty seven", "twenty eight", "twenty nine"};
    // Kullanacağımız stringler için array 
    string time;
    if(m < 30){
        if(m == 0){
            time = times[h] + " " + times[0];
        }
        else if(m == 1){
            time = times[m] + " minute past " + times[h];
        }
        else if(m == 15){
            time = "quarter past " + times[h];
        }
        else{
            time = times[m] + " minutes past " + times[h];
        }
    }
    else if(m > 30){
        m = 60 - m;
        h++;
        if(m == 15){
            time = "quarter to " + times[h];
        }
        else if(m == 1){
            time = times[m] + " minute to " + times[h];
        }
        else{
            time = times[m] + " minutes to " + times[h];
        }  
    }
    else if(m == 30){
        time = "half past " + times[h];
    }
    return time;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string h_temp;
    getline(cin, h_temp);

    int h = stoi(ltrim(rtrim(h_temp)));

    string m_temp;
    getline(cin, m_temp);

    int m = stoi(ltrim(rtrim(m_temp)));

    string result = timeInWords(h, m);

    fout << result << "\n";

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
