#ifndef EVENEMENT
#define EVENEMENT

#include "timing.h"
#include "qt.h"

using namespace std;

using namespace TIME;

class Evenement {
protected:
    QString id;
    QString titre;
    Date dispo;
    Date echeance;
    bool estProg;
public:
<<<<<<< HEAD
    Evenement(const QString& ident, const QString& t, const Date& d,const Date& ech, bool estProg=false):id(ident),titre(t),dispo(d),echeance(ech){std::cout<<"creation d'un evenement";}
=======
    Evenement(const QString& ident, const QString& t, const Date& d,const Date& ech):id(ident),titre(t),dispo(d),echeance(ech){std::cout<<"creation d'un evenement\n";}
>>>>>>> a6cd4216acc54cca3aec88cf4c12149b93bf0892
    QString getId() const{return id;}
    bool getStatus()const {return estProg;}
    QString getTitre() const{return titre;}
    Date getDate() const{return dispo;}
    Date getEcheance() const{return echeance;}
    void setTitre(const QString& t) {titre = t;}
    void setDateDisponibilite(const Date& d) {dispo = d;}
    void setEcheance(const Date& ech) {echeance = ech;}
    virtual void setEffectue(bool effect) {estProg=effect;}
    virtual ~Evenement() {}
    virtual QString Type() const=0;
    virtual void afficher(std::ostream& f) const{
        f<<"\nID : "<<qPrintable(id)<<"\nTitre : "<<qPrintable(titre)<<"\nDispo : "<<dispo<<"\nEcheance : "<<echeance<< " \nEst programmé:"<<estProg;
    }
    bool operator<(const Evenement& e)const
    {
        return dispo<e.dispo && echeance<e.echeance;
    }

    //methode pour savoir si est programme ou pas (virtuelle) -> voir avec aude
};

std::ostream& operator<<(std::ostream& fout, const Evenement& e);
bool operator ==(const Evenement& e1, const Evenement& e2);


#endif // EVENEMENT

