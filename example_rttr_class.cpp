#include "example_rttr_class.h"


example_autoreg::example_autoreg(const std::string& data)
: _data(data)
{
}

int example_autoreg::example_func_no_reflect()
{
    return 0;
}

int example_autoreg::example_func_reflect(int param_name)
{
    return param_name * 2;
    
}

void example_autoreg::example_func_no_return(int a, int b)
{
}
