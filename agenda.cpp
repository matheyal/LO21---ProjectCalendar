#include "agenda.h"
#include "programmation.h"
#include "calendar.h"

Agenda::Handler Agenda::handler=Agenda::Handler();
Agenda::Agenda(): progs(0){}
Agenda::~Agenda(){} //à faire avec file

Agenda& Agenda::getInstance(){
    if (handler.instance==0) handler.instance=new Agenda;
    return *(handler.instance);
}

void Agenda::libererInstance(){
    if (handler.instance!=0) delete handler.instance;
    handler.instance=0;
}

Programmation& Agenda::ajouterProg(const Evenement& e, const Date& d, const Horaire& h){
    if (trouverProgrammation(e)) throw AgendaException("erreur, tache deja existante dans le projet");
    if (e.getDate()<d && d<e.getEcheance()){
        Programmation* newt=new Programmation(d,h,e);
        addItem(newt);
        return *newt;
    }else throw AgendaException("erreur les dates ne concordent pas");
};

Programmation* Agenda::trouverProgrammation(const Evenement& e) const{
    for(std::size_t i=0;i<progs.size();++i)
        if (e==progs[i]->getEvenement()) return progs[i];
    return 0;
}


void Agenda::addItem(Programmation* p){
            progs.push_back(p);
        }

void Agenda::afficherProg(){
   for(std::vector<Programmation*>::iterator it=progs.begin(); it!= progs.end(); ++it)
       std::cout<< ' '<<*it;
     std::cout << '\n';
};
