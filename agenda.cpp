#include "agenda.h"
#include "programmation.h"
#include "calendar.h"

void Agenda::ajouterProg(const Date& d, const Horaire& h, Evenement *e){
    if(e->getDate()<d && d<e->getEcheance()){
        Programmation* p= new Programmation(d, h, e);
        progs.push_back(p);
    } else throw CalendarException("Erreur les dates ne concordent pas");
};

void Agenda::afficherProg(){
   for(std::vector<Programmation*>::iterator it=progs.begin(); it!= progs.end(); ++it)
       std::cout<< ' '<<*it;
     std::cout << '\n';
};


