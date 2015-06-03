#ifndef FABRIQUE
#define FABRIQUE

#include "evenement.h"

class Fabrique {
private:

public:
    virtual Evenement& ajouterTacheUnitaire(const QString& id, const QString& t, const Date& dispo, const Date& deadline, const Duree& dur)=0;
    virtual Evenement& ajouterTachePreemptable(const QString& id, const QString& t, const Date& dispo, const Date& deadline, const Duree& dur)=0;
    virtual Evenement& ajouterTacheComposite(const QString& id, const QString& t, const Date& dispo, const Date& deadline)=0;


};



#endif // FABRIQUE

