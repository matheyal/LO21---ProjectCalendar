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
    pm.ajouterProjet("1","cool","c'est top", Date(12,10,1984), Date(12,10,2000));
    pm.trouverProjet("1")->ajouterTacheComposite("1","compo",Date(12,10,1994), Date(12,10,2000));
    pm.trouverProjet("1")->ajouterTacheUnitaire("2","compo2",Date(12,10,1999), Date(12,10,2002),Duree(3,50));
    pm.trouverProjet("1")->ajouterTacheComposite("3","compo3",Date(12,10,2004), Date(12,10,2008));

    pm.trouverProjet("1")->getTache("3").addPrecedence(pm.trouverProjet("1")->trouverTache("2"));
    pm.trouverProjet("1")->getTache("3").addPrecedence(pm.trouverProjet("1")->trouverTache("1"));
    pm.trouverProjet("1")->getTache("1").ajouterSousTache(pm.trouverProjet("1")->trouverTache("2"));
    pm.trouverProjet("1")->getTache("1").ajouterSousTache(pm.trouverProjet("1")->trouverTache("3"));
    pm.trouverProjet("1")->getTache("3").afficherPrecedence();
    pm.trouverProjet("1")->getTache("1").afficherSousTache();
    /*Rdv *rdv = new Rdv("1","coco", Date(12,10,2000), Date(20,12,2015), Duree(2,0), "marie", "bf");
    rdv->afficher(std::cout);
    a.ajouterProg(rdv, Date(12,12,2012), Horaire(15,30));
    a.ajouterProg(pm.trouverProjet("1")->trouverTache("1"),Date(15,10,1999), Horaire(14,30));
    a.supprimerProg(rdv);
    a.afficherProg();*/
  // return a.exec();
   return 0;
}
