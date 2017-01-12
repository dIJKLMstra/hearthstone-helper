#include "inputdlg.h"
#include <QFile>
#include <QFont>
#include <QTextStream>
void InputDlg::add_new_pack()
{
    bool ok;
    QFile data("data.txt");
    data.open(QIODevice::ReadOnly);
    QTextStream in(&data);
    in >> common >> rare >> epic >> legendary;
    in >> Gcommon >> Grare >> Gepic >> Glegendary;
    data.close();
    QString commonStr = commonLineEdit ->text();
    int commonInt = commonStr.toInt(&ok);
    common += commonInt;
    QString rareStr = rareLineEdit ->text();
    int rareInt = rareStr.toInt(&ok);
    rare += rareInt;
    QString epicStr = epicLineEdit ->text();
    int epicInt = epicStr.toInt(&ok);
    epic += epicInt;
    QString legendaryStr = legendaryLineEdit ->text();
    int legendaryInt = legendaryStr.toInt(&ok);
    legendary += legendaryInt;
    QString GcommonStr = GcommonLineEdit ->text();
    int GcommonInt = GcommonStr.toInt(&ok);
    Gcommon += GcommonInt;
    QString GrareStr = GrareLineEdit ->text();
    int GrareInt = GrareStr.toInt(&ok);
    Grare += GrareInt;
    QString GepicStr = GepicLineEdit ->text();
    int GepicInt = GepicStr.toInt(&ok);
    Gepic += GepicInt;
    QString GlegendaryStr = GlegendaryLineEdit ->text();
    int GlegendaryInt = GlegendaryStr.toInt(&ok);
    Glegendary += GlegendaryInt;
    QTextStream out(&data);
    data.open(QIODevice::WriteOnly | QIODevice::Truncate);
    out << common <<" "<<rare<<" "<<epic<<" "<<legendary<<" ";
    out << Gcommon <<" "<<Grare<<" "<<Gepic<<" "<<Glegendary;
    data.close();
}
InputDlg::InputDlg(QWidget* parent)
    :QDialog(parent)
{
    setWindowTitle(tr("New Pack ?!"));

    QFont font("Consolas",11,60);
    commonLabel = new QLabel;
    commonLabel -> setFont(font);
    commonLabel -> setText(tr("Common : "));
    commonLineEdit = new QLineEdit;
    commonLineEdit -> setFixedSize(QSize(40,20));
    rareLabel = new QLabel;
    rareLabel -> setFont(font);
    rareLabel -> setText(tr("Rare : "));
    rareLineEdit = new QLineEdit;
    rareLineEdit -> setFixedSize(QSize(40,20));
    epicLabel = new QLabel;
    epicLabel -> setFont(font);
    epicLabel -> setText(tr("Epic : "));
    epicLineEdit = new QLineEdit;
    epicLineEdit -> setFixedSize(QSize(40,20));
    legendaryLabel = new QLabel;
    legendaryLabel -> setFont(font);
    legendaryLabel -> setText(tr("Legendary : "));
    legendaryLineEdit = new QLineEdit;
    legendaryLineEdit -> setFixedSize(QSize(40,20));

    GcommonLabel = new QLabel;
    GcommonLabel -> setFont(font);
    GcommonLabel -> setText(tr("  Golden Common : "));
    GcommonLineEdit = new QLineEdit;
    GcommonLineEdit -> setFixedSize(QSize(40,20));
    GrareLabel = new QLabel;
    GrareLabel -> setFont(font);
    GrareLabel -> setText(tr("  Golden Rare : "));
    GrareLineEdit = new QLineEdit;
    GrareLineEdit -> setFixedSize(QSize(40,20));
    GepicLabel = new QLabel;
    GepicLabel -> setFont(font);
    GepicLabel -> setText(tr("  Golden Epic : "));
    GepicLineEdit = new QLineEdit;
    GepicLineEdit -> setFixedSize(QSize(40,20));
    GlegendaryLabel = new QLabel;
    GlegendaryLabel -> setFont(font);
    GlegendaryLabel -> setText(tr("  Golden Legendary : "));
    GlegendaryLineEdit = new QLineEdit;
    GlegendaryLineEdit -> setFixedSize(QSize(40,20));

    OK = new QPushButton;
    OK -> setFixedSize(QSize(70,20));
    OK -> setText(tr("OK"));

    mainLayout = new QGridLayout(this);
    mainLayout -> setSpacing(10);
    mainLayout -> addWidget(commonLabel,0,0);
    mainLayout -> addWidget(commonLineEdit,0,1);
    mainLayout -> addWidget(rareLabel,1,0);
    mainLayout -> addWidget(rareLineEdit,1,1);
    mainLayout -> addWidget(epicLabel,2,0);
    mainLayout -> addWidget(epicLineEdit,2,1);
    mainLayout -> addWidget(legendaryLabel,3,0);
    mainLayout -> addWidget(legendaryLineEdit,3,1);
    mainLayout -> addWidget(GcommonLabel,0,2);
    mainLayout -> addWidget(GcommonLineEdit,0,3);
    mainLayout -> addWidget(GrareLabel,1,2);
    mainLayout -> addWidget(GrareLineEdit,1,3);
    mainLayout -> addWidget(GepicLabel,2,2);
    mainLayout -> addWidget(GepicLineEdit,2,3);
    mainLayout -> addWidget(GlegendaryLabel,3,2);
    mainLayout -> addWidget(GlegendaryLineEdit,3,3);
    mainLayout -> addWidget(OK,4,2);

    connect(OK,SIGNAL(clicked()),this,SLOT(add_new_pack()));
}

InputDlg::~InputDlg()
{

}

