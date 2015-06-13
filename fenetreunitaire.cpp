#include "fenetreunitaire.h"
#include"projetmanager.h"
#include<QDebug>

FenetreUnitaire::FenetreUnitaire(QMainWindow* parent) : QMainWindow(parent)
{
    fenetreUnitaire = new QWidget;

    idUnitaire = new QLineEdit;
    titreUnitaire = new QLineEdit;
    idProjet = new QComboBox(this);
    idProjet->addItem("");
    ProjetManager& pm=ProjetManager::getInstance();
    for(vector<Projet*>::const_iterator it = (*pm.getProjets()).begin(); it != (*pm.getProjets()).end(); ++it){
        idProjet->addItem((*it)->getId());
    }
    idComposite = new QComboBox;
    idComposite->addItem("");
    idComposite->setDisabled(true);
    dispoUnitaire = new QDateTimeEdit(QDateTime::currentDateTime());
    echeanceUnitaire = new QDateTimeEdit(QDateTime::currentDateTime());
    dureeUnitaire = new QTimeEdit;
    preemptive = new QCheckBox;
    enregistrerUnitaire = new QPushButton("Enregistrer");
    enregistrerUnitaire->setDisabled(true);
    quitterUnitaire = new QPushButton("Quitter");


    layoutTitreProjetDispoEcheanceDuree = new QFormLayout;
    layoutTitreProjetDispoEcheanceDuree->addRow("Projet", idProjet);
    layoutTitreProjetDispoEcheanceDuree->addRow("Composite : ", idComposite);
    layoutTitreProjetDispoEcheanceDuree->addRow("ID", idUnitaire);
    layoutTitreProjetDispoEcheanceDuree->addRow("Titre", titreUnitaire);
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

    QObject::connect(idProjet, SIGNAL(currentIndexChanged(int)), this, SLOT(load()));
    QObject::connect(enregistrerUnitaire, SIGNAL(clicked()), this, SLOT(enregistrerTacheUnitaire()));
    QObject::connect(dispoUnitaire, SIGNAL(dateTimeChanged(const QDate)), this, SLOT(checkDate(const QDate&)));
    QObject::connect(echeanceUnitaire, SIGNAL(dateTimeChanged(const QDate&)), this, SLOT(checkDate(const QDate&)));
    QObject::connect(quitterUnitaire, SIGNAL(clicked()), this, SLOT(close()));
    QObject::connect(idUnitaire, SIGNAL(textChanged(QString)), this, SLOT(checkModifier()));
    QObject::connect(titreUnitaire, SIGNAL(textChanged(QString)), this, SLOT(checkModifier()));
    QObject::connect(dureeUnitaire, SIGNAL(dateTimeChanged(QDateTime)), this, SLOT(checkModifier()));
    QObject::connect(dispoUnitaire, SIGNAL(dateTimeChanged(QDateTime)), this, SLOT(checkModifier()));
    QObject::connect(echeanceUnitaire, SIGNAL(dateTimeChanged(QDateTime)), this, SLOT(checkModifier()));
}

void FenetreUnitaire::checkModifier(){
    if(!idProjet->currentText().isEmpty() && !idUnitaire->text().isEmpty() && !titreUnitaire->text().isEmpty() && dureeUnitaire->time()>QTime(0,0) && dispoUnitaire->dateTime().secsTo(echeanceUnitaire->dateTime())>QTime(0,0,0).secsTo(dureeUnitaire->time())){
        if (!preemptive->isChecked() && dureeUnitaire->time()>QTime(12,00))
            enregistrerUnitaire->setDisabled(true);
        else enregistrerUnitaire->setEnabled(true);
    }
    else enregistrerUnitaire->setDisabled(true);
}


