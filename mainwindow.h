#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include<QtWidgets>
#include "calendar.h"
#include "timing.h"
#include "fenetreprojet.h"
#include "fenetresupmodprojet.h"
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
#include <vector>
#include <unistd.h>
#include "export.h"
#include "fenetresupmodactivite.h"
#include "fenetresave.h"
#include "fenetreload.h"
#include "fenetreprecedence.h"
#include "fenetreactivite.h"
#include "vuesemaine.h"


class MainWindow: public QMainWindow
{

    Q_OBJECT

public :
    MainWindow(QWidget *parent=0);
    //Méthode permettant de redéfinir l'action effectuée en sortie de l'application (ici demander si sauvegarde ou non)
    void closeEvent(QCloseEvent *event);

public slots:
    void chargerProjet();
    void sauvegarderProjet();
    void supmodProjet();
    void enregistrerTache();
    void ajouterProjet();
    void ajouterTacheUnitaire();
    void ajouterTacheComposite();
    void nouvelleActivite();
    void supModActivite();
    void ajoutProjetCalendrier();
    void ajoutTacheCalendrier();
    void ajouterPrecedence();
    void ajoutActiviteCalendrier();
    void treeView();

protected:
    void chargerFichier();


    QList<QTreeWidgetItem*>  treeProjets;
    QList<QTreeWidgetItem*> tachei;

    QWidget *mainWindow;
    QTabWidget *barreOnglet;
    QWidget *onglet1;
    QWidget *onglet2;
    QWidget *onglet3;

    QVBoxLayout* layout21;
    QHBoxLayout* layoutMenu;


    QMenu *menuFichier;
    QMenuBar* barreMenu;

    //onglet 2

    QLabel* label1;
    QLabel* label2;
    QLabel* label3;
    QLabel* label4;

    QComboBox* choixProjet;
    QLineEdit* titreProjet;

    QPushButton* nouveau;
    QPushButton* supmod;
    QPushButton* unitaire;
    QPushButton* precedence;
    QPushButton* composite;
    QPushButton* ajoutProjet;
    QPushButton* ajoutTache;
    QPushButton* ajoutActivite;
    QPushButton* refresh;

    QTextEdit* description;

    QDateTimeEdit* dispoProjet;
    QDateTimeEdit* echeanceProjet;

    QTreeWidget* tree;

    QGroupBox* groupeProjet;
    QGroupBox* groupeTache;
    QGroupBox* groupeAjout;
    QGroupBox* groupeTree;

    QHBoxLayout* layoutBoutonProjet;
    QFormLayout* layoutTitreDescription;
    QFormLayout* layoutDispoProjet;
    QFormLayout* layoutEcheanceProjet;
    QHBoxLayout* layoutDispoEcheance;
    QVBoxLayout* layoutProjet;

    QHBoxLayout* layoutTache;

    QHBoxLayout* layoutAjout;

    QHBoxLayout* layoutTree;

    QVBoxLayout* layoutDemiOnglet2;
    QHBoxLayout* layoutOnglet2;


    //onglet 3

    QGroupBox* groupeActivite;
    QVBoxLayout *layoutOnglet3;

    QPushButton* nouvact;
    QPushButton* supmodact;
    QHBoxLayout * layoutBoutonActivite;
    QHBoxLayout *modifierActivite;

    QPushButton* quitter;
    QHBoxLayout *layoutHorizontal2;
    QVBoxLayout* layout;


    QTimer timer;

};

#endif // MAINWINDOW_H

