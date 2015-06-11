#include "vuesemaine.h"

VueSemaine::VueSemaine(QWidget* parent):QWidget(parent){

    calendrier = new QCalendarWidget(this);
    calendrier->hide();
    vueSemaine = new QTableView(this);
    semainePrecedente = new QPushButton("<<<");
    semaineSuivante = new QPushButton(">>>");
    semaineCourante = new QLabel("08 Juin - 14 Juin");

    for (unsigned int i = 0; i < 48 ; ++i){
        int heure = i/2;
        if (!(i % 2)) ListeHeures << QString("%0h00").arg(heure);
        else ListeHeures << QString();
    }

    model = new QStandardItemModel(this);
    model->setHorizontalHeaderLabels(ListeJours);
    model->setVerticalHeaderLabels(ListeHeures);

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

    QStandardItem* item;
    item = model->item(2,3);
    item->setText("test");
    vueSemaine->setSpan(item->row(), item->column(), 3, 1);
    item->setBackground(QBrush(QColor(255, 200, 190)));


    Hlayout1 = new QHBoxLayout;
    Hlayout1->addWidget(semainePrecedente);
    Hlayout1->addWidget(semaineCourante,0, Qt::AlignCenter);
    Hlayout1->addWidget(semaineSuivante);

    Hlayout2 = new QHBoxLayout;
    Hlayout2->addWidget(vueSemaine);

    Vlayout = new QVBoxLayout;
    Vlayout->addLayout(Hlayout1);
    Vlayout->addLayout(Hlayout2);

    this->setLayout(Vlayout);

    //QObject::connect()

}
