#ifndef FABRIQUEACTIV
#define FABRIQUEACTIV

#include "fabrique.h"
#include "activite.h"

class FabriqueActiv : public Fabrique {
private:

public:
    Activite& creation(const QString& ident, const QString& t, const Date& d,const Date& ech,const Duree& du);
};


#endif // FABRIQUEACTIV

