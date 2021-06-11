#include "ethowatcher.h"
#include <QtGlobal>
#include <QMessageBox>



void assert_file_exist(QString nome_arquivo){
    try{
        QFile OutEtografia;
        OutEtografia.setFileName(nome_arquivo);
        bool r_arquivo_nao_existe = !OutEtografia.exists();

        if(r_arquivo_nao_existe){
            throw "File dosen't exist";
        }


    }catch(...){
        qDebug() << "File dosen't exist";
        Q_ASSERT(false);

    }

}

QString abrindo_etografia()
{
    QString fonteVideoETOXML = QFileDialog::getOpenFileName(
                NULL,
                "C://Users//Bio//Desktop//videos//",
                "*.etoxml"
                );

    return fonteVideoETOXML;
}

Etografia lerETOXML(QString nomeArquivo)
{
    assert_file_exist(nomeArquivo);

    QFile OutEtografia;
    OutEtografia.setFileName(nomeArquivo);
    OutEtografia.open(QIODevice::ReadOnly);

    // inicializando as estrutura necessárias para essa parte do código.
    analiseEtografica *etografiaLida = new analiseEtografica();
    catalago *catalagoLido = new catalago();
    dadosVideo *videoLido = new dadosVideo();

    videoLido->fps = 30;
    videoLido->controle = true;
    catalagoLido->controle = true;
    etografiaLida->controle = true;
    etografiaLida->quantidadeDePontos = 0;



    QXmlStreamReader streamReader(&OutEtografia); //passa o endereço
    QString conversor;


    bool r_habilitado_ler_proxima_linha = true;
    while(r_habilitado_ler_proxima_linha){

        streamReader.readNext();

        if(streamReader.name() == "analise"){

            if(etografiaLida->controle){

                etografiaLida->ponto.push_back(streamReader.attributes().value("ponto").toInt());
                etografiaLida->id.push_back(streamReader.attributes().value("id").toInt());
                etografiaLida->frameInicial.push_back(streamReader.attributes().value("frameInicial").toDouble());
                etografiaLida->frameFinal.push_back(streamReader.attributes().value("frameFinal").toDouble()-1);
                // etografiaLida->frameFinal.push_back(streamReader.attributes().value("frameFinal").toDouble());
                //   contadorTamanho++;
                etografiaLida->quantidadeDePontos++;

            }
            etografiaLida->controle=!etografiaLida->controle;
            //qDebug() << leitorXML.attributes().value("id").toInt();

        }


        if(streamReader.name() == "categoria"){

            if(catalagoLido->controle){
                QString nome;
                // etografiaLida.ponto.push_back(streamReader.attributes().value("ponto").toInt());
                catalagoLido->id.push_back(streamReader.attributes().value("id").toInt());
                nome= streamReader.attributes().value("nome").toString();
                catalagoLido->nome.push_back(nome);
                //etografiaLida.frameFinal.push_back(streamReader.attributes().value("frameFinal").toDouble());
                //   contadorTamanho++;
                catalagoLido->quantidadeDeCategorias++;

            }
            catalagoLido->controle=!catalagoLido->controle;
            //qDebug() << leitorXML.attributes().value("id").toInt();

        }

        if(streamReader.name() == "nomeCaminhoExt"){
            catalagoLido->caminhoArquivo= streamReader.readElementText();


        }

        if(streamReader.name() == "tipoAnalise"){
            catalagoLido->tipoAnalise= streamReader.readElementText();


        }

        if((streamReader.name() == "dadosVideoAnalisado")||(videoLido->controle)){


            if(streamReader.name() == "nomeVxml"){
                videoLido->nome= streamReader.readElementText();

            }

            if(streamReader.name() == "frameProces"){

                videoLido->frameInicial= streamReader.readElementText().toInt();

            }

            if(streamReader.name() == "frameFinal"){
                videoLido->frameFinal= streamReader.readElementText().toInt();

                videoLido->controle=false;
            }
            if(streamReader.name() == "fps"){
                videoLido->fps= streamReader.readElementText().toDouble();

                videoLido->controle=false;
            }


        }
        r_habilitado_ler_proxima_linha = !streamReader.atEnd() && !streamReader.hasError();
    }

    Etografia etografia_lida;
    etografia_lida.registro = etografiaLida;
    etografia_lida.catalogo = catalagoLido;
    etografia_lida.video = videoLido;



    OutEtografia.close();

    return etografia_lida;
}

ethowatcher::ethowatcher()
{
}



