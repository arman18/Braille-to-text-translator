#ifndef LINEIDENTIFIRE_H
#define LINEIDENTIFIRE_H

#include "databundle.h"
#include "scalevaraibles.h"
#include "dotprocessor.h"
#include "charreader.h"

class LineIdentifire : public ScaleVaraibles
{
public:
    LineIdentifire();
    DataBundle getNextChar(QImage image, QPoint startPt);
private:
    DataBundle extractChar(QImage &image, QPoint blackPix);
    DataBundle findCenter(const QImage &image,QPoint cntrBlckDot);
    bool hasEnoughDot(QImage &image, int row);

    DotProcessor dotProcessor;
    CharReader charReader;
};

#endif // LINEIDENTIFIRE_H
