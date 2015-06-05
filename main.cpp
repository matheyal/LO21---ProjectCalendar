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
    ProjetManager& pm= ProjetManager::getInstance();
    pm.ajouterProjet("1","cool","c'est top", Date(12,10,1984), Date(12,10,2000));
    //pm.afficherProjets();
    Projet* p1 = new Projet("2","cool2","c'est top2", Date(12,10,1984), Date(12,10,2000));
    p1->ajouterTacheUnitaire("3","c'est top", Date(12,10,1984), Date(12,10,2000), Duree(2,30));
    p1->ajouterTacheComposite("4","c'est tip", Date(12,10,1984), Date(12,10,2000));
    p1->ajouterTachePreemptable("5","c'est Cool", Date(12,10,1984), Date(12,10,2000), Duree(2,30));
    p1->ajouterTacheUnitaire("6","c'est toptip", Date(12,10,1982), Date(12,10,1983), Duree(2,30));
    p1->afficherPrecedence("3");
    std::cout<<"Fin de la precedence";
    p1->afficherTaches();


    return a.exec();
}
