//
// Created by Daisy on 2020/10/13.
//

# include "iostream"
#include <string>

using std::cin; using std::endl;
using std::cout;using std::string;


int loop_greetings()
{
    cout << "please input your name";

    string name;
    cin >> name;

    cout << "please input the pad size you want";

    int pad = 0;
    cin >> pad;

    const string greetings = "Hello, " + name + "!";
    const int rows = pad*2 + 3;
    const string::size_type cols = greetings.size() + pad*2 + 2;

    cout << endl;

    for(int r = 0; r!=rows; ++r){
        string::size_type c = 0;
        while (c!=cols){
            if(r==pad+1 && c == pad+1){
                cout << greetings;
                c += greetings.size();
            }else{
                if(c == 0 || c == cols-1 || r == 0 || r == rows -1)
                    cout << "*";
                else
                    cout << " ";
                ++c;
            }
        }
        cout << endl;
    }
    return 0;
}

int bigger()
{
    int number1, number2;
    cout << "please input 2 numbers";
    cin >> number1 >> number2;

    if(number2<number1){
        cout << number1 << " is bigger than " << number2;
    }
    else if(number2 == number1){
        cout << number1 << " is the same with " << number2;
    }
    else{
        cout << number2 << " is bigger than " << number1;

    }
    cout << endl;
}