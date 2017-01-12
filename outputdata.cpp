#include "outputdata.h"
#include <QLabel>
#include <QGridLayout>
#include <QFile>
#include <QFont>
#include <QTextStream>
OutputData::OutputData(QWidget* parent)
   :QDialog(parent)
{
    setWindowTitle(tr("Show Some Details !"));

    QFile data("data.txt");
    data.open(QIODevice::ReadOnly);
    QTextStream in(&data);
    in >> common >> rare >> epic >> legendary >> Gcommon >> Grare >> Gepic >> Glegendary;

    QFont font("Consolas",10,60);
    upperWord = new QLabel;
    upperWord -> setFont(font);
    upperWord ->setText(tr("Since 2016/7/21 you have opened "));
    commonLabel = new QLabel;
    commonLabel -> setFont(font);
    commonLabel -> setText(tr("Rate of Common : "));
    commonRate = new QLabel;
    commonRate -> setFont(font);
    rareLabel = new QLabel;
    rareLabel -> setFont(font);
    rareLabel -> setText(tr("Rate of Rare : "));
    rareRate = new QLabel;
    rareRate -> setFont(font);
    epicLabel = new QLabel;
    epicLabel -> setFont(font);
    epicLabel -> setText(tr("Rate of Epic : "));
    epicRate = new QLabel;
    epicRate -> setFont(font);
    legendaryLabel = new QLabel;
    legendaryLabel -> setFont(font);
    legendaryLabel -> setText(tr("Rate of Legendary : "));
    legendaryRate = new QLabel;
    legendaryRate -> setFont(font);
    GcommonLabel = new QLabel;
    GcommonLabel -> setFont(font);
    GcommonLabel -> setText(tr("Rate of Golen Common : "));
    GcommonRate = new QLabel;
    GcommonRate -> setFont(font);
    GrareLabel = new QLabel;
    GrareLabel -> setFont(font);
    GrareLabel -> setText(tr("Rate of Golden Rare : "));
    GrareRate = new QLabel;
    GrareRate -> setFont(font);
    GepicLabel = new QLabel;
    GepicLabel -> setFont(font);
    GepicLabel -> setText(tr("Rate of Golden Epic : "));
    GepicRate = new QLabel;
    GepicRate -> setFont(font);
    GlegendaryLabel = new QLabel;
    GlegendaryLabel -> setFont(font);
    GlegendaryLabel -> setText(tr("Rate of Golden Legendary : "));
    GlegendaryRate = new QLabel;
    GlegendaryRate -> setFont(font);

    float sum = common + rare + epic + legendary + Gcommon + Grare + Gepic + Glegendary;
    QString tempStr;
    packsCnt = new QLabel;
    int lCnt = sum /5;
    QString packCnt;
    packCnt = tempStr.setNum(lCnt);
    packCnt += " packs";
    packsCnt -> setFont(font);
    packsCnt -> setText(packCnt);
    float commonR = common / sum;
    commonRate -> setText(tempStr.setNum(commonR));
    float rareR = rare / sum;
    rareRate -> setText(tempStr.setNum(rareR));
    float epicR = epic / sum;
    epicRate -> setText(tempStr.setNum(epicR));
    float legendaryR = legendary / sum;
    legendaryRate -> setText(tempStr.setNum(legendaryR));
    float GcommonR = Gcommon / sum;
    GcommonRate -> setText(tempStr.setNum(GcommonR));
    float GrareR = Grare / sum;
    GrareRate -> setText(tempStr.setNum(GrareR));
    float GepicR = Gepic / sum;
    GepicRate -> setText(tempStr.setNum(GepicR));
    float GlegendaryR = Glegendary / sum;
    GlegendaryRate -> setText(tempStr.setNum(GlegendaryR));

    mainLayout = new QGridLayout(this);
    mainLayout -> addWidget(upperWord,0,0,1,2);
    mainLayout -> addWidget(packsCnt,0,2);
    mainLayout -> addWidget(commonLabel,1,0);
    mainLayout -> addWidget(commonRate,1,1);
    mainLayout -> addWidget(rareLabel,2,0);
    mainLayout -> addWidget(rareRate,2,1);
    mainLayout -> addWidget(epicLabel,3,0);
    mainLayout -> addWidget(epicRate,3,1);
    mainLayout -> addWidget(legendaryLabel,4,0);
    mainLayout -> addWidget(legendaryRate,4,1);
    mainLayout -> addWidget(GcommonLabel,1,2);
    mainLayout -> addWidget(GcommonRate,1,3);
    mainLayout -> addWidget(GrareLabel,2,2);
    mainLayout -> addWidget(GrareRate,2,3);
    mainLayout -> addWidget(GepicLabel,3,2);
    mainLayout -> addWidget(GepicRate,3,3);
    mainLayout -> addWidget(GlegendaryLabel,4,2);
    mainLayout -> addWidget(GlegendaryRate,4,3);
}

OutputData::~OutputData()
{

}

