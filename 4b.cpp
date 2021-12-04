#include <bits/stdc++.h>
#include <boost/tokenizer.hpp>

using namespace std;


vector<int> split(std::string s, const char* sep1, const char* sep2);

bool checkRow(vector<vector<vector<int>>>& bingos, int bingoNum, int rowNum);
bool checkCol(vector<vector<vector<int>>>& bingos, int bingoNum, int colNum);



int main(){


    ifstream fin;
    fin.open("input4.txt");
    string line;

    getline(fin, line);
    vector<int> draws = split(line, ",", ""); 
    // for (int i : draws){
    //     cout << i << " ";
    // }
    // cout << endl;
    getline(fin, line);
    vector<vector<vector<int>>> bingos;

    while (fin){
        vector<vector<int>> bingo;
        for (int i = 0; i != 5; ++i){
            getline(fin, line);
            bingo.emplace_back(split(line, " ", ""));
        }
        bingos.emplace_back(bingo);
        getline(fin, line);
    }
    // for (int i = 0; i != bingos.size(); ++i){
    //     for (int j = 0; j != bingos[0].size(); ++j){
    //         for (int k = 0; k != bingos[0][0].size(); ++k){
    //             cout << bingos[i][j][k] << " ";
    //         }
    //         cout << endl;
    //     }
    //     cout << endl;
    // } 
    long long int res;
    vector<bool> done(bingos.size(), false);
    for (int d : draws){
        for (int i = 0; i != bingos.size(); ++i){
            if (!done[i]){
                for (int j = 0; j != 5; ++j){
                    for (int k = 0; k != 5; ++k){
                        if (bingos[i][j][k] == d){
                            bingos[i][j][k] = -1;
                            if (checkRow(bingos, i, j) || checkCol(bingos, i, k)){
                                int sum = 0;
                                done[i] = true;
                                for (int l = 0; l != 5; ++l){
                                    for (int m = 0; m != 5; ++m){
                                        if (bingos[i][l][m] != -1){
                                            sum += bingos[i][l][m];
                                        }
                                    }
                                }
                                res = sum * d;
                            }
                        }
                    }
                }
            }
        }
    }
    cout << res << endl;

    return 0;
}

vector<int> split(std::string s, const char* sep1, const char* sep2)
{
    vector<int> tokens;
    boost::char_separator<char> sep(sep1, sep2);
    boost::tokenizer<boost::char_separator<char> > tok(s, sep);
    for(auto i = tok.begin(); i!=tok.end(); ++i)
        tokens.emplace_back(stoi(*i));
    return tokens;
}

bool checkRow(vector<vector<vector<int>>>& bingos, int bingoNum, int rowNum){
    for (int i = 0; i != 5; ++i){
        if (bingos[bingoNum][rowNum][i] != -1){
            return false;
        }
    }
    return true;
}
bool checkCol(vector<vector<vector<int>>>& bingos, int bingoNum, int colNum){
    for (int i = 0; i != 5; ++i){
        if (bingos[bingoNum][i][colNum] != -1){
            return false;
        }
    }
    return true;
}


