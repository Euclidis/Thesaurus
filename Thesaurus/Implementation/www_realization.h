#ifndef WWW_REALIZATION_H
#define WWW_REALIZATION_H

#ifndef CARCASS_H
#include "../carcass.h"
#endif

class WWWAbstraction : public QObject
{
    Q_OBJECT

//*********************************************
//                 INTERFACE
//*********************************************
public:
    Carcass* carcass;
    CurrentLearnDir* language;
    QStringList DctCheck;
public:
    //-----------------------------------------
    explicit WWWAbstraction(Carcass* _carcass);
    virtual ~WWWAbstraction();
    //-----------------------------------------
    bool Initialize();
    void addDctCheck(QString);
    void removeDctCheck(QString);
public slots:
    bool SaveWord(QString _word,
                  QString _transcription,
                  QStringList _translates,
                  QString _note);
    bool AddDictionary(QString str);
//*********************************************

private:
    bool initialized;

signals:
    void DctShow();
    //void DctCheckChange(QMap<QString, bool>);
};

#endif // WWW_REALIZATION_H
