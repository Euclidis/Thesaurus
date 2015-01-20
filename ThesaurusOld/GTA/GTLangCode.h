#ifndef GTLANGCODE_H
#define GTLANGCODE_H

#include <QString>
#include <QMap>

////////////////////////////////////////////////////////////////////////////////
// Impliments a table of ISO 639-1 language codes supported by Google Translate

namespace GTLangCode {

    static const QMap<QString, QString>& langMap();

    inline QString langName(const QString & iso639_1) {
        if (langMap().contains(iso639_1))
            return langMap()[iso639_1];
        return QString();
    }

    inline QString isoCode(const QString& languageName) {
        foreach(const QString& key, langMap().keys()){
            if (langMap()[key].compare(languageName, Qt::CaseInsensitive) == 0)
                return key;
        }
        return QString();
    }

    //////////////////////////////////////////////
    // Inizializes the langugages-code map
    // returns a reference to an initialized static map
    // created 2014/11/22

    static const QMap<QString, QString>& langMap() {

        static bool alreadyInitialized = false;
        static QMap<QString, QString> langMap;

        if (alreadyInitialized)
            return langMap;

//langMap["auto"]="Auto";
//langMap["af"]="Afrikaans";
//langMap["sq"]="Albanian";
//langMap["ar"]="Arabic";
//langMap["az"]="Azerbaijani";
//langMap["eu"]="Basque";
//langMap["bn"]="Bengali";
//langMap["be"]="Belarusian";
//langMap["bg"]="Bulgarian";
//langMap["ca"]="Catalan";
//langMap["zh-CN"]="Chinese Simplified";
//langMap["zh-TW"]="Chinese Traditional";
//langMap["hr"]="Croatian";
//langMap["cs"]="Czech";
//langMap["da"]="Danish";
//langMap["nl"]="Dutch";
//langMap["en"]="English";
//langMap["eo"]="Esperanto";
//langMap["et"]="Estonian";
//langMap["tl"]="Filipino";
//langMap["fi"]="Finnish";
//langMap["fr"]="French";
//langMap["gl"]="Galician";
//langMap["ka"]="Georgian";
//langMap["de"]="German";
//langMap["el"]="Greek";
//langMap["gu"]="Gujarati";
//langMap["ht"]="Haitian Creole";
//langMap["iw"]="Hebrew";
//langMap["hi"]="Hindi";
//langMap["hu"]="Hungarian";
//langMap["is"]="Icelandic";
//langMap["id"]="Indonesian";
//langMap["ga"]="Irish";
//langMap["it"]="Italian";
//langMap["ja"]="Japanese";
//langMap["kn"]="Kannada";
//langMap["ko"]="Korean";
//langMap["la"]="Latin";
//langMap["lv"]="Latvian";
//langMap["lt"]="Lithuanian";
//langMap["mk"]="Macedonian";
//langMap["ms"]="Malay";
//langMap["mt"]="Maltese";
//langMap["no"]="Norwegian";
//langMap["fa"]="Persian";
//langMap["pl"]="Polish";
//langMap["pt"]="Portuguese";
//langMap["ro"]="Romanian";
//langMap["ru"]="Russian";
//langMap["sr"]="Serbian";
//langMap["sk"]="Slovak";
//langMap["sl"]="Slovenian";
//langMap["es"]="Spanish";
//langMap["sw"]="Swahili";
//langMap["sv"]="Swedish";
//langMap["ta"]="Tamil";
//langMap["te"]="Telugu";
//langMap["th"]="Thai";
//langMap["tr"]="Turkish";
//langMap["uk"]="Ukrainian";
//langMap["ur"]="Urdu";
//langMap["vi"]="Vietnamese";
//langMap["cy"]="Welsh";
//langMap["yi"]="Yiddish";

        langMap["Auto"]="auto";
        langMap["Afrikaans"]="af";
        langMap["Albanian"]="sq";
        langMap["Arabic"]="ar";
        langMap["Azerbaijani"]="az";
        langMap["Basque"]="eu";
        langMap["Bengali"]="bn";
        langMap["Belarusian"]="be";
        langMap["Bulgarian"]="bg";
        langMap["Catalan"]="ca";
        langMap["Chinese Simplified"]="zh-CN";
        langMap["Chinese Traditional"]="zh-TW";
        langMap["Croatian"]="hr";
        langMap["Czech"]="cs";
        langMap["Danish"]="da";
        langMap["Dutch"]="nl";
        langMap["English"]="en";
        langMap["Esperanto"]="eo";
        langMap["Estonian"]="et";
        langMap["Filipino"]="tl";
        langMap["Finnish"]="fi";
        langMap["French"]="fr";
        langMap["Galician"]="gl";
        langMap["Georgian"]="ka";
        langMap["German"]="de";
        langMap["Greek"]="el";
        langMap["Gujarati"]="gu";
        langMap["Haitian Creole"]="ht";
        langMap["Hebrew"]="iw";
        langMap["Hindi"]="hi";
        langMap["Hungarian"]="hu";
        langMap["Icelandic"]="is";
        langMap["Indonesian"]="id";
        langMap["Irish"]="ga";
        langMap["Italian"]="it";
        langMap["Japanese"]="ja";
        langMap["Kannada"]="kn";
        langMap["Korean"]="ko";
        langMap["Latin"]="la";
        langMap["Latvian"]="lv";
        langMap["Lithuanian"]="lt";
        langMap["Macedonian"]="mk";
        langMap["Malay"]="ms";
        langMap["Maltese"]="mt";
        langMap["Norwegian"]="no";
        langMap["Persian"]="fa";
        langMap["Polish"]="pl";
        langMap["Portuguese"]="pt";
        langMap["Romanian"]="ro";
        langMap["Russian"]="ru";
        langMap["Serbian"]="sr";
        langMap["Slovak"]="sk";
        langMap["Slovenian"]="sl";
        langMap["Spanish"]="es";
        langMap["Swahili"]="sw";
        langMap["Swedish"]="sv";
        langMap["Tamil"]="ta";
        langMap["Telugu"]="te";
        langMap["Thai"]="th";
        langMap["Turkish"]="tr";
        langMap["Ukrainian"]="uk";
        langMap["Urdu"]="ur";
        langMap["Vietnamese"]="vi";
        langMap["Welsh"]="cy";
        langMap["Yiddish"]="yi";
        alreadyInitialized = true;
        return langMap;
    }
}

#endif // GTLANGCODE_H
