#ifndef PREPROCESSOR_H
#define PREPROCESSOR_H

#include <qimage.h>
#include "scalevaraibles.h"


class PreProcessor: public ScaleVaraibles
{
public:
    PreProcessor();
    QImage mainImageToBinImage(QString imageFile);
};

#endif // PREPROCESSOR_H
