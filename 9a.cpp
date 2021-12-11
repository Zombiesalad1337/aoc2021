#include <bits/stdc++.h>
#include <boost/tokenizer.hpp>

using namespace std;


vector<string> split(std::string s, const char* sep1, const char* sep2);


int main(){


    ifstream fin;
    fin.open("input9.txt");
    string line;

    vector<vector<int>> points;

    while (fin){
        getline(fin, line);
        if (line.size()){
            vector<int> temp;
            for (char i : line){
                temp.emplace_back(i - '0');
            }
            points.emplace_back(temp);
        }
    }
    int risk = 0;

    for (int i = 1; i != points.size() - 1; ++i){
        for (int j = 1; j != points[0].size() - 1; ++j){
            if (points[i][j] < min({points[i][j+1], points[i][j-1], points[i+1][j], points[i-1][j]}))
                risk += points[i][j] + 1;
        }
    }

    //corners
    if (points[0][0] < min(points[0][1], points[1][0]))
        risk += points[0][0] + 1;
    if (points[points.size() - 1][points[0].size() - 1] < min(points[points.size() - 2][points[0].size() - 1], points[points.size() - 1][points[0].size() - 2]))
        risk += points[points.size() - 1][points[0].size() - 1] + 1;
    if (points[0][points[0].size() - 1] < min(points[0][points[0].size() - 2], points[1][points[0].size() - 1]))
        risk += points[0][points[0].size() - 1] + 1;
    if (points[points.size() - 1][0] < min(points[points.size() - 1][1], points[points.size() - 2][0]))
        risk += points[points.size() - 1][0] + 1;
    //edges
    for (int j = 1; j != points[0].size() - 1; ++j){
        if (points[0][j] < min({points[1][j], points[0][j+1], points[0][j-1]}))
            risk += points[0][j] + 1;
        if (points[points.size() - 1][j] < min({points[points.size() - 2][j], points[points.size() - 1][j + 1], points[points.size() - 1][j - 1]}))
            risk += points[points.size() - 1][j] + 1;
    }
    int n = points[0].size() - 1;
    for (int i = 1; i != points.size() - 1; ++i){
        if (points[i][0] < min({points[i][1], points[i + 1][0], points[i - 1][0]}))    
            risk += points[i][0] + 1;
        if (points[i][n] < min({points[i - 1][n], points[i + 1][n], points[i][n - 1]}))
            risk += points[i][n] + 1;
    }
    cout << risk << endl;

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


