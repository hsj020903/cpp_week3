#include <iostream>
#include <string>
using namespace std;

string sub(string s1, string s2){
    string s3 ="";
    int aSize = s1.size();
    int bSize = s2.size();
    string subs, dvsStr;
    int a, b, i, dvsInt, count;
    int k = 0, sign = 0;
    const int billion = 1000000000;

    if(aSize < bSize){ 
        subs = s1;
        s1 = s2;
        s2 = subs;
        sign = -1;
    }    
    else if(aSize == bSize){
        a = aSize/9;
        for(i = 0; i < a; i++){
            dvsInt = atoi(s1.substr(0 + (9 * i), 9).c_str()) - atoi(s2.substr(0 + (9 * i), 9).c_str());
            if(dvsInt < 0){
                subs = s1;
                s1 = s2;
                s2 = subs;
                sign = -1;
                break;
            }
            else if(dvsInt > 0){
                sign = 1;
                break;
            }
        }
        if(sign == 0 && aSize%9 != 0){
            dvsInt = atoi(s1.substr(aSize - aSize%9-1, aSize%9).c_str()) - atoi(s2.substr(bSize - bSize%9 -1, bSize%9).c_str());
            if(dvsInt < 0){
                subs = s1;
                s1 = s2;
                s2 = subs;
                sign = -1;
            }
            else if(dvsInt > 0){
                sign = 1;
            }
        }
        if(sign == 0)
            return "0";
    }

    aSize = s1.size();
    bSize = s2.size();
    count = 9 - aSize%9;
    while(count > 0){
        count--;
        s1 = "0" + s1;
    }

    aSize = s1.size();
    count = aSize - bSize;
    while(count > 0){
        count--;
        s2 = "0" + s2;
    }

    bSize = s2.size();
    a = aSize/9;
    for(i = 1; i <= a; i++){ 
        dvsInt = atoi(s1.substr(aSize - (9 * i), 9).c_str()) - atoi(s2.substr(bSize - (9 * i), 9).c_str()) - k;
        dvsStr = to_string(dvsInt);
        k = 0;
        if(dvsInt < 0){
            dvsStr = to_string(dvsInt + billion);
            k = 1;
        }
        while(dvsStr.size() < 9){
            dvsStr = "0" + dvsStr;
        }
        s3 = dvsStr + s3;
    }

    while(s3.substr(0, 1) == "0"){
        s3 = s3.erase(0, 1);
    }

    if(sign == -1)
        s3 = "-" + s3;
    
    return s3;
}