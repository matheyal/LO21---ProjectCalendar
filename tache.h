#ifndef TACHE
#define TACHE

#include "timing.h"
#include "evenement.h"
#include <vector>
#include <QDate>

class Projet;
class Tache : public Evenement {
friend class Projet;
private:
    vector<Tache*> taches;
public:
    Tache(const QString& ident, const QString& t, const Date& d,const Date& ech): Evenement(ident,t,d,ech),taches(0){}
    virtual bool begun()=0;
    virtual bool terminated()=0;
};

std::ostream& operator<<(std::ostream& f, const Tache& t);


#endif // TACHE

