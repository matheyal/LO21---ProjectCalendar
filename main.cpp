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
    Agenda * A1= new Agenda();
    Evenement* e= new Evenement("1","ok", Date(12,5,2015), Date(45,5,2015));
    A1->ajouterProg(Date(2,5,2015),Horaire(13,07), e);
    return a.exec();
}
