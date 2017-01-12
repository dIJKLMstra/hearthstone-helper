#ifndef DIALOG_H
#define DIALOG_H
#include "inputdlg.h"
#include "outputdata.h"
#include "addlegendary.h"
#include "legendarycardlist.h"
#include <QDialog>
#include <QPushButton>
#include <QGridLayout>
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
private slots:
    void showInputDlg();
    void showSecDlg();
    void showThdDlg();
    void showForDlg();
private:
    Ui::Dialog *ui;
    QPushButton *inputBtn;
    QPushButton *secBtn;
    QPushButton *thdBtn;
    QPushButton *forBtn;
    QGridLayout *mainLayout;
    InputDlg *inputDlg;
    OutputData *secDlg;
    AddLegendary *thdDlg;
    LegendaryCardList *forDlg;
};

#endif // DIALOG_H
