#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int main(){
    fstream fin;
    string line;
    int sum = 0;

    fin.open("input1.txt");
    
    vector<int> window;
    //getting first 3 inputs
    for (int i = 0; i != 3; ++i){
        getline(fin, line);
        int curr = stoi(line);
        window.emplace_back(curr);
        sum += curr;
    }
    int prevSum = sum;
    int count = 0;
    while (fin){
        getline(fin, line);
        if (line.size()){
            int curr = stoi(line);
            sum += curr;
            sum -= window[0];
            if (sum > prevSum){
                count++;
            }
            prevSum = sum;
            window[0] = window[1];
            window[1] = window[2];
            window[2] = curr;
        }
    }
    cout << count << endl;
    return 0;
}