#ifndef INPUTDLG_H
#define INPUTDLG_H
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QDialog>
#include <QLineEdit>
class InputDlg : public QDialog
{
    Q_OBJECT
public:
    InputDlg(QWidget* parent = 0);
    ~InputDlg();
private slots:
    void add_new_pack();
private:
    int common;
    int rare;
    int epic;
    int legendary;
    int Gcommon;
    int Grare;
    int Gepic;
    int Glegendary;
    QLabel *commonLabel;
    QLabel *rareLabel;
    QLabel *epicLabel;
    QLabel *legendaryLabel;
    QLabel *GcommonLabel;
    QLabel *GrareLabel;
    QLabel *GepicLabel;
    QLabel *GlegendaryLabel;
    QLineEdit *commonLineEdit;
    QLineEdit *rareLineEdit;
    QLineEdit *epicLineEdit;
    QLineEdit *legendaryLineEdit;
    QLineEdit *GcommonLineEdit;
    QLineEdit *GrareLineEdit;
    QLineEdit *GepicLineEdit;
    QLineEdit *GlegendaryLineEdit;
    QPushButton *OK;
    QGridLayout *mainLayout;
};

#endif // INPUTDLG_H
