#include "www_realization.h"

//**************************************************************************
//                               INTERFACE
//**************************************************************************

WWWAbstraction::WWWAbstraction(Carcass* _carcass) : carcass (_carcass)
{
    initialized = false;
}

bool WWWAbstraction::Initialize()
{
    if(carcass->CurLearnDir->Get().knownL == "") return false;
    initialized = true;
    return true;
}

bool WWWAbstraction::SaveWord(QString _word,
                              QString _transcription,
                              QStringList _translates,
                              QString _note)
{
    if(initialized){
        if(_word != ""){
            if(!_translates.isEmpty()){
               if(!carcass->CurLearnDir->dictionaries.isEmpty()){
                    if(!DctCheck.isEmpty()){
                        Word w(_word, _transcription, _translates, DctCheck, _note);
                        carcass->CurLearnDir->AddWord(w);
                        return true;
                    }
                    else{
                        emit DctShow();
                        carcass->message(tr("Select a Dictionary"));
                    }
                }
                else{
                    emit DctShow();
                    carcass->message(tr("Create a Dictionary"));
                }
            }
        }
    }
    else{
        carcass->message("Не инициализирован абстрактор WWW");
    }
    return false;
}

bool WWWAbstraction::AddDictionary(QString dct_name)
{
    if(initialized){
        if(carcass->CurLearnDir->AddDictionary(dct_name))
            return true;
    }
    else{
        carcass->message("Не инициализирован абстрактор WWW");
        return false;
    }
}

void WWWAbstraction::addDctCheck(QString dct_name)
{
    if(!DctCheck.contains(dct_name)) DctCheck << dct_name;
}

void WWWAbstraction::removeDctCheck(QString str)
{
    int i = DctCheck.indexOf(str);
    if(i > -1) DctCheck.removeAt(i);
}

WWWAbstraction::~WWWAbstraction()
{

}

//********************************************************************************
//********************************************************************************
