#ifndef TACHEUNITAIRE
#define TACHEUNITAIRE

#include "timing.h"
#include "tache.h"
#include <QDate>

class TacheUnitaire : public Tache {
private:
    static const int DUREE_MAX = 12;
    Duree duree;

public:
    TacheUnitaire(const QString& ident, const QString& t, const Date& d,const Date& ech,const Duree& du):Tache(ident,t,d,ech),duree(du){}
    Duree getDuree() const{return duree;}
    bool begun(){};
    bool terminated(){};
};
std::ostream& operator<<(std::ostream& fout, const TacheUnitaire& t);

#endif // TACHEUNITAIRE

