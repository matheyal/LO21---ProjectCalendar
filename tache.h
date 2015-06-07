#ifndef TACHE
#define TACHE

#include "timing.h"
#include "evenement.h"
#include <vector>
#include "qt.h"

class Projet;

class Tache : public Evenement {
friend class Projet;
private:
    //vector<Tache*> taches;
public:
    QString Type() const {return typeid(*this).name();}
    Tache(const QString& ident, const QString& t, const Date& d,const Date& ech): Evenement(ident,t,d,ech){std::cout<<"creation d'une tache";}
    virtual bool begun()=0;
    virtual bool terminated()=0;
    virtual void afficher(std::ostream& f)const {Evenement::afficher(f);}
};

std::ostream& operator<<(std::ostream& f, const Tache& t);


#endif // TACHE

