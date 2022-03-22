#include "relatorio_paper.h"

Relatorio_paper::Relatorio_paper(std::vector<int> etrografia_1,
                                 std::vector<int> etrografia_2,
                                 std::vector<int> catalogo,
                                 QList<QString> cata_name,
                                 int qnt_amostras)
{

    auto transfor_to_saida  = [](Calculo_paper c){

    };

    this->cata_name = cata_name;

//    std::vector<int> etrografia_1  = {0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2};
//    std::vector<int> etrografia_2  = {1, 1, 1, 1, 0, 0, 0, 0, 2, 2, 2, 2, 2};
//    std::vector<int> catalogo  = {0, 1, 2};


     this->medido = new Calculo_paper(etrografia_1, etrografia_2, catalogo);
//    varios_kappa.push_back(c_1);

    for(int i=0; i<qnt_amostras; i++){
        Bootstrap a = Bootstrap(etrografia_1,etrografia_2 );
        std::tuple< std::vector<int>, std::vector<int> >  novas_etografias  = a.generate_new_etografia();
        std::vector<int> e1 = std::get<0>(novas_etografias);
        std::vector<int> e2 = std::get<1>(novas_etografias);
        Calculo_paper *c = new Calculo_paper(e1, e2, catalogo);
        this->varios_kappa.push_back(c);

//        qDebug() << i;

    }

}

void Relatorio_paper::generate_relatorio()
{

    auto ge_conc = [](Calculo_paper::Concordancia con, QList<QString> texto ){
        auto gene_matriz_conco = [](std::vector< std::vector<int> > matriz_concordancia){
            QList<QString> ls_matriz;
            for(auto linha: matriz_concordancia){
                ls_matriz.push_back(generate_list_number_json(linha));
            }

            return creat_list(ls_matriz);
        };

        QList<QString> ls_kappa;
        ls_kappa.push_back(creat_var("categoria", "'" + texto[con.categoria]+ "'"));
        ls_kappa.push_back(creat_var("observada",  QString::number(con.observada)));
        ls_kappa.push_back(creat_var("acaso",  QString::number(con.acaso)));
        ls_kappa.push_back(creat_var("vies",  QString::number(con.vies)));
        ls_kappa.push_back(creat_var("kappa",  QString::number(con.kappa)));
        ls_kappa.push_back(creat_var("prevalencia",  QString::number(con.prevalencia)));
        ls_kappa.push_back(creat_var("matriz_concordancia", gene_matriz_conco(con.matriz_concordancia)));

        return creat_object(ls_kappa);
    };

    auto ge_ls_categoria = [&ge_conc](std::vector<Calculo_paper::Concordancia> list_concordancia,
                                      QList<QString> texto){
        QList<QString> saida_ls;

        for(auto linha: list_concordancia){
            saida_ls.push_back(ge_conc(linha, texto));
        }
        return creat_list(saida_ls);

    };

    auto generating_calculo_paper_json = [&ge_conc, &ge_ls_categoria ](Calculo_paper *c ,
                                             QList<QString> texto_ls_cat   ){
        QList<QString> saida_ls;
        QList<QString> texto = {"Catalog"};
        saida_ls.push_back(creat_var("et1",generate_list_number_json(c->et1)));
        saida_ls.push_back(creat_var("et2",generate_list_number_json(c->et2)));
        saida_ls.push_back(creat_var("catalogo_var",ge_conc(c->catalogo_var, texto)));
        saida_ls.push_back(creat_var("catalogo_var_max",ge_conc(c->catalogo_var_max, texto)));
        saida_ls.push_back(creat_var("list_kappa_cat",ge_ls_categoria(c->list_kappa_cat, texto_ls_cat)));
        saida_ls.push_back(creat_var("list_kappa_cat_max",ge_ls_categoria(c->list_kappa_cat_max, texto_ls_cat)));

        return creat_object(saida_ls);
    };




    QList<QString> relatorio;
    relatorio.push_back(creat_var("medido",
                                  generating_calculo_paper_json(this->medido, this->cata_name)));

    relatorio.push_back(creat_var("ls_cat_txt",creat_list_string(this->cata_name)));



    QList<QString> varios_kapp;
    for(auto bootstraped: this->varios_kappa){
        varios_kapp.push_back(generating_calculo_paper_json(bootstraped, this->cata_name));
    }

    relatorio.push_back(creat_var("varios_kappa",creat_list(varios_kapp)));



//    relatorio.push_back(creat_var("medido",
//                                  generating_calculo_paper_json(this->medido)));


    txt_relatorio = creat_object(relatorio);

//    qDebug() << txt_relatorio;


}


