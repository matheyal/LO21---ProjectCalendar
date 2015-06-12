#ifndef VUESEMAINE
#define VUESEMAINE

#include "qt.h"
#include "agenda.h"

class ChoixSemaine : public QDateEdit{
    Q_OBJECT
public slots:
    void semaineSuivante();
    void semainePrecedente();
public:
    ChoixSemaine(const QDate& date, QDateEdit* parent=0) : QDateEdit(date,parent){}
};

class VueSemaine : public QWidget{

    Q_OBJECT

private:
    QDate date;
    QStringList ListeJours, ListeHeures;
    QTableView* vueSemaine;
    QCalendarWidget* calendrier;
    ChoixSemaine* choixSemaine;
    QStandardItemModel* model;
    QHBoxLayout *Hlayout1, *Hlayout2;
    QVBoxLayout* Vlayout;
    QPushButton *semaineSuivante, *semainePrecedente;
    QLabel *semaineCourante;

public:
    VueSemaine(QWidget* parent=0);

public slots:
    void updateVueSemaine();

};

#endif // WEEKVIEW

