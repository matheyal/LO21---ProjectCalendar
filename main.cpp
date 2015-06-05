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
    QCoreApplication a(argc, argv);
    /*ProjetManager& pm= ProjetManager::getInstance();
    pm.ajouterProjet("1","cool","c'est top", Date(12,10,1984), Date(12,10,2000));
    pm.afficherProjets();*/
    Projet* p1 = new Projet("1","cool","c'est top", Date(12,10,1984), Date(12,10,2000));
    p1->ajouterTacheUnitaire("id","c'est top", Date(12,10,1984), Date(12,10,2000), Duree(2,30));
    p1->afficherTaches();


    return a.exec();
}
