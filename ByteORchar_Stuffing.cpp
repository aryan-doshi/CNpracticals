#include <iostream>
#include <string>

using namespace std;

int main() {
    string data, stuffed_data = "";
    char start = '$', end = '#', escape = '*';
    
    cout << "Enter the data: ";
    cin >> data;
    
    stuffed_data += start;
    for (char c : data) {
        if (c == start || c == end || c == escape) {
            stuffed_data += escape;
        }
        stuffed_data += c;
    }
    stuffed_data += end;
    
    cout << "Stuffed data: " << stuffed_data << endl;
    
    return 0;
}
