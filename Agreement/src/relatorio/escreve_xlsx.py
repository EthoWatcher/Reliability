# import json
import xlsxwriter

# import pandas as pd

def next_alpha(s):
    return chr((ord(s.upper())+1 - 65) % 26 + 65)

def creat_lis_name(name):
    return [name, "not " + name]

def creta_matriz_confusao(wk, local, mat, ls_cat):
    def creat_name():
        letter = local[0]
        for i, cat in enumerate(ls_cat):
            wk.write(letter + str(local[1]+i), cat)


        for i, cat in enumerate(ls_cat):
            letter = next_alpha(letter)
            wk.write(letter + str(local[1]-1), cat)
    
    def matriz_confusao():
        last_c = 0
        letter = next_alpha(local[0])
        for linha in mat:
            for i,celula in enumerate(linha):
                wk.write(letter + str(local[1]+i), celula)
            letter = next_alpha(letter)
        
        last_c = local[1] + len(mat[0])
        return letter, last_c
     
    creat_name()
    letter = matriz_confusao()
    return letter

def set_descricao(wk, local, mat):
    wk.write(local[0] + str(local[1]-1), 'Observed agreement')
    wk.write(local[0] + str(local[1]), mat['observada'])
    local = (next_alpha(local[0]), local[1])

    wk.write(local[0] + str(local[1]-1), 'Chance agreement')
    wk.write(local[0] + str(local[1]), mat['acaso'])
    local = (next_alpha(local[0]), local[1])

    wk.write(local[0] + str(local[1]-1), 'Cohen Kappa')
    wk.write(local[0] + str(local[1]), mat['kappa'])
    local = (next_alpha(local[0]), local[1])

    wk.write(local[0] + str(local[1]-1), 'Bias')
    wk.write(local[0] + str(local[1]), mat['vies'])
    local = (next_alpha(local[0]), local[1])

    wk.write(local[0] + str(local[1]-1), 'Prevalence')
    wk.write(local[0] + str(local[1]), mat['prevalencia'])
    local = (next_alpha(local[0]), local[1])
    return local


def get_descritores_max(r_max, data):
    def map_categ(data, descritor, r_max):
        def map_des(linha):
            if r_max:
                return linha['catalogo_var_max'][descritor]
            else:
                return linha['catalogo_var'][descritor]

        return list(map(map_des, data['varios_kappa'] ))
    
    ls_descritores = list(data['varios_kappa'][0]['catalogo_var'].keys())
    ls = {}

    for descritor in ls_descritores:
        r_calcula = descritor != "matriz_concordancia"
        if r_calcula:
            ls[descritor] = map_categ(data, descritor, r_max)
    
    return ls


def create_cate(wk, local_inicio, data, numero):
    mat = data['medido']['list_kappa_cat'][numero]['matriz_concordancia']
    ls_name = creat_lis_name(data['medido']['list_kappa_cat'][numero]['categoria'])

    
    la            = set_text(wk, (local_inicio[0], local_inicio[1]+4), "Measured Agreement from  behavioral categorie")
    last_letter_4 = creta_matriz_confusao(wk, (local_inicio[0], local_inicio[1]+4), mat, ls_name)
    last_letter_5 = set_descricao(wk, (local_inicio[0], last_letter_4[1]+2) , data['medido']['list_kappa_cat'][numero])


    ## create maximum matrix
    la            = set_text(wk, 
                             (next_alpha(next_alpha(next_alpha(last_letter_4[0]))), local_inicio[1]+4),
                             "Maximum Agreement from behavioral categorie")
    last_letter_6 = creta_matriz_confusao(wk, 
                                          (next_alpha(next_alpha(next_alpha(last_letter_4[0]))), local_inicio[1]+4),
                                          data['medido']['list_kappa_cat_max'][numero]['matriz_concordancia'], ls_name)


    last_letter_7 = set_descricao(wk, 
                                (next_alpha(next_alpha(next_alpha(last_letter_4[0]))),last_letter_6[1]+2), 
                                  data['medido']['list_kappa_cat_max'][numero])
    
    return last_letter_7


def set_text(wk, local, text):
    wk.write(local[0] + str(local[1]-2), text)
    return (local[0], local[1])


