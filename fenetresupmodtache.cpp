#include "fenetresupmodtache.h"
#include "projetmanager.h"

FenetreSupModTache::FenetreSupModTache(QMainWindow *parent) : QMainWindow(parent)
{
    fenetreSupModTache = new QWidget;

    idProjet= new QComboBox(this);
    idProjet->addItem("");
    ProjetManager& pm=ProjetManager::getInstance();
    for(vector<Projet*>::const_iterator it = (*pm.getProjets()).begin(); it != (*pm.getProjets()).end(); ++it){
        idProjet->addItem((*it)->getId());
    }

    idTache = new QComboBox(this);


    titreTache = new QLineEdit;
    titreTache->setDisabled(true);
    dispoTache = new QDateTimeEdit;
    dispoTache->setDisabled(true);
    echeanceTache = new QDateTimeEdit;
    echeanceTache->setDisabled(true);
    dureeTache = new QTimeEdit;
    dureeTache->setDisabled(true);
    supprimerPrecedence=new QComboBox;
    supprimerPrecedence->setDisabled(true);
    supprimerSousTache = new QComboBox;
    supprimerSousTache->setDisabled(true);
    mod = new QPushButton("Modifier");
    mod->setDisabled(true);
    ann = new QPushButton("Réinitialiser");
    ann->setDisabled(true);
    supp = new QPushButton("supprimer");
    supp->setDisabled(true);

    layout21Form = new QFormLayout;
    layout21Form->addRow("Projet",idProjet);
    layout21Form->addRow("Id", idTache);
    layout21Form->addRow("Titre", titreTache);
    layout21Form->addRow("Date de disponnibilite", dispoTache);
    layout21Form->addRow("Date d'echeance", echeanceTache);
    layout21Form->addRow("Duree", dureeTache);
    layout21Form->addRow("Supprimer une sous tache", supprimerSousTache);
    layout21Form->addRow("Supprimer une relation de précédence", supprimerPrecedence);

    horizontal=new QHBoxLayout;
    horizontal->addWidget(supp);
    horizontal->addWidget(mod);
    horizontal->addWidget(ann);

    layoutNouvelleTache = new QVBoxLayout;
    layoutNouvelleTache->addLayout(layout21Form);
    layoutNouvelleTache->addLayout(horizontal);

    groupeTache = new QGroupBox("Supprimer ou modifier une tache", this);
    groupeTache->setLayout(layoutNouvelleTache);

    layout = new QHBoxLayout;
    layout->addWidget(groupeTache);

    fenetreSupModTache->setLayout(layout);

    setCentralWidget(fenetreSupModTache);

    QObject::connect(idProjet, SIGNAL(currentIndexChanged(int)), this, SLOT(loadTache()));
    QObject::connect(idTache, SIGNAL(currentIndexChanged(int)), this, SLOT(load()));
    QObject::connect(mod, SIGNAL(clicked()), this, SLOT(modifier()));
    QObject::connect(mod, SIGNAL(clicked()), this, SLOT(close()));
    QObject::connect(ann, SIGNAL(clicked()), this, SLOT(load()));
    QObject::connect(supp, SIGNAL(clicked()), this, SLOT(supprimer()));
    QObject::connect(supp, SIGNAL(clicked()), this, SLOT(close()));
    QObject::connect(dispoTache, SIGNAL(dateTimeChanged(QDateTime)), this, SLOT(checkDate(const QDateTime&)));
    QObject::connect(echeanceTache, SIGNAL(dateTimeChanged(QDateTime)), this, SLOT(checkDate(const QDateTime&)));

}


void FenetreSupModTache::loadTache(){
        ProjetManager& pm=ProjetManager::getInstance();
        if(pm.trouverProjet(idProjet->currentText())){
            idTache->clear();
            idTache->addItem("");
            for(vector<Tache*>::const_iterator it = (*pm.trouverProjet(idProjet->currentText())->getTaches()).begin(); it != (*pm.trouverProjet(idProjet->currentText())->getTaches()).end(); ++it){
                idTache->addItem((*it)->getId());
            }
        }
}

