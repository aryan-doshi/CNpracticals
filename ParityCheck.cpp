#include <iostream>
#include <bitset>

using namespace std;

int main() {
    bitset<8> data;
    int num_ones = 0;
    
    cout << "Enter the data (8 bits): ";
    cin >> data;
    
    for (int i = 0; i < 8; i++) {
        if (data[i]) {
            num_ones++;
        }
    }
    
    if (num_ones % 2 == 0) {
        data[7] = 1; // even parity
    }
    else {
        data[7] = 0; // odd parity
    }
    
    cout << "Parity bit: " << data[7] << endl;
    cout << "Data with parity: " << data << endl;
    
    return 0;
}
