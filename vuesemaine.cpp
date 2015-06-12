#include "vuesemaine.h"

VueSemaine::VueSemaine(QWidget* parent):QWidget(parent){

    calendrier = new QCalendarWidget(this);
    calendrier->hide();
    vueSemaine = new QTableView(this);
    semainePrecedente = new QPushButton("<<<");
    semainePrecedente->setMaximumWidth(400);
    semaineSuivante = new QPushButton(">>>");
    semaineSuivante->setMaximumWidth(400);
    //semaineCourante = new QLabel("08 Juin - 14 Juin",this);
    choixSemaine = new ChoixSemaine(QDate::currentDate());
    choixSemaine->setCalendarPopup(true);
    choixSemaine->setMinimumWidth(150);

    ListeJours<<"Lundi"<<"Mardi"<<"Mercredi"<<"Jeudi"<<"Vendredi"<<"Samedi"<<"Dimanche";

    for (unsigned int i = 0; i < 48 ; ++i){
        int heure = i/2;
        if (!(i % 2)) ListeHeures << QString("%0h00").arg(heure);
        else ListeHeures << QString();
    }

    model = new QStandardItemModel(this);
    model->setHorizontalHeaderLabels(ListeJours);
    model->setVerticalHeaderLabels(ListeHeures);

    //Création du modele vide
    for (int jour = 0; jour < 7; ++jour){
        for (int demieHeure = 0; demieHeure < 48; ++demieHeure){
            QStandardItem *item = new QStandardItem();
            model->setItem(demieHeure, jour, item);
            model->item(demieHeure, jour)->setEditable(false);
            item->setData(Qt::AlignCenter, Qt::TextAlignmentRole);
            //item->setFont(QFont());
        }
    }

    //QHeaderView* vHeader = weekView->verticalHeader();
    //vHeader->setSectionResizeMode(QHeaderView::Fixed);
    //vHeader->setDefaultSectionSize(20);

    vueSemaine->setModel(model);

    updateVueSemaine();

/*
    QStandardItem* item;
    item = model->item(2,3);
    item->setText("test");
    vueSemaine->setSpan(item->row(), item->column(), 3, 1);
    item->setBackground(QBrush(QColor(255, 200, 190)));
*/


    Hlayout1 = new QHBoxLayout;
    Hlayout1->addWidget(semainePrecedente);
    Hlayout1->addWidget(choixSemaine,0, Qt::AlignCenter);
    Hlayout1->addWidget(semaineSuivante);

    Hlayout2 = new QHBoxLayout;
    Hlayout2->addWidget(vueSemaine);

    Vlayout = new QVBoxLayout;
    Vlayout->addLayout(Hlayout1);
    Vlayout->addLayout(Hlayout2);

    this->setLayout(Vlayout);

    QObject::connect(semainePrecedente, SIGNAL(clicked()), choixSemaine, SLOT(semainePrecedente()));
    QObject::connect(semaineSuivante, SIGNAL(clicked()), choixSemaine, SLOT(semaineSuivante()));
    QObject::connect(choixSemaine, SIGNAL(dateChanged(QDate)),this, SLOT(updateVueSemaine()));

}

void VueSemaine::updateVueSemaine(){
    date = choixSemaine->date();

    //Nettoyage de la vue
    for (int jour = 0; jour < 7; ++jour){
        for (int demieHeure = 0; demieHeure < 48; ++demieHeure){
            model->item(demieHeure, jour)->setText("");
            model->item(demieHeure, jour)->setBackground(QBrush(QColor(Qt::white)));
        }
    }
    vueSemaine->clearSpans();

    //Parcours des programmations pour placer les objets dans la vue
    Agenda& agenda = Agenda::getInstance();
    const vector<Programmation*>* progs = agenda.getProgramamtions();
    for(vector<Programmation*>::const_iterator it = progs->begin(); it != progs->end(); ++it){
        if ((*it)->getDate() >= date.addDays(-date.dayOfWeek()+1) && (*it)->getDate() <= date.addDays(-date.dayOfWeek()+7)){
            //Vérifie si la date de la programmation en cours est dans la semaine séléctionnée
            QStandardItem *item = new QStandardItem();
            int column = (*it)->getDate().dayOfWeek()-1;
            unsigned short int heure = (*it)->getHoraire().getHeure();
            unsigned short int minutes = (*it)->getHoraire().getMinute();
            unsigned int row = (heure*2 + minutes/30);
            item = model->item(row,column);
            item->setText((*it)->getEvenement()->getTitre());
            item->setBackground(QBrush(QColor(190, 200, 255)));

        }
    }

}

void ChoixSemaine::semainePrecedente(){
    //QDate* old_date = date();

}

void ChoixSemaine::semaineSuivante(){

}
