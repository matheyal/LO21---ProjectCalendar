#include "fenetrecomposite.h"
#include "projetmanager.h"
#include<QDebug>

FenetreComposite::FenetreComposite(QWidget *parent)
{
    tacheComposite = new QWidget;

    titreComposite = new QLineEdit;
    projetComposite = new QLineEdit;
    dispoComposite = new QDateEdit(QDate::currentDate());
    echeanceComposite = new QDateEdit(QDate::currentDate());
    idComposite = new QLineEdit;
    enregistrerComposite = new QPushButton("Enregistrer");
    quitterComposite = new QPushButton("Quitter");

    layoutTitreProjetDispoEcheanceDuree = new QFormLayout;
    layoutTitreProjetDispoEcheanceDuree->addRow("ID", idComposite);
    layoutTitreProjetDispoEcheanceDuree->addRow("Titre", titreComposite);
    layoutTitreProjetDispoEcheanceDuree->addRow("Projet", projetComposite);
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
    if(projetComposite->text().isEmpty())
    {
        QMessageBox::warning(this, "erreur","Rentrer un projet");
        idComposite->setText("");
        projetComposite->setText("");
        titreComposite->setText("");
        dispoComposite->setDate(QDate::currentDate());
        echeanceComposite->setDate(QDate::currentDate());
    }
    else if(!(pm.trouverProjet(projetComposite->text())))
    {
        QMessageBox::warning(this, "erreur","sauvegarde impossible, projet inexistant");
        idComposite->setText("");
        projetComposite->setText("");
        titreComposite->setText("");
        dispoComposite->setDate(QDate::currentDate());
        echeanceComposite->setDate(QDate::currentDate());
    }
    else if(dispoComposite->date()<QDate::currentDate())
    {
        QMessageBox::warning(this, "erreur","sauvegarde impossible, date du jour supérieure");
        idComposite->setText("");
        projetComposite->setText("");
        titreComposite->setText("");
        dispoComposite->setDate(QDate::currentDate());
        echeanceComposite->setDate(QDate::currentDate());
    }
    else if(titreComposite->text().isEmpty())
    {
        QMessageBox::warning(this, "erreur","Rentrer un titre pour la tache");
        idComposite->setText("");
        projetComposite->setText("");
        titreComposite->setText("");
        dispoComposite->setDate(QDate::currentDate());
        echeanceComposite->setDate(QDate::currentDate());
    }
    else if(pm.trouverProjet(projetComposite->text())->trouverTache(idComposite->text()))
    {
        QMessageBox::warning(this, "erreur","sauvegarde impossible, tache deja existante");
        idComposite->setText("");
        projetComposite->setText("");
        titreComposite->setText("");
        dispoComposite->setDate(QDate::currentDate());
        echeanceComposite->setDate(QDate::currentDate());
    }
    else if(pm.trouverProjet(projetComposite->text())->getDispo()>dispoComposite->date())
    {
        QMessageBox::warning(this, "erreur","sauvegarde impossible, date de dispo de la tache inferieure a la date de dispo du projet");
        idComposite->setText("");
        projetComposite->setText("");
        titreComposite->setText("");
        dispoComposite->setDate(QDate::currentDate());
        echeanceComposite->setDate(QDate::currentDate());
    }
    else if(pm.trouverProjet(projetComposite->text())->getEcheance()<echeanceComposite->date())
    {
        QMessageBox::warning(this, "erreur","sauvegarde impossible, date d'echeance de la tache superieure a la date d'echeance du projet");
        idComposite->setText("");
        projetComposite->setText("");
        titreComposite->setText("");
        dispoComposite->setDate(QDate::currentDate());
        echeanceComposite->setDate(QDate::currentDate());
    }
    else
    {
        pm.trouverProjet(projetComposite->text())->ajouterTacheComposite(idComposite->text(),titreComposite->text(),dispoComposite->date(), echeanceComposite->date());
        idComposite->setText("");
        projetComposite->setText("");
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
