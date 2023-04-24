#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> data;
    int sum = 0;
    
    cout << "Enter the data (separated by spaces, end with -1): ";
    int d;
    while (cin >> d && d != -1) {
        data.push_back(d);
    }
    
    for (int d : data) {
        sum += d;
    }
    
    sum = ~(sum & 0xFF);
    
    cout << "Checksum: " << sum << endl;
    
    return 0;
}
