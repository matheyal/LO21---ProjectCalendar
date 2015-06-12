#ifndef FENETREACTIVITE
#define FENETREACTIVITE

#include <QMainWindow>
#include <QtWidgets>

class FenetreActivite : public QMainWindow
{
    Q_OBJECT
public:
    FenetreActivite(QMainWindow *parent=0);

private slots:
    void saveActivite();
    void cancel();
    void checkDate(const QDateTime &d);
    void checkType();

private:
    QLineEdit *idActivite;
    QCheckBox *reunion;
    QCheckBox *rdv;
    QLineEdit *titreActivite;
    QDateTimeEdit *dispoActivite;
    QDateTimeEdit *echeanceActivite;
    QSpinBox *dureeActivite;
    QLineEdit *lieuActivite;
    QLineEdit *personne;

    QPushButton *enregistrerActivite;
    QPushButton* annuler;

    QGroupBox* groupeNouvelleActivite;
    QHBoxLayout*horizontal;
    QFormLayout *layout21Form;
    QVBoxLayout* layoutNouvelleActivite;
    QHBoxLayout* layout;

    QWidget *fenetreActivite;
};

#endif // FENETREACTIVITE

