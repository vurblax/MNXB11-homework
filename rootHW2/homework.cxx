#include "homework.h"
#include <iostream>
#include "TObject.h"

ClassImp(my_class)

my_class::my_class(){
}

my_class::my_class(Int_t variable)
{
    SetVariable(variable);

    Int_t value = GetVariable();
    std::cout << "Value of variable 'twentyfive': " << value << std::endl;
}

my_class::~my_class(){
}