void FenetreUnitaire::enregistrerTacheUnitaire()
{
    Duree du(dureeUnitaire->time().hour(), dureeUnitaire->time().minute());
    ProjetManager& pm = ProjetManager::getInstance();
    if(pm.trouverProjet(idProjet->currentText())->trouverTache(idUnitaire->text()))
    {
        QMessageBox::warning(this, "erreur","sauvegarde impossible, tache deja existante");
        dispoUnitaire->setDateTime(QDateTime::currentDateTime());
        echeanceUnitaire->setDateTime(QDateTime::currentDateTime());
    }
    else if(pm.trouverProjet(idProjet->currentText())->getEcheance()<echeanceUnitaire->dateTime())
    {
        QMessageBox::warning(this, "erreur","sauvegarde impossible, date d'echeance de la tache superieure a la date d'echeance du projet");
        dispoUnitaire->setDateTime(QDateTime::currentDateTime());
        echeanceUnitaire->setDateTime(QDateTime::currentDateTime());
    }
    else if(preemptive->isChecked())
    {
        if(idComposite->currentText()!="")
        {
            if(pm.trouverProjet(idProjet->currentText())->getTache(idComposite->currentText()).getEcheance()<echeanceUnitaire->dateTime())
            {
                QMessageBox::warning(this, "erreur", "date echeance de la composite inferieure a l'echeance de la tache que vous ajoutez");
            }
            else if(pm.trouverProjet(idProjet->currentText())->getTache(idComposite->currentText()).getDate()>dispoUnitaire->dateTime())
            {
                QMessageBox::warning(this, "erreur", "date dispo de la composite superierue a la dispo que la date que vous ajoutez");
            }
            else {
            pm.trouverProjet(idProjet->currentText())->ajouterTacheUnitaire(idUnitaire->text(),titreUnitaire->text(),dispoUnitaire->dateTime(), echeanceUnitaire->dateTime(), du);
            pm.trouverProjet(idProjet->currentText())->getTache(idComposite->currentText()).ajouterSousTache(new TachePreemptable(idUnitaire->text(),titreUnitaire->text(),dispoUnitaire->dateTime(), echeanceUnitaire->dateTime(), du));
            idUnitaire->setText("");
            idComposite->setCurrentIndex(0);
            idProjet->setCurrentIndex(0);
            titreUnitaire->setText("");
            dispoUnitaire->setDateTime(QDateTime::currentDateTime());
            echeanceUnitaire->setDateTime(QDateTime::currentDateTime());
            dureeUnitaire->clear();
            QMessageBox::about(this, "ajout", "Tache preemptable dans composite ajoutée");}

        }
        else
        {
            if(pm.trouverProjet(idProjet->currentText())->getTache(idComposite->currentText()).getEcheance()<echeanceUnitaire->dateTime())
            {
                QMessageBox::warning(this, "erreur", "date echeance de la composite inferieure a l'echeance de la tache que vous ajoutez");
            }
            else if(pm.trouverProjet(idProjet->currentText())->getTache(idComposite->currentText()).getDate()>dispoUnitaire->dateTime())
            {
                QMessageBox::warning(this, "erreur", "date dispo de la composite superieure a la dispo de la date que vous ajoutez");
            }
            else{
            pm.trouverProjet(idProjet->currentText())->ajouterTachePreemptable(idUnitaire->text(),titreUnitaire->text(),dispoUnitaire->dateTime(), echeanceUnitaire->dateTime(), du);
            idUnitaire->setText("");
            idProjet->setCurrentIndex(0);
            titreUnitaire->setText("");
            dispoUnitaire->setDateTime(QDateTime::currentDateTime());
            echeanceUnitaire->setDateTime(QDateTime::currentDateTime());
            dureeUnitaire->clear();}
        }

    }
    else if(idComposite->currentText()!="")
    {
        pm.trouverProjet(idProjet->currentText())->ajouterTacheUnitaire(idUnitaire->text(),titreUnitaire->text(),dispoUnitaire->dateTime(), echeanceUnitaire->dateTime(), du);
        pm.trouverProjet(idProjet->currentText())->getTache(idComposite->currentText()).ajouterSousTache(new TacheUnitaire(idUnitaire->text(),titreUnitaire->text(),dispoUnitaire->dateTime(), echeanceUnitaire->dateTime(), du));
        idUnitaire->setText("");
        idComposite->setCurrentIndex(0);
        idProjet->setCurrentIndex(0);
        titreUnitaire->setText("");
        dispoUnitaire->setDateTime(QDateTime::currentDateTime());
        echeanceUnitaire->setDateTime(QDateTime::currentDateTime());
        dureeUnitaire->clear();
        QMessageBox::about(this, "ajout", "Tache unitaire dans composite ajoutée");
    }
    else
    {
        pm.trouverProjet(idProjet->currentText())->ajouterTacheUnitaire(idUnitaire->text(),titreUnitaire->text(),dispoUnitaire->dateTime(), echeanceUnitaire->dateTime(), du);
        idUnitaire->setText("");
        idProjet->setCurrentIndex(0);
        titreUnitaire->setText("");
        dispoUnitaire->setDateTime(QDateTime::currentDateTime());
        echeanceUnitaire->setDateTime(QDateTime::currentDateTime());
        dureeUnitaire->clear();
        QMessageBox::about(this, "ajout", "Tache ajoutée");
    }

}
void FenetreUnitaire::checkDate(const QDateTime& d)
{
    if(d==dispoUnitaire->dateTime() && d<QDateTime::currentDateTime())
        dispoUnitaire->setDateTime(QDateTime::currentDateTime());
    if(d==dispoUnitaire->dateTime() && echeanceUnitaire->dateTime()<dispoUnitaire->dateTime())
        echeanceUnitaire->setDateTime(dispoUnitaire->dateTime());
    else if (d==echeanceUnitaire->dateTime() && echeanceUnitaire->dateTime()<dispoUnitaire->dateTime())
            dispoUnitaire->setDateTime(echeanceUnitaire->dateTime());
}

void FenetreUnitaire::load()
{
    idComposite->setEnabled(true);
    idComposite->clear();
    idComposite->addItem("");
    ProjetManager& pm= ProjetManager::getInstance();
    if(pm.trouverProjet(idProjet->currentText()))
    {
        vector<Tache*> tac= *pm.trouverProjet(idProjet->currentText())->getTaches();
        for(size_t i=0; i<tac.size();i++)
        {
            if(tac[i]->Type()=="14TacheComposite")
            {
                idComposite->addItem(tac[i]->getId());
            }
        }
    }
}
