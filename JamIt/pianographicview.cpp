#include "pianographicview.h"
#define WIDTH           600
#define HEIGHT          120
#define BLACKKEYRATIO   0.8
#define KEYWIDTH        5
#define KEYHEIGHT       80
#define NOTECIRCLE      14

PianoGraphicView::PianoGraphicView(QWidget *parent) :
    QWidget(parent)
{
    //setFixedWidth(WIDTH);
    //setFixedHeight(HEIGHT);
    setMinimumWidth(WIDTH);
    setMinimumHeight(HEIGHT);
    pitch = 0;
    octaveNumber = 2;
    gamme.clear();
    gamme << 0 << 0 << 0 << 0 << 0 << 0 << 0 << 0 << 0 << 0 << 0 << 0;
}

void PianoGraphicView::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    QBrush brush = QBrush();
    QColor color = QColor(192,192,192,200);
    color.setRgb(255,255,255,255);
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(color);
    p.setBrush(brush);
    //p.fillRect(0,0,width()-1,height()-1,1);
    p.drawRect(0,0,width()-1,height()-1);

    int x, y;
    keyList.clear();

    float keyWidth = (width()/(((octaveNumber*7)+1)*1.0));
    for( int i = 0; i < (octaveNumber*7)+1; i++)
    {
        keyList << keyWidth*i;
        p.drawLine(keyList.last(),0,keyList.last(),height());
    }
    QList<int> keyPattern;
    keyPattern << 0 << 1 << 1 << 0 << 1 << 1 << 1 ;


    keyWidth = keyWidth*BLACKKEYRATIO;
    for( int i = 0; i < octaveNumber*7; i++)
    {
        if(keyPattern.at(i%7)==1)
        {
            x = keyList.at(i)-(keyWidth/2)+1;
            p.fillRect(x,0,keyWidth,KEYHEIGHT,1);

        }
    }
    int count = 3;

    color.setRgb(255,0,0,255);
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(color);
    p.setBrush(brush);
    for( int i = 0; i < ((octaveNumber*7)*2)+1; i++)
    {
        if((i%2)==0)
        {
            if(gamme.at((12-pitch+count)%12)==1)
            {
                x = keyList.at(i/2)+(width()/(((octaveNumber*7)+1)*1.0))/2-NOTECIRCLE/2;
                y = 100;
                p.drawEllipse(x,y,NOTECIRCLE,NOTECIRCLE);
            }
            count++;
        }
        else
        {
            if(keyPattern.at(((i/2)+1)%7) == 1)
            {
                if(gamme.at((12-pitch+count)%12)==1)
                {
                    x = keyList.at((i/2)+1)-NOTECIRCLE/2;
                    y = 50;
                    p.drawEllipse(x,y,NOTECIRCLE,NOTECIRCLE);
                }
                count++;
            }
        }
    }


    p.end();
}

/*void PianoGraphicView::updateScalePitch(int pitch)
{
    this->pitch = pitch;
    repaint();
}*/

void PianoGraphicView::updateScale(QString scalePattern, int pitch)
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
    }
}

void PianoGraphicView::updateOctaveCount(int octave)
{
    this->octaveNumber = octave;
    repaint();
}
