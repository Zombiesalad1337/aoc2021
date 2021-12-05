#include <bits/stdc++.h>
#include <boost/tokenizer.hpp>

using namespace std;


vector<string> split(std::string s, const char* sep1, const char* sep2);


int main(){


    ifstream fin;
    fin.open("input5.txt");
    string line;
    
    vector<vector<int>> points;
    while (fin){
        getline(fin, line);
        if (line.size()){
            // cout << "x";
            vector<string> pointStrings = split(line, " -> ", "");
            // cout << pointStrings.size() << endl;
            vector<int> pairs;
            for (string i : pointStrings){
                // cout << i << endl;
                vector<string> vals = split(i, ",", "");
                for (string j : vals){
                    // cout << j << endl;
                    pairs.emplace_back(stoi(j));
                }
            }
            points.emplace_back(pairs);
        }
    }
    int maxX = 0;
    int maxY = 0;
    for (int i = 0; i != points.size(); ++i){
        for (int j = 0; j != points[0].size(); ++j){
            if (j & 1){
                maxY = max(points[i][j], maxY);
            }
            else{
                maxX = max(points[i][j], maxX);
            }
            // cout << points[i][j] << " ";
        }
        // cout << endl;
    }
    // cout << maxX << " " << maxY << endl;
    // cout << points.size() << endl;
    int count = 0;
    vector<vector<int>> covered(990, vector<int>(990, 0));

    for (int i = 0; i != points.size(); ++i){
        if (points[i][0] == points[i][2]){
            int upper = max(points[i][1], points[i][3]);
            int lower = min(points[i][1], points[i][3]);
            for (int j = lower; j <= upper; ++j){
                covered[points[i][0]][j]++;
            }
        }
        //else if, since a line seg that's just a point will be counted twice
        else if (points[i][1] == points[i][3]){
            int upper = max(points[i][0], points[i][2]);
            int lower = min(points[i][0], points[i][2]);
            for (int j = lower; j <= upper; ++j){
                covered[j][points[i][1]]++;
            }
        }
    }
    for (int i = 0; i != covered.size(); ++i){
        for (int j = 0; j != covered[0].size(); ++j){
            if (covered[i][j] > 1)
                count++;
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