def set_wt(wk, local, linha):
    def calcula_mean(linha):
        a = sum(linha)
        tamanho = len(linha)
        return a/tamanho

    def calcula_std(linha):
        mean = calcula_mean(linha)
        def map_linha(el):
            return (el - mean) ** 2
        
        s = sum(map(map_linha, linha))/(len(linha)-1)
        return s
        


    wk.write(local[0] + str(local[1]), calcula_mean(linha))
    wk.write(next_alpha(local[0]) + str(local[1]), calcula_std(linha))
    return (next_alpha(local[0]), local[1])

def set_var(wk, local, nome):
    wk.write(local[0] + str(local[1]), nome)
    return local

def creat_cabecalho(wk, local):
    saida = set_var(wk, local, 'Observed agreement mean')
    saida = set_var(wk, (next_alpha(saida[0]), saida[1]), 'Observed agreement std')
    saida = set_var(wk, (next_alpha(saida[0]), saida[1]), 'Chance agreement mean')
    saida = set_var(wk, (next_alpha(saida[0]), saida[1]), 'Chance agreement std')
    saida = set_var(wk, (next_alpha(saida[0]), saida[1]), 'Bias mean')
    saida = set_var(wk, (next_alpha(saida[0]), saida[1]), 'Bias std')
    saida = set_var(wk, (next_alpha(saida[0]), saida[1]), 'Prevalence mean')
    saida = set_var(wk, (next_alpha(saida[0]), saida[1]), 'Prevalence std')
    saida = set_var(wk, (next_alpha(saida[0]), saida[1]), 'Cohen Kappa mean')
    saida = set_var(wk, (next_alpha(saida[0]), saida[1]), 'Cohen Kappa std')
    



def create_excel_file(data, path):
    workbook = xlsxwriter.Workbook(path)
    worksheet = workbook.add_worksheet()

    mat  = data['medido']['catalogo_var']['matriz_concordancia']
    ls_cat = data['ls_cat_txt']

    local = ("C", 10)

    la            = set_text(worksheet, local, "Agreement from measured data")
    last_letter   = creta_matriz_confusao(worksheet, local, mat, ls_cat)
    last_letter_1 = set_descricao(worksheet, (local[0], last_letter[1]+2) , data['medido']['catalogo_var'])


    la            = set_text(worksheet, (next_alpha(next_alpha(last_letter[0])), local[1]), "Maximum Agreement from measured data")
    last_letter_2 = creta_matriz_confusao(worksheet, (next_alpha(next_alpha(last_letter[0])), local[1]),
                                        data['medido']['catalogo_var_max']['matriz_concordancia'], ls_cat)

    last_letter_3 = set_descricao(worksheet, (next_alpha(next_alpha(last_letter[0])), last_letter_2[1]+2) , data['medido']['catalogo_var_max'])


    ## categories resume
    last_letter_7 = (local[0], last_letter_3[1])
    for i in range(len(data['medido']['list_kappa_cat'])):
        last_letter_7 = create_cate(worksheet, (local[0], last_letter_7[1]), data, i)


    # bootstrap resume
    last_letter_8 = (local[0], last_letter_7[1] + 4)

    dt = get_descritores_max(False, data)
    dt_max = get_descritores_max(True, data)

    s     = creat_cabecalho(worksheet, (next_alpha(last_letter_8[0]), last_letter_8[1] - 1 ))
    saida = set_var(worksheet, last_letter_8, "Parameter estimated:  ")
    saida = set_wt(worksheet, (next_alpha(saida[0]), saida[1] ), dt['observada'])
    saida = set_wt(worksheet, (next_alpha(saida[0]), saida[1] ), dt['acaso'])
    saida = set_wt(worksheet, (next_alpha(saida[0]), saida[1] ), dt['vies'])
    saida = set_wt(worksheet, (next_alpha(saida[0]), saida[1] ), dt['prevalencia'])
    saida = set_wt(worksheet, (next_alpha(saida[0]), saida[1] ), dt['kappa'])


    saida = set_var(worksheet, (last_letter_8[0], last_letter_8[1]+1), "Maximum parameter estimated: ")
    saida = set_wt(worksheet, (next_alpha(saida[0]), saida[1] ), dt_max['observada'])
    saida = set_wt(worksheet, (next_alpha(saida[0]), saida[1] ), dt_max['acaso'])
    saida = set_wt(worksheet, (next_alpha(saida[0]), saida[1] ), dt_max['vies'])
    saida = set_wt(worksheet, (next_alpha(saida[0]), saida[1] ), dt_max['prevalencia'])
    saida = set_wt(worksheet, (next_alpha(saida[0]), saida[1] ), dt_max['kappa'])

    workbook.close()