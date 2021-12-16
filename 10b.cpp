#include <bits/stdc++.h>
#include <boost/tokenizer.hpp>

using namespace std;


vector<string> split(std::string s, const char* sep1, const char* sep2);


int main(){


    ifstream fin;
    fin.open("input10.txt");
    string line;
    map <char, int> vals;
    vals[')'] = 1;
    vals[']'] = 2;
    vals['}'] = 3;
    vals['>'] = 4;
    vector<long long int> scores;
    int lc = 1;
    while (fin){
        getline(fin, line);
        bool corrupted = false;
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
                    corrupted = true;
                    break;
                }
            }

            if (!s.empty() && !corrupted){
                long long int score = 0;
                while (!s.empty()){
                    // cout << s.top() << " ";
                    score *= 5;
                    score += vals[s.top()];
                    s.pop();
                }
                // cout << score << endl;
                scores.emplace_back(score);
            }
        }
        lc++;
    }
    sort(scores.begin(), scores.end());
    cout << scores[scores.size() / 2] << endl;
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


