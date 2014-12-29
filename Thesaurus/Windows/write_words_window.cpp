#include "write_words_window.h"
#include "ui_write_words_window.h"


WriteWordsWindow::WriteWordsWindow(Carcass * _carcass) :
    ui(new Ui::WriteWordsWindow), carcass(_carcass)
{
    ui->setupUi(this);
    realiz = new WWWAbstraction(carcass);
    DW = nullptr;
    //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>SOMEFASTCODING<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
    gtApi = new GTApi(this);
    connect(gtApi, SIGNAL(translationReady(GTApiTranslation)), SLOT(onTranslationReady(GTApiTranslation)));
    //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>SOMEFASTCODING<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
    if(realiz->Initialize()){
        ConnectRealizator();
        ConnectWidgets();
    }
    else{
        //*********** Добавить эксепшн ***************
       deleteLater();
    }
}

void WriteWordsWindow::ConnectRealizator()
{
    connect(realiz, SIGNAL(DctShow()),SLOT(DW_open()));
}

//*******************************************************************
//                 Функции "присоединения" виджетов
//*******************************************************************

//--------Сигналы от виджетов
void WriteWordsWindow::ConnectWidgets()
{
    connect(ui->pushButton, SIGNAL(clicked()), SLOT(SaveWord()));
    connect(ui->pushButton_2, SIGNAL(clicked()), SLOT(DW_open()));
}
//--------Функции для текстовых полей
void WriteWordsWindow::TakeTexts()
{
    word            = ui->lineEdit->text().trimmed();
    transcription   = ui->lineEdit_2->text().trimmed();
    translates      = ui->textEdit->toPlainText().split("\n");
    note            = ui->textEdit_2->toPlainText().trimmed();
}
void WriteWordsWindow::ClearTexts()
{
    ui->lineEdit->setText   ("");
    ui->lineEdit_2->setText ("");
    ui->textEdit->setText   ("");
    ui->textEdit_2->setText ("");
}
//--------Функции работы с дополнительным окном
void WriteWordsWindow::DW_open()
{
    if(!DW) DW = new DctWindow(realiz);
    DW->show();
}
void WriteWordsWindow::closeEvent(QCloseEvent * event)
{
    emit close_me(this);
    event->accept();
}
//*******************************************************************
//*******************************************************************


void WriteWordsWindow::SaveWord()
{
    TakeTexts();
    if(realiz->SaveWord(word, transcription, translates, note)) ClearTexts();
}

WriteWordsWindow::~WriteWordsWindow()
{
    delete gtApi; //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>SOMEFASTCODING<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
    delete ui;
}
//////////////////////////////////////////////////////////////////
//Translate button
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>SOMEFASTCODING<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
void WriteWordsWindow::on_pushButton_3_clicked()
{
  QString targetLang;
  if (carcass->CurLearnDir->Get().targL == "England")
    targetLang = "en";
     gtApi->translate(ui->lineEdit->text(), "ru", "en", "ru");
}

void WriteWordsWindow::onTranslationReady(const GTApiTranslation& gtApiTr) {

//ui->lineEdit->clear();
//ui->textEdit_2->clear();

    const GTReplyObject & ref = gtApiTr.replyObjectRef();

    for (int child =0; child < ref.size(); ++child ) {

        QString comment;/* = "Unknown parameter\n";*/
        QString childDescription = "Unknown/Not-Usable";

        if ( child == 0 ) {

            childDescription = "[<Translation>*, <Translit>]";
            comment = QString("Translation:\n\t%1 (%2)\n").arg(gtApiTr.translation().join(""), gtApiTr.translit());
            comment += QString("Original:\n\t%1 (%2)\n").arg(gtApiTr.original().join(""), gtApiTr.sourceTranslit());

        } /*else if (child == 2) {
            childDescription = "detected_source_lang";
            comment = QString("Detected Source Language: %1\n").arg(gtApiTr.detectedSourceLang());

        }else if (child == 7) {
            childDescription="<SpellChecker>";
            comment = QString("Spell Checker:\n\t%1\nFormatted:\n\t%2\n").arg(gtApiTr.spellChecked(), gtApiTr.spellChecked(true));

        } else if (child == 8) {
            childDescription = "<LangDetect>";
            comment = "Detected Languages:\n";

            QList<GTLangDetect> langsDetect = gtApiTr.detectedSourceLanguages();
            foreach (const GTLangDetect & langDetect, langsDetect ) {
                comment += QString("\tlang: %1 | reliability: %2\n").arg(langDetect.first, QString::number(langDetect.second));
            }
        } else if (child == 14) {
            childDescription = "<SeeAlsoList>";
            comment = "See Also Suggestions:\n";
            comment += "\t" + gtApiTr.seeAlsoList().join(", ") + "\n";

        } */else if (child == 1) {

            childDescription = "[<PosDict>*]";
            comment = "Part-of-speech dictionary:\n";

            QList<GTPosDict> dicts = gtApiTr.getPosDictionary();
            foreach ( const GTPosDict & dict, dicts) {
                QString header = QString("%1 - %2(#%3)").arg(dict.wordSourceBaseForm, dict.posNameHl, QString::number(dict.posDictEnum));
                comment += header + "\n";

                foreach (const GTPosDictEntry & entry, dict.entries) {

                    QString entryStr = QString("\t%1 %2\n").arg(entry.previousWordTarge, entry.wordTarget/*, QString::number(entry.score), entry.synsetIds.join("")*/);
                    comment += entryStr;
                }
            }

        }/* else if (child == 11) {
            childDescription = "[<SynonymDict>*]";
            comment = "Synonyms Dictionary:\n";

            QList<GTSynDict> dicts = gtApiTr.getSynDictionary();
            foreach ( const GTSynDict & dict, dicts) {
                QString header = QString("%1 - %2").arg(dict.wordBaseForm, dict.posName);
                comment += header + "\n";

                foreach (const GTSynDictEntry & entry, dict.entries) {
                    comment += QString("\t[%1] :\n\t%2\n").arg(entry.word_id, entry.synonyms.join(','));
                }
            }

        } else if (child == 12 ) {
            childDescription = "[<DefDict>*]";
            comment = "Definition Dictionary:\n";

            QList<GTDefDict> dicts = gtApiTr.getDefDictionary();
            foreach ( const GTDefDict & dict, dicts) {
                QString header = QString("%1 - %2").arg(dict.wordBaseForm, dict.posName);
                comment += header + "\n";

                foreach (const GTDefDictEntry & entry, dict.entries) {
                    comment += QString("\t[%1] :\n\t%2\n\t%3\n").arg(entry.word_id, entry.definition, entry.definitionExampleUsage);
                }
            }
        } else if (child == 13 ) {
            childDescription = "[<ExampleDict>*]";
            comment = "Example Dictionary:\n";

            GTExampleDict dict = gtApiTr.getExampleDictionary();
            foreach (const GTExampleDictEntry & entry, dict.entries) {
                comment += QString("\t[%1] : %2\n").arg(entry.word_id, entry.exampleFormatted);
            }
        }


        apiView->setTextColor(textColor);
        QString childName = QString("Child #%1: %2\n").arg(QString::number(child), childDescription);*/
        //apiView->append( childName + ref[child].toRawString(true)+ "\n");

        //apiComment->setTextColor(textColor);
        ui->textEdit_2->append(comment);
      }
}
