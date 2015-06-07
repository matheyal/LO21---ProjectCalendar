#include "qt.h"
#include <iostream>
#include "activite.h"
#include "agenda.h"
#include "evenement.h"
#include "fabrique.h"
#include "fabriqueactiv.h"
#include "programmation.h"
#include "projet.h"
#include "projetmanager.h"
#include "tache.h"
#include "tachecomposite.h"
#include "tacheunitaire.h"
#include "timing.h"

int main(int argc, char *argv[])
{
    //QCoreApplication a(argc, argv);
    ProjetManager& pm= ProjetManager::getInstance();

    try{
    pm.ajouterProjet("1","cool","c'est top", Date(12,10,1984), Date(12,10,2000));

    pm.trouverProjet("1")->ajouterTacheUnitaire("3","c'est top", Date(12,10,1995), Date(12,10,2000), Duree(2,30),NULL);
    pm.trouverProjet("1")->ajouterTacheComposite("4","c'est tip", Date(12,10,1984), Date(12,10,2000), pm.trouverProjet("1")->trouverTache("3"));
    pm.trouverProjet("1")->ajouterTachePreemptable("5","c'est Cool", Date(12,10,1984), Date(12,10,2000), Duree(2,30),NULL);
    pm.trouverProjet("1")->ajouterTacheUnitaire("6","c'est toptip", Date(12,10,1982), Date(12,10,1983), Duree(2,30), NULL);

    }catch(ProjetException e) { std::cout<<e.getInfo().toStdString();}

    pm.afficherProjets();
    pm.trouverProjet("1")->trouverTache("5")->afficherPrecedence();
    Agenda& a=Agenda::getInstance();
    try{
    a.ajouterProg(pm.trouverProjet("1")->getTache("3"),Date(12,10,1999),Horaire(12,0));
    std::cout<<a.trouverProgrammation(pm.trouverProjet("1")->getTache("3"))->getEvenement()<<std::endl;
    std::cout<<a.trouverProgrammation(pm.trouverProjet("1")->getTache("3"))->getDate()<<std::endl;
    std::cout<<a.trouverProgrammation(pm.trouverProjet("1")->getTache("3"))->getHoraire()<<std::endl;
    } catch(AgendaException a){std::cout<<a.getInfo().toStdString();}
    return 0;
}
