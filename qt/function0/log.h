#ifndef LOG_H
#define LOG_H

#include <QList>
#include <QDateTime>
#include <QString>
#include <QVariant>
#include <QIODevice>

namespace  onelab {
class log
{
public:
    static int printf(const char* format, ...);
    
    class Message
    {
    public:
        QString Time;
        QString Sender;
        QString Content;
        Message(const QString& aSender, const QString& aContent);
    };
    
public:
    typedef QList<Message> Messages;
    log();
    static void err(const QString& aSender, QVariant aContent);
    static void info(const QString& aSender, QVariant aContent);
    static bool outputInfo(QIODevice* writer);
    static bool outputError(QIODevice* writer);
    
private:
    static void mark(const QString& aSender, QVariant aContent, Messages &info);
    static bool output(QIODevice* writer, const Messages& info);

};

}

#endif // LOG_H
