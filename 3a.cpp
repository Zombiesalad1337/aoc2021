#include <bits/stdc++.h>

using namespace std;

int main(){


    ifstream fin;
    fin.open("input3.txt");
    string line;

    vector<int> bits(12, 0);

    while (fin){
        getline(fin, line);
        if (line.size()){
            for (int i = 0; i != 12; ++i){
                if (line[i] == '1')
                    bits[11 - i]++;
                else
                    bits[11 - i]--;
            }
        }
    }

    int gamma = 0;
    int epsilon = 0;

    for (int i = 0; i != 12; ++i){
        if (bits[i] >= 0){
            gamma += (int) pow(2, i);
        }
        if (bits[i] < 0){
            epsilon += (int) pow(2, i);
        }
    }
    long long int res = gamma * epsilon;
    cout << res << endl;


    return 0;
}