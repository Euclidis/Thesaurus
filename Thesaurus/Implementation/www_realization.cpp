#include "www_realization.h"

//**************************************************************************
//                               INTERFACE
//**************************************************************************

WWWAbstraction::WWWAbstraction(Carcass* _carcass)
{
    carcass = _carcass;
    language = new CurrentLearnDir(carcass);
    initialized = false;
}

bool WWWAbstraction::Initialize()
{
//    if(language->Initialize()){
//        initialized = true;
//        return true;
//    }
    return false;
}

bool WWWAbstraction::SaveWord(QString _word,
                              QString _transcription,
                              QStringList _translates,
                              QString _note)
{
    if(initialized){
        if(_word != ""){
            if(!_translates.isEmpty()){
//                if(!language->dictionaries.isEmpty()){
                    if(!DctCheck.isEmpty()){
                        Word w(_word, _transcription, _translates, DctCheck, _note);
                        language->AddWord(w);
                        return true;
                    }
                    else{
                        emit DctShow();
                        carcass->message(tr("Select a Dictionary"));
                    }
//                }
//                else{
//                    emit DctShow(); //нужно вызывать меню ****************************
//                    carcass->message(tr("Create a Dictionary"));
//                }
            }
        }
    }
    else{
        carcass->message("Не инициализирован абстрактор WWW");
    }
    return false;
}

bool WWWAbstraction::AddDictionary(QString str)
{
    if(initialized){
        if(language->AddDictionary(str)) return true;
    }
    else{
        carcass->message("Не инициализирован абстрактор WWW");
    }
    return false;
}

void WWWAbstraction::addDctCheck(QString str)
{
    if(!DctCheck.contains(str)) DctCheck << str;
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
