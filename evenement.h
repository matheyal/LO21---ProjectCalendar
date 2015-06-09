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
    Evenement(const QString& ident, const QString& t, const Date& d,const Date& ech, bool b=false):id(ident),titre(t),dispo(d),echeance(ech), estProg(b){std::cout<<"\ncreation d'un evenement";}
    QString getId() const{return id;}
    bool getStatus()const {return estProg;}
    QString getTitre() const{return titre;}
    Date getDate() const{return dispo;}
    Date getEcheance() const{return echeance;}
    void setTitre(const QString& t) {titre = t;}
    void setDateDisponibilite(const Date& d) {dispo = d;}
    void setEcheance(const Date& ech) {echeance = ech;}
    void setEffectue(bool effect){estProg=effect;}
    virtual ~Evenement() {}
    virtual QString Type() const=0;
    virtual void afficher(std::ostream& f) const{
        f<<"\n\nID : "<<qPrintable(id)<<"\nTitre : "<<qPrintable(titre)<<"\nDispo : "<<dispo<<"\nEcheance : "<<echeance<< " \nEst programme:";
        if (estProg) f<<"vrai";
        else f<<"faux";
    }
    bool operator<(const Evenement& e)const
    {
        return dispo<e.dispo && echeance<e.echeance;
    }
};

std::ostream& operator<<(std::ostream& fout, const Evenement& e);
bool operator ==(const Evenement& e1, const Evenement& e2);


#endif // EVENEMENT

