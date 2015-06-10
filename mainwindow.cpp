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
#include "tachecomposite.h"
#include "tacheunitaire.h"
#include "timing.h"
#include <vector>
#include <unistd.h>
#include "export.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    mainWindow = new QWidget;

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

            groupeProjet = new QGroupBox("Selecitonner projet", onglet2);
            groupeProjet->setLayout(layoutProjet);

            QObject::connect(nouveau, SIGNAL(clicked()), this, SLOT(ajouterProjet()));
            QObject::connect(charger, SIGNAL(clicked()), this, SLOT(chargerProjet()));
            QObject::connect(supmod, SIGNAL(clicked()), this, SLOT(supmodProjet()));


            //Nouvelle Tache

            unitaire = new QPushButton("Unitaire");
            unitaire->setDisabled(false);
            composite = new QPushButton("Composite");
            composite->setDisabled(false);
            unitairePreemptee = new QPushButton("Unitaire Preemptee");
            unitairePreemptee->setDisabled(false);

            layoutTache = new QHBoxLayout;
            layoutTache->addWidget(unitaire);
            layoutTache->addWidget(composite);
            layoutTache->addWidget(unitairePreemptee);

            groupeTache = new QGroupBox("Nouvelle Tache", onglet2);
            groupeTache->setLayout(layoutTache);

            QObject::connect(unitaire, SIGNAL(clicked()), this, SLOT(ajouterTacheUnitaire()));
            QObject::connect(composite, SIGNAL(clicked()), this, SLOT(ajouterTacheComposite()));
            QObject::connect(unitairePreemptee, SIGNAL(clicked()), this, SLOT(ajouterTacheUnitairePreemptee()));

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

        titreEvenement= new QLineEdit;
        descriptionEvenement = new QTextEdit;
        dateActuelle = new QDateTime;
        debutEvenement = new QDateTimeEdit(dateActuelle->currentDateTime());
        finEvenement = new QDateTimeEdit(dateActuelle->currentDateTime());
        ajouterEvenement = new QPushButton("Ajouter");
        ajouterEvenement->setMaximumWidth(120);

        layoutTitreDescriptionEvenement = new QFormLayout;
        layoutTitreDescriptionEvenement->addRow("Titre", titreEvenement);
        layoutTitreDescriptionEvenement->addRow("Description", descriptionEvenement);

        layoutDebutEvenement = new QFormLayout;
        layoutDebutEvenement->addRow("Debut", debutEvenement);
        layoutFinEvenement = new QFormLayout;
        layoutFinEvenement->addRow("Fin", finEvenement);
        layoutDebutFin = new QHBoxLayout;
        layoutDebutFin->addLayout(layoutDebutEvenement);
        layoutDebutFin->addLayout(layoutFinEvenement);

        layoutAjouterEvenement = new QHBoxLayout;
        layoutAjouterEvenement->addWidget(ajouterEvenement);

        layoutEvenement = new QVBoxLayout;
        layoutEvenement->addLayout(layoutTitreDescriptionEvenement);
        layoutEvenement->addLayout(layoutDebutFin);
        layoutEvenement->addLayout(layoutAjouterEvenement);

        groupeEvenement = new QGroupBox("Nouvel evenement", onglet3);
        groupeEvenement->setLayout(layoutEvenement);

        layoutOnglet3 = new QHBoxLayout;
        layoutOnglet3->addWidget(groupeEvenement);

        onglet3->setLayout(layoutOnglet3);

        QObject::connect(ajouterEvenement,SIGNAL(clicked()), this, SLOT(ajoutEvenement()));

    //Cr�ation du bouton quitter

    quitter = new QPushButton("Quitter");
    quitter->setMaximumWidth(100);


        //Cr�ation d'un layout horizontal pour le bouton "quitter"
        QHBoxLayout *layoutHorizontal = new QHBoxLayout;
        layoutHorizontal->addWidget(quitter);

        // Connection pour le bouton quitter
        QObject::connect(quitter, SIGNAL(clicked()), qApp, SLOT(quit()));

    //Attachement de ces onglets � la barre d'onglet

    barreOnglet->addTab(onglet1, "Calendrier");
    barreOnglet->addTab(onglet2, "Projet");
    barreOnglet->addTab(onglet3, "Evenement");

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
    /*TacheUnitaire *t = new TacheUnitaire;
    t->show();*/
}

void MainWindow::ajouterTacheComposite()
{
    /*TacheComposite *t = new TacheComposite;
    t->show();*/
}

void MainWindow::ajouterTacheUnitairePreemptee()
{
    /*TacheUnitairePreemptee *t=new TacheUnitairePreemptee;
    t->show();*/
}

void MainWindow::ajoutEvenement()
{
    titreEvenement->setText("");
    descriptionEvenement->setText("");
    debutEvenement->setDateTime(dateActuelle->currentDateTime());
    finEvenement->setDateTime(dateActuelle->currentDateTime());
    QMessageBox::information(this,"Evenement ajoute", "Evenement ajoute");
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
