#include "mainwindow.h"
#include "qt.h"
#include <iostream>
#include "activite.h"
#include "agenda.h"
#include "evenement.h"
#include "programmation.h"
#include "projet.h"
#include "projetmanager.h"
#include "tache.h"
#include "fenetrecomposite.h"
#include "fenetreunitaire.h"
#include "timing.h"
#include <vector>
#include <unistd.h>
#include "export.h"
#include "fenetresave.h"
#include "fenetreload.h"
#include "fenetreprecedence.h"
#include "fenetreactivite.h"
#include "activitemanager.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    mainWindow = new QWidget;

    //Chargement d'un fichier XML
    //new FenetreSave;

    //Cr�ation d'une barre d'outil MENU

    barreMenu = new QMenuBar;

    menuFichier = new QMenu("Fichier");
    barreMenu->addMenu(menuFichier);

        //Cr�ation d'un layout pour le menu
        layoutMenu = new QHBoxLayout;
        layoutMenu->addWidget(barreMenu);

    //Cr�ation de 3 onglets

    barreOnglet= new QTabWidget;
    onglet1 = new QWidget;
    onglet2 = new QWidget;
    onglet3 = new QWidget;

        //Onglet numero 1
        QTableWidget* tableau= new QTableWidget(10,7);

        QVBoxLayout *layout1 = new QVBoxLayout;
        layout1->addWidget(tableau);

        //Premiere case du tableau
        QDate *today = new QDate(QDate::currentDate());
        for(int i=0;i<7; i++)
        {
            QTableWidgetItem* a = new QTableWidgetItem((today->addDays(i)).toString());
            tableau->setHorizontalHeaderItem(i,a);
        }

        onglet1->setLayout(layout1);

        //Onglet numero 2

            //Selectionner projet

            label1 = new QLabel("Selectonner projet");
            nouveau = new QPushButton("Nouveau Projet");
            charger=new QPushButton("Charger Projet");
            supmod=new QPushButton("Supprimer ou modifier Projet");
            titreProjet = new QLineEdit;
            titreProjet->setDisabled(true);
            description = new QTextEdit;
            description->setDisabled(true);
            dispoProjet = new QDateTimeEdit;
            dispoProjet->setDisabled(true);
            echeanceProjet = new QDateTimeEdit;
            echeanceProjet->setDisabled(true);

            layoutBoutonProjet = new QHBoxLayout;
            layoutBoutonProjet->addWidget(nouveau);
            layoutBoutonProjet->addWidget(charger);
            layoutBoutonProjet->addWidget(supmod);

            layoutTitreDescription = new QFormLayout;
            layoutTitreDescription->addRow("Titre", titreProjet);
            layoutTitreDescription->addRow("Description", description);

            layoutDispoProjet = new QFormLayout;
            layoutDispoProjet->addRow("Disponnibilite", dispoProjet);

            layoutEcheanceProjet = new QFormLayout;
            layoutEcheanceProjet->addRow("Echeance", echeanceProjet);

            layoutDispoEcheance = new QHBoxLayout;
            layoutDispoEcheance->addLayout(layoutDispoProjet);
            layoutDispoEcheance->addLayout(layoutEcheanceProjet);

            layoutProjet = new QVBoxLayout;
            layoutProjet->addLayout(layoutBoutonProjet);
            layoutProjet->addLayout(layoutTitreDescription);
            layoutProjet->addLayout(layoutDispoEcheance);

            groupeProjet = new QGroupBox("Selectionner projet", onglet2);
            groupeProjet->setLayout(layoutProjet);

            QObject::connect(nouveau, SIGNAL(clicked()), this, SLOT(ajouterProjet()));
            QObject::connect(charger, SIGNAL(clicked()), this, SLOT(chargerProjet()));
            QObject::connect(supmod, SIGNAL(clicked()), this, SLOT(supmodProjet()));


            //Nouvelle Tache

            unitaire = new QPushButton("Unitaire");
            unitaire->setDisabled(false);
            composite = new QPushButton("Composite");
            composite->setDisabled(false);
            precedence = new QPushButton("Precedence");
            precedence->setDisabled(false);

            layoutTache = new QHBoxLayout;
            layoutTache->addWidget(unitaire);
            layoutTache->addWidget(composite);
            layoutTache->addWidget(precedence);

            groupeTache = new QGroupBox("Nouvelle Tache", onglet2);
            groupeTache->setLayout(layoutTache);

            QObject::connect(unitaire, SIGNAL(clicked()), this, SLOT(ajouterTacheUnitaire()));
            QObject::connect(composite, SIGNAL(clicked()), this, SLOT(ajouterTacheComposite()));
            QObject::connect(precedence, SIGNAL(clicked()), this, SLOT(ajouterPrecedence()));

            // Ajouter au calendrier

            ajoutProjet = new QPushButton("Projet");
            ajoutTache = new QPushButton("Tache");

            layoutAjout  =new QHBoxLayout;
            layoutAjout->addWidget(ajoutProjet);
            layoutAjout->addWidget(ajoutTache);

            groupeAjout = new QGroupBox("Ajouter au calendrier", onglet2);
            groupeAjout->setLayout(layoutAjout);

            QObject::connect(ajoutProjet, SIGNAL(clicked()), this, SLOT(ajoutProjetCalendrier()));
            QObject::connect(ajoutTache, SIGNAL(clicked()), this, SLOT(ajoutTacheCalendrier()));

            // Tree view

            tree =  new QTreeWidget;

            ProjetManager& pm = ProjetManager::getInstance();

            QTreeWidgetItem* item1 = new QTreeWidgetItem(tree);
            item1->setText(0, "test");
            tree->addTopLevelItem(item1);
            QTreeWidgetItem* item11 = new QTreeWidgetItem(tree);
            item11->setText(0, "test11");
            item1->addChild(item11);
            QTreeWidgetItem* item111 = new QTreeWidgetItem(tree);
            item111->setText(0, "test111");
            item11->addChild(item111);

            layoutTree = new QHBoxLayout;
            layoutTree->addWidget(tree);

            groupeTree = new QGroupBox("Tree-View", onglet2);
            groupeTree->setLayout(layoutTree);


        layoutDemiOnglet2 = new QVBoxLayout;
        layoutOnglet2 = new QHBoxLayout;
        layoutDemiOnglet2->addWidget(groupeProjet);
        layoutDemiOnglet2->addWidget(groupeTache);
        layoutDemiOnglet2->addWidget(groupeAjout);
        layoutOnglet2->addLayout(layoutDemiOnglet2);
        layoutOnglet2->addWidget(groupeTree);

        onglet2->setLayout(layoutOnglet2);




       //Onglet numero3

       nouvact= new QPushButton("nouvelle activité");

       layoutBoutonActivite = new QHBoxLayout;
       layoutBoutonActivite->addWidget(nouvact);

       groupeNouvelleActivite = new QGroupBox("Rentrer une nouvelle Activite dans la base de donnee", this);
       groupeNouvelleActivite->setLayout(layoutBoutonActivite);

       idActivite = new QComboBox(this);
       idActivite->addItem("");

       ActiviteManager& am=ActiviteManager::getInstance();

       for(vector<Activite*>::const_iterator it = (*am.getActivites()).begin(); it != (*am.getActivites()).end(); ++it){
           idActivite->addItem((*it)->getId());
       }

       titreActivite = new QLineEdit;
       titreActivite->setDisabled(true);
       dispoActivite = new QDateEdit;
       dispoActivite->setDisabled(true);
       echeanceActivite = new QDateEdit;
       echeanceActivite->setDisabled(true);
       dureeActivite = new QSpinBox;
       dureeActivite->setMinimum(0);
       dureeActivite->setMaximum(12);
       dureeActivite->setDisabled(true);
       lieuActivite = new QLineEdit;
       lieuActivite->setDisabled(true);
       mod = new QPushButton("Modifier");
       mod->setDisabled(true);
       ann = new QPushButton("Réinitialiser");
       ann->setDisabled(true);
       supp = new QPushButton("supprimer");
       supp->setDisabled(true);

       layout21Form = new QFormLayout;
       layout21Form->addRow("Id", idActivite);
       layout21Form->addRow("Titre", titreActivite);
       layout21Form->addRow("Date de disponnibilite", dispoActivite);
       layout21Form->addRow("Date d'echeance", echeanceActivite);
       layout21Form->addRow("Duree", dureeActivite);
       layout21Form->addRow("Lieu", lieuActivite);

       horizontal=new QHBoxLayout;
       horizontal->addWidget(supp);
       horizontal->addWidget(mod);
       horizontal->addWidget(ann);

       layoutActivite = new QVBoxLayout;
       layoutActivite->addLayout(layout21Form);
       layoutActivite->addLayout(horizontal);

       groupeActivite = new QGroupBox("Supprimer ou modifier une activité", this);
       groupeActivite->setLayout(layoutActivite);

       layoutOnglet3 = new QVBoxLayout;
       layoutOnglet3->addWidget(groupeNouvelleActivite);
       layoutOnglet3->addWidget(groupeActivite);

       onglet3->setLayout(layoutOnglet3);

       QObject::connect(nouvact,SIGNAL(clicked()), this, SLOT(nouvelleActivite()));
       QObject::connect(idActivite, SIGNAL(currentIndexChanged(int)), this, SLOT(load()));
       QObject::connect(mod, SIGNAL(clicked()), this, SLOT(modifier()));
       QObject::connect(mod, SIGNAL(clicked()), this, SLOT(close()));
       QObject::connect(ann, SIGNAL(clicked()), this, SLOT(load()));
       QObject::connect(supp, SIGNAL(clicked()), this, SLOT(supprimer()));
       QObject::connect(supp, SIGNAL(clicked()), this, SLOT(close()));
       QObject::connect(dispoActivite, SIGNAL(dateChanged(const QDate)), this, SLOT(checkDate(const QDate&)));
       QObject::connect(echeanceActivite, SIGNAL(dateChanged(const QDate&)), this, SLOT(checkDate(const QDate&)));

    //Cr�ation du bouton quitter

    quitter = new QPushButton("Quitter");
    quitter->setMaximumWidth(100);


        //Cr�ation d'un layout horizontal pour le bouton "quitter"
        QHBoxLayout *layoutHorizontal = new QHBoxLayout;
        layoutHorizontal->addWidget(quitter);

        // Connection pour le bouton quitter
        QObject::connect(quitter, SIGNAL(clicked()), this, SLOT(saveAndQuit()));

    //Attachement de ces onglets � la barre d'onglet

    barreOnglet->addTab(onglet1, "Calendrier");
    barreOnglet->addTab(onglet2, "Projet");
    barreOnglet->addTab(onglet3, "Activité");

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addLayout(layoutMenu);
    layout->addWidget(barreOnglet);
    layout->addLayout(layoutHorizontal);

    mainWindow->setLayout(layout);

    setCentralWidget(mainWindow);
}

