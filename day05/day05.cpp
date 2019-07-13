#include "../reader.h"
#include "../md5.h"

int main(){
    vector<char> input = read("input.txt");
    string id = "";
    string hash = "";
    string pass1 = "";
    string pass2[8];
    int index = 0;
    int loc = 0;
    bool found = false;
    string loc_char;

    //convert input to string
    for(int i = 0; i < input.size(); i++){
        id += input[i];
    }
    //initialise pass2 array
    for(int i = 0; i < 8; i++){
        pass2[i] = "-";
    }


    while(!found){
        //generate hash from id followed by index
        hash = md5(id + to_string(index));
        if("00000" == (hash.substr(0,5))){
            //add to pass1
            loc_char = hash.substr(5,1);
            pass1 += loc_char;

            //check if location character is a valid number, and the character at that position has not been found
            if((stringstream(loc_char) >> loc) && loc < 8 && pass2[loc] == "-"){
                pass2[loc] = hash.substr(6,1);

                //check if password found
                found = true;
                for(int i = 0; i < 8; i++){
                    if(pass2[i] == "-") found = false;
                }
            }
        }
        index++;
    }

    std::cout << "Part 1, Password: " << pass1.substr(0,8) << endl;
    cout << "Part 2, Password: ";
    for(int i = 0; i < 8; i++){
        cout << pass2[i];
    }
    cout << endl;
    return 0;
}