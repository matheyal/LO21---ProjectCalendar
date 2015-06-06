#ifndef TACHEPREEMPTABLE
#define TACHEPREEMPTABLE

#include "timing.h"
#include "tacheunitaire.h"

class TachePreemptable : public TacheUnitaire {
private:
    vector<Tache*> tachesPrecedentes;
public:
    TachePreemptable(const QString& ident, const QString& t, const Date& d,const Date& ech,const Duree& du):TacheUnitaire(ident,t,d,ech, du), tachesPrecedentes(0){std::cout<<"qui est preemptable\n";}
    Duree getDuree() const{return getDuree();}
    void addItem(Tache *t);
    void afficherPrecedence() const;
    //void afficher(std::ostream& f)const {Evenement::afficher(f);std::cout<<"\nDuree : "<<getDuree();}

};

QTextStream& operator<<(QTextStream& fout, const TachePreemptable& t);
#endif // TACHEPREEMPTABLE

