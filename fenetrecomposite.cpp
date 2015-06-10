#include "fenetrecomposite.h"
#include "projetmanager.h"
#include<QDebug>

FenetreComposite::FenetreComposite(QMainWindow *parent) : QMainWindow(parent)
{
    tacheComposite = new QWidget;

    titreComposite = new QLineEdit;
    dispoComposite = new QDateEdit(QDate::currentDate());
    echeanceComposite = new QDateEdit(QDate::currentDate());
    idComposite = new QLineEdit;
    idProjet = new QComboBox(this);
    ProjetManager& pm=ProjetManager::getInstance();
    for(vector<Projet*>::const_iterator it = (*pm.getProjets()).begin(); it != (*pm.getProjets()).end(); ++it){
        idProjet->addItem((*it)->getId());
    }
    enregistrerComposite = new QPushButton("Enregistrer");
    quitterComposite = new QPushButton("Quitter");

    layoutTitreProjetDispoEcheanceDuree = new QFormLayout;
    layoutTitreProjetDispoEcheanceDuree->addRow("ID", idComposite);
    layoutTitreProjetDispoEcheanceDuree->addRow("Titre", titreComposite);
    layoutTitreProjetDispoEcheanceDuree->addRow("Projet", idProjet);
    layoutTitreProjetDispoEcheanceDuree->addRow("Dispo", dispoComposite);
    layoutTitreProjetDispoEcheanceDuree->addRow("Echeance", echeanceComposite);

    layoutEnregistrerQuitter  =new QHBoxLayout;
    layoutEnregistrerQuitter->addWidget(enregistrerComposite);
    layoutEnregistrerQuitter->addWidget(quitterComposite);

    layoutComposite = new QVBoxLayout;
    layoutComposite->addLayout(layoutTitreProjetDispoEcheanceDuree);
    layoutComposite->addLayout(layoutEnregistrerQuitter);

    groupeComposite = new QGroupBox("Ajouter une nouvelle tache composite", tacheComposite);
    groupeComposite->setLayout(layoutComposite);

    layout=new QVBoxLayout;
    layout->addWidget(groupeComposite);

    tacheComposite->setLayout(layout);

    setCentralWidget(tacheComposite);

    QObject::connect(enregistrerComposite, SIGNAL(clicked()), this, SLOT(enregistrerTacheComposite()));
    QObject::connect(dispoComposite, SIGNAL(dateChanged(const QDate)), this, SLOT(checkDate(const QDate&)));
    QObject::connect(echeanceComposite, SIGNAL(dateChanged(const QDate&)), this, SLOT(checkDate(const QDate&)));
    QObject::connect(quitterComposite, SIGNAL(clicked()), this, SLOT(close()));
}

void FenetreComposite::enregistrerTacheComposite()
{
    ProjetManager& pm = ProjetManager::getInstance();
    if(idProjet->currentText().isEmpty())
    {
        QMessageBox::warning(this, "erreur","Rentrer un projet");
        idComposite->setText("");
        idProjet->setCurrentText("");
        titreComposite->setText("");
        dispoComposite->setDate(QDate::currentDate());
        echeanceComposite->setDate(QDate::currentDate());
    }
    else if(!(pm.trouverProjet(idProjet->currentText())))
    {
        QMessageBox::warning(this, "erreur","sauvegarde impossible, projet inexistant");
        idComposite->setText("");
        idProjet->setCurrentText("");
        titreComposite->setText("");
        dispoComposite->setDate(QDate::currentDate());
        echeanceComposite->setDate(QDate::currentDate());
    }
    else if(dispoComposite->date()<QDate::currentDate())
    {
        QMessageBox::warning(this, "erreur","sauvegarde impossible, date du jour supérieure");
        idComposite->setText("");
        idProjet->setCurrentText("");
        titreComposite->setText("");
        dispoComposite->setDate(QDate::currentDate());
        echeanceComposite->setDate(QDate::currentDate());
    }
    else if(titreComposite->text().isEmpty())
    {
        QMessageBox::warning(this, "erreur","Rentrer un titre pour la tache");
        idComposite->setText("");
        idProjet->setCurrentText("");
        titreComposite->setText("");
        dispoComposite->setDate(QDate::currentDate());
        echeanceComposite->setDate(QDate::currentDate());
    }
    else if(pm.trouverProjet(idProjet->currentText())->trouverTache(idComposite->text()))
    {
        QMessageBox::warning(this, "erreur","sauvegarde impossible, tache deja existante");
        idComposite->setText("");
        idProjet->setCurrentText("");
        titreComposite->setText("");
        dispoComposite->setDate(QDate::currentDate());
        echeanceComposite->setDate(QDate::currentDate());
    }
    else if(pm.trouverProjet(idProjet->currentText())->getDispo()>dispoComposite->date())
    {
        QMessageBox::warning(this, "erreur","sauvegarde impossible, date de dispo de la tache inferieure a la date de dispo du projet");
        idComposite->setText("");
        idProjet->setCurrentText("");
        titreComposite->setText("");
        dispoComposite->setDate(QDate::currentDate());
        echeanceComposite->setDate(QDate::currentDate());
    }
    else if(pm.trouverProjet(idProjet->currentText())->getEcheance()<echeanceComposite->date())
    {
        QMessageBox::warning(this, "erreur","sauvegarde impossible, date d'echeance de la tache superieure a la date d'echeance du projet");
        idComposite->setText("");
        idProjet->setCurrentText("");
        titreComposite->setText("");
        dispoComposite->setDate(QDate::currentDate());
        echeanceComposite->setDate(QDate::currentDate());
    }
    else
    {
        pm.trouverProjet(idProjet->currentText())->ajouterTacheComposite(idComposite->text(),titreComposite->text(),dispoComposite->date(), echeanceComposite->date());
        idComposite->setText("");
        idProjet->setCurrentText("");
        titreComposite->setText("");
        dispoComposite->setDate(QDate::currentDate());
        echeanceComposite->setDate(QDate::currentDate());
    }
}
void FenetreComposite::checkDate(const QDate& d)
{
    if(d==dispoComposite->date() && echeanceComposite->date()<dispoComposite->date())
        echeanceComposite->setDate(dispoComposite->date());
    else if (d==echeanceComposite->date() && echeanceComposite->date()<dispoComposite->date())
            dispoComposite->setDate(echeanceComposite->date());
}
