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
    idSousCompo = new QComboBox;
    idSousCompo->addItem("");
    idSousCompo->setDisabled("true");
    enregistrerComposite = new QPushButton("Enregistrer");
    quitterComposite = new QPushButton("Quitter");

    layoutTitreProjetDispoEcheanceDuree = new QFormLayout;
    layoutTitreProjetDispoEcheanceDuree->addRow("Projet", idProjet);
    layoutTitreProjetDispoEcheanceDuree->addRow("Sous Tache : ", idSousCompo);
    layoutTitreProjetDispoEcheanceDuree->addRow("ID", idComposite);
    layoutTitreProjetDispoEcheanceDuree->addRow("Titre", titreComposite);
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

    QObject::connect(idProjet, SIGNAL(currentIndexChanged(int)), this, SLOT(load()));
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
        dispoComposite->setDate(QDate::currentDate());
        echeanceComposite->setDate(QDate::currentDate());
    }
    else if(!(pm.trouverProjet(idProjet->currentText())))
    {
        QMessageBox::warning(this, "erreur","sauvegarde impossible, projet inexistant");
        dispoComposite->setDate(QDate::currentDate());
        echeanceComposite->setDate(QDate::currentDate());
    }
    else if(dispoComposite->date()<QDate::currentDate())
    {
        QMessageBox::warning(this, "erreur","sauvegarde impossible, date du jour supérieure");
        dispoComposite->setDate(QDate::currentDate());
        echeanceComposite->setDate(QDate::currentDate());
    }
    else if(titreComposite->text().isEmpty())
    {
        QMessageBox::warning(this, "erreur","Rentrer un titre pour la tache");
        dispoComposite->setDate(QDate::currentDate());
        echeanceComposite->setDate(QDate::currentDate());
    }
    else if(pm.trouverProjet(idProjet->currentText())->trouverTache(idComposite->text()))
    {
        QMessageBox::warning(this, "erreur","sauvegarde impossible, tache deja existante");
        dispoComposite->setDate(QDate::currentDate());
        echeanceComposite->setDate(QDate::currentDate());
    }
    else if(pm.trouverProjet(idProjet->currentText())->getDispo()>dispoComposite->date())
    {
        QMessageBox::warning(this, "erreur","sauvegarde impossible, date de dispo de la tache inferieure a la date de dispo du projet");
        dispoComposite->setDate(QDate::currentDate());
        echeanceComposite->setDate(QDate::currentDate());
    }
    else if(pm.trouverProjet(idProjet->currentText())->getEcheance()<echeanceComposite->date())
    {
        QMessageBox::warning(this, "erreur","sauvegarde impossible, date d'echeance de la tache superieure a la date d'echeance du projet");
        dispoComposite->setDate(QDate::currentDate());
        echeanceComposite->setDate(QDate::currentDate());
    }
    else if(idSousCompo->currentText()!="")
    {
        pm.trouverProjet(idProjet->currentText())->ajouterTacheComposite(idComposite->text(),titreComposite->text(),dispoComposite->date(), echeanceComposite->date());
        pm.trouverProjet(idProjet->currentText())->getTache(idSousCompo->currentText()).ajouterSousTache(new TacheComposite(idComposite->text(),titreComposite->text(),dispoComposite->date(), echeanceComposite->date()));
        idComposite->setText("");
        idProjet->setCurrentIndex(0);
        titreComposite->setText("");
        dispoComposite->setDate(QDate::currentDate());
        echeanceComposite->setDate(QDate::currentDate());
    }
    else {
        pm.trouverProjet(idProjet->currentText())->ajouterTacheComposite(idComposite->text(),titreComposite->text(),dispoComposite->date(), echeanceComposite->date());
        idComposite->setText("");
        idProjet->setCurrentIndex(0);
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

void FenetreComposite::load()
{
    idSousCompo->setEnabled(true);
    idSousCompo->clear();
    idSousCompo->addItem("");
    ProjetManager& pm= ProjetManager::getInstance();
    if(pm.trouverProjet(idProjet->currentText()))
    {
        vector<Tache*> tac= *pm.trouverProjet(idProjet->currentText())->getTaches();
        for(size_t i=0; i<tac.size();i++)
        {
            if(tac[i]->Type()=="14TacheComposite")
            {
                idSousCompo->addItem(tac[i]->getId());
            }
        }
    }
}
