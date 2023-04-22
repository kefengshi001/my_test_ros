#ifndef _HELLO_H    //头文件保护
#define _HELLO_H
/*
    申明 namespace
        |--class
            |--run
*/
namespace hello_ns {

    class MyHello{

    public:
        void run();  
    };
    
}

#endif

/*
    编辑完头文件后需要配置 .vscode 下 c_cpp_properties.json 的 includepath属性
*/