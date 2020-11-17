//
// Created by zjhar on 2020/9/12.
//

#include <iostream>

void helloworld(){
    std::cout << "Hello, World!" <<std::endl;
}

int pseudomain()
{
    helloworld();
    return 0;
}


int helper()
{
    std::cout << 3+4 << std::endl;
    std::cout << "This (\") is a quote, \tand this (\\) is a backslash" << std::endl;
    //这样我们可以
    // 进行 // /*
    // 多行注释 */
}
