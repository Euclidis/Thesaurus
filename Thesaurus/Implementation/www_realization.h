#ifndef WWW_REALIZATION_H
#define WWW_REALIZATION_H

#include "../language.h"

class WWWRealization : public QObject
{
    Q_OBJECT

//*********************************************
//                 INTERFACE
//*********************************************
public:
    Carcass* carcass;
    Language* language;
    QMap<QString, bool> DctCheck;
public:
    //-----------------------------------------
    explicit WWWRealization(Carcass* _carcass);
    virtual ~WWWRealization();
    //-----------------------------------------
    bool Initialize();
public slots:
    void SaveWord(QString _word,
                  QString _transcription,
                  QStringList _translates,
                  QString _note);
//*********************************************

private:
    bool initialized;
private:
    void DctInitializ();

signals:
    void DctShow(QMap<QString, bool>);
    //void DctCheckChange(QMap<QString, bool>);
};

#endif // WWW_REALIZATION_H
