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
  /* pt->ajouterParticipant("prout");
    cout<<pt->getNbParticipants();

    pt->afficher(cout);
    pt->supprimmerParticipant("prout");
    pt->afficher(cout);
 */

  // return a.exec();
   return 0;
}
