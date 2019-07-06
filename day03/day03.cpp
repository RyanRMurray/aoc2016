#include "../reader.h"
#include <sstream>

class triangle{
    public:
    int a;
    int b;
    int c;

    triangle(int na, int nb, int nc){
        a = na;
        b = nb;
        c = nc;
    }
};

int main(){
    vector<char> input = read("input.txt");
    vector<triangle> ts;
    vector<triangle> ts2;
    char in[48];
    int k;
    int side;
    int sides[9];
    stringstream ss;
    string temp;
    int possible = 0;
    int possible2 = 0;

    //generate triangles
    for(int i = 0; i < (input.size()/48) + 1; i++){
        k = 0;
        //parse line into a string
        for(int j = 0; j < 48; j++){
            in[j] = input[(i*48)+j];
        }
        ss << in;
        while(k < 9){
            //extract substrings as integers
            ss >> temp;
            if(stringstream(temp) >> side){
                sides[k] = side;
                k++;
            }
        }
        //generate triangles
        ts.push_back(triangle(sides[0],sides[1],sides[2]));
        ts.push_back(triangle(sides[3],sides[4],sides[5]));
        ts.push_back(triangle(sides[6],sides[7],sides[8]));

        ts2.push_back(triangle(sides[0],sides[3],sides[6]));
        ts2.push_back(triangle(sides[1],sides[4],sides[7]));
        ts2.push_back(triangle(sides[2],sides[5],sides[8]));
    }

    //count possible triangles
    for(int i = 0; i < ts.size(); i++){
        int a = ts[i].a;
        int b = ts[i].b;
        int c = ts[i].c;
        int a2 = ts2[i].a;
        int b2 = ts2[i].b;
        int c2 = ts2[i].c;

        if((a+b > c)&&(a+c > b)&&(c+b > a)) possible++;
        if((a2+b2 > c2)&&(a2+c2 > b2)&&(c2+b2 > a2)) possible2++;
    }

    cout << "Part 1, triangles: " << possible << endl;
    cout << "Part 2, triangles: " << possible2 << endl;

    return 0;
}