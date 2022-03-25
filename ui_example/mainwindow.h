#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>

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
//    void on_pushButton_clicked();

    void on_pb_add_categorie_clicked();


    void on_pb_create_matriz_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    QVBoxLayout * ls_categorias;
    QList<QLabel *> ls_label;
    QList<QList<QLineEdit*>> ls_edi;
};
#endif // MAINWINDOW_H
