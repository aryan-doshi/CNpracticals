#include <iostream>
#include <bitset>

using namespace std;

int main() {
    bitset<7> data, encoded_data;
    
    cout << "Enter the data (4 bits): ";
    cin >> data;
    
    // Calculate parity bits
    encoded_data[2] = data[0] ^ data[1] ^ data[3];
    encoded_data[4] = data[0] ^ data[2] ^ data[3];
    encoded_data[5] = data[1] ^ data[2] ^ data[3];
    
    // Insert data and parity bits into encoded data
    encoded_data[0] = data[0];
    encoded_data[1] = data[1];
    encoded_data[3] = data[2];
    encoded_data[6] = data[3];
    
    cout << "Encoded data: " << encoded_data << endl;
    
    // Simulate a single-bit error
    encoded_data[2] = !encoded_data[2];
    
    // Correct error
    int error_pos = 0;
    error_pos += encoded_data[2] * 1;
    error_pos += encoded_data[4] * 2;
    error_pos += encoded_data[5] * 4;
    if (error_pos != 0) {
        encoded_data.flip(error_pos-1);
    }
    
    cout << "Corrected data: " << encoded_data << endl;
    
    return 0;
}
