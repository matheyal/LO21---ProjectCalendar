#ifndef TACHEUNITAIRE
#define TACHEUNITAIRE

#include "timing.h"
#include "tache.h"
#include "qt.h"

class TacheUnitaire : public Tache {
private:
    Duree duree;

public:
    TacheUnitaire(const QString& ident, const QString& t, const Date& d,const Date& ech,const Duree& du,bool b=false):Tache(ident,t,d,ech,b),duree(du){std::cout<<"\ncreation d'une tache unitaire\n";}
    Duree getDuree() const{return duree;}
    void afficher(std::ostream& f)const {Evenement::afficher(f);std::cout<<"\nDuree : "<<getDuree();}
    void commencer();
    void setDuree(Duree d){duree=d;}
    //Définition de getSousTaches pour ne pas avoir de classe abstraite
    const vector<Tache*>* getSousTaches() const{return 0;}

};
std::ostream& operator<<(std::ostream& fout, const TacheUnitaire& t);

#endif // TACHEUNITAIRE

