#ifndef TACHEUNITAIRE
#define TACHEUNITAIRE

#include "timing.h"
#include "tache.h"
#include "qt.h"

class TacheUnitaire : public Tache {
private:
    vector<Tache*> tachesPrecedentes;
    static const int DUREE_MAX = 12;
    Duree duree;

public:
    TacheUnitaire(const QString& ident, const QString& t, const Date& d,const Date& ech,const Duree& du):Tache(ident,t,d,ech),tachesPrecedentes(0),duree(du){std::cout<<"creation d'une tache unitaire";}
    Duree getDuree() const{return duree;}
    bool begun(){};
    bool terminated(){};
    void afficher(std::ostream& f)const {Evenement::afficher(f);std::cout<<"\nDuree : "<<duree;}
    void addItem(Tache* t);
    void afficherPrecedence() const;
    size_t getSizeVector(){return tachesPrecedentes.size();}

};
std::ostream& operator<<(std::ostream& fout, const TacheUnitaire& t);

#endif // TACHEUNITAIRE

