#include "fenetresupmodprojet.h"
#include "projetmanager.h"

FenetreSupModProjet::FenetreSupModProjet(QMainWindow *parent) : QMainWindow(parent)
{
    fenetreProjet = new QWidget;

    idProjet = new QComboBox(this);
    idProjet->addItem("");
    ProjetManager& pm=ProjetManager::getInstance();
    for(vector<Projet*>::const_iterator it = (*pm.getProjets()).begin(); it != (*pm.getProjets()).end(); ++it){
        idProjet->addItem((*it)->getId());
    }

    titreProjet = new QLineEdit;
    titreProjet->setDisabled(true);
    descriptionProjet = new QTextEdit;
    descriptionProjet->setDisabled(true);
    dispoProjet = new QDateEdit;
    dispoProjet->setDisabled(true);
    echeanceProjet = new QDateEdit;
    echeanceProjet->setDisabled(true);
    mod = new QPushButton("Modifier");
    mod->setDisabled(true);
    ann = new QPushButton("Réinitialiser");
    ann->setDisabled(true);
    supp = new QPushButton("supprimer");
    supp->setDisabled(true);

    layout21Form = new QFormLayout;
    layout21Form->addRow("Id", idProjet);
    layout21Form->addRow("Titre", titreProjet);
    layout21Form->addRow("Descritpion", descriptionProjet);
    layout21Form->addRow("Date de disponnibilite", dispoProjet);
    layout21Form->addRow("Date d'echeance", echeanceProjet);

    horizontal=new QHBoxLayout;
    horizontal->addWidget(supp);
    horizontal->addWidget(mod);
    horizontal->addWidget(ann);

    layoutNouveauProjet = new QVBoxLayout;
    layoutNouveauProjet->addLayout(layout21Form);
    layoutNouveauProjet->addLayout(horizontal);

    QObject::connect(idProjet, SIGNAL(currentIndexChanged(int)), this, SLOT(load()));
    QObject::connect(mod, SIGNAL(clicked()), this, SLOT(modifier()));
    QObject::connect(mod, SIGNAL(clicked()), this, SLOT(close()));
    QObject::connect(ann, SIGNAL(clicked()), this, SLOT(load()));
    QObject::connect(supp, SIGNAL(clicked()), this, SLOT(supprimer()));
    QObject::connect(supp, SIGNAL(clicked()), this, SLOT(close()));
    QObject::connect(dispoProjet, SIGNAL(dateChanged(const QDate)), this, SLOT(checkDate(const QDate&)));
    QObject::connect(echeanceProjet, SIGNAL(dateChanged(const QDate&)), this, SLOT(checkDate(const QDate&)));

    groupeNouveauProjet = new QGroupBox("Rentrer un nouveau projet dans la base de donnee", this);
    groupeNouveauProjet->setLayout(layoutNouveauProjet);

    layout = new QHBoxLayout;
    layout->addWidget(groupeNouveauProjet);

    fenetreProjet->setLayout(layout);

    setCentralWidget(fenetreProjet);
}

void FenetreSupModProjet::load(){    
    ProjetManager& pm= ProjetManager::getInstance();
    if(pm.trouverProjet(idProjet->currentText())){
        mod->setEnabled(true);
        ann->setEnabled(true);
        supp->setEnabled(true);
        titreProjet->setEnabled(true);
        descriptionProjet->setEnabled(true);
        dispoProjet->setEnabled(true);
        echeanceProjet->setEnabled(true);
        titreProjet->setText(pm.trouverProjet(idProjet->currentText())->getTitre());
        descriptionProjet->setText(pm.trouverProjet(idProjet->currentText())->getDesc());
        dispoProjet->setDate(pm.trouverProjet(idProjet->currentText())->getDispo());
        echeanceProjet->setDate(pm.trouverProjet(idProjet->currentText())->getEcheance());
    }else QMessageBox::warning(this, "erreur","Ce projet n'existe pas");

}

void FenetreSupModProjet::modifier(){
    ProjetManager& pm= ProjetManager::getInstance();
    pm.trouverProjet(idProjet->currentText())->setTitre(titreProjet->text());
    pm.trouverProjet(idProjet->currentText())->setDesc(descriptionProjet->toPlainText());
    pm.trouverProjet(idProjet->currentText())->setDispo(dispoProjet->date());
    pm.trouverProjet(idProjet->currentText())->setEcheance(echeanceProjet->date());
}

void FenetreSupModProjet::checkDate(const QDate& d){
    if(d==dispoProjet->date() && d<QDate::currentDate())
        dispoProjet->setDate(QDate::currentDate());
    if(d==dispoProjet->date() && echeanceProjet->date()<dispoProjet->date())
        echeanceProjet->setDate(dispoProjet->date());
    else if (d==echeanceProjet->date() && echeanceProjet->date()<dispoProjet->date())
            dispoProjet->setDate(echeanceProjet->date());
}

void FenetreSupModProjet::supprimer(){
    ProjetManager& pm= ProjetManager::getInstance();
    pm.supprimerProjet(idProjet->currentText());
}
