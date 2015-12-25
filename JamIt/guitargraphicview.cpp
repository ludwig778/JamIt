#include "guitargraphicview.h"
#define WIDTH           600
#define HEIGHT          50
#define OFFSETNUT       20
#define OFFSETLASTFRET  17
#define OFFSETEDGE      12
#define FRETWIDTH       7
#define STRINGWIDTH     4
#define STRINGSPACING   30
#define CIRCLEDIAMETER  24
#define CIRCLEDIAMETER2 20

GuitarGraphicView::GuitarGraphicView(QWidget *parent) :
    QWidget(parent)
{
    //setFixedWidth(WIDTH);
    //setFixedHeight(HEIGHT);
    setMinimumWidth(WIDTH);
    setMinimumHeight(HEIGHT);
    nb_string = 6;
    pitch = 0;
    number_fret = 12;
    gamme.clear();
    gamme << 0 << 0 << 0 << 0 << 0 << 0 << 0 << 0 << 0 << 0 << 0 << 0;
    fretPattern.clear();
    fretPattern << 0 << 0 << 1 << 0 << 1 << 0 << 1 << 0 << 1 << 0 << 0 << 2;
}

void GuitarGraphicView::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    QPixmap temp;
    QString fileName = ":/Pictures/Resources/maple.png";
    QBrush brush = QBrush();
    QColor color = QColor(192,192,192,50);
    temp.load(fileName);
    p.drawPixmap(0, 0, temp);
    int mWidth = width()-OFFSETNUT-OFFSETLASTFRET;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(color);
    p.setBrush(brush);
    p.drawRect(0,0,width()-1,height()-1);
    fretList.clear();
    stringList.clear();
    p.fillRect(OFFSETNUT-FRETWIDTH,0,FRETWIDTH*2,height()-1,1);


    color.setRgb(192,192,192,200);
    brush.setColor(color);
    p.setBrush(brush);

    for(int i = 1;i < number_fret+1;i++)
    {
        fretList << ((mWidth/number_fret)*i)+OFFSETNUT;
        p.fillRect(fretList.last(),0,FRETWIDTH,height()-1,1);
        p.drawRect(fretList.last(),0,FRETWIDTH,height()-1);
    }
    color.setRgb(0,0,0,255);
    brush.setColor(color);
    p.setBrush(brush);

    int calcul = 0;
    for(int i = 0; i < number_fret; i++)
    {
        if(fretPattern.at(i%12) == 1)
        {
            p.drawEllipse(((fretList.at(i-1)+fretList.at(i))/2)-CIRCLEDIAMETER/2+FRETWIDTH/2+2
                          ,((height()/2)-CIRCLEDIAMETER/2)-1,CIRCLEDIAMETER,CIRCLEDIAMETER);
        }
        if(fretPattern.at(i%12) == 2)
        {
            p.drawEllipse(((fretList.at(i-1)+fretList.at(i))/2)-CIRCLEDIAMETER/2+FRETWIDTH/2+2
                          ,((height()/2)-CIRCLEDIAMETER/2)-1+(STRINGSPACING*5)/3
                          ,CIRCLEDIAMETER,CIRCLEDIAMETER);
            p.drawEllipse(((fretList.at(i-1)+fretList.at(i))/2)-CIRCLEDIAMETER/2+FRETWIDTH/2+2
                          ,((height()/2)-CIRCLEDIAMETER/2)-1-(STRINGSPACING*5)/3
                          ,CIRCLEDIAMETER,CIRCLEDIAMETER);
        }
        else
        {
        }
    }

    color.setRgb(150,150,150,232);
    brush.setColor(color);
    p.setBrush(brush);
    int mHeight = height()-OFFSETEDGE*2;
    setFixedHeight(nb_string*STRINGWIDTH+OFFSETEDGE*2+(nb_string-1)*STRINGSPACING);

    for(int i = 0;i < nb_string;i++)
    {
        stringList << ((mHeight/(nb_string-1))*i)+OFFSETEDGE-(STRINGWIDTH/2)+1;
        p.drawRect(0,stringList.last(),width()-1,STRINGWIDTH);
    }

    tuning << 7 << 2 << 10 << 5 << 0 << 7;

    notes = new Notes();

    int x, y;
    for(int i = 0;i < nb_string;i++)
    {
        calcul = (12-pitch+tuning.at(i))%12;
        for(int j = 0;j < number_fret+1;j++)
        {
            if(gamme.at((calcul+j)%12) == 1)
            {
                y = stringList.at(i)-CIRCLEDIAMETER2/2+2;
                if(j == 0)
                {
                    x = OFFSETNUT-CIRCLEDIAMETER2+FRETWIDTH*6/4-1;
                    p.drawEllipse(x,stringList.at(i)-CIRCLEDIAMETER2/2+2,CIRCLEDIAMETER2,CIRCLEDIAMETER2);
                }
                else
                {
                    x = fretList.at(j-1)-CIRCLEDIAMETER2/2+(FRETWIDTH*2)/3-(fretList.at(2)-fretList.at(1))/2;
                    p.drawEllipse(x,stringList.at(i)-CIRCLEDIAMETER2/2+2,CIRCLEDIAMETER2,CIRCLEDIAMETER2);
                }
                QString varNote = notes->listReturn().at(((tuning.at(i)+j)%12));
                if(varNote.length()==2) x=x-4;
                p.drawText(x+8,y+14,varNote);
            }
        }
    }

    p.end();
}

void GuitarGraphicView::updateNbString(int nb)
{
    nb_string = nb;
}

void GuitarGraphicView::updateTuning(QList<int> tuningSended)
{
    tuning.clear();
    tuning.append(tuningSended);
}

/*void GuitarGraphicView::updateScalePitch()
{
    repaint();
}*/

void GuitarGraphicView::updateScale(QString scalePattern, int pitch)
{
    this->pitch = pitch;
    if(scalePattern != "")
    {
        gamme.clear();
        for(int i = 0 ; i < 12; i++)
        {
            gamme << (scalePattern.at(i)).digitValue();
        }
        repaint();
        qDebug() << scalePattern << "test";
    }
}

void GuitarGraphicView::updateDoubleClickPitch(QModelIndex pitch)
{
    this->pitch = pitch.row();
    repaint();
}

void GuitarGraphicView::updateDoubleClickScale(QTreeWidgetItem* scale,int row)
{
    if(scale->text(1) != "")
    {
        gamme.clear();
        for(int i = 0 ; i < 12; i++)
        {
            gamme << scale->text(1).at(i).digitValue();
        }
        repaint();
        qDebug() << "guitar piano :" << scale << "row" << row;

    }
}

void GuitarGraphicView::updateFretNumber(int fret)
{
    this->number_fret = fret;
    repaint();
}
