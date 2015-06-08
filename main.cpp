#include "qt.h"
#include <iostream>
#include "activite.h"
#include "agenda.h"
#include "evenement.h"
#include "programmation.h"
#include "projet.h"
#include "projetmanager.h"
#include "tache.h"
#include "tachecomposite.h"
#include "tacheunitaire.h"
#include "timing.h"
#include <vector>
#include <unistd.h>
#include "export.h"

int main(int argc, char *argv[])
{
    //QCoreApplication a(argc, argv);
    /*
    ProjetManager& pm= ProjetManager::getInstance();

    TacheUnitaire* unit = new TacheUnitaire("1", "coucou", Date(10,01,2015), Date(10,10,2015), Duree(10,50));
    unit->commencer();
    TachePreemptable* prem = new TachePreemptable("2", "coucou", Date(10,01,2015), Date(10,10,2015), Duree(10,50));
    prem->commencer();
    TacheUnitaire* unit2 = new TacheUnitaire("3", "coucou", Date(10,01,2015), Date(10,10,2015), Duree(10,50));
    prem->interruption();
    prem->reprise();

    Reunion* pt=new Reunion("3","caca",Date(12,10,1324),Date(15,10,1324),Duree(2,4),"coucou");
    pt->afficher(cout);
    pt->ajouterParticipant("prout");
    cout<<pt->getNbParticipants();

    pt->afficher(cout);
    pt->supprimmerParticipant("prout");
    pt->afficher(cout);

    */

    /* ----- Test export ----- */
    /*
    ProjetManager& pm= ProjetManager::getInstance();
    pm.ajouterProjet("1","projet1", "projet de test 1", Date(1,6,2015),Date(20, 6, 2015));
    pm.ajouterProjet("2","projet2", "projet de test 2", Date(1,4,2015),Date(1, 9, 2015));

    pm.trouverProjet("1")->ajouterTacheUnitaire("1", "coucou", Date(1,6,2015), Date(10,6,2015), Duree(10,50));
    pm.trouverProjet("1")->ajouterTachePreemptable("2", "blabla", Date(15,6,2015), Date(30,6,2015), Duree(5,30));
    pm.trouverProjet("1")->ajouterTacheUnitaire("3", "reunion", Date(25,7,2015), Date(10,8,2015), Duree(2,30));
    pm.trouverProjet("2")->ajouterTacheUnitaire("4", "brainstorm", Date(1,4,2015), Date(10,6,2015), Duree(1,0));
    pm.trouverProjet("2")->ajouterTacheComposite("5", "open the pic", Date(1,5,2015), Date(10,8,2015));

    Tache* t1 = &(pm.trouverProjet("1")->getTache("1"));
    Tache* t2 = &(pm.trouverProjet("1")->getTache("2"));
    pm.trouverProjet("1")->getTache("3").addPrecedence(t1);
    pm.trouverProjet("1")->getTache("3").addPrecedence(t2);

    //t1 = &(pm.trouverProjet("2")->getTache("4"));
    //pm.trouverProjet("2")->getTache("5").ajouterTacheUnitaire(t1);

    try{
        ExportXML strategy;
        strategy.save("/home/matheyal/Documents/LO21/Projet/projet.xml");
    }
    catch(CalendarException& e){std::cout<<e.getInfo().toStdString()<<std::endl;}
    */

  // return a.exec();
   return 0;
}
