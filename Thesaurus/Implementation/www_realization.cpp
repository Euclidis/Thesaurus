#include "www_realization.h"

WWWRealization::WWWRealization(Carcass* _carcass, bool& flag_good)
{
    flag_good = true;
    carcass = _carcass;
    language = new Language(carcass, flag_good);
    if (flag_good){
        DctInitializ();
    }
}

void WWWRealization::DctInitializ()
{
    if(!language->words.isEmpty()){
        for (int i = 0; i < language->words.size(); ++i){
            for (int u = 0; u < language->words[i].dictionaryes.size(); ++u){
                if(!DctCheck.contains(language->words[i].dictionaryes[u])) DctCheck.insert(language->words[i].dictionaryes[u], false);
            }
        }
    }
}

WWWRealization::~WWWRealization()
{
    delete language;
}

void WWWRealization::SaveWord1(QString _word,
                              QString _transcription,
                              QStringList _translates,
                              QString _note)
{
    carcass->message("OK3");
    if(_word != ""){
        if(!_translates.isEmpty()){
            if(DctCheck.isEmpty()){   //Добавить !
                QStringList dct;
//                QMap<QString, bool>::const_iterator i = DctCheck.constBegin();
//                while (i != DctCheck.constEnd()) {
//                    if(i.value()) dct << i.key();
//                }
                dct << "Dct";        //Удалить
                if(!dct.isEmpty()){
                    Word w(_word, _transcription, _translates, dct, _note);
                    language->AddNewWord(w);
                    language->WriteFile();
                }
                else {
                    carcass->message(tr("Select a Dictionary"));
                }
            }
            else{
                carcass->message(tr("Create a Dictionary"));
            }
        }
    }
}
