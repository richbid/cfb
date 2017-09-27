#include "log.h"
#include <QDebug>

namespace onelab {

log::Messages ErrorList;
log::Messages InfoList;

log::Message::Message(const QString& aSender, const QString& aContent)
{
    Sender = aSender;
    Content  = aContent;
    Time = QDateTime::currentDateTime().toString("yyyy/MM/dd HH:mm:ss.zzz");
}

int log::printf(const char* format, ...)
{
    va_list arg;
    int done;

    va_start(arg, format);
    done = vfprintf(stdout, format, arg);
    va_end(arg);

    return done;
}

void log::err(const QString &aSender, QVariant aContent)
{
    mark(aSender, aContent, ErrorList);
}

void log::info(const QString &aSender, QVariant aContent)
{
    mark(aSender, aContent, InfoList);
}

bool log::outputInfo(QIODevice *writer)
{
    return output(writer, InfoList);
}

bool log::outputError(QIODevice *writer)
{
    return output(writer, ErrorList);
}

bool log::output(QIODevice *writer, const Messages &list)
{
    QString line;    
    if (writer)
    {
        foreach(Message msg, list)
        {
            line = msg.Time + "\t" + msg.Sender + "\t" + msg.Content;            
            if (writer->write(line.toUtf8()) < 0)
                return false;
        }        
    }
    else
    {
        foreach(Message msg, list)
        {
            line = msg.Time + "\t" + msg.Sender + "\t" + msg.Content;            
            printf("%s\n", line.toStdString().c_str());
        }    
    }
    return true;    
}

void log::mark(const QString& aSender, QVariant aContent, Messages& list)
{
    if (aSender.isEmpty() || aContent.isNull()) return;
    QString content = aContent.toString();
    if (content.isEmpty()) return;
    Message msg(aSender, content);
    list << msg;
}

}

