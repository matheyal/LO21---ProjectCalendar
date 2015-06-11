#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    mainWindow = new QWidget;
    setWindowTitle("Project Calendar");

    //Chargement d'un fichier XML
    //new FenetreSave;
    //FenetreLoad* fl = new FenetreLoad(this);
    //fl->show();
    chargerFichier();

    //Cr�ation d'une barre d'outil MENU

    barreMenu = new QMenuBar;

    menuFichier = new QMenu("Fichier");
    barreMenu->addMenu(menuFichier);

        //Cr�ation d'un layout pour le menu
        layoutMenu = new QHBoxLayout;
        layoutMenu->addWidget(barreMenu);

    //Cr�ation de 3 onglets

    barreOnglet= new QTabWidget;
    onglet1 = new QWidget;
    onglet2 = new QWidget;
    onglet3 = new QWidget;

    //Onglet numero 1
    VueSemaine* Semaine = new VueSemaine(this);
    QVBoxLayout* layout1 = new QVBoxLayout;
    layout1->addWidget(Semaine);
/*
    QTableWidget* tableau= new QTableWidget(10,7);

    QVBoxLayout *layout1 = new QVBoxLayout;
    layout1->addWidget(tableau);

    //Premiere case du tableau
    QDate *today = new QDate(QDate::currentDate());
    for(int i=0;i<7; i++)
    {
        QTableWidgetItem* a = new QTableWidgetItem((today->addDays(i)).toString());
        tableau->setHorizontalHeaderItem(i,a);
    }
*/

        onglet1->setLayout(layout1);

        //Onglet numero 2

            //Selectionner projet

            label1 = new QLabel("Selectonner projet");
            nouveau = new QPushButton("Nouveau Projet");
            supmod=new QPushButton("Supprimer ou modifier Projet");

            layoutBoutonProjet = new QHBoxLayout;
            layoutBoutonProjet->addWidget(nouveau);
            layoutBoutonProjet->addWidget(supmod);


            groupeProjet = new QGroupBox("Projet", onglet2);
            groupeProjet->setLayout(layoutBoutonProjet);

            layoutProjet = new QVBoxLayout;
            layoutProjet->addLayout(layoutBoutonProjet);
            layoutProjet->addLayout(layoutTitreDescription);
            layoutProjet->addLayout(layoutDispoEcheance);

            groupeProjet = new QGroupBox("Selecitonner projet", onglet2);
            groupeProjet->setLayout(layoutProjet);



            QObject::connect(nouveau, SIGNAL(clicked()), this, SLOT(ajouterProjet()));
            QObject::connect(supmod, SIGNAL(clicked()), this, SLOT(supmodProjet()));


            //Nouvelle Tache

            unitaire = new QPushButton("Unitaire");
            unitaire->setDisabled(false);
            composite = new QPushButton("Composite");
            composite->setDisabled(false);
            precedence = new QPushButton("Precedence");
            precedence->setDisabled(false);

            layoutTache = new QHBoxLayout;
            layoutTache->addWidget(unitaire);
            layoutTache->addWidget(composite);
            layoutTache->addWidget(precedence);

            groupeTache = new QGroupBox("Tache", onglet2);
            groupeTache->setLayout(layoutTache);

            QObject::connect(unitaire, SIGNAL(clicked()), this, SLOT(ajouterTacheUnitaire()));
            QObject::connect(composite, SIGNAL(clicked()), this, SLOT(ajouterTacheComposite()));
            QObject::connect(precedence, SIGNAL(clicked()), this, SLOT(ajouterPrecedence()));

            //Activité


            nouvact= new QPushButton("nouvelle activité");
            supmodact = new QPushButton("supprimer ou modifier une activité"),

            layoutBoutonActivite = new QHBoxLayout;
            layoutBoutonActivite->addWidget(nouvact);
            layoutBoutonActivite->addWidget(supmodact);

            groupeActivite = new QGroupBox("Activite", this);
            groupeActivite->setLayout(layoutBoutonActivite);

            QObject::connect(nouvact,SIGNAL(clicked()), this, SLOT(nouvelleActivite()));
            QObject::connect(supmodact,SIGNAL(clicked()), this, SLOT(supModActivite()));

            // Ajouter au calendrier

            ajoutProjet = new QPushButton("Projet");
            ajoutTache = new QPushButton("Tache");
            ajoutActivite= new QPushButton("Activite");


            layoutAjout  =new QHBoxLayout;
            layoutAjout->addWidget(ajoutProjet);
            layoutAjout->addWidget(ajoutTache);
            layoutAjout->addWidget(ajoutActivite);

            groupeAjout = new QGroupBox("Programmer", onglet2);
            groupeAjout->setLayout(layoutAjout);

            QObject::connect(ajoutProjet, SIGNAL(clicked()), this, SLOT(ajoutProjetCalendrier()));
            QObject::connect(ajoutTache, SIGNAL(clicked()), this, SLOT(ajoutTacheCalendrier()));
            QObject::connect(choixProjet, SIGNAL(currentIndexChanged(int)), this, SLOT(afficherCaracteristiques()));
            QObject::connect(choixProjet, SIGNAL(currentIndexChanged(int)), this, SLOT(miseAJourTreeView()));
            QObject::connect(ajoutActivite, SIGNAL(clicked()), this, SLOT(ajoutActiviteCalendrier()));


            // Tree view

            tree =  new QTreeWidget;
            /*QTreeWidgetItem* item11 = new QTreeWidgetItem(tree);
            item11->setText(0, "test11");
            item1->addChild(item11);
            QTreeWidgetItem* item111 = new QTreeWidgetItem(tree);
            item111->setText(0, "test111");
            item11->addChild(item111);*/

            layoutTree = new QHBoxLayout;
            layoutTree->addWidget(tree);

            groupeTree = new QGroupBox("Tree-View", onglet2);
            groupeTree->setLayout(layoutTree);


        layoutDemiOnglet2 = new QVBoxLayout;
        layoutOnglet2 = new QHBoxLayout;
        layoutDemiOnglet2->addWidget(groupeProjet);
        layoutDemiOnglet2->addWidget(groupeTache);
        layoutDemiOnglet2->addWidget(groupeActivite);
        layoutDemiOnglet2->addWidget(groupeAjout);
        layoutOnglet2->addLayout(layoutDemiOnglet2);
        layoutOnglet2->addWidget(groupeTree);

        onglet2->setLayout(layoutOnglet2);




    //Cr�ation du bouton quitter

    quitter = new QPushButton("Quitter");
    quitter->setMaximumWidth(100);


        //Cr�ation d'un layout horizontal pour le bouton "quitter"
        QHBoxLayout *layoutHorizontal = new QHBoxLayout;
        layoutHorizontal->addWidget(quitter);

        // Connection pour le bouton quitter
        QObject::connect(quitter, SIGNAL(clicked()), this, SLOT(close()));

    //Attachement de ces onglets � la barre d'onglet

    barreOnglet->addTab(onglet1, "Calendrier");
    barreOnglet->addTab(onglet2, "Evenement");

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addLayout(layoutMenu);
    layout->addWidget(barreOnglet);
    layout->addLayout(layoutHorizontal);

    mainWindow->setLayout(layout);

    setCentralWidget(mainWindow);
}

