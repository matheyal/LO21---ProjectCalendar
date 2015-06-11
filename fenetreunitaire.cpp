#include "fenetreunitaire.h"
#include"projetmanager.h"
#include<QDebug>

FenetreUnitaire::FenetreUnitaire(QMainWindow* parent) : QMainWindow(parent)
{
    fenetreUnitaire = new QWidget;

    idUnitaire = new QLineEdit;
    titreUnitaire = new QLineEdit;
    idProjet = new QComboBox(this);
    ProjetManager& pm=ProjetManager::getInstance();
    for(vector<Projet*>::const_iterator it = (*pm.getProjets()).begin(); it != (*pm.getProjets()).end(); ++it){
        idProjet->addItem((*it)->getId());
    }
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
    layoutTitreProjetDispoEcheanceDuree->addRow("Projet", idProjet);
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
    if(idProjet->currentText().isEmpty())
    {
        QMessageBox::warning(this, "erreur","Rentrer un projet");
        idUnitaire->setText("");
        idProjet->setCurrentText("");
        titreUnitaire->setText("");
        dispoUnitaire->setDate(QDate::currentDate());
        echeanceUnitaire->setDate(QDate::currentDate());
        dureeUnitaire->cleanText();
    }
    else if(!(pm.trouverProjet(idProjet->currentText())))
    {
        QMessageBox::warning(this, "erreur","sauvegarde impossible, projet inexistant");
        idUnitaire->setText("");
        idProjet->setCurrentText("");
        titreUnitaire->setText("");
        dispoUnitaire->setDate(QDate::currentDate());
        echeanceUnitaire->setDate(QDate::currentDate());
        dureeUnitaire->cleanText();
    }
    else if(dispoUnitaire->date()<QDate::currentDate())
    {
        QMessageBox::warning(this, "erreur","sauvegarde impossible, date du jour supérieure");
        idUnitaire->setText("");
        idProjet->setCurrentText("");
        titreUnitaire->setText("");
        dispoUnitaire->setDate(QDate::currentDate());
        echeanceUnitaire->setDate(QDate::currentDate());
        dureeUnitaire->cleanText();
    }
    else if(titreUnitaire->text().isEmpty())
    {
        QMessageBox::warning(this, "erreur","Rentrer un titre pour la tache");
        idUnitaire->setText("");
        idProjet->setCurrentText("");
        titreUnitaire->setText("");
        dispoUnitaire->setDate(QDate::currentDate());
        echeanceUnitaire->setDate(QDate::currentDate());
        dureeUnitaire->cleanText();
    }
    else if(pm.trouverProjet(idProjet->currentText())->trouverTache(idUnitaire->text()))
    {
        QMessageBox::warning(this, "erreur","sauvegarde impossible, tache deja existante");
        idUnitaire->setText("");
        idProjet->setCurrentText("");
        titreUnitaire->setText("");
        dispoUnitaire->setDate(QDate::currentDate());
        echeanceUnitaire->setDate(QDate::currentDate());
        dureeUnitaire->cleanText();
    }
    else if(pm.trouverProjet(idProjet->currentText())->getDispo()>dispoUnitaire->date())
    {
        QMessageBox::warning(this, "erreur","sauvegarde impossible, date de dispo de la tache inferieure a la date de dispo du projet");
        idUnitaire->setText("");
        idProjet->setCurrentText("");
        titreUnitaire->setText("");
        dispoUnitaire->setDate(QDate::currentDate());
        echeanceUnitaire->setDate(QDate::currentDate());
        dureeUnitaire->cleanText();
    }
    else if(pm.trouverProjet(idProjet->currentText())->getEcheance()<echeanceUnitaire->date())
    {
        QMessageBox::warning(this, "erreur","sauvegarde impossible, date d'echeance de la tache superieure a la date d'echeance du projet");
        idUnitaire->setText("");
        idProjet->setCurrentText("");
        titreUnitaire->setText("");
        dispoUnitaire->setDate(QDate::currentDate());
        echeanceUnitaire->setDate(QDate::currentDate());
        dureeUnitaire->cleanText();
    }
    else if(dureeUnitaire->value()>dispoUnitaire->date().daysTo(echeanceUnitaire->date()))
    {
        QMessageBox::warning(this, "erreur","sauvegarde impossible, duree trop longue");
        idUnitaire->setText("");
        idProjet->setCurrentText("");
        titreUnitaire->setText("");
        dispoUnitaire->setDate(QDate::currentDate());
        echeanceUnitaire->setDate(QDate::currentDate());
        dureeUnitaire->cleanText();
    }
    else if(preemptive->isChecked())
    {
        pm.trouverProjet(idProjet->currentText())->ajouterTachePreemptable(idUnitaire->text(),titreUnitaire->text(),dispoUnitaire->date(), echeanceUnitaire->date(), dureeUnitaire->value());
        idUnitaire->setText("");
        idProjet->setCurrentText("");
        titreUnitaire->setText("");
        dispoUnitaire->setDate(QDate::currentDate());
        echeanceUnitaire->setDate(QDate::currentDate());
        dureeUnitaire->cleanText();
    }
        else
    {
        pm.trouverProjet(idProjet->currentText())->ajouterTacheUnitaire(idUnitaire->text(),titreUnitaire->text(),dispoUnitaire->date(), echeanceUnitaire->date(), dureeUnitaire->value());
        idUnitaire->setText("");
        idProjet->setCurrentText("");
        titreUnitaire->setText("");
        dispoUnitaire->setDate(QDate::currentDate());
        echeanceUnitaire->setDate(QDate::currentDate());
        dureeUnitaire->cleanText();
    }
}
void FenetreUnitaire::checkDate(const QDate& d)
{
    if(d==dispoUnitaire->date() && echeanceUnitaire->date()<dispoUnitaire->date())
        echeanceUnitaire->setDate(dispoUnitaire->date());
    else if (d==echeanceUnitaire->date() && echeanceUnitaire->date()<dispoUnitaire->date())
            dispoUnitaire->setDate(echeanceUnitaire->date());
}
