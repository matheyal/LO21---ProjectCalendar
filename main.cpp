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
#include"mainwindow.h"
#include "import.h"

int main(int argc, char *argv[])
{
/*
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
    Rdv *rdv = new Rdv("1","coco", QDate(2000,10,12), QDate(2015,12,20), Duree(2,0), "marie", "bf");
    rdv->afficher(std::cout);
    a.ajouterProg(rdv, QDate(2012,12,12), Horaire(15,30));
    a.ajouterProg(pm.trouverProjet("1")->trouverTache("1"),QDate(1999,10,15), Horaire(14,30));
    a.supprimerProg(rdv);
    a.afficherProg();

<<<<<<< HEAD

 ----- Test export -----
=======
/* ----- Test export ----- */
>>>>>>> 4d895204d940735f38141d3c6a6842c58dd139f7

    ProjetManager& pm= ProjetManager::getInstance();
    pm.ajouterProjet("1","cool","c'est top", QDate(1984,10,12), QDate(2000,10,12));
    pm.trouverProjet("1")->ajouterTacheComposite("1","compo",QDate(1994,10,12), QDate(2000,10,12));
    pm.trouverProjet("1")->ajouterTacheUnitaire("2","unit2",QDate(1999,10,12), QDate(2002,10,12),Duree(3,50));
    pm.trouverProjet("1")->ajouterTacheComposite("3","compo3",QDate(2004,10,12), QDate(2008,10,12));

    pm.trouverProjet("1")->getTache("3").addPrecedence(pm.trouverProjet("1")->trouverTache("2"));
    pm.trouverProjet("1")->getTache("3").addPrecedence(pm.trouverProjet("1")->trouverTache("1"));
    pm.trouverProjet("1")->getTache("1").ajouterSousTache(pm.trouverProjet("1")->trouverTache("2"));
    pm.trouverProjet("1")->getTache("1").ajouterSousTache(pm.trouverProjet("1")->trouverTache("3"));

    //t1 = &(pm.trouverProjet("2")->getTache("4"));
    //pm.trouverProjet("2")->getTache("5").ajouterTacheUnitaire(t1);

    try{
        ExportXML strategy;
        strategy.save("/home/matheyal/Documents/LO21/Projet/projet.xml");
    }
    catch(CalendarException& e){std::cout<<e.getInfo().toStdString()<<std::endl;}


/* ------ Test Import -------*/
/*
    ProjetManager& pm = ProjetManager::getInstance();
    try{
        ImportXML import;
        import.load("/home/matheyal/Documents/LO21/Projet/projet.xml");
        pm.afficherProjets();
    }
    catch (CalendarException& e){
        std::cout<<e.getInfo().toStdString()<<std::endl;
    }
    catch (ProjetException& e){
        std::cout<<e.getInfo().toStdString()<<std::endl;
    }
*/

  // return a.exec();
    QApplication app(argc, argv);
    MainWindow fenetre;
    fenetre.show();
    ProjetManager& pm1= ProjetManager::getInstance();
    return app.exec();
}
