#include "fenetreunitaire.h"
#include"projetmanager.h"
#include<QDebug>

FenetreUnitaire::FenetreUnitaire(QWidget* parent)
{
    fenetreUnitaire = new QWidget;

    idUnitaire = new QLineEdit;
    titreUnitaire = new QLineEdit;
    projetUnitaire = new QLineEdit;
    dispoUnitaire = new QDateEdit(QDate::currentDate());
    echeanceUnitaire = new QDateEdit(QDate::currentDate());
    dureeUnitaire = new QSpinBox;
    preemptive = new QCheckBox;
    dureeUnitaire->setRange(1, 10000);
    enregistrerUnitaire = new QPushButton("Enregistrer");
    quitterUnitaire = new QPushButton("Quitter");

    layoutTitreProjetDispoEcheanceDuree = new QFormLayout;
    layoutTitreProjetDispoEcheanceDuree->addRow("ID", idUnitaire);
    layoutTitreProjetDispoEcheanceDuree->addRow("Titre", titreUnitaire);
    layoutTitreProjetDispoEcheanceDuree->addRow("Projet", projetUnitaire);
    layoutTitreProjetDispoEcheanceDuree->addRow("Dispo", dispoUnitaire);
    layoutTitreProjetDispoEcheanceDuree->addRow("Echeance", echeanceUnitaire);
    layoutTitreProjetDispoEcheanceDuree->addRow("Duree", dureeUnitaire);
    layoutTitreProjetDispoEcheanceDuree->addRow("preemptive", preemptive);

    layoutEnregistrerQuitter  =new QHBoxLayout;
    layoutEnregistrerQuitter->addWidget(enregistrerUnitaire);
    layoutEnregistrerQuitter->addWidget(quitterUnitaire);

    layoutUnitaire = new QVBoxLayout;
    layoutUnitaire->addLayout(layoutTitreProjetDispoEcheanceDuree);
    layoutUnitaire->addLayout(layoutEnregistrerQuitter);

    groupeUnitaire = new QGroupBox("Ajouter une nouvelle tache unitaire",fenetreUnitaire);
    groupeUnitaire->setLayout(layoutUnitaire);

    layout=new QVBoxLayout;
    layout->addWidget(groupeUnitaire);

    fenetreUnitaire->setLayout(layout);

    setCentralWidget(fenetreUnitaire);

    QObject::connect(enregistrerUnitaire, SIGNAL(clicked()), this, SLOT(enregistrerTacheUnitaire()));
    QObject::connect(dispoUnitaire, SIGNAL(dateChanged(const QDate)), this, SLOT(checkDate(const QDate&)));
    QObject::connect(echeanceUnitaire, SIGNAL(dateChanged(const QDate&)), this, SLOT(checkDate(const QDate&)));
    QObject::connect(quitterUnitaire, SIGNAL(clicked()), this, SLOT(close()));
}
void FenetreUnitaire::enregistrerTacheUnitaire()
{
    ProjetManager& pm = ProjetManager::getInstance();
    if(projetUnitaire->text().isEmpty())
    {
        QMessageBox::warning(this, "erreur","Rentrer un projet");
    }
    else if(!(pm.trouverProjet(projetUnitaire->text())))
    {
        QMessageBox::warning(this, "erreur","sauvegarde impossible, projet inexistant");
    }
    else if(dispoUnitaire->date()<QDate::currentDate())
    {
        QMessageBox::warning(this, "erreur","sauvegarde impossible, date du jour supérieure");
    }
    else if(titreUnitaire->text().isEmpty())
    {
        QMessageBox::warning(this, "erreur","Rentrer un titre pour la tache");
    }
    else if(preemptive->isChecked())
    {
        pm.trouverProjet(projetUnitaire->text())->ajouterTachePreemptable(idUnitaire->text(),titreUnitaire->text(),dispoUnitaire->date(), echeanceUnitaire->date(), dureeUnitaire->value());
    }
        else pm.trouverProjet(projetUnitaire->text())->ajouterTacheUnitaire(idUnitaire->text(),titreUnitaire->text(),dispoUnitaire->date(), echeanceUnitaire->date(), dureeUnitaire->value());
}
void FenetreUnitaire::checkDate(const QDate& d)
{
    if(d==dispoUnitaire->date() && echeanceUnitaire->date()<dispoUnitaire->date())
        echeanceUnitaire->setDate(dispoUnitaire->date());
    else if (d==echeanceUnitaire->date() && echeanceUnitaire->date()<dispoUnitaire->date())
            dispoUnitaire->setDate(echeanceUnitaire->date());
}
