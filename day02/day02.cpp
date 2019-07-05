#include "../reader.h"
using namespace std;

int main(){
    vector<char> input = read("input.txt");
    char pad[3][3] = {{'1','2','3'},
                      {'4','5','6'},
                      {'7','8','9'}};
    char dpad[5][5] = {{'0','0','1','0','0'},
                       {'0','2','3','4','0'},
                       {'5','6','7','8','9'},
                       {'0','A','B','C','0'},
                       {'0','0','D','0','0'}};
    int x = 1;
    int y = 1;
    int dx = 1;
    int dy = 1;
    string code = "";
    string dcode = "";

    //simple switch that checks for exterior collisions
    for(int i = 0; i < input.size(); i++){
        while(input[i] != '\n' && i < input.size()){
            switch(input[i]){
                case 'U': 
                    if(y != 0) y--; 
                    if(dy != 0 && dpad[dy-1][dx] != '0') dy--;
                break;
                case 'D': 
                    if(y != 2) y++; 
                    if(dy != 4 && dpad[dy+1][dx] != '0') dy++;
                break;
                case 'L': 
                    if(x != 0) x--; 
                    if(dx != 0 && dpad[dy][dx-1] != '0') dx--;
                break;
                case 'R': 
                    if(x != 2) x++; 
                    if(dx != 4 && dpad[dy][dx+1] != '0') dx++;
                break;
            }
            i++;
        }
        code += pad[y][x];
        dcode += dpad[dy][dx];
    }

    cout << "Part 1, code: " << code << endl;
    cout << "Part 2, code: " << dcode << endl;
}