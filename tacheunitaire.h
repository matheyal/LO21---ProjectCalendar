#ifndef TACHEUNITAIRE
#define TACHEUNITAIRE

#include "timing.h"
#include "tache.h"
#include "qt.h"

class TacheUnitaire : public Tache {
private:
    static const int DUREE_MAX = 12;
    Duree duree;

public:
    TacheUnitaire(const QString& ident, const QString& t, const Date& d,const Date& ech,const Duree& du):Tache(ident,t,d,ech),duree(du){std::cout<<"creation d'une tache unitaire\n";}
    Duree getDuree() const{return duree;}
    bool begun(){};
    bool terminated(){};
    void afficher(std::ostream& f)const {Evenement::afficher(f);std::cout<<"\nDuree : "<<getDuree();}
    void commencer();
    void setDuree(Duree d){duree=d;}

};
std::ostream& operator<<(std::ostream& fout, const TacheUnitaire& t);

#endif // TACHEUNITAIRE

