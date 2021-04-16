//
// file: dial800.cpp 
// dialnum() converts 1-800-NUMBERS to a real number such as 1-800-COLLECT to 1-800-
// 
// 1-800 numbers (along with 1-888, 877, 866, 855 and 844) are toll free numbers that passes
// the expense for a call to a business, rather than the user making the call. If you’ve ever 
// watched television or listened to the radio, you’ll know that advertisers love to use 
// toll-free numbers to imprint your memory, in hopes it will lead to you patronizing their 
// business.
// 
// 1-800-COLLECT        1-800-2655328
// 1-800-flowers        1-800-3569377
// 1-800-taxicab        1-800-8294222
// 1-888-POPCORN        1-800-7672676
// 1-800-redcros        1-800-7337677
// 1-800-new-cars       1-800-639-2277
// 1-800-JET-BLUE       1-800-538-2583
// 1-800-GO-FEDEX       1-800-46-33339
// 
// Created by idebtor@gmail.com
// 

#include <iostream>
#include <vector>
using namespace std;

void dialnum(string& str) {
    cout << "your code here";
}

int main() {
    vector<string> list = { "1-800-COLLECT", "1-800-FLOWERS", "1-800-taxicab", "1-800-POPCORN", 
        "1-800-red-ross", "1-800-new-cars", "1-800-JET-BLUE", "1-800-GO-FED-EX" };
    for (auto x: list) {
        cout << x; 
        dialnum(x);
        cout << ": " << x << endl; 
    }

    while(1) {
        string str;
        cout << "Enter 1-800-XXXXXXX to convert or q to quit: ";
        getline(cin, str);
        if (str.front() == 'q') return 0;
        std::cout << str;
        dialnum(str);
        cout << ": " << str << endl; 
    } 
}
