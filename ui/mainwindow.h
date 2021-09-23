#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include "teaconcordancia.h"
#include "../src/ethowatcher.h"
#include "../src/concordance.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_reliability_clicked();

    void on_pb_teste_1_clicked();

private:
    Ui::MainWindow *ui;

    teaConcordancia *tela_reliability;
};
#endif // MAINWINDOW_H
