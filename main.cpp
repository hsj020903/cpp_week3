#include <iostream>
#include <string>
using namespace std;
string sum(string s1, string s2);
string sub(string s1, string s2);

int main(){
    string s1, s2, s3;

    cout << "First number   >> ";
    cin >> s1;
    cout << "Second number  >> ";
    cin >> s2;

    s3 = sum(s1, s2);
    cout << "Sum            >> " << s3 << endl;
    s3 = sub(s1, s2);
    cout << "Sub            >> " << s3;


    return 0;
}