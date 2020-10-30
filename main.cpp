#include <iostream>
#include <map>
#include <fstream>
#include <vector>

using namespace std;

struct poster{
    int x1;
    int y1;
    int x2;
    int y2;

    poster(int x1, int y1, int x2, int y2){
        this -> x1 = x1;
        this -> y1 = y1;
        this -> x2 = x2;
        this -> y2 = y2;
    }
};

int main(){
    map<int, int> x_axis;
    map<int, int> y_axis;
    vector<poster> arr;

    ifstream fin("input.txt");

    int a;
    int b;
    int N;
    fin >> a >> b >> N;
    x_axis.insert(pair<int, int>(a, 0));
    y_axis.insert(pair<int, int>(b, 0));

    x_axis.insert(pair<int, int>(0, 0));
    y_axis.insert(pair<int, int>(0, 0));

    for(int i = 0; i < N; i++){                                                             //CREATION OF AXIS
        int x1;
        int y1;
        int x2;
        int y2;
        fin >> x1 >> y1 >> x2 >> y2;
        arr.push_back(poster(x1, y1, x2, y2));

        x_axis.insert(pair<int, int>(x1, 0));
        y_axis.insert(pair<int, int>(y1, 0));

        x_axis.insert(pair<int, int>(x2, 0));
        y_axis.insert(pair<int, int>(y2, 0));
    }

    /*for(map<int,int>::iterator i = x_axis.begin(); i != x_axis.end(); ++i){               //OUPUT OF AXIS
        cout << "x = " << i -> first << endl;
    }
    for(map<int,int>::iterator i = y_axis.begin(); i != y_axis.end(); ++i){
        cout << "y = " << i -> first << endl;
    }
    cout << endl;*/

    int table[x_axis.size() - 1][y_axis.size() - 1];                                        //CREATION OF TABLE
    for(int i = 0; i < x_axis.size() - 1; i++){
        for(int j = 0; j < y_axis.size() - 1; j++){
            table[i][j] = 0;
        }
    }
                                                                                            //FILLING OF TABLE
    for(int i = 0; i < arr.size(); i++){
        for(map<int, int>::iterator xit = x_axis.find(arr[i].x1); xit != x_axis.find(arr[i].x2); ++xit){
            for(map<int, int>::iterator yit = y_axis.find(arr[i].y1); yit != y_axis.find(arr[i].y2); ++yit){
                table[distance(x_axis.begin(), xit)][distance(y_axis.begin(), yit)]++;
            }
        }
    }

    for(int i = y_axis.size() - 2; i >= 0; i--){                                            //OUTPUT OF TALBE
        for(int j = 0; j < x_axis.size() - 1; j++){
            cout << table[j][i] << " ";
        }
        cout << endl;
    }

    return 0;
}
