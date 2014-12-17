#include "www_realization.h"

//**************************************************************************
//                               INTERFACE
//**************************************************************************

WWWRealization::WWWRealization(Carcass* _carcass)
{
    carcass = _carcass;
    language = new Language(carcass);
    initialized = false;
}

bool WWWRealization::Initialize()
{
    if(language->Initialize()){
        initialized = true;
        DctInitializ();
        return true;
    }
    else return false;
}

void WWWRealization::SaveWord(QString _word,
                              QString _transcription,
                              QStringList _translates,
                              QString _note)
{
    if(initialized){
        if(_word != ""){
            if(!_translates.isEmpty()){
                if(DctCheck.isEmpty()){   //Добавить !
                    QStringList dct;
    //                QMap<QString, bool>::const_iterator i = DctCheck.constBegin();
    //                while (i != DctCheck.constEnd()) {
    //                    if(i.value()) dct << i.key();
    //                }
                    //dct << "Dct";        //Удалить
                    if(!dct.isEmpty()){
                        Word w(_word, _transcription, _translates, dct, _note);
                        language->AddNewWord(w);
                        language->WriteFile();
                    }
                    else {
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
}

WWWRealization::~WWWRealization()
{
    delete language;
}

//********************************************************************************
//********************************************************************************

void WWWRealization::DctInitializ()
{
    if (initialized){
        if(!language->words.isEmpty()){
            for (int i = 0; i < language->words.size(); ++i){
                for (int u = 0; u < language->words[i].dictionaryes.size(); ++u){
                    if(!DctCheck.contains(language->words[i].dictionaryes[u])) DctCheck.insert(language->words[i].dictionaryes[u], false);
                }
            }
        }
    }
    else{
        carcass->message("Не инициализирован абстрактор WWW");
    }
}
