#include "fenetreprojet.h"
#include "projetmanager.h"

FenetreProjet::FenetreProjet(QMainWindow *parent) : QMainWindow(parent)
{
    fenetreProjet = new QWidget;

    idProjet = new QLineEdit;
    titreProjet = new QLineEdit;
    descriptionProjet = new QTextEdit;
    dispoProjet = new QDateTimeEdit(QDateTime::currentDateTime());
    echeanceProjet = new QDateTimeEdit(QDateTime::currentDateTime());
    enregistrerProjet = new QPushButton("Enregister");
    annuler = new QPushButton("annuler");

    layout21Form = new QFormLayout;
    layout21Form->addRow("Id", idProjet);
    layout21Form->addRow("Titre", titreProjet);
    layout21Form->addRow("Descritpion", descriptionProjet);
    layout21Form->addRow("Date de disponnibilite", dispoProjet);
    layout21Form->addRow("Date d'echeance", echeanceProjet);

    horizontal=new QHBoxLayout;
    horizontal->addWidget(enregistrerProjet);
    horizontal->addWidget(annuler);

    layoutNouveauProjet = new QVBoxLayout;
    layoutNouveauProjet->addLayout(layout21Form);
    layoutNouveauProjet->addLayout(horizontal);

    QObject::connect(enregistrerProjet, SIGNAL(clicked()), this, SLOT(saveProjet()));
    QObject::connect(enregistrerProjet, SIGNAL(clicked()), this, SLOT(close()));
    QObject::connect(annuler, SIGNAL(clicked()), this, SLOT(cancel()));
    QObject::connect(dispoProjet, SIGNAL(dateChanged(const QDateTime)), this, SLOT(checkDate(const QDateTime&)));
    QObject::connect(echeanceProjet, SIGNAL(dateChanged(const QDateTime&)), this, SLOT(checkDate(const QDateTime&)));

    groupeNouveauProjet = new QGroupBox("Rentrer un nouveau projet dans la base de donnee", this);
    groupeNouveauProjet->setLayout(layoutNouveauProjet);

    layout = new QHBoxLayout;
    layout->addWidget(groupeNouveauProjet);

    fenetreProjet->setLayout(layout);

    setCentralWidget(fenetreProjet);
}


void FenetreProjet::saveProjet()
{
    ProjetManager& pm= ProjetManager::getInstance();
    if(pm.trouverProjet(idProjet->text()))
        QMessageBox::warning(this, "erreur","sauvegarde impossible, id deja utilise");
    else pm.ajouterProjet(idProjet->text(), titreProjet->text(), descriptionProjet->toPlainText(), dispoProjet->dateTime(), echeanceProjet->dateTime());
}

void FenetreProjet::cancel(){
    idProjet->clear();
    titreProjet->clear();
    descriptionProjet->clear();
    dispoProjet->setDateTime(QDateTime::currentDateTime());
    echeanceProjet->setDateTime(QDateTime::currentDateTime());
}


void FenetreProjet::checkDate(const QDateTime& d){
    if(d==dispoProjet->dateTime() && d<QDateTime::currentDateTime())
        dispoProjet->setDateTime(QDateTime::currentDateTime());
    if(d==dispoProjet->dateTime() && echeanceProjet->dateTime()<dispoProjet->dateTime())
        echeanceProjet->setDateTime(dispoProjet->dateTime());
    else if (d==echeanceProjet->dateTime() && echeanceProjet->dateTime()<dispoProjet->dateTime())
            dispoProjet->setDateTime(echeanceProjet->dateTime());
}
