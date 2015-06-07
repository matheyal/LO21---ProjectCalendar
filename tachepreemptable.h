#ifndef TACHEPREEMPTABLE
#define TACHEPREEMPTABLE

#include "timing.h"
#include "tacheunitaire.h"

class TachePreemptable : public TacheUnitaire {
private:
    bool enCours;
    Duree reste;
public:
    TachePreemptable(const QString& ident, const QString& t, const Date& d,const Date& ech,const Duree& du):TacheUnitaire(ident,t,d,ech, du), reste(getDuree()), enCours(false){std::cout<<"qui est preemptable\n";}
    //Duree getDuree() const{return getDuree();}
    //void afficher(std::ostream& f)const {Evenement::afficher(f);std::cout<<"\nDuree : "<<getDuree();}
    void commencer();
    bool getEnCours() const {return enCours;}
    void setEnCours(bool b){enCours=b;}
    Duree getReste() const {return reste;}
    void setReste(Duree r){reste=r;}
    void setReste(int r){Duree res(r);reste=res;}
    void interruption();
    void reprise();
};

QTextStream& operator<<(QTextStream& fout, const TachePreemptable& t);
#endif // TACHEPREEMPTABLE

