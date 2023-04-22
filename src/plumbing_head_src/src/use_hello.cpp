#include "ros/ros.h"
#include "plumbing_head_src/hello.h"
#include <iostream>

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL,"");

    hello_ns::MyHello myhello;
    myhello.run();
   
    
    return 0;
}
   