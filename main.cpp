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
<<<<<<< HEAD
#include <vector>

int main(int argc, char *argv[])
{
    //QCoreApplication a(argc, argv);
    /*ProjetManager& pm= ProjetManager::getInstance();
    pm.ajouterProjet("1","cool","c'est top", Date(12,10,1984), Date(12,10,2000));
    //pm.afficherProjets();
    Projet* p1 = new Projet("2","cool2","c'est top2", Date(12,10,1984), Date(12,10,2000));
    p1->ajouterTacheUnitaire("3","c'est top", Date(12,10,1984), Date(12,10,2000), Duree(2,30));
    p1->ajouterTacheComposite("4","c'est tip", Date(12,10,1984), Date(12,10,2000));
    p1->ajouterTachePreemptable("5","c'est Cool", Date(12,10,1984), Date(12,10,2000), Duree(2,30));
    p1->ajouterTacheUnitaire("6","c'est toptip", Date(12,10,1982), Date(12,10,1983), Duree(2,30));
    p1->afficherPrecedence("3");
    std::cout<<"Fin de la precedence";
    p1->afficherTaches();*/
=======
#include <unistd.h>
#include "export.h"

int main(int argc, char *argv[])
{

    //QCoreApplication a(argc, argv);
    ProjetManager& pm= ProjetManager::getInstance();
>>>>>>> a6cd4216acc54cca3aec88cf4c12149b93bf0892

    TacheUnitaire* unit = new TacheUnitaire("1", "coucou", Date(10,01,2015), Date(10,10,2015), Duree(10,50));
    unit->commencer();
    TachePreemptable* prem = new TachePreemptable("2", "coucou", Date(10,01,2015), Date(10,10,2015), Duree(10,50));
    prem->commencer();
    TacheUnitaire* unit2 = new TacheUnitaire("3", "coucou", Date(10,01,2015), Date(10,10,2015), Duree(10,50));
    prem->interruption();
    prem->reprise();

<<<<<<< HEAD
   Reunion* pt=new Reunion("3","caca",Date(12,10,1324),Date(15,10,1324),Duree(2,4),"coucou");
    pt->afficher(cout);
  /* pt->ajouterParticipant("prout");
    cout<<pt->getNbParticipants();

    pt->afficher(cout);
    pt->supprimmerParticipant("prout");
    pt->afficher(cout);
 */

  // return a.exec();
=======
    return 0;
>>>>>>> a6cd4216acc54cca3aec88cf4c12149b93bf0892
}
