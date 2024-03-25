#include <iostream>
#include <string>
using namespace std;

string sum(string s1, string s2){
    string s3 ="";
    int a = s1.size();
    int b = s2.size();
    int j;
    int k = 0;
    int count;
    if(a > b){
        count = a - b;
        while(count > 0){
            count--;
            s2 = "0" + s2;
        }
    }
    else if(a < b){
        count = b - a;
        while(count > 0){
            count--;
            s1 = "0" + s1;
        }
    }
    a = s1.size();
    for(int i = 1; i <= a; i++){
            j = atoi(s1.substr(a-i, 1).c_str()) + atoi(s2.substr(a-i, 1).c_str()) + k;
            k = 0;
            if(j < 10){
                s3 = to_string(j) + s3;

            }
            else{
                s3 = to_string(j-10) + s3;
                k = 1;
            }
                
        }
        if(k == 1){
                s3 = "1" + s3;
        }
    return s3;
}