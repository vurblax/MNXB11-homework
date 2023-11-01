#ifndef HOMEWORK_H
#define HOMEWORK_H

#include "TObject.h"

class my_class : public TObject {
public:
    my_class(); 
    my_class(Int_t twentyfive);
    virtual ~my_class();

    void SetVariable(Int_t twentyfive);
    Int_t GetVariable() const;

private:

    ClassDef(my_class, 1);
};


#endif // HOMEWORK_H