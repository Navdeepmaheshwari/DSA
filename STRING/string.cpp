#include <bits/stdc++.h>
using namespace std;

int main()
{
    // string s = "navdeep";
    string s;

    // cin >> s;
    //  when new line character or space occur "cin" stop reading
    //  so if i enter navdeep maheshwari it only read navdeep

    // *****getline()*****
    getline(cin, s); // it read complete string with space and new lone character

    cout << s << endl;
    cout << s.length() << endl;
    s = s + " iiit surat"; // concat maheshwari to string
    cout << s << endl;
    cout << s.length() << endl;
    cout << s.substr(1, 6) << endl; // give string starting from index 1 till 5
    cout << s.find("eep") << endl;  // give start index
}