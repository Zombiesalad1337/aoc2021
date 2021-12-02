#include <bits/stdc++.h>

using namespace std;

int main(){

    int hor = 0;
    int aim = 0;
    long long int ver = 0; 
    ifstream fin;
    fin.open("input2.txt");
    string line;

    while (fin){
        getline(fin, line);
        if (line.size()){
            if (line[0] == 'f'){
                int x;
                x = stoi(line.substr(8, line.size() - 1));
                hor += x;
                ver += aim * x;
            }
            if (line[0] == 'u'){
                aim -= stoi(line.substr(3, line.size() - 1));
            }
            if (line[0] == 'd'){
                aim += stoi(line.substr(5, line.size() - 1));
            }
        }
    }
    long long res = hor * ver;
    cout << res << endl;


    return 0;
}