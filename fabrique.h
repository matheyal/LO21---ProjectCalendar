#ifndef FABRIQUE
#define FABRIQUE

#include "evenement.h"

class Fabrique {
private:

public:
    virtual Evenement& creation(const QString& ident, const QString& t, const Date& d,const Date& ech)=0;
};



#endif // FABRIQUE

