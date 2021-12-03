#include <bits/stdc++.h>

using namespace std;

int main(){


    ifstream fin;
    fin.open("input3.txt");
    string line;

    int bitSize = 12;
    vector<int> bits(bitSize, 0);
    vector<string> vals;

    while (fin){
        getline(fin, line);
        if (line.size()){
            for (int i = 0; i != bitSize; ++i){
                if (line[i] == '1')
                    bits[bitSize - 1 - i]++;
                else
                    bits[bitSize - 1 - i]--;
            }
            vals.emplace_back(line);
        }
    }

    string prefixOxy = "";
    string prefixCo2 = "";
    string oxy;
    string co2;
    bool foundOxy = false;
    bool foundCo2 = false;

    vector<int> nextBitOxy(bitSize, 0);
    vector<int> nextBitCo2(bitSize, 0);
    nextBitOxy[0] = bits[bitSize - 1];
    nextBitCo2[0] = bits[bitSize - 1];

    for (int i = 0; i != bitSize; ++i){

        if (foundOxy && foundCo2){
            break;
        }

        if (nextBitOxy[i] >= 0){
            prefixOxy += "1";
        }
        else{
            prefixOxy += "0";
        }
        if (nextBitCo2[i] >= 0){
            prefixCo2 += "0";
        }
        else{
            prefixCo2 += "1";
        }

        int countOxy = 0;
        int countCo2 = 0;

        int indexOxy = 0;
        int indexCo2 = 0;

        for (int j = 0; j != vals.size(); ++j){
            if (!foundOxy && prefixOxy == vals[j].substr(0, i + 1)){
                countOxy++;
                indexOxy = j;
                if (i < bitSize - 1){
                    if (vals[j][i + 1] == '1'){
                        nextBitOxy[i + 1]++;
                    }
                    else{
                        nextBitOxy[i + 1]--;
                    }
                }
            }
            if (!foundCo2 && prefixCo2 == vals[j].substr(0, i + 1)){
                countCo2++;
                indexCo2 = j;
                if (i < bitSize - 1){
                    if (vals[j][i + 1] == '1'){
                        nextBitCo2[i + 1]++;
                    }
                    else{
                        nextBitCo2[i + 1]--;
                    }
                }
            }
        }
        if (countOxy == 1){
            oxy = vals[indexOxy];
            foundOxy = true;
        }
        if (countCo2 == 1){
            co2 = vals[indexCo2];
            foundCo2 = true;
        }

    }
    int oxygen = 0;
    int carbonDioxide = 0;
    for (int i = 0; i != bitSize; ++i){
        if (oxy[bitSize - 1 - i] == '1'){
            oxygen += (int) pow(2, i);
        }
        if (co2[bitSize - 1 - i] == '1'){
            carbonDioxide += (int) pow(2, i);
        }
    }
    long long int res = oxygen * carbonDioxide;

    cout << res << endl;

    return 0;
}