#ifndef WORKERTHREAD_H
#define WORKERTHREAD_H

#include <QObject>
#include <QThread>

class WorkerThread : public QThread
{
    Q_OBJECT
public:
    explicit WorkerThread(QObject *parent = nullptr);
    void run() override {
            QString result;
            /* ... here is the expensive or blocking operation ... */
            emit resultReady(result);
        };



signals:
    void resultReady(const QString &s);

};

#endif // WORKERTHREAD_H
