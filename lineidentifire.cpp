#include "lineidentifire.h"
#include "dotBoundaryFinder.h"
LineIdentifire::LineIdentifire()
{

}

DataBundle LineIdentifire::getNextChar(QImage image, QPoint startPt)
{
    if(shouldPrint) qDebug()<<"getnextcher()"<<startPt<<Qt::endl;
    int row = image.height();
    int col = image.width();
    DataBundle dataBundle;
    for(int j=startPt.y();j<row;j+=5)
    {
        for(int i=startPt.x();i<col;i+=3)
        {
            if(image.pixel(i,j)==qRgb(0,0,0))
            {
                if(shouldPrint) qDebug()<<"getnextcher() founded a black pixel at: "<<QPoint(i,j)<<Qt::endl;
                dataBundle = extractChar(image,QPoint(i,j));
                if(dataBundle.isValidDot){
                    if(shouldPrint) qDebug()<<"getnextcher() corresponding dot is valid: "<<QPoint(i,j)<<Qt::endl;
                    DotBoundaryFinder ulbrObjct(image);
                    QList<int> list = ulbrObjct.findBoundary(i,j);
                    if(hasEnoughDot(image,(list[0]+list[2])/2)) // go through middle
                    {
                        if(shouldPrint) qDebug()<<"getnextcher() corresponding character can be reference: "<<QPoint(i,list[0]+list[2])<<Qt::endl;
                        return dataBundle;
                    }

                    else{
                        if(shouldPrint) qDebug()<<"getnextcher() bad luck this line do not have enough dot: "<<QPoint(i,list[0]+list[2])<<Qt::endl;
                        i=col; //continue
                    }
                }
                else {
                    if(shouldPrint) qDebug()<<"getnextcher() not a valid dot: "<<QPoint(i,j)<<Qt::endl;
                    i+=20; //continue
                }

            }
            //else if(_isDebug)  image.setPixel(i,j,qRgb(128,128,128));
            //else image.setPixel(i,j,qRgb(128,128,128));
        }
    }
    dataBundle.isValidDot = false;
    dataBundle.image = image;
    return dataBundle;
}

DataBundle LineIdentifire::extractChar(QImage &image, QPoint blackPix)
{   // this function only used by line identification purpose
    if(!(image.pixel(blackPix.x(),blackPix.y())==qRgb(0,0,0))){
        qDebug()<<"Error: extractChar(): "<<blackPix.x()<<","<<blackPix.y()<<Qt::endl;
        return DataBundle();
    }
    DataBundle dataBundle;
    dataBundle = dotProcessor.markDotByPoint(image,blackPix,false);
    if(dataBundle.isVeryLarge || dataBundle.isLargeDot || !dataBundle.shouldInCharIdentification){

        if(shouldPrint) qDebug()<<"extractChar(): "<<"problem with given dot"<<Qt::endl;
        if(dataBundle.isVeryLarge) image = dataBundle.image; // return by ref
        dataBundle.isValidDot = false;
        return dataBundle;
    }
    if(shouldPrint) qDebug()<<"extractChar(): "<<"no problem with given dot"<<Qt::endl;
    // okk this dot is almost perfect

    dataBundle = findCenter(image,dataBundle.dotCenter);
    if(!dataBundle.isValidCh() || !dataBundle.shouldInCharIdentification) //!dataBundle.isValidDot ||
    {
        if(shouldPrint) qDebug()<<"extractChar(): "<<"number of dots: "<<dataBundle.numberOfDotInCh<<Qt::endl;
        dataBundle.isValidDot = false;
        return dataBundle;
    }
    if(shouldPrint) qDebug()<<"extractChar(): "<<"character is found for: "<<dataBundle.dotCenter<<Qt::endl;
    // okk character is also perfect
    // now mark this character and return


    int u = dataBundle.charCenter.y()-_distBetDot.y();
    int b = dataBundle.charCenter.y()+_distBetDot.y();
    int l = dataBundle.charCenter.x()-_distBetDot.x()/2;
    int r = dataBundle.charCenter.x()+_distBetDot.x()/2;
    if(_isDebug) dotProcessor.markByBoundaries(image,qRgb(128,128,128),QList<int>()<<u<<l<<b<<r);
    if(_isDebug) dotProcessor.markByBoundaries(image,qRgb(128,128,128),QList<int>()<<u-3<<l-3<<b+3<<r+3);
    dataBundle.image = image;
    return dataBundle;

}

DataBundle LineIdentifire::findCenter(const QImage &image, QPoint cntrBlckDot)
{   // only used by extract() method
    QPoint leftUpper = QPoint(cntrBlckDot.x()+(_distBetDot.x()/2),cntrBlckDot.y()+_distBetDot.y());
    QPoint rightUpper = QPoint(cntrBlckDot.x()-(_distBetDot.x()/2),cntrBlckDot.y()+_distBetDot.y());
    if(shouldPrint) qDebug()<<"------------consdering left Upper---------------"<<Qt::endl;
     DataBundle dataBundle1 = charReader.getBrailleChPosCenter(image,leftUpper); // they do not modify image
     if(shouldPrint) qDebug()<<"------------consdering right Upper---------------"<<Qt::endl;
     DataBundle dataBundle2 = charReader.getBrailleChPosCenter(image,rightUpper);
     return dataBundle1.numberOfDotInCh>dataBundle2.numberOfDotInCh ? dataBundle1 : dataBundle2;
}

bool LineIdentifire::hasEnoughDot(QImage &image, int row)
{
    int count = 0;
    for(int i=0;i<image.width();i+=3)
        if(image.pixel(i,row-3)==qRgb(0,0,0)
                || image.pixel(i,row)==qRgb(0,0,0)
                || image.pixel(i,row+3)==qRgb(0,0,0)) {
            count++;
            if(count==2) return true; // two means actually three dot present in that line
            i+=20;
        }
        //else image.setPixel(i,row,qRgb(128,128,128));
    return false;
}
