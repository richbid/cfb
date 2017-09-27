#ifndef _DEMO_H_
#define _DEMO_H_

#include "config.h"
#include "widgets.h"
#include "database.h"
#include "filesys.h"
#include "memio.h"
#include "networks.h"
#include "threads.h"

namespace demo
{
	class Thread : public QThread
	{
		rw_field(int, Status);

	public:
		~Thread(){}
		Thread(QObject* parent = 0) : QThread(parent) {}
	protected:
		virtual void run();
	};

	void startup();
	void centerWidget(QWidget* widget);
	char* stringToStdChars(const QString& input);
	int main();
}

#endif