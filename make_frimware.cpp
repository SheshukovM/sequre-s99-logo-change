#include <iostream>
#include <fstream>
#include <vector>
#include <cstdint>
#include <sstream>
#include <iomanip>
#include <conio.h>

using namespace std;


void change_checksum(string& hex_line) {
    vector<uint8_t> bytes;
    int sum = 0;

    for (size_t i = 1; i < hex_line.length() - 2; i += 2) {
        int byte;
        stringstream ss;
        ss << hex << hex_line.substr(i, 2);
        ss >> byte;
        bytes.push_back(static_cast<uint8_t>(byte));
        sum += byte;
    }

    uint8_t checksum = static_cast<uint8_t>(-sum & 0xFF);

    stringstream result;
    result << hex_line.substr(0, hex_line.length() - 2);
    result << setw(2) << setfill('0') << uppercase << hex << (int)checksum;

    hex_line = result.str();
}

void change_string(string &p, const string s,int pos) {
    p.replace(pos, s.length(), s);
    change_checksum(p);
}

string make_digit(string s){
    string result;
    for (size_t i = 0; i < s.length(); i += 4) {
        string byte1 = s.substr(i, 2);
        string byte2 = s.substr(i + 2, 2);

        uint8_t b1 = stoi(byte1, nullptr, 16);
        uint8_t b2 = stoi(byte2, nullptr, 16);

        uint16_t combined = (b1 << 8) | b2;

        combined <<= 2;

        stringstream ss;
        ss << hex << setw(4) << setfill('0') << uppercase << combined;
        result += ss.str();
    }
    return result;
}

int main() {
//================ reading file ==================
    fstream file;
    file.open("S99_V1.08.hex", ios::in);
    if (!file.is_open()) {
        cerr << "Error opening file!" << endl;
        return -1;
    }

    int n;
    cout << "Enter bytearray:" << endl;
    
    int ind = 0;
    vector<string> text(3800);

    while (getline(file, text[ind])) {
        ++ind;
    }

    file.close();

    vector<string> code(33);
    for (int i = 0; i < 33; ++i) {
        getline(cin, code[i]);
    }

    code[0] = "0000000000000000" + code[0];
    code[32] += "0000000000000000";



// ==================== fixing 1 ==================
{
    string temp = code[15]+code[16]+code[17];
    string one =  temp.substr(20,4)
                + temp.substr(28,4)
                + temp.substr(36,4)
                + temp.substr(44,4)
                + temp.substr(52,4)
                + temp.substr(60,4)
                + temp.substr(68,4)
                + temp.substr(76,4);

    string new_image = make_digit(one);

    change_string(text[2279],new_image.substr(0,28),13);
    change_string(text[2280],new_image.substr(28,4),9);
}

//=================== fixing . ====================

{
    string temp = code[17]+code[18];
    string one =  temp.substr(28,4)
                + temp.substr(36,4)
                + temp.substr(44,4)
                + temp.substr(52,4)
                + temp.substr(60,4);

    string new_image = make_digit(one);

    change_string(text[2289],new_image.substr(0,20),13);
}

//=================== fixing 0 ====================
{
    string temp = code[19]+code[20];
    string one =  temp.substr(4,4)
                + temp.substr(12,4)
                + temp.substr(20,4)
                + temp.substr(28,4)
                + temp.substr(36,4)
                + temp.substr(44,4)
                + temp.substr(52,4)
                + temp.substr(60,4);

    string new_image = make_digit(one);

    change_string(text[2278],new_image.substr(0,28),13);
    change_string(text[2279],new_image.substr(28,4),9);
}


//=================== fixing 8 ====================
{
    string temp = code[21]+code[22]+code[23];
    string one =  temp.substr(12,4)
                + temp.substr(20,4)
                + temp.substr(28,4)
                + temp.substr(36,4)
                + temp.substr(44,4)
                + temp.substr(52,4)
                + temp.substr(60,4)
                + temp.substr(68,4);

    string new_image = make_digit(one);

    change_string(text[2286],new_image.substr(0,28),13);
    change_string(text[2287],new_image.substr(28,4),9);
}



//=============== changing main picture ===========

    for (int i = 0; i < 33; ++i) {
        change_string(text[3274 + i], code[i],9);
    }
    
//================ making new file ================
    fstream outFile;
    outFile.open("new_firmware.hex", ios::out);
    if (!outFile.is_open()) {
        cerr << "Error opening file for writing!" << endl;
        return -1;
    }

    for (const string &line : text) {
        outFile << line << endl;
    }

    outFile.close();
    cout << "New firmware file created successfully!\npress any key to exit";

    char a = getch();
    return 0;
}
