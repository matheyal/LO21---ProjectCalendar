#ifndef VUESEMAINE
#define VUESEMAINE

#include "qt.h"

class VueSemaine : public QWidget{

    Q_OBJECT

private:
    QStringList ListeJours, ListeHeures;
    QTableView* vueSemaine;
    QCalendarWidget* calendrier;
    QStandardItemModel* model;
    QHBoxLayout *Hlayout1, *Hlayout2;
    QVBoxLayout* Vlayout;
    QPushButton *semaineSuivante, *semainePrecedente;
    QLabel *semaineCourante;

public:
    VueSemaine(QWidget* parent=0);

public slots:
    //void updateVueSemaine();

};

#endif // WEEKVIEW