void MainWindow::chargerProjet()
{
    QString dossier = QFileDialog::getExistingDirectory(this);
}

void MainWindow::supmodProjet(){
    FenetreSupModProjet *p=new FenetreSupModProjet;
    p->show();
}

void MainWindow::sauvegarderProjet()
{

    // choix du chemin d'enregistrement
    QString fichier = QFileDialog::getSaveFileName(this, "Enregistrer une tache", QString());
}

void MainWindow::enregistrerTache()
{
    /*QDate d2(2015,10, 10);
    QDate d3(2015, 11, 11);
    Duree d1(1,0);
    Tache& t=m.ajouterTache("1", titreTache->text(),d1,d2, d3);

    QMessageBox::information(this, "Enregistrement de la tache", t.getTitre());*/

}

void MainWindow::ajouterProjet()
{
    FenetreProjet* p= new FenetreProjet;
    p->show();
}

void MainWindow::ajouterTacheUnitaire()
{
    FenetreUnitaire *t = new FenetreUnitaire;
    t->show();
}

void MainWindow::ajouterTacheComposite()
{
    FenetreComposite *t = new FenetreComposite;
    t->show();
}


void MainWindow::nouvelleActivite()
{
    FenetreActivite *p=new FenetreActivite;
    p->show();
}

void MainWindow::supModActivite()
{
    FenetreSupModActivite *p=new FenetreSupModActivite;
    p->show();
}


void MainWindow::ajoutProjetCalendrier()
{
    QMessageBox::information(this, "information", "Projet ajoute");
}


void MainWindow::ajoutTacheCalendrier()
{
    /*AjoutTacheCalendrier *t = new AjoutTacheCalendrier;
    t->show();*/
}

void MainWindow::ajoutActiviteCalendrier()
{
    /*AjoutActiviteCalendrier *t = new AjoutActiviteCalendrier;
    t->show();*/
}

void MainWindow::ajouterPrecedence(){
    FenetrePrecedence* pr = new FenetrePrecedence();
    pr->show();
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    QMessageBox::StandardButton ret;
    ret = QMessageBox::warning(this, tr("Project Calendar"), tr("Voulez-vous sauvegarder votre calendrier ?"),
                QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
    if (ret == QMessageBox::Save){
       new FenetreSave();
        event->accept();
    }
    else if (ret == QMessageBox::Cancel)
       event->ignore();
    else if (ret == QMessageBox::Discard)
       event->accept();
}

void MainWindow::chargerFichier(){
    QMessageBox::StandardButton ret;
    ret = QMessageBox::question(this, tr("Project Calendar"), tr("Voulez-vous charger un calendrier ?"),
                QMessageBox::Yes | QMessageBox::No);
    if (ret == QMessageBox::Yes){
       new FenetreLoad();
    }
}

void MainWindow::afficherCaracteristiques()
{
    ProjetManager& pm = ProjetManager::getInstance();
    titreProjet->setText(pm.trouverProjet(choixProjet->currentText())->getTitre());
    titreProjet->setEnabled(true);
    description->setText(pm.trouverProjet(choixProjet->currentText())->getDesc());
    description->setEnabled(true);
    dispoProjet->setDate(pm.trouverProjet(choixProjet->currentText())->getDispo());
    dispoProjet->setEnabled(true);
    echeanceProjet->setDate(pm.trouverProjet(choixProjet->currentText())->getEcheance());
}

void MainWindow::miseAJourTreeView()
{
    tree->clear();
    ProjetManager& pm = ProjetManager::getInstance();
    QTreeWidgetItem* titre = new QTreeWidgetItem(tree);
    titre->setText(0, pm.trouverProjet(choixProjet->currentText())->getTitre());
    tree->addTopLevelItem(titre);
}

