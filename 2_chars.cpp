//
// Created by zjhar on 2020/9/12.
//

#include <iostream>
#include <string>

int psmain()
{
    std::cout << "please enter your first name: ";
    std::string name;
    std::cin >> name;

    const std::string greetings = " Hello, " + name + "! ";
    const std::string spaces(greetings.size(),' ');
    const std::string second = "*" + spaces + "*";
    const std::string first(greetings.size()+2,'*');


    std::cout << std::endl;
    std::cout << first << std::endl;
    std::cout << second << std::endl;
    std::cout << '*' << greetings << '*' << std::endl;
    std::cout << second << std::endl;
    std::cout << first << std::endl;
    return 0;
}

int greeting()
{
    std::cout << "what is your name?";
    std::string name1;
    std::string name2;
    std::cin >> name1 >> name2;
    std::cout << "Hello, " << name1
              << std::endl
              << "And what is yours?" << std::endl;
    std::cout << "Hello, " << name2
              << "; nice to meet you!" << std::endl;

    return 0;
}
