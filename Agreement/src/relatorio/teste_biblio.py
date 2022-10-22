import json
import escreve_xlsx as es
import plot_graph as pg

# path = "C:\\saida_teste\\figura_tese_dev.xlsx"
path = "C:\\saida_teste\\saida_integracao_final.xlsx"
with open(path + ".txt", 'r') as file:
    text = file.read()


# print(text)
text = text.replace("\'", "\"")
text = text.replace("nan", "\"nan\"")
data = json.loads(text)

pg.plot_graphe(path + ".txt")
es.create_excel_file(data, path)