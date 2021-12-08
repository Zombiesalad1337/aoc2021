#include <bits/stdc++.h>
#include <boost/tokenizer.hpp>

using namespace std;


vector<string> split(std::string s, const char* sep1, const char* sep2);


int main(){


    ifstream fin;
    fin.open("input8.txt");
    string line;

    int count = 0;
    while (fin){
        getline(fin, line);
        if (line.size()){
            vector<string> splitted = split(line, "|", "");
            vector<string> output = split(splitted[1], " ", "");
            for (string i : output){
                int size = i.size();
                if (size == 2 || size == 4 || size == 3 || size == 7){
                    count++;
                }
            }
        }
    }
    cout << count << endl;

        
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


