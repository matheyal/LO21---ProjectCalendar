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
    Agenda& a = Agenda::getInstance();
    ProjetManager& pm= ProjetManager::getInstance();
    pm.ajouterProjet("1","cool","c'est top", QDate(1984,10,12), QDate(2000,10,12));
    pm.trouverProjet("1")->ajouterTacheComposite("1","compo",QDate(1994,10,12), QDate(2000,10,12));
    pm.trouverProjet("1")->ajouterTacheUnitaire("2","compo2",QDate(1999,10,12), QDate(2002,10,12),Duree(3,50));
    pm.trouverProjet("1")->ajouterTacheComposite("3","compo3",QDate(2004,10,12), QDate(2008,10,12));

    pm.trouverProjet("1")->getTache("3").addPrecedence(pm.trouverProjet("1")->trouverTache("2"));
    pm.trouverProjet("1")->getTache("3").addPrecedence(pm.trouverProjet("1")->trouverTache("1"));
    pm.trouverProjet("1")->getTache("1").ajouterSousTache(pm.trouverProjet("1")->trouverTache("2"));
    pm.trouverProjet("1")->getTache("1").ajouterSousTache(pm.trouverProjet("1")->trouverTache("3"));
    pm.trouverProjet("1")->getTache("3").afficherPrecedence();
    pm.trouverProjet("1")->getTache("1").afficherSousTaches();
    /*Rdv *rdv = new Rdv("1","coco", QDate(2000,10,12), QDate(2015,12,20), Duree(2,0), "marie", "bf");
    rdv->afficher(std::cout);
    a.ajouterProg(rdv, QDate(2012,12,12), Horaire(15,30));
    a.ajouterProg(pm.trouverProjet("1")->trouverTache("1"),QDate(1999,10,15), Horaire(14,30));
    a.supprimerProg(rdv);
    a.afficherProg();*/
  // return a.exec();
   return 0;
}
