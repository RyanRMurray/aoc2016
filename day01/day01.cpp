#include "../reader.h"
using namespace std;

int main(){
    vector<char> input = read("input.txt");
    enum Directions{N,E,S,W};
    Directions dir = N;
    int steps = 0;
    int north = 0;
    int east = 0;
    int baseDistance = 0;
    vector<int> norths;
    vector<int> easts;
    bool found = false;

    for(int i = 0; i < input.size(); i++){
        //change direction based on Left or Right instruction
        if(input[i] == 'L'){
            switch (dir){
                case N: dir = W; break;
                case E: dir = N; break;
                case S: dir = E; break;
                case W: dir = S; break;
            }
        }else{
            switch (dir){
                case N: dir = E; break;
                case E: dir = S; break;
                case S: dir = W; break;
                case W: dir = N; break;
            }
        }
        i++;
        //find number of steps to take
        steps = 0;
        while(input[i] != ',' && i < input.size()){
            steps = (steps*10) + (input[i] - '0');
            i++;
        }
        i++;
        //record north and east steps
        for(int s = steps; s > 0; s--){
            switch(dir){
                case N: north += 1; break;
                case E: east += 1; break;
                case W: east -= 1; break;
                case S: north -= 1; break;
            }

            //check if north and east steps direct to location visited previously
            if(!found){
                for(int j = 0; j < norths.size(); j++){
                    if(north == norths[j]){
                        if(east == easts[j]){
                            found = true;
                            baseDistance = abs(north) + abs(east);
                        }
                    }
                }
                //push current coordinates to the vectors
                norths.push_back(north);
                easts.push_back(east);
            }
        }
    }

    int distance = abs(north) + abs(east);

    cout << "Part 1, Distance: " << distance << endl;
    cout << "Part 2, Distance: " << baseDistance << endl;
    return 0;
}


