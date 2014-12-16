#ifndef WWW_REALIZATION_H
#define WWW_REALIZATION_H

#include "../language.h"

class WWWRealization : public QObject
{
    Q_OBJECT
public:
    Carcass* carcass;
    Language* language;
    QMap<QString, bool> DctCheck;
public:
    explicit WWWRealization(Carcass* _carcass, bool& flag_good);
    virtual ~WWWRealization();
private:
    void DctInitializ();

signals:

public slots:
    void SaveWord1(QString _word,
                  QString _transcription,
                  QStringList _translates,
                  QString _note);
    //void DctCheckChange(QMap<QString, bool>);
};

#endif // WWW_REALIZATION_H
