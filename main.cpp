#include <QCoreApplication>
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
    Projet *p=new Projet("1","cool", Date(12,10,1984), Date(12,10,2000));
    p->ajouterTacheUnitaire("1","toto", Date(14,10,1999), Date(16,10,1999),Duree(20));
    p->ajouterTacheComposite("2","titi", Date(14,10,1999), Date(16,10,1999));
    p->afficherTaches();
    p->supprimerTache("1");
    p->afficherTaches();

    return a.exec();
}
