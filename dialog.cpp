#include "dialog.h"
#include "ui_dialog.h"
#include <QPushButton>
#include <QGridLayout>
#include <QDialog>
#include <QFont>
void Dialog::showInputDlg()
{
        inputDlg = new InputDlg;
        inputDlg -> show();
}

void Dialog::showSecDlg()
{
    secDlg = new OutputData;
    secDlg -> show();
}

void Dialog::showThdDlg()
{
    thdDlg = new AddLegendary;
    thdDlg -> show();
}

void Dialog::showForDlg()
{
    forDlg = new LegendaryCardList;
    forDlg -> show();
}

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    setWindowTitle(tr("Hearthstone Helper"));

    this->resize( QSize( 250, 250 ));
    QFont font("Consolas",13,60);

    inputBtn = new QPushButton;
    inputBtn -> setFixedSize(QSize(200,50));
    inputBtn -> setFont(font);
    inputBtn -> setText(tr("New Pack ?!"));

    secBtn = new QPushButton;
    secBtn -> setFixedSize(QSize(200,50));
    secBtn -> setFont(font);
    secBtn -> setText(tr("Show Some Details !"));

    thdBtn = new QPushButton;
    thdBtn -> setFixedSize(QSize(200,50));
    thdBtn -> setFont(font);
    thdBtn -> setText(tr("New Legendary ?!"));

    forBtn = new QPushButton;
    forBtn -> setFixedSize(QSize(200,50));
    forBtn -> setFont(font);
    forBtn -> setText(tr("Legendary List"));

    mainLayout = new QGridLayout(this);
    mainLayout -> addWidget(inputBtn,0,0);
    mainLayout -> addWidget(secBtn,1,0);
    mainLayout -> addWidget(thdBtn,2,0);
    mainLayout -> addWidget(forBtn,3,0);

    connect(inputBtn,SIGNAL(clicked()),this,SLOT(showInputDlg()));
    connect(secBtn,SIGNAL(clicked()),this,SLOT(showSecDlg()));
    connect(thdBtn,SIGNAL(clicked()),this,SLOT(showThdDlg()));
    connect(forBtn,SIGNAL(clicked()),this,SLOT(showForDlg()));
}

Dialog::~Dialog()
{
    delete ui;
}
