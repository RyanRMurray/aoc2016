#include "../reader.h"
#include <map>

multimap<int, char> flip_freqs(map<char,int> &freqs){
    string alpha = "zyxwvutsrqponmlkjihgfedcba";
    multimap<int,char> output;
    for(char c: alpha){
        if(freqs.find(c) != freqs.end()){
            output.insert({freqs[c],c});
        }
    }
    return output;
}

int main(){
    vector<char> input = read("input.txt");
    vector<vector<char>> roomcodes;
    vector<vector<char>> real_rooms;
    vector<string> decoded_names;
    vector<map<char,int>> freqs; 
    vector<int> ids;
    vector<string> checksums;
    int ptr = 0;
    int id_total = 0;

    //get room codes
    while(ptr < input.size()){
        vector<char> in;
        while(input[ptr] != '\n' && ptr < input.size()){
            in.push_back(input[ptr]);
            ptr++;
        }
        roomcodes.push_back(in);
        ptr++;
    }

    //parse room codes
    for(int i = 0; i < roomcodes.size(); i++){
        map<char,int> freq;
        char checksum[5];
        ptr = 0;
        int id;
        char c = roomcodes[i][0];

        //count frequency of chars in names
        while(ptr < roomcodes[i].size() - 10){
            if(c != '-'){
                if(freq.find(c) != freq.end()){
                    freq[c]++;
                }else{
                    freq[c] = 1;
                }
            }
            ptr++;
            c = roomcodes[i][ptr];
        }
        freqs.push_back(freq);
        
        //get room id number
        id = 0;
        int id_c;
        while(c != '['){
            id = (id * 10) + (c - '0');
            ptr++;
            c = roomcodes[i][ptr];
        }
        ids.push_back(id);

        //get checksum
        ptr++;
        for(int j = 0; j < 5; j++){
            checksum[j] = roomcodes[i][ptr + j];
        }
        checksums.push_back(checksum);
    }

    //filter out fake rooms, sum real room ID numbers.
    for(int i = 0; i < roomcodes.size(); i++){
        multimap<int, char> flipped = flip_freqs(freqs[i]);
        bool real_room = true;
        multimap<int,char> :: iterator itptr = flipped.end();
        itptr--;

        for(int j = 0; j < 5; j++){
            if( (*itptr).second != checksums[i][j] ) real_room = false;
            itptr--;
        }

        if(real_room){
            id_total += ids[i];
            real_rooms.push_back(roomcodes[i]);
        }
    }

    //translate rooms
    for(int i = 0; i < roomcodes.size(); i++){
        vector<char> in_str = roomcodes[i];
        string decode = "";
        char d;
        int in_id = ids[i] % 26;
        
        //caesar shift letters and output to decoded_names
        for(int i = 0; i < in_str.size() - 11; i++){
            d = in_str[i];
            //cout << d;
            if(d == '-'){
                decode += ' ';
            }else{
                d += in_id;
                if(!isalpha(d)) d -= 26;
                decode += d;
            }
        }
        decoded_names.push_back(decode);
    }

    cout << "Part 1, ID Total: " << id_total << endl;

    cout << "Part 2, Prospective rooms: " << endl;

    for(int i = 0; i < decoded_names.size(); i++){
        size_t f = decoded_names[i].find("north");
        if(f != string::npos){
            cout <<  decoded_names[i] << ", ID = " << ids[i] << endl;
        }
    }

    return 0;
}