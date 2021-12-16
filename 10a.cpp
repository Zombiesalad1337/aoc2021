#include <bits/stdc++.h>
#include <boost/tokenizer.hpp>

using namespace std;


vector<string> split(std::string s, const char* sep1, const char* sep2);


int main(){


    ifstream fin;
    fin.open("input10.txt");
    string line;
    map <char, int> vals;
    vals[')'] = 3;
    vals[']'] = 57;
    vals['}'] = 1197;
    vals['>'] = 25137;
    long long int points = 0;
    int lc = 1;
    while (fin){
        getline(fin, line);
        if (line.size()){
            stack<char> s;
            for (char i : line){
                if (i == '(')
                    s.push(')');
                else if (i == '[')
                    s.push(']');
                else if (i == '{')
                    s.push('}');
                else if (i == '<')
                    s.push('>');
                else if (i == s.top())
                    s.pop();
                else{
                    // cout << lc << endl;
                    // cout << i << endl;
                    points += vals[i];
                    break;
                }
            }
        }
        lc++;
    }
    cout << points << endl;
    return 0;
}

vector<string> split(std::string s, const char* sep1, const char* sep2)
{
    vector<string> tokens;
    boost::char_separator<char> sep(sep1, sep2);
    boost::tokenizer<boost::char_separator<char> > tok(s, sep);
    for(auto i = tok.begin(); i!=tok.end(); ++i)
        tokens.emplace_back(*i);
    return tokens;
}


