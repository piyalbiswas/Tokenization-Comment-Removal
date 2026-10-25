#include <iostream>
using namespace std;
int main() {
    string s;
    bool c = false;
    while (getline(cin, s)) {
        for (int i = 0; s[i]; i++) {
            if (c) {
                if (s[i] == '*' && s[i+1] == '/') {
                    c = false;
                    i++;
                }
            }
            else if (s[i] == '/' && s[i+1] == '/')
                break;
            else if (s[i] == '/' && s[i+1] == '*') {
                c = true;
                i++;
            }
            else cout << s[i];
        }
        cout << '\n';
    }
}
