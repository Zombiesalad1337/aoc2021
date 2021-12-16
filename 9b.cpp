#include <bits/stdc++.h>
#include <boost/tokenizer.hpp>

using namespace std;


vector<string> split(std::string s, const char* sep1, const char* sep2);
int BFS(int iq, int jq, vector<vector<int>>& points);


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
                // cout << i << endl;
                temp.emplace_back(i - '0');
            }
            points.emplace_back(temp);
        }
    }
    vector<vector<int>> lows;
    vector<vector<bool>> marked(points.size(), vector<bool>(points[0].size(), false)); 
    int m = points.size() - 1;
    int n = points[0].size() - 1;

    for (int i = 1; i != points.size() - 1; ++i){
        for (int j = 1; j != points[0].size() - 1; ++j){
            if (points[i][j] < min({points[i][j+1], points[i][j-1], points[i+1][j], points[i-1][j]}))
            {
                vector<int> temp = {i, j};
                lows.emplace_back(temp);
            }
        }
    }

    //corners
    if (points[0][0] < min(points[0][1], points[1][0]))
    {
        vector<int> temp = {0, 0};
        lows.emplace_back(temp);
    }
    if (points[points.size() - 1][points[0].size() - 1] < min(points[points.size() - 2][points[0].size() - 1], points[points.size() - 1][points[0].size() - 2]))
    {
        vector<int> temp = {m, n};
        lows.emplace_back(temp);
    }
    if (points[0][points[0].size() - 1] < min(points[0][points[0].size() - 2], points[1][points[0].size() - 1]))
    {
        vector<int> temp = {0, n};
        lows.emplace_back(temp);
    }
    if (points[points.size() - 1][0] < min(points[points.size() - 1][1], points[points.size() - 2][0]))
    {
        vector<int> temp = {m, 0};
        lows.emplace_back(temp);
    }
    //edges
    for (int j = 1; j != points[0].size() - 1; ++j){
        if (points[0][j] < min({points[1][j], points[0][j+1], points[0][j-1]}))
        {
            vector<int> temp = {0, j};
            lows.emplace_back(temp);
        }
        if (points[points.size() - 1][j] < min({points[points.size() - 2][j], points[points.size() - 1][j + 1], points[points.size() - 1][j - 1]}))
        {
            vector<int> temp = {m, j};
            lows.emplace_back(temp);
        }
    }
    for (int i = 1; i != points.size() - 1; ++i){
        if (points[i][0] < min({points[i][1], points[i + 1][0], points[i - 1][0]}))    
        {
            vector<int> temp = {i, 0};
            lows.emplace_back(temp);
        }
        if (points[i][n] < min({points[i - 1][n], points[i + 1][n], points[i][n - 1]}))
        {
            vector<int> temp = {i, n};
            lows.emplace_back(temp);
        }
    }

    // for (auto i : lows){
    //     for (auto x : i)
    //         cout << x << " ";
    //     cout << endl;
    // }

    vector<int> sizes;
    for (auto i : lows){
        sizes.emplace_back(BFS(i[0], i[1], points));
    }
    // for (auto i : sizes){
    //     cout << i << " ";
    // }
    // cout << endl;

    sort(sizes.begin(), sizes.end(), greater<int>());
    long long int res = sizes[0] * sizes[1] * sizes[2];
    cout << res << endl;

    return 0;
}


int BFS(int iq, int jq, vector<vector<int>>& points){
    int size = 0;
    vector<vector<bool>> marked(points.size(), vector<bool>(points[0].size(), false));

    queue<pair<int, int>> q;
    q.push(make_pair(iq, jq));
    marked[iq][jq] = true;
    size++;

    while (!q.empty()){
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        // cout << "x";
        // cout << i << " " << j << endl;

        if (i > 0 && points[i - 1][j] > points[i][j] && points[i-1][j] != 9){
            if (!marked[i-1][j]){
                size++;
                q.push(make_pair(i-1, j));
                marked[i-1][j] = true;
            }
        }
        if (i < points.size() - 1 && points[i + 1][j] > points[i][j] && points[i+1][j] != 9){
            if (!marked[i+1][j]){
                size++;
                q.push(make_pair(i+1, j));
                marked[i+1][j] = true;
            }
        }
        if (j < points[0].size() - 1 && points[i][j+1] > points[i][j] && points[i][j+1] != 9){
            if (!marked[i][j+1]){
                size++;
                q.push(make_pair(i, j+1));
                marked[i][j+1] = true;
            }
        }
        if (j > 0 && points[i][j-1] > points[i][j] && points[i][j-1] != 9){
            if (!marked[i][j-1]){
                size++;
                q.push(make_pair(i, j-1));
                marked[i][j-1] = true;
            }
        }
    }
    // cout << endl;
    return size;
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


