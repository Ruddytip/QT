#include "parsetext.h"

#define MIN(a, b) (a < b) ? a : b

QString cast(QString str){
    if(str == "RUB") return "₽";
    if(str == "COPYRIGHT") return "©";
    if(str == "PROMIL") return "‰";
    if(str == "EURO") return "€";
    return "ERROR";
}

bool Parse::change(QString str){
    qint32 length = MIN(MIN(oldStr.length(), str.length()), pos);
    newStr = "";

    for (qint32 i = 0; i < length; i++){
        if (oldStr[i] != str[i]){
            pos = i;
            break;
        }
    }

    const QChar *arStr = str.constData();
    qint32 ppos = 0, lastp = -1; // курсор на начало символа, с которого будет осуществлять происк

    // метку #@
    bool chg = false; // есть изменения текста?

    for (qint32 fnd = str.indexOf("#@", pos); // поиск первого примера в тексте
        fnd != -1 && lastp != pos; // -1 - означает, что в строке нет (больше) примеров
        fnd = str.indexOf("#@", pos)
    ){
        newStr.insert(newStr.length(), &arStr[ppos], fnd); // копируем текст до примера

        int r = str.indexOf('@', fnd + 2);//если есть равенство, то пример завершен
        if(r == -1) return chg;

        QString exampl = "";
        exampl.insert(0, &arStr[fnd + 2], r - fnd - 2);
        newStr += cast(exampl);
        pos = r + 1;
        chg = true;

        newStr.insert(newStr.length(), &arStr[pos], str.length() - pos); //дописываем оставшийся текст
    }
    return chg;
}

QString Parse::getText(){
    oldStr = newStr;
    return oldStr;
}
