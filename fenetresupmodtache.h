#ifndef FENETRESUPMODTACHE
#define FENETRESUPMODTACHE

#include<QtWidgets>
#include"mainwindow.h"

class FenetreSupModTache : public QMainWindow
{
    Q_OBJECT
public:
    FenetreSupModTache(QMainWindow *parent=0);

private slots:
    void modifier();
    void checkDate(const QDateTime &d);
    void supprimer();
    void load();
    void loadTache();

private:
    QComboBox *idProjet;
    QComboBox *idTache;
    QComboBox *supprimerPrecedence;
    QComboBox *supprimerSousTache;
    QLineEdit *titreTache;

    QDateTimeEdit *dispoTache;
    QDateTimeEdit *echeanceTache;

    QTimeEdit *dureeTache;
    QLineEdit *precedentes;
    QLineEdit *soustaches;

    QPushButton *supp;
    QPushButton* ann;
    QPushButton* mod;

    QGroupBox *groupeTache;

    QHBoxLayout *horizontal;
    QFormLayout *layout21Form;
    QVBoxLayout* layoutNouvelleTache;
    QHBoxLayout *layout;

    QWidget *fenetreSupModTache;
};


#endif // FENETRESUPMODTACHE

