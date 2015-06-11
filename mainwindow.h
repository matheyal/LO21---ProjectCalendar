#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include<QtWidgets>
#include "calendar.h"
#include "timing.h"
#include "fenetreprojet.h"
#include "fenetresupmodprojet.h"
/*#include "tacheunitaire.h"
#include "tachecomposite.h"
#include "tacheunitairepreemptee.h"
#include "ajouttachecalendrier.h"*/

class MainWindow: public QMainWindow
{

    Q_OBJECT

public :
    MainWindow(QWidget *parent=0);
    void closeEvent(QCloseEvent *event);

public slots:
    void chargerProjet();
    void sauvegarderProjet();
    void supmodProjet();
    void enregistrerTache();
    void ajouterProjet();
    void ajouterTacheUnitaire();
    void ajouterTacheComposite();
    void ajoutEvenement();
    void ajoutProjetCalendrier();
    void ajoutTacheCalendrier();
    void ajouterPrecedence();

protected:
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

    QLineEdit* titreProjet;

    QPushButton* nouveau;
    QPushButton* charger;
    QPushButton* supmod;
    QPushButton* unitaire;
    QPushButton* precedence;
    QPushButton* composite;
    QPushButton* ajoutProjet;
    QPushButton* ajoutTache;

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

    QGroupBox* groupeEvenement;

    QLineEdit* titreEvenement;

    QTextEdit* descriptionEvenement;

    QDateTimeEdit* debutEvenement;
    QDateTime* dateActuelle;
    QDateTimeEdit* finEvenement;

    QPushButton* ajouterEvenement;

    QHBoxLayout* layoutOnglet3;
    QHBoxLayout* layoutDebutFin;
    QFormLayout* layoutDebutEvenement;
    QFormLayout* layoutFinEvenement;
    QFormLayout* layoutTitreDescriptionEvenement;
    QVBoxLayout* layoutEvenement;
    QHBoxLayout* layoutAjouterEvenement;

    QPushButton* quitter;

    QPushButton *chargerTache;
    QLineEdit *titreTache;
    QLineEdit *dureeTache;
};

#endif // MAINWINDOW_H

