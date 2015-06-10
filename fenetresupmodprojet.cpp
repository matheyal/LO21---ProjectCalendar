#include "fenetresupmodprojet.h"
#include "projetmanager.h"

FenetreSupModProjet::FenetreSupModProjet(QWidget *parent)
{
    fenetreProjet = new QWidget;

    idProjet = new QLineEdit;
    titreProjet = new QLineEdit;
    descriptionProjet = new QTextEdit;
    dispoProjet = new QDateEdit;
    echeanceProjet = new QDateEdit;
    mod = new QPushButton("Modifier");
    ann = new QPushButton("annuler");
    supp = new QPushButton("supprimer");

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

    QObject::connect(idProjet, SIGNAL(textChanged(QString)), this, SLOT(load()));
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
    if(pm.trouverProjet(idProjet->text())){
        titreProjet->setText(pm.trouverProjet(idProjet->text())->getTitre());
        descriptionProjet->setText(pm.trouverProjet(idProjet->text())->getDesc());
        dispoProjet->setDate(pm.trouverProjet(idProjet->text())->getDispo());
        echeanceProjet->setDate(pm.trouverProjet(idProjet->text())->getEcheance());
    }else QMessageBox::warning(this, "erreur","Ce projet n'existe pas");

}

void FenetreSupModProjet::modifier(){
    ProjetManager& pm= ProjetManager::getInstance();
    if(pm.trouverProjet(idProjet->text())){
        pm.trouverProjet(idProjet->text())->setTitre(titreProjet->text());
        pm.trouverProjet(idProjet->text())->setDesc(descriptionProjet->toPlainText());
        pm.trouverProjet(idProjet->text())->setDispo(dispoProjet->date());
        pm.trouverProjet(idProjet->text())->setEcheance(echeanceProjet->date());
    }else QMessageBox::warning(this, "erreur","Ce projet n'existe pas");

}

void FenetreSupModProjet::checkDate(const QDate& d){
    if(d==dispoProjet->date() && echeanceProjet->date()<dispoProjet->date())
        echeanceProjet->setDate(dispoProjet->date());
    else if (d==echeanceProjet->date() && echeanceProjet->date()<dispoProjet->date())
            dispoProjet->setDate(echeanceProjet->date());
}

void FenetreSupModProjet::supprimer(){
    ProjetManager& pm= ProjetManager::getInstance();
    pm.supprimerProjet(idProjet->text());
}