void MainWindow::chargerProjet()
{
    QString dossier = QFileDialog::getExistingDirectory(this);
}

void MainWindow::supmodProjet(){
    FenetreSupModProjet *p=new FenetreSupModProjet;
    p->show();
}

void MainWindow::sauvegarderProjet()
{

    // choix du chemin d'enregistrement
    QString fichier = QFileDialog::getSaveFileName(this, "Enregistrer une tache", QString());
}

void MainWindow::enregistrerTache()
{
    /*QDate d2(2015,10, 10);
    QDate d3(2015, 11, 11);
    Duree d1(1,0);
    Tache& t=m.ajouterTache("1", titreTache->text(),d1,d2, d3);

    QMessageBox::information(this, "Enregistrement de la tache", t.getTitre());*/

}

void MainWindow::ajouterProjet()
{
    FenetreProjet* p= new FenetreProjet;
    p->show();
}

void MainWindow::ajouterTacheUnitaire()
{
    FenetreUnitaire *t = new FenetreUnitaire;
    t->show();
}

void MainWindow::ajouterTacheComposite()
{
    FenetreComposite *t = new FenetreComposite;
    t->show();
}


void MainWindow::nouvelleActivite()
{
    FenetreActivite *p=new FenetreActivite;
    p->show();
}

void MainWindow::load(){
    ActiviteManager& am= ActiviteManager::getInstance();
    if(am.trouverActivite(idActivite->currentText())){
        mod->setEnabled(true);
        ann->setEnabled(true);
        supp->setEnabled(true);
        titreActivite->setEnabled(true);
        descriptionActivite->setEnabled(true);
        dispoActivite->setEnabled(true);
        echeanceActivite->setEnabled(true);
        dureeActivite->setEnabled(true);
        lieuActivite->setEnabled(true);
        titreActivite->setText(am.trouverActivite(idActivite->currentText())->getTitre());
        dispoActivite->setDate(am.trouverActivite(idActivite->currentText())->getDate());
        echeanceActivite->setDate(am.trouverActivite(idActivite->currentText())->getEcheance());
        dureeActivite->setValue(am.trouverActivite(idActivite->currentText())->getDuree().getDureeEnHeures());
        lieuActivite->setText(am.trouverActivite(idActivite->currentText())->getLieu());
    }else QMessageBox::warning(this, "erreur","Cette Activite n'existe pas");

}