void FenetreSupModTache::load(){
    ProjetManager& pm=ProjetManager::getInstance();
    if(pm.trouverProjet(idProjet->currentText())->trouverTache(idTache->currentText())){
        supprimerSousTache->setDisabled(true);
        supprimerSousTache->clear();
        supprimerSousTache->addItem("");
        supprimerPrecedence->clear();
        supprimerPrecedence->addItem("");
        supprimerPrecedence->setEnabled(true);
        mod->setEnabled(true);
        ann->setEnabled(true);
        supp->setEnabled(true);
        titreTache->setEnabled(true);
        dispoTache->setEnabled(true);
        echeanceTache->setEnabled(true);
        dureeTache->setDisabled(true);
        titreTache->setText(pm.trouverProjet(idProjet->currentText())->trouverTache(idTache->currentText())->getTitre());
        dispoTache->setDateTime(pm.trouverProjet(idProjet->currentText())->trouverTache(idTache->currentText())->getDate());
        echeanceTache->setDateTime(pm.trouverProjet(idProjet->currentText())->trouverTache(idTache->currentText())->getEcheance());
        for(vector<Tache*>::const_iterator it = (*pm.trouverProjet(idProjet->currentText())->trouverTache(idTache->currentText())->getTachesPrecedentes()).begin(); it != (*pm.trouverProjet(idProjet->currentText())->trouverTache(idTache->currentText())->getTachesPrecedentes()).end(); ++it){
            supprimerPrecedence->addItem((*it)->getId());
        }
        if (typeid(*(pm.trouverProjet(idProjet->currentText())->trouverTache(idTache->currentText())))==typeid(TacheUnitaire)){
            QTime time(pm.trouverProjet(idProjet->currentText())->trouverTache(idTache->currentText())->getDuree().getDureeEnHeures(), pm.trouverProjet(idProjet->currentText())->trouverTache(idTache->currentText())->getDuree().getDureeEnMinutes());
            supprimerSousTache->clear();
            dureeTache->setEnabled(true);
            dureeTache->setTime(time);
        }
        if (typeid(*(pm.trouverProjet(idProjet->currentText())->trouverTache(idTache->currentText())))==typeid(TacheComposite)){
            dureeTache->clear();
            dureeTache->setDisabled(true);
            supprimerSousTache->setEnabled(true);
            for(vector<Tache*>::const_iterator it = (*pm.trouverProjet(idProjet->currentText())->trouverTache(idTache->currentText())->getSousTaches()).begin(); it != (*pm.trouverProjet(idProjet->currentText())->trouverTache(idTache->currentText())->getSousTaches()).end(); ++it){
                supprimerSousTache->addItem((*it)->getId());
            }
        }
    }else{
            titreTache->clear();
            titreTache->setDisabled(true);
            dispoTache->clear();
            dispoTache->setDisabled(true);
            echeanceTache->clear();
            echeanceTache->setDisabled(true);
            dureeTache->clear();
            dureeTache->setDisabled(true);
            supprimerSousTache->setDisabled(true);
            supprimerSousTache->clear();
            supprimerPrecedence->setDisabled(true);
            supprimerPrecedence->clear();
        }
}

    void FenetreSupModTache::modifier(){
        ProjetManager& pm= ProjetManager::getInstance();
        Duree du(dureeTache->time().hour(), dureeTache->time().minute());
        pm.trouverProjet(idProjet->currentText())->trouverTache(idTache->currentText())->setTitre(titreTache->text());
        pm.trouverProjet(idProjet->currentText())->trouverTache(idTache->currentText())->setDateDisponibilite(dispoTache->dateTime());
        pm.trouverProjet(idProjet->currentText())->trouverTache(idTache->currentText())->setEcheance(echeanceTache->dateTime());
        pm.trouverProjet(idProjet->currentText())->trouverTache(idTache->currentText())->setDuree(du);
        pm.trouverProjet(idProjet->currentText())->trouverTache(idTache->currentText())->supprimerPrecedence(supprimerPrecedence->currentText());
        if (typeid(*((pm.trouverProjet(idProjet->currentText())->trouverTache(idTache->currentText()))))==typeid(TacheComposite)){
            pm.trouverProjet(idProjet->currentText())->trouverTache(idTache->currentText())->supprimerSousTache(supprimerSousTache->currentText());
            pm.trouverProjet(idProjet->currentText())->supprimerTache(supprimerSousTache->currentText());
        }
        if (typeid(*(pm.trouverProjet(idProjet->currentText())->trouverTache(idTache->currentText())))==typeid(TacheUnitaire)){
            pm.trouverProjet(idProjet->currentText())->trouverTache(idTache->currentText())->setDuree(du);

        }

    }

    void FenetreSupModTache::checkDate(const QDateTime& d){
        if(d==dispoTache->dateTime() && d<QDateTime::currentDateTime())
            dispoTache->setDateTime(QDateTime::currentDateTime());
        if(d==dispoTache->dateTime() && echeanceTache->dateTime()<dispoTache->dateTime())
            echeanceTache->setDateTime(dispoTache->dateTime());
        else if (d==echeanceTache->dateTime() && echeanceTache->dateTime()<dispoTache->dateTime())
                dispoTache->setDateTime(echeanceTache->dateTime());
    }

    void FenetreSupModTache::supprimer(){
        ProjetManager& pm= ProjetManager::getInstance();
        pm.trouverProjet(idProjet->currentText())->supprimerTache(idTache->currentText());
    }


