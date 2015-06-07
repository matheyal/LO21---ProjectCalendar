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
<<<<<<< HEAD
#include <unistd.h>
=======
#include "export.h"
>>>>>>> c933bdbd8de200ae63109b99db883cdc97ed0283

int main(int argc, char *argv[])
{

    //QCoreApplication a(argc, argv);
    ProjetManager& pm= ProjetManager::getInstance();

<<<<<<< HEAD
    TacheUnitaire* unit = new TacheUnitaire("1", "coucou", Date(10,01,2015), Date(10,10,2015), Duree(10,50));
    unit->commencer();
    TachePreemptable* prem = new TachePreemptable("2", "coucou", Date(10,01,2015), Date(10,10,2015), Duree(10,50));
    prem->commencer();
    TacheUnitaire* unit2 = new TacheUnitaire("3", "coucou", Date(10,01,2015), Date(10,10,2015), Duree(10,50));
    prem->interruption();
    prem->reprise();
=======
    try{
    pm.ajouterProjet("1","cool","c'est top", Date(12,10,1984), Date(12,10,2000));
    pm.ajouterProjet("2","chaud","c'est top", Date(12,10,1995), Date(12,10,2001));

    pm.trouverProjet("1")->ajouterTacheUnitaire("3","c'est top", Date(12,10,1995), Date(12,10,2000), Duree(2,30),NULL);
    pm.trouverProjet("1")->ajouterTacheComposite("4","c'est tip", Date(12,10,1984), Date(12,10,2000), pm.trouverProjet("1")->trouverTache("3"));
    pm.trouverProjet("1")->ajouterTachePreemptable("5","c'est Cool", Date(12,10,1984), Date(12,10,2000), Duree(2,30),NULL);
    pm.trouverProjet("1")->ajouterTacheUnitaire("6","c'est toptip", Date(12,10,1982), Date(12,10,1983), Duree(2,30), NULL);

    /*const vector<Projet*>* projets = pm.getProjets();
    for(vector<Projet*>::const_iterator it1 = projets->begin(); it1 != projets->end(); ++it1)
        std::cout<<(*it1)->getTitre().toStdString()<<std::endl;
    */

    ExportXML strategy;
    QString file="/home/matheyal/Documents/LO21/Projet/projet.xml";
    //std::cout<<file.toStdString();
    strategy.save(file);

    }
    catch(ProjetException e) { std::cout<<e.getInfo().toStdString();}
    catch(CalendarException e) {std::cout<<e.getInfo().toStdString();}

<<<<<<< HEAD
    //pm.afficherProjets();
>>>>>>> c933bdbd8de200ae63109b99db883cdc97ed0283


=======
    pm.afficherProjets();
    pm.trouverProjet("1")->trouverTache("5")->afficherPrecedence();
    Agenda& a=Agenda::getInstance();
    try{
    a.ajouterProg(pm.trouverProjet("1")->getTache("3"),Date(12,10,1999),Horaire(12,0));
    std::cout<<a.trouverProgrammation(pm.trouverProjet("1")->getTache("3"))->getEvenement()<<std::endl;
    std::cout<<a.trouverProgrammation(pm.trouverProjet("1")->getTache("3"))->getDate()<<std::endl;
    std::cout<<a.trouverProgrammation(pm.trouverProjet("1")->getTache("3"))->getHoraire()<<std::endl;
    } catch(AgendaException a){std::cout<<a.getInfo().toStdString();}
>>>>>>> cba51c6a11cabd9c24e9387b55f0eef2c66792f6
    return 0;
}
