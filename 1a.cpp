#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    ifstream fin;
    fin.open("input1.txt");
    string line;
    int prev;
    getline(fin, line);
    prev = stoi(line);

    int count = 0;
    while (fin){
        getline(fin, line);
        if (line.size() != 0){
            int curr = stoi(line);
            if (curr > prev){
                count++;
            }
            prev = curr;
        }
        cout << line << endl;
    }
    fin.close();
    cout << count << endl;
    return 0;
}