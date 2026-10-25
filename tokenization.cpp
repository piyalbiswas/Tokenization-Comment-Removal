#include <iostream>
#include <cctype>
using namespace std;
int main() {
    string s;
    cout << "Enter a string: ";
    getline(cin, s);
    for (int i = 0; s[i] != '\0'; ) {
        if (isspace(s[i])) {
            i++;
        }
        else if (isalpha(s[i])) {
            string t = "";
            while (isalnum(s[i]))
                t += s[i++];
            if (t == "int" || t == "float" || t == "char" ||
                t == "if" || t == "else" || t == "return")
                cout << t << " : Keyword\n";
            else
                cout << t << " : Identifier\n";
        }
        else if (isdigit(s[i])) {
            while (isdigit(s[i]))
                cout << s[i++];
            cout << " : Number\n";
        }
        else if (s[i] == '"' || s[i] == '\'') {
            char q = s[i];
            cout << s[i++];
            while (s[i] != q && s[i] != '\0')
                cout << s[i++];
            if (s[i] != '\0') cout << s[i++];
            cout << (q == '"' ? " : String\n" : " : Character\n");
        }
        else if (string("+-*/=%<>").find(s[i]) != string::npos) {
            cout << s[i++] << " : Operator\n";
        }
        else {
            cout << s[i++] << " : Special Symbol\n";
        }
    }
    return 0;
}
