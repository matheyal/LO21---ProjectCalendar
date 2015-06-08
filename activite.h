#ifndef ACTIVITE
#define ACTIVITE

using namespace std;
#include "qt.h"
#include "timing.h"
#include "evenement.h"
#include "calendar.h"
#include <vector>
#include <sstream>
#include <iostream>
#include <typeinfo>

class Activite : public Evenement {
protected:
    Duree duree;
    QString lieu;
public:
    Activite(const QString& ident, const QString& t, const Date& d,const Date& ech,const Duree& du,const QString& li,bool b=false): Evenement(ident,t,d,ech,b), duree(du),lieu(li){}
    const Duree& getDuree()const{return duree;}
    const QString& getLieu()const{return lieu;}
    void setLieu(QString newLieu) { lieu = newLieu; }
    void setDuree(Duree newDuree) { duree = newDuree; }
    QString Type() const {return typeid(*this).name();}
    void afficher(std::ostream& f) const {
         Evenement::afficher(f);
         f<<"\nDuree="<<duree<<"\nLieu="<<lieu.toStdString()<<"\n";
    }
    ~Activite() {}

};

class Reunion : public Activite {
private:
    vector<QString> participants;
public:
    Reunion(const QString& ident, const QString& t, const Date& d,const Date& ech,const Duree& du,const QString& li,bool b=false):Activite(ident,t,d,ech,du,li,b){}
    QString Type() const {return typeid(*this).name();}
    int getNbParticipants() const {return static_cast<int>(participants.size());}
    const vector<QString>& getParticipants() const {return participants;}
    void ajouterParticipant(const QString & parti);
    void supprimmerParticipant(const QString & parti);
    void afficher(std::ostream& f) const {
         Activite::afficher(f);
         for (size_t i=0;i<participants.size();++i)
             f<<"Participants: "<<qPrintable(participants[i]);
    }
     ~Reunion() {}
};

class Rdv : public Activite{
private:
    QString personne;
public:
    QString Type() const {return typeid(*this).name();}
    Rdv(const QString& ident, const QString& t, const Date& d,const Date& ech,const Duree& du, const QString& pers, const QString& li,bool b=false):Activite(ident,t,d,ech,du,li,b),personne(pers){}
    const QString& getInterlocuteur() const { return personne; }
    void setInterlocuteur(const QString& interl) { personne = interl; }
    void afficher(std::ostream& f) const {
         Activite::afficher(f);
         f<<"Interlocuteur="<<personne.toStdString();
    }
     ~Rdv() {}
};

#endif // ACTIVITE

