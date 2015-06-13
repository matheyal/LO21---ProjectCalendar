#include"fenetreprecedence.h"

FenetrePrecedence::FenetrePrecedence(QMainWindow* parent):QMainWindow(parent)
{
    fenetrePrecedence = new QWidget;

    projets = new QComboBox;
    projets->addItem("");
    ProjetManager& pm=ProjetManager::getInstance();
    for(vector<Projet*>::const_iterator it = (*pm.getProjets()).begin(); it != (*pm.getProjets()).end(); ++it){
        projets->addItem((*it)->getId());
    }
    taches=new QComboBox;
    taches->setDisabled(true);
    precedente = new QComboBox;
    precedente->setDisabled(true);

    ajouter = new QPushButton("Ajouter");
    ajouter->setDisabled(true);
    quitter = new QPushButton("quitter");

    layoutFormulaire = new QFormLayout;
    layoutFormulaire->addRow("Projet : ", projets);
    layoutFormulaire->addRow("Tache : ", taches);
    layoutFormulaire->addRow("Contrainte de precedence : ", precedente);

    layoutHorizontal = new QHBoxLayout;
    layoutHorizontal->addWidget(ajouter);
    layoutHorizontal->addWidget(quitter);

    layout = new QVBoxLayout;
    layout->addLayout(layoutFormulaire);
    layout->addLayout(layoutHorizontal);

    fenetrePrecedence->setLayout(layout);

    QObject::connect(projets, SIGNAL(currentIndexChanged(int)), this, SLOT(load()));
    QObject::connect(ajouter, SIGNAL(clicked()), this, SLOT(ajouterPrecedence()));
    QObject::connect(quitter, SIGNAL(clicked()), this, SLOT(close()));
    QObject::connect(projets, SIGNAL(currentIndexChanged(int)), this, SLOT(checkModifier()));
    QObject::connect(taches, SIGNAL(currentIndexChanged(int)), this, SLOT(checkModifier()));
    QObject::connect(precedente, SIGNAL(currentIndexChanged(int)), this, SLOT(checkModifier()));

    setCentralWidget(fenetrePrecedence);
}

void FenetrePrecedence::load()
{
    taches->setEnabled(true);
    precedente->setEnabled(true);
    precedente->clear();
    taches->clear();
    taches->addItem("");
    precedente->addItem("");
    ProjetManager& pm= ProjetManager::getInstance();
    if(pm.trouverProjet(projets->currentText()))
    {
        vector<Tache*> tac= *pm.trouverProjet(projets->currentText())->getTaches();
        for(size_t i=0; i<tac.size();i++)
        {
            taches->addItem(tac[i]->getId());
            precedente->addItem(tac[i]->getId());
        }
    }
}

void FenetrePrecedence::checkModifier(){
    if(!projets->currentText().isEmpty() && !taches->currentText().isEmpty() && !precedente->currentText().isEmpty() && taches->currentText()!=precedente->currentText()){
       ajouter->setEnabled(true);
    }
    else ajouter->setDisabled(true);
}

void FenetrePrecedence::ajouterPrecedence()
{
    ProjetManager& pm = ProjetManager::getInstance();
    QDateTime d = pm.trouverProjet(projets->currentText())->getTache(precedente->currentText()).getDebut().addSecs((pm.trouverProjet(projets->currentText())->getTache(precedente->currentText()).getDuree().getDureeEnMinutes()*60));
    if(pm.trouverProjet(projets->currentText())->getTache(taches->currentText()).getEcheance()<d)
    {
            QMessageBox::warning(this, "erreur","impossible de finir cette tache a temps");
    }
    else if (taches->currentText()==precedente->currentText())
    {
        QMessageBox::warning(this, "erreur","les deux taches sont identiques ");
    }
    else
    {
        pm.trouverProjet(projets->currentText())->getTache(taches->currentText()).addPrecedence(&pm.trouverProjet(projets->currentText())->getTache(precedente->currentText()));
        QMessageBox::about(this, "ajout", "Tache precedente ajoutée");
        taches->setCurrentIndex(0);
        projets->setCurrentIndex(0);
        precedente->setCurrentIndex(0);
    }
}
