    #include "DupliCon.h"
    #include <iostream>
    #include <string>

    using namespace std;

    int main() {
        const string s = "applesauce";
        DupliCon<char> dc(s.begin(), s.end());
        dc.erase('c');
        cout << "Size should be 9: " << dc.size() << endl;
        cout << "Unique size should be 6: " << dc.unique_size() << endl;
        cout << "Should be aaeelppsu: ";
        for (char c : dc)
            cout << c;
        cout << endl;
    }


