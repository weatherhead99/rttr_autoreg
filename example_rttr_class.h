#pragma once
#include <rttr/registration>
#include <string>

class example_autoreg
{
public:
    
    example_autoreg(const std::string& data);
    
    void example_func_no_return(int a, int b); //@reflect
    
    int example_func_no_reflect();
    
    int example_func_reflect(int param_name); //@reflect
    
private:
    std::string _data;
      
};
