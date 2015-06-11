#include "fenetreactivite.h"
#include "activitemanager.h"

FenetreActivite::FenetreActivite(QMainWindow *parent) : QMainWindow(parent)
{
    fenetreActivite = new QWidget;

    idActivite = new QLineEdit;
    titreActivite = new QLineEdit;
    descriptionActivite = new QTextEdit;
    dispoActivite = new QDateEdit(QDate::currentDate());
    echeanceActivite = new QDateEdit(QDate::currentDate());
    dureeActivite = new QSpinBox;
    dureeActivite->setMinimum(0);
    dureeActivite->setMaximum(12);
    lieuActivite= new QLineEdit;
    enregistrerActivite = new QPushButton("Enregister");
    annuler = new QPushButton("annuler");

    layout21Form = new QFormLayout;
    layout21Form->addRow("Id", idActivite);
    layout21Form->addRow("Titre", titreActivite);
    layout21Form->addRow("Descritpion", descriptionActivite);
    layout21Form->addRow("Date de disponnibilite", dispoActivite);
    layout21Form->addRow("Date d'echeance", echeanceActivite);
    layout21Form->addRow("Durée", dureeActivite);
    layout21Form->addRow("Lieu", lieuActivite);

    horizontal=new QHBoxLayout;
    horizontal->addWidget(enregistrerActivite);
    horizontal->addWidget(annuler);

    layoutNouvelleActivite = new QVBoxLayout;
    layoutNouvelleActivite->addLayout(layout21Form);
    layoutNouvelleActivite->addLayout(horizontal);

    QObject::connect(enregistrerActivite, SIGNAL(clicked()), this, SLOT(saveActivite()));
    QObject::connect(enregistrerActivite, SIGNAL(clicked()), this, SLOT(close()));
    QObject::connect(annuler, SIGNAL(clicked()), this, SLOT(cancel()));
    QObject::connect(dispoActivite, SIGNAL(dateChanged(const QDate)), this, SLOT(checkDate(const QDate&)));
    QObject::connect(echeanceActivite, SIGNAL(dateChanged(const QDate&)), this, SLOT(checkDate(const QDate&)));

    groupeNouvelleActivite = new QGroupBox("Rentrer un nouveau Activite dans la base de donnee", this);
    groupeNouvelleActivite->setLayout(layoutNouvelleActivite);

    layout = new QHBoxLayout;
    layout->addWidget(groupeNouvelleActivite);

    fenetreActivite->setLayout(layout);

    setCentralWidget(fenetreActivite);
}


void FenetreActivite::saveActivite()
{
    ActiviteManager& am= ActiviteManager::getInstance();
    if(am.trouverActivite(idActivite->text()))
        QMessageBox::warning(this, "erreur","sauvegarde impossible, id deja utilise");
    else am.ajouterActivite(idActivite->text(), titreActivite->text(), dispoActivite->date(), echeanceActivite->date(), Duree(dureeActivite->value()), lieuActivite->text());
}

void FenetreActivite::cancel(){
    idActivite->clear();
    titreActivite->clear();
    descriptionActivite->clear();
    dispoActivite->setDate(QDate::currentDate());
    echeanceActivite->setDate(QDate::currentDate());
    dureeActivite->clear();
    lieuActivite->clear();
}


void FenetreActivite::checkDate(const QDate& d){
    if(d==dispoActivite->date() && d<QDate::currentDate())
        dispoActivite->setDate(QDate::currentDate());
    if(d==dispoActivite->date() && echeanceActivite->date()<dispoActivite->date())
        echeanceActivite->setDate(dispoActivite->date());
    else if (d==echeanceActivite->date() && echeanceActivite->date()<dispoActivite->date())
            dispoActivite->setDate(echeanceActivite->date());
}

