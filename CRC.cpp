#include <iostream>
#include <bitset>

using namespace std;

int main() {
    bitset<16> data, divisor, remainder;
    int data_size = 16, divisor_size = 4;
    
    cout << "Enter the data (16 bits): ";
    cin >> data;
    cout << "Enter the divisor (4 bits): ";
    cin >> divisor;
    
    for (int i = 0; i < data_size; i++) {
        if (i < divisor_size) {
            remainder[i] = data[i];
        }
        else if (remainder[0]) {
            remainder = (remainder << 1) ^ divisor;
            remainder[divisor_size-1] = data[i];
        }
        else {
            remainder = (remainder << 1) ^ 0;
            remainder[divisor_size-1] = data[i];
        }
    }
    
    cout << "Remainder: " << remainder << endl;
    cout << "Data with CRC: " << data << remainder << endl;
    
    return 0;
}
