#ifndef _BASE_THREADS_H_
#define _BASE_THREADS_H_

#include "config.h"
#include "QtCore/QtCore"

class BaseThread : public QThread
{
	Q_OBJECT

	rw_field(int, Progress)

public:
	~BaseThread();
	BaseThread(QObject* parent = 0);

signals:
	int reportProgress(int value, int min, int max);

protected:
	virtual void run();
};

#endif