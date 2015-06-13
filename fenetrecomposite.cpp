#include "fenetrecomposite.h"
#include "projetmanager.h"
#include<QDebug>

FenetreComposite::FenetreComposite(QMainWindow *parent) : QMainWindow(parent)
{
    tacheComposite = new QWidget;

    titreComposite = new QLineEdit;
    titreComposite->setDisabled(true);
    dispoComposite = new QDateTimeEdit(QDateTime::currentDateTime());
    dispoComposite->setDisabled(true);
    echeanceComposite = new QDateTimeEdit(QDateTime::currentDateTime());
    echeanceComposite->setDisabled(true);
    idComposite = new QLineEdit;
    idComposite->setDisabled(true);
    idProjet = new QComboBox(this);
    idProjet->addItem("");
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
    layoutTitreProjetDispoEcheanceDuree->addRow("Composite : ", idSousCompo);
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
    QObject::connect(dispoComposite, SIGNAL(dateChanged(const QDateTime)), this, SLOT(checkDate(const QDateTime&)));
    QObject::connect(echeanceComposite, SIGNAL(dateChanged(const QDateTime&)), this, SLOT(checkDate(const QDateTime&)));
    QObject::connect(quitterComposite, SIGNAL(clicked()), this, SLOT(close()));
}


void FenetreComposite::checkModifier(){
    if(!idProjet->currentText().isEmpty() && !idComposite->text().isEmpty() && !titreComposite->text().isEmpty()){
        enregistrerComposite->setEnabled(true);
    }
    else enregistrerComposite->setDisabled(true);
}


void FenetreComposite::enregistrerTacheComposite()
{
    ProjetManager& pm = ProjetManager::getInstance();
    if(!(pm.trouverProjet(idProjet->currentText())))
    {
        QMessageBox::warning(this, "erreur","sauvegarde impossible, projet inexistant");
        dispoComposite->setDateTime(QDateTime::currentDateTime());
        echeanceComposite->setDateTime(QDateTime::currentDateTime());
    }
    else if(pm.trouverProjet(idProjet->currentText())->trouverTache(idComposite->text()))
    {
        QMessageBox::warning(this, "erreur","sauvegarde impossible, tache deja existante");
        dispoComposite->setDateTime(QDateTime::currentDateTime());
        echeanceComposite->setDateTime(QDateTime::currentDateTime());
    }
    else if(pm.trouverProjet(idProjet->currentText())->getDispo()>dispoComposite->dateTime())
    {
        QMessageBox::warning(this, "erreur","sauvegarde impossible, date de dispo de la tache inferieure a la date de dispo du projet");
        dispoComposite->setDateTime(QDateTime::currentDateTime());
        echeanceComposite->setDateTime(QDateTime::currentDateTime());
    }
    else if(pm.trouverProjet(idProjet->currentText())->getEcheance()<echeanceComposite->dateTime())
    {
        QMessageBox::warning(this, "erreur","sauvegarde impossible, date d'echeance de la tache superieure a la date d'echeance du projet");
        dispoComposite->setDateTime(QDateTime::currentDateTime());
        echeanceComposite->setDateTime(QDateTime::currentDateTime());
    }
    else if(dispoComposite->dateTime()>echeanceComposite->dateTime())
    {
        QMessageBox::warning(this, "erreur", "date dispo anterieure a date echeance");
    }
    else if(idSousCompo->currentText()!="")
    {
        if(pm.trouverProjet(idProjet->currentText())->getTache(idSousCompo->currentText()).getEcheance()<echeanceComposite->dateTime())
        {
            QMessageBox::warning(this, "erreur", "date echeance de la composite inferieure a l'echeance de la tache que vous ajoutez");
        }
        else if(pm.trouverProjet(idProjet->currentText())->getTache(idSousCompo->currentText()).getDate()>dispoComposite->dateTime())
        {
            QMessageBox::warning(this, "erreur", "date dispo de la composite superierue a la dispo que la date que vous ajoutez");
        }
        else {
        pm.trouverProjet(idProjet->currentText())->ajouterTacheComposite(idComposite->text(),titreComposite->text(),dispoComposite->dateTime(), echeanceComposite->dateTime());
        pm.trouverProjet(idProjet->currentText())->getTache(idSousCompo->currentText()).ajouterSousTache(new TacheComposite(idComposite->text(),titreComposite->text(),dispoComposite->dateTime(), echeanceComposite->dateTime()));
        idComposite->setText("");
        idProjet->setCurrentIndex(0);
        titreComposite->setText("");
        dispoComposite->setDateTime(QDateTime::currentDateTime());
        echeanceComposite->setDateTime(QDateTime::currentDateTime());}
    }
    else {
        pm.trouverProjet(idProjet->currentText())->ajouterTacheComposite(idComposite->text(),titreComposite->text(),dispoComposite->dateTime(), echeanceComposite->dateTime());
        idComposite->setText("");
        idProjet->setCurrentIndex(0);
        titreComposite->setText("");
        dispoComposite->setDateTime(QDateTime::currentDateTime());
        echeanceComposite->setDateTime(QDateTime::currentDateTime());
    }
}
void FenetreComposite::checkDate(const QDateTime& d)
{
    if(d==dispoComposite->dateTime() && echeanceComposite->dateTime()<dispoComposite->dateTime())
        echeanceComposite->setDateTime(dispoComposite->dateTime());
    else if (d==echeanceComposite->dateTime() && echeanceComposite->dateTime()<dispoComposite->dateTime())
            dispoComposite->setDateTime(echeanceComposite->dateTime());
}

void FenetreComposite::load()
{
    idSousCompo->setEnabled(true);
    titreComposite->setEnabled(true);
    echeanceComposite->setEnabled(true);
    dispoComposite->setEnabled(true);
    idComposite->setEnabled(true);
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