QString creat_var(QString name, QString saida_ls){
    QString saida;

    saida = "'" + name + "'"+ ":" + saida_ls;
    return saida;

};

QString creat_list_string(QList<QString> saida_ls){
    QString saida;

    saida = saida + "[";
    for(int i=0 ; i< saida_ls.size(); i++){
        bool r_ultimo = i == saida_ls.size() - 1;
        if(r_ultimo){
            saida = saida + "'"+ saida_ls[i] +"'" + "]";
        }else{
            saida = saida + "'"+ saida_ls[i] +"'" + " , " ;
        }
    }
    return saida;

};

QString creat_list(QList<QString> saida_ls){
    QString saida;

    saida = saida + "[";
    for(int i=0 ; i< saida_ls.size(); i++){
        bool r_ultimo = i == saida_ls.size() - 1;
        if(r_ultimo){
            saida = saida + saida_ls[i] + "]";
        }else{
            saida = saida + saida_ls[i] + " , " ;
        }
    }
    return saida;

};

QString creat_object(QList<QString> saida_ls){
    QString saida;

    saida = saida + "{";
    for(int i=0 ; i< saida_ls.size(); i++){
        bool r_ultimo = i == saida_ls.size() - 1;
        if(r_ultimo){
            saida = saida + saida_ls[i] + "}";
        }else{
            saida = saida + saida_ls[i] + " , " ;
        }
    }
    return saida;

};

QString generate_list_number_json(std::vector<int> ls_int)
{
    QString saida;

//    saida =  creat_var "'" + name + "'"+ ":[";

    saida = "[";

    for(int i=0 ; i< ls_int.size(); i++){
        bool r_ultimo = i == ls_int.size() - 1;
        if(r_ultimo){
            saida = saida + QString::number(ls_int[i]) + "]";
        }else{
            saida = saida + QString::number(ls_int[i]) + " , " ;
        }

    }

    return saida;

}


void gera_relatorio_python(QString path, QString text)
{
    //    https://forum.qt.io/topic/115682/how-to-get-the-path-of-a-c-file-which-is-added-as-the-resource-file/12

    //C:\Users\User\AppData\Local\Temp o arquivo temporario fica aqui

    std::string path_inside_qrc = ":/script/relatorio/dist/gera_relatorio.exe";
    std::unique_ptr<QTemporaryFile> temporary_file;

    temporary_file.reset(
        QTemporaryFile::createNativeFile(QString::fromStdString(path_inside_qrc))
     );
    std::string file_name = temporary_file->fileName().toUtf8().constData();

//    QObject *parent;
    QString program = temporary_file->fileName();
    QStringList arguments;
    QString newname = program + ".exe";


    QFile::copy(program, newname);

    arguments << path << text;




//     QString Cmd = "cmd";
//    QProcess::startDetached(program, arguments );
    QObject *parent = nullptr;

    QProcess *myProcess = new QProcess(parent);
    myProcess->start( newname, arguments);
//    myProcess->waitForFinished(-1);


    if(myProcess->waitForStarted(5000))
    {
        QByteArray out_data = myProcess->readAllStandardOutput();
        QString out_string(out_data);
        qDebug() << out_string.toStdString().c_str();
    }
    else
    {
        qDebug() << "myProcess did not start in time";
    }
     myProcess->waitForFinished();


    temporary_file.reset();


    if (QFile::exists(newname))
    {
        QFile::remove(newname);

    }

}
