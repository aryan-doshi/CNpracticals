#include <iostream>
#include <string>

using namespace std;

int main() {
    string data, stuffed_data = "";
    int count = 0;
    
    cout << "Enter the data: ";
    cin >> data;
    
    for (char c : data) {
        stuffed_data += c;
        if (c == '1') {
            count++;
            if (count == 5) {
                stuffed_data += '0';
                count = 0;
            }
        }
        else {
            count = 0;
        }
    }
    
    cout << "Stuffed data: " << stuffed_data << endl;
    
    return 0;
}
