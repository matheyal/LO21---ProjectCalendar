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

public slots:
    void chargerProjet();
    void sauvegarderProjet();
    void supmodProjet();
    void enregistrerTache();
    void ajouterProjet();
    void ajouterTacheUnitaire();
    void ajouterTacheComposite();
    void nouvelleActivite();
    void modifier();
    void checkDate(const QDate& d);
    void supprimer();
    void load();
    void ajoutProjetCalendrier();
    void ajoutTacheCalendrier();
    void saveAndQuit();
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

    QGroupBox* groupeNouvelleActivite;
    QGroupBox *groupeActivite;
    QVBoxLayout *layoutOnglet3;

    QPushButton* nouvact;
    QHBoxLayout * layoutBoutonActivite;
    QHBoxLayout *modifierActivite;

    QPushButton* quitter;


    QComboBox *idActivite;
    QLineEdit *titreActivite;

    QTextEdit* descriptionActivite;

    QDateEdit *dispoActivite;
    QDateEdit *echeanceActivite;

    QSpinBox *dureeActivite;
    QLineEdit *lieuActivite;

    QPushButton *supp;
    QPushButton* ann;
    QPushButton* mod;

    QHBoxLayout *horizontal;
    QFormLayout *layout21Form;
    QVBoxLayout *layoutActivite;
    QVBoxLayout* layoutNouvelleActivite;
    QHBoxLayout* layoutfinal;

};

#endif // MAINWINDOW_H

