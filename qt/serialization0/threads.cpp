#include "threads.h"

BaseThread::~BaseThread()
{
}

BaseThread::BaseThread(QObject* parent) : QThread(parent)
{
}

void BaseThread::run()
{

}