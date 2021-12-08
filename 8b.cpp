#include <bits/stdc++.h>
#include <boost/tokenizer.hpp>

using namespace std;


vector<string> split(std::string s, const char* sep1, const char* sep2);
set<char> diff(set<char> s1, set<char> s2);
set<char> makeSet(string s);
set<char> intersect(set<char> s1, set<char> s2);
set<char> interList(vector<string> ls);

int main(){


    ifstream fin;
    fin.open("input8.txt");
    string line;

    long long int sum = 0;
    map<string, int> strToDigit;

    strToDigit["abcefg"] = 0;
    strToDigit["cf"] = 1;
    strToDigit["acdeg"] = 2;
    strToDigit["acdfg"] = 3;
    strToDigit["bcdf"] = 4;
    strToDigit["abdfg"] = 5;
    strToDigit["abdefg"] = 6;
    strToDigit["acf"] = 7;
    strToDigit["abcdefg"] = 8;
    strToDigit["abcdfg"] = 9;

    while (fin){
        getline(fin, line);
        if (line.size()){
            vector<string> splitted = split(line, "|", "");
            vector<string> left = split(splitted[0], " ", "");
            vector<string> output = split(splitted[1], " ", "");

            string one, four, seven, eight;
            vector<string> fives;
            vector<string> sixes;
            for (string i : left){
                if (i.size() == 2)
                    one = i;
                if (i.size() == 3)
                    seven = i;
                if (i.size() == 4)
                    four = i;
                if (i.size() == 7)
                    eight = i;
                if (i.size() == 5)
                    fives.emplace_back(i);
                if (i.size() == 6)
                    sixes.emplace_back(i);
            }        
            map<char, char> mapping;
            //comparing 1 and 7
            set<char> oneSet = makeSet(one);
            set<char> sevenSet = makeSet(seven);
            set<char> diffSevenOne = diff(sevenSet, oneSet); 
            mapping[*diffSevenOne.begin()] = 'a';
            // cout << *diffSevenOne.begin() << endl;

            //4 and 1
            set<char> fourSet = makeSet(four);
            set<char> diffFourOne = diff(fourSet, oneSet);

            //intersection of 5 letters
            set<char> interFives = interList(fives);
            interFives.erase(*diffSevenOne.begin());

            set<char> interFivesFourOne = intersect(interFives, diffFourOne);
            // cout << *interFivesFourOne.begin() << endl;
            mapping[*interFivesFourOne.begin()] = 'd';
            
            set<char> diffInterFivesInterFiveFourOnes = diff(interFives, interFivesFourOne);
            // cout << *diffInterFivesInterFiveFourOnes.begin() << endl;
            set<char> diffDiffFourOneInterFivesFourOne = diff(diffFourOne, interFivesFourOne);
            // cout << *diffDiffFourOneInterFivesFourOne.begin() << endl;
            
            mapping[*diffInterFivesInterFiveFourOnes.begin()] = 'g';
            mapping[*diffDiffFourOneInterFivesFourOne.begin()] = 'b';
            
            //intersection of 6 letters
            set<char> interSixes = interList(sixes);
            set<char> alreadyMapped;
            alreadyMapped.insert(*diffSevenOne.begin()); //d
            alreadyMapped.insert(*diffInterFivesInterFiveFourOnes.begin()); //c
            alreadyMapped.insert(*diffDiffFourOneInterFivesFourOne.begin()); // e

            set<char> diffInterSixesAlreadyMapped = diff(interSixes, alreadyMapped);
            // cout << *diffInterSixesAlreadyMapped.begin() << endl;
            mapping[*diffInterSixesAlreadyMapped.begin()] = 'f';

            set<char> otherOfOne = diff(oneSet, diffInterSixesAlreadyMapped);
            // cout << *otherOfOne.begin() << endl;
            mapping[*otherOfOne.begin()] = 'c';
            
            alreadyMapped.insert(*diffInterSixesAlreadyMapped.begin()); //b
            alreadyMapped.insert(*otherOfOne.begin()); // a
            // alreadyMapped.insert(*diffFourOne.begin()); //it is a set, not a single element
            alreadyMapped.insert(*interFivesFourOne.begin());


        //    for (auto i : alreadyMapped){
        //        cout << i << " ";
        //    } 
        //    cout << endl;

            set<char> eightSet = makeSet(eight);
            set<char> otherOfEight = diff(eightSet, alreadyMapped);
            // cout << *otherOfEight.begin() << endl;
            mapping[*otherOfEight.begin()] = 'e';
            // for (auto i : interFives){
            //     cout << i << " ";
            // }
            int digit = 0;
            for (string i : output){
                string mapped = "";
                for (char x : i){
                    mapped += mapping[x];
                }
                // cout << "mapped:  " << mapped << endl;
                sort(mapped.begin(), mapped.end());
                // cout << mapped << "    " << strToDigit[mapped] << endl;
                digit *= 10;
                digit += strToDigit[mapped];
            }
            // cout << digit << endl;
            sum += digit;
            // for (auto i : mapping){
            //     cout << i.first << " " << i.second << endl;
            // }
            // for (auto i : strToDigit){
            //     cout << i.first << " " << i.second << endl;
            // }
        }
    }

    cout << sum << endl;
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

set<char> diff(set<char> s1, set<char> s2){
    set<char> result;
    set_difference(s1.begin(), s1.end(), s2.begin(), s2.end(),
    inserter(result, result.end()));
    return result;
}
set<char> makeSet(string s){
    set<char> result;
    for (char i : s)
        result.insert(i);
    return result;
}

set<char> intersect(set<char> s1, set<char> s2){
    set<char> result;
    set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(result, result.begin()));
    return result;
}

set<char> interList(vector<string> ls){
    set<char> one = makeSet(ls[0]);
    set<char> two = makeSet(ls[1]);
    set<char> three = makeSet(ls[2]);

    set<char> intersection = intersect(one, two);
    intersection = intersect(intersection, three);
    return intersection;
}

    