#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <cstdint>
#include <iomanip>
#include <conio.h>
using namespace std;

uint8_t reverseBits(uint8_t b) {
        b = (b & 0xF0) >> 4 | (b & 0x0F) << 4;
        b = (b & 0xCC) >> 2 | (b & 0x33) << 2;
        b = (b & 0xAA) >> 1 | (b & 0x55) << 1;
        return b;
}

int main() {
    string text, temp;
    while (getline(cin, temp)) {
        if (temp == "") break;
        text += temp;
    }

    text.erase(0, 45);

    string result;
    for (size_t i = 0; i < text.size(); ++i) {
        char c = text[i];
        if (!isalnum(c) && c != 'x') continue;
        if (c == '0' && i + 1 < text.size() && text[i + 1] == 'x') {
            ++i;
            continue;
        }
        result += c;
    }

    vector <uint8_t> v;
    v.reserve(512);

    for (int i = 0; i < result.length(); i += 2) {
        uint8_t byte = stoi(result.substr(i, 2), nullptr, 16);
        byte = reverseBits(byte);
        v.push_back(byte);
    }

    for (int i = 0; i < v.size(); i++) {
        cout << uppercase << setw(2) << setfill('0') 
             << hex << (static_cast<unsigned>(static_cast<unsigned char>(v[i])));
        if ((i + 9) % 16 == 0 || i == 7)  cout << endl;
    }

    if (v.size() % 16 != 0)
    cout << endl;

    char a = getch();
    return 0;
}
