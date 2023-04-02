#pragma once
#ifndef PARSETEXT_H
#define PARSETEXT_H

#include <QString>

class Parse{
private:
    qint32 pos;
    QString oldStr;
    QString newStr;
public:
    Parse(): oldStr(""), newStr(""), pos(0) {}
    virtual ~Parse() {}
    bool change(QString str);
    QString getText();
};

#endif // PARSETEXT_H
