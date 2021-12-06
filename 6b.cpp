#include <bits/stdc++.h>
#include <boost/tokenizer.hpp>

using namespace std;


vector<string> split(std::string s, const char* sep1, const char* sep2);


int main(){


    ifstream fin;
    fin.open("input6.txt");
    string line;

    vector<long long int> fish(9, 0);

    getline(fin, line);
    //for testcase
    // vector<string> firstLine = split(line, ": ", "");
    // vector<string> firstDay = split(firstLine[2], ",", "");
    // for (string i : firstDay){
    //     fish[stoi(i)]++;
    // }
    // for (auto i : fish){
    //     cout << i << " ";
    // }
    // cout << endl;

    vector<string> firstDay = split(line, ",", "");
    for (string i : firstDay){
        fish[stoi(i)]++;
    }

    int days = 256;
    for (int i = 0; i != days; ++i){
        long long int newFish = fish[0];
        rotate(fish.begin(), fish.begin() + 1, fish.begin() + 7);
        fish[6] += fish[7];
        fish[7] = fish[8];
        fish[8] = newFish;
    }
    long long int total = 0;
    for (long long int i : fish){
        total += i;
    }
    cout << total << endl;

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


