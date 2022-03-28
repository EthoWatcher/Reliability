#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>

#include "Agreement_global.h"
#include "agreement.h"


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

    void on_pb_load_eto_clicked();

    void on_sb_qnt_simp_2_valueChanged(int arg1);

    void on_pb_creat_analisis_clicked();

private:
    Ui::MainWindow *ui;
    QVBoxLayout * ls_categorias;
    QList<QLabel *> ls_label;
    QList<QList<QLineEdit*>> ls_edi;

    QList<Etografia> ls_etografias;

    std::vector<std::vector<int>> matriz_confusao;
    std::tuple<QList<QString> , std::vector<int> > catalogo;
    void print_categories();
};


std::tuple<std::vector<int> , std::vector<int> > gera_etografias_pela_matriz(std::vector<std::vector<int>> matriz_confusao);
QList<QList<QLineEdit*>> create_matriz_confusao(QList<QString> ls_categorias, QWidget *tela);
void prenche_valores_matriz(std::vector<std::vector<int>> matriz_confusao, QList<QList<QLineEdit *> > local);

#endif // MAINWINDOW_H
