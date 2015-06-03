#ifndef TACHEUNITAIRE
#define TACHEUNITAIRE

#include "timing.h"
#include "tache.h"

class TacheUnitaire : public Tache {
private:
    static const int DUREE_MAX = 12;
    Duree duree;
    TacheUnitaire(const QString& ident, const QString& t, const Date& d,const Date& ech,const Duree& du):Tache(ident,t,d,ech),duree(du){}

public:
    Duree getDuree() {return duree;}
};

#endif // TACHEUNITAIRE

