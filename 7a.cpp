#include <bits/stdc++.h>
#include <boost/tokenizer.hpp>

using namespace std;


vector<string> split(std::string s, const char* sep1, const char* sep2);


int main(){


    ifstream fin;
    fin.open("input7.txt");
    string line;

    vector<int> pos;
    getline(fin, line);
    vector<string> tokens = split(line, ",", "");
    for (string i : tokens){
        pos.emplace_back(stoi(i));
    }
    sort(pos.begin(), pos.end());
    // cout << pos.size() << endl;

    int maxCount = 0;
    int count = 0;
    vector<int> maxAtSamePlace;
    for (int i = 1; i != pos.size(); ++i){
        if (pos[i] == pos[i - 1]){
            count++;
            maxCount = max(count, maxCount);
        }
        else
            count = 0;
    }
    // cout << maxCount + 1 << endl;

    count = 0;
    for (int i = 1; i != pos.size(); ++i){
        if (pos[i] == pos[i - 1]){
            count++;
            if (count == maxCount){
                maxAtSamePlace.emplace_back(pos[i]);
            }
        }
        else
            count = 0;
    }

    // for (int i : maxAtSamePlace){
    //     cout << i << " ";
    // }
    // cout << endl;
    
    // vector<int> minFuel;
    // for (int n : maxAtSamePlace){
    //     int sum = 0;
    //     for (int i : pos){
    //         sum += abs(n - i);
    //     }
    //     minFuel.emplace_back(sum);
    // }
    // for (int i : pos){
    //     cout << i << " ";
    // }
    // cout << endl;
    // cout << pos[0] << " " << pos.back() << endl;
    // cout << minFuel.size() << endl;
    // sort(minFuel.begin(), minFuel.end());
    // cout << minFuel[0] << endl;

    int minSum = INT32_MAX; 
    int minPos = -1;
    for (int i = 0; i != pos.size(); ++i){
        int sum = 0;
        for (int j = 0; j != pos.size(); ++j){
            sum += abs(pos[i] - pos[j]);
        }
        if (sum < minSum){
            minSum = sum;
            minPos = pos[i];
        }
    }
    cout << minSum << endl;
    // cout << minPos << endl;
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