void MainWindow::modifier(){
    ActiviteManager& am= ActiviteManager::getInstance();
    am.trouverActivite(idActivite->currentText())->setTitre(titreActivite->text());
    am.trouverActivite(idActivite->currentText())->setDateDisponibilite(dispoActivite->date());
    am.trouverActivite(idActivite->currentText())->setEcheance(echeanceActivite->date());
}

void MainWindow::checkDate(const QDate& d){
    if(d==dispoActivite->date() && d<QDate::currentDate())
        dispoActivite->setDate(QDate::currentDate());
    if(d==dispoActivite->date() && echeanceActivite->date()<dispoActivite->date())
        echeanceActivite->setDate(dispoActivite->date());
    else if (d==echeanceActivite->date() && echeanceActivite->date()<dispoActivite->date())
            dispoActivite->setDate(echeanceActivite->date());
}

void MainWindow::supprimer(){
    ActiviteManager& am= ActiviteManager::getInstance();
    am.supprimerActivite(idActivite->currentText());
}



void MainWindow::ajoutProjetCalendrier()
{
    QMessageBox::information(this, "information", "Projet ajoute");
}


void MainWindow::ajoutTacheCalendrier()
{
    /*AjoutTacheCalendrier *t = new AjoutTacheCalendrier;
    t->show();*/
}

void MainWindow::saveAndQuit(){
    FenetreLoad* fl = new FenetreLoad();
    //il faut réussir à faire quitter l'appli lorsqu'on on valide le choix de fichier
    QObject::connect(fl, SIGNAL(accepted()), qApp, SLOT(quit()));
}

void MainWindow::ajouterPrecedence(){
    FenetrePrecedence* pr = new FenetrePrecedence();
    pr->show();
}
