# import json
from ast import Str
# from cv2 import sqrt
import math
import xlsxwriter

import extrai_descritor as ed
from copy import deepcopy

def calcula_mean(linha):
    a = sum(linha)
    tamanho = len(linha)
    return a/tamanho

def calcula_std(linha):
    mean = calcula_mean(linha)
    def map_linha(el):
        return (el - mean) ** 2
    
    s = sum(map(map_linha, linha))/(len(linha)-1)
    s = math.sqrt(s)
    return s
    
# import pandas as pd

def next_alpha(s):
    return chr((ord(s.upper())+1 - 65) % 26 + 65)

def creat_lis_name(name):
    return [name, "not " + name]

def creta_matriz_confusao(wk, local, mat, ls_cat):
    def creat_name(local):
        ls_c = ls_cat.copy()
        ls_c.append("Total")
        # letter = local[0]
        # wk.write(letter + str(local[1]), "Transcription file 2")

        # local = (next_alpha(local[0]), local[1]+1)
        saida = set_text_pos(wk, (next_alpha(local[0]), local[1]-1 ), "Transcription file 2")

        # wk.write(letter + str(local[1]-1), "Transcription file 1")
        saida_0 = set_text_pos(wk, (local[0], saida[1] + 1), "Transcription file 1")
        # saida = (local[0], local[1])
        saida = saida_0
        for i, cat in enumerate(ls_c):
            if cat == "Undefined (frames that are not marked)":
                cat = "*Unmarked"
            saida = set_text_pos(wk, (local[0], saida[1] + 1), cat)

        saida = saida_0
        for i, cat in enumerate(ls_c):
            if cat == "Undefined (frames that are not marked)":
                cat = "*Unmarked"
            saida = set_text_pos(wk, (next_alpha(saida[0]), saida[1]), cat)

        
        return saida

    
    def matriz_confusao(local, mat_copiada):
        last_c = 0
        saida = (local[0], local[1])

        mat_c = mat_copiada.copy()

        l_to = []
        for i,_ in enumerate(mat_c):
            soma = 0
            for j,linha in enumerate(mat_c):
                soma = soma + linha[i]
            l_to.append(soma)
        
        mat_c.append(l_to)


        print(mat_c)
        for i,linha in enumerate(mat_c):
            soma = 0
            for j, celula in enumerate(linha):
                r_ultima_linha = i == len(mat_c) -1
                if r_ultima_linha:
                    soma = soma + celula
                else:
                    soma = soma + celula
                

            
            mat_c[i].append(soma)
    
        print(mat_c[i])
        for linha in mat_c:
            saida= (next_alpha(saida[0]), local[1])
            for i,celula in enumerate(linha):
                saida = set_text_pos(wk, (saida[0], saida[1] + 1), celula)
            
            


        # for linha in mat:
        #     for i,celula in enumerate(linha):
        #         wk.write(letter + str(local[1]+i), celula)
        #     letter = next_alpha(letter)
        
        # last_c = local[1] + len(mat[0])
        return saida
     
    sa = creat_name(local)
    mat_copiada = mat[:].copy()
    letter = matriz_confusao(local, mat_copiada)
    return (local[0], letter[1]+3)

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


def get_d_cohen(data_e, data_c):
    # https://sci-hub.se/https://doi.org/10.1093/jpepsy/jsp004
    N = len(data_c)


    me = calcula_mean(data_e)
    mc = calcula_mean(data_c)
    SDe = calcula_std(data_e)
    SDc = calcula_std(data_c)

    
    mean_abs = abs(me - mc)
    sd_pooled = math.sqrt(((SDe**2) + (SDc**2))/2)
    ajust = (N - 3)/ (N - 2.25) * math.sqrt((N-2)/N)

    d_cohen = mean_abs/sd_pooled *ajust
    return d_cohen


def set_text(wk, local, text):
    wk.write(local[0] + str(local[1]-2), text)
    return (local[0], local[1])

def set_text_pos(wk, local, text):
    wk.write(local[0] + str(local[1]), text)
    return (local[0], local[1])

def set_image_pos(wk, local, path):
    wk.insert_image(local[0] + str(local[1]), path)
    return (local[0], local[1])

def set_wt(wk, local, linha):
    # def calcula_mean(linha):
    #     a = sum(linha)
    #     tamanho = len(linha)
    #     return a/tamanho

    # def calcula_std(linha):
    #     mean = calcula_mean(linha)
    #     def map_linha(el):
    #         return (el - mean) ** 2
        
    #     s = sum(map(map_linha, linha))/(len(linha)-1)
    #     return s
        


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


def escreve_cabecalho(wk, local, data):
    def escreve_cima_baixo(wk, local, texto_cima, texto_baixo):
        saida = set_text_pos(wk, (local[0], local[1]), texto_cima)
        saida = set_text_pos(wk, (saida[0], saida[1]+1), texto_baixo)
        return saida
    
    saida = local
    for i, eto in enumerate(data['ls_eto']):
        saida = escreve_cima_baixo(wk, (next_alpha(saida[0]) , local[1]), "Ethography  " + str(i+1), eto)

    saida = escreve_cima_baixo(wk, (next_alpha(saida[0]) , local[1]), "Boostrap sample size", data['qnt_amostras'])
    saida = escreve_cima_baixo(wk, (next_alpha(saida[0]) , local[1]), "Seed usada para gerar a amostra", data['seed_bootstap'])
    saida = escreve_cima_baixo(wk, (next_alpha(saida[0]) , local[1]), "Divisor da matriz de concordancia usada na medição", data['qnt_simpl'])
    saida = escreve_cima_baixo(wk, (next_alpha(saida[0]) , local[1]), "Divisor da matriz de concordancia usada durante o bootstrap", data['qnt_simpl_boots'])
    saida = escreve_cima_baixo(wk, (next_alpha(saida[0]) , local[1]), "Quantidade máxima de permutações", data['qnt_maxima_permutaca'])
    saida = escreve_cima_baixo(wk, (next_alpha(saida[0]) , local[1]), "Quantide de threads", data['qnt_threads'])

    return saida    



def resume_d_cohen(wk, local, dt, dt_max):
    def escreve_cima_baixo(wk, local, texto_cima, texto_baixo):
        saida = set_text_pos(wk, (local[0], local[1]), texto_cima)
        saida = set_text_pos(wk, (saida[0], saida[1]+1), texto_baixo)
        return saida

    saida = local
    saida = escreve_cima_baixo(wk, (next_alpha(saida[0]) , local[1]), "d de cohen", get_d_cohen(dt['kappa'], dt_max['kappa']))
    return saida


def escreve_info_doc(wk, local, data, tabela= False):
    saida = set_text_pos(wk, (local[0], local[1]), "texto_cima")
    saida = set_text_pos(wk, ( next_alpha(saida[0]) , saida[1]), "RELIABILITY TESTS REPORT: ")
    saida = set_text_pos(wk, ( next_alpha(saida[0]) , saida[1]), "COHEN'S K FOR 2 OBSERVERS OR 2 TRANSCRIPTIONS OF THE SAME SESSION")
    if not tabela:
        saida = set_text_pos(wk, ( local[0], saida[1]+1), " Video file:")
        saida = set_text_pos(wk, ( next_alpha(saida[0]), saida[1]) , "nome_do_arquivo_de_video")

        #nova linha
        saida = set_text_pos(wk, ( local[0], saida[1]+1), "Frames per second (fps)")
        saida = set_text_pos(wk, ( next_alpha(saida[0]), saida[1]), "First Frame of the transcription")
        saida = set_text_pos(wk, ( next_alpha(saida[0]), saida[1]), " Last Frame of the transcription")

        # nova linha
        saida = set_text_pos(wk, ( local[0], saida[1]+1), data['fps'])
        saida = set_text_pos(wk, ( next_alpha(saida[0]), saida[1]), data['frame_start'])
        saida = set_text_pos(wk, ( next_alpha(saida[0]), saida[1]), data['frame_end'])
        
        #
        saida = set_text_pos(wk, ( local[0], saida[1]+1), "Transcription (or ethography) file 1")
        r_nao_tem = len(data['ls_eto'])  == 0
        if r_nao_tem:
            saida = set_text_pos(wk, ( next_alpha(saida[0]), saida[1]), "")
        else:
            saida = set_text_pos(wk, ( next_alpha(saida[0]), saida[1]), data['ls_eto'][0])

        #
        saida = set_text_pos(wk, ( local[0], saida[1]+1), "Transcription (or ethography) file 2")
        r_nao_tem = len(data['ls_eto'])  == 0

        if r_nao_tem:
            saida = set_text_pos(wk, ( next_alpha(saida[0]), saida[1]), "")
        else:
            saida = set_text_pos(wk, ( next_alpha(saida[0]), saida[1]), data['ls_eto'][1])

        #

        
        saida = set_text_pos(wk, ( local[0], saida[1]+1), "Observer 1 or 1st transcription")
        saida = set_text_pos(wk, ( next_alpha(saida[0]), saida[1]), data['ls_experimentadores'][0])

        #
        saida = set_text_pos(wk, ( local[0], saida[1]+1), "Observer 2 or 2nd transcription")
        saida = set_text_pos(wk, ( next_alpha(saida[0]), saida[1]), data['ls_experimentadores'][1])

        saida = set_text_pos(wk, ( local[0], saida[1]+1), "In this version, decimals are separated by COMMA ")

        saida = set_text_pos(wk, ( local[0], saida[1]+2), "Categories in the behavioral catalog")

       
        def map_ca(x):
            r_cate_unmarked = "Undefined (frames that are not marked)" == x
            if r_cate_unmarked:
                return "*Unmarked"
            else:
                return x


    ls_cat = list(map(map_ca, data["ls_cat_txt"] ))
    
    d_cat = {}
    saida= (local[0], saida[1])
    for i,categ in enumerate(ls_cat):
        saida = set_text_pos(wk, ( saida[0], saida[1]+1), categ)

        d_cat[i] = categ


    

    saida = set_text_pos(wk, (local[0], saida[1]+1), "Transcription 1")
    saida = set_text_pos(wk, ( next_alpha(saida[0]) , saida[1]), "Transcription 1")
    saida = set_text_pos(wk, ( next_alpha(saida[0]) , saida[1]), "Frame")
    saida = set_text_pos(wk, ( next_alpha(saida[0]) , saida[1]), "seconds")

    saida= (local[0], saida[1])
    for i, eto_1, eto_2 in zip(range(1,len(data['medido']['et1'])+1), data['medido']['et1'], data['medido']['et2']):
        saida = set_text_pos(wk, (local[0], saida[1] + 1), d_cat[eto_1])
        saida = set_text_pos(wk, ( next_alpha(saida[0]) , saida[1]), d_cat[eto_2])
        saida = set_text_pos(wk, ( next_alpha(saida[0]) , saida[1]), i)


    # la1           = escreve_cabecalho(wk, saida, data)
    return saida

    # saida = set_text_pos(wk, (saida[0], saida[1]+1), texto_baixo)

def resumo_data_medido(wk, local, data):

    saida = set_text_pos(wk, ( local[0], local[1]+1), "Categories")
    saida = set_text_pos(wk, ( next_alpha(saida[0]), saida[1]), "Agreements (totals)")
    saida = set_text_pos(wk, ( next_alpha(saida[0]), saida[1]), "Agreements (totals) (max)")
    saida = set_text_pos(wk, ( next_alpha(saida[0]), saida[1]), "Agreements by chance")
    saida = set_text_pos(wk, ( next_alpha(saida[0]), saida[1]), "Agreements by chance (max)")

    saida = set_text_pos(wk, ( next_alpha(saida[0]), saida[1]), "K (per categ.)")
    saida = set_text_pos(wk, ( next_alpha(saida[0]), saida[1]), "K max (per categ.)")

    saida = set_text_pos(wk, ( next_alpha(saida[0]), saida[1]), "Prevalence")
    saida = set_text_pos(wk, ( next_alpha(saida[0]), saida[1]), "Prevalence (max)")

    saida = set_text_pos(wk, ( next_alpha(saida[0]), saida[1]), "Bias")
    saida = set_text_pos(wk, ( next_alpha(saida[0]), saida[1]), "Bias (max)")

    
    for numero, categoria in enumerate(data['medido']['list_kappa_cat']):
        d_me = data['medido']['list_kappa_cat'][numero]
        d_me_max = data['medido']['list_kappa_cat_max'][numero]

        cat = categoria['categoria']
        if cat == "Undefined (frames that are not marked)":
            cat = "*Unmarked"

        saida = set_text_pos(wk, ( local[0], saida[1]+1), cat)
        saida = set_text_pos(wk, ( next_alpha(saida[0]), saida[1]), d_me['observada'])
        saida = set_text_pos(wk, ( next_alpha(saida[0]), saida[1]), d_me_max['observada'])

        saida = set_text_pos(wk, ( next_alpha(saida[0]), saida[1]), d_me['acaso'])
        saida = set_text_pos(wk, ( next_alpha(saida[0]), saida[1]), d_me_max['acaso'])

        saida = set_text_pos(wk, ( next_alpha(saida[0]), saida[1]), d_me['kappa'])
        saida = set_text_pos(wk, ( next_alpha(saida[0]), saida[1]), d_me_max['kappa'])

        saida = set_text_pos(wk, ( next_alpha(saida[0]), saida[1]), d_me['prevalencia'])
        saida = set_text_pos(wk, ( next_alpha(saida[0]), saida[1]), d_me_max['prevalencia'])

        saida = set_text_pos(wk, ( next_alpha(saida[0]), saida[1]), d_me['vies'])
        saida = set_text_pos(wk, ( next_alpha(saida[0]), saida[1]), d_me_max['vies'])


    d_ca = data['medido']['catalogo_var']
    d_ca_max = data['medido']['catalogo_var_max']

    saida = set_text_pos(wk, ( local[0], saida[1]+1), "Overall catalog")
    saida = set_text_pos(wk, ( next_alpha(saida[0]), saida[1]), d_ca['observada'])
    saida = set_text_pos(wk, ( next_alpha(saida[0]), saida[1]), d_ca_max['observada'])

    saida = set_text_pos(wk, ( next_alpha(saida[0]), saida[1]), d_ca['acaso'])
    saida = set_text_pos(wk, ( next_alpha(saida[0]), saida[1]), d_ca_max['acaso'])

    saida = set_text_pos(wk, ( next_alpha(saida[0]), saida[1]), d_ca['kappa'])
    saida = set_text_pos(wk, ( next_alpha(saida[0]), saida[1]), d_ca_max['kappa'])

    saida = set_text_pos(wk, ( next_alpha(saida[0]), saida[1]), d_ca['prevalencia'])
    saida = set_text_pos(wk, ( next_alpha(saida[0]), saida[1]), d_ca_max['prevalencia'])

    saida = set_text_pos(wk, ( next_alpha(saida[0]), saida[1]), d_ca['vies'])
    saida = set_text_pos(wk, ( next_alpha(saida[0]), saida[1]), d_ca_max['vies'])


    saida = set_text_pos(wk, ( local[0], saida[1]+2), "Landis JR, Koch GG. The measurement of observer agreement for categorical data. Biometrics 1977;33:159–174.")

    saida = set_text_pos(wk, ( local[0], saida[1]+1), "Poor (<0.00)")
    saida = set_text_pos(wk, ( next_alpha(saida[0]), saida[1]), "Sligh (0.01 -/ 0.20)")
    saida = set_text_pos(wk, ( next_alpha(saida[0]), saida[1]), "Fair (0.21 -/ 0.40)")
    saida = set_text_pos(wk, ( next_alpha(saida[0]), saida[1]), "Moderate (0.41 -/ 0.6)")
    saida = set_text_pos(wk, ( next_alpha(saida[0]), saida[1]), "Substantial (0.61 -/ 0.8)")
    saida = set_text_pos(wk, ( next_alpha(saida[0]), saida[1]), "Almost perfect (o.81 -/ 1)")


    return (local[0], saida[1])

        # print("as")

        # last_letter_5 = set_descricao(wk, (local_inicio[0], last_letter_4[1]+2) , data['medido']['list_kappa_cat'][numero])
        # last_letter_7 = set_descricao(wk, 
        #                         (next_alpha(next_alpha(next_alpha(last_letter_4[0]))),last_letter_6[1]+2), 
        #                           data['medido']['list_kappa_cat_max'][numero])



def resumo_bootstrap(wk, local, data):
    dic = ed.get_descritores(data)
    print(dic)

    saida = set_text_pos(wk, ( local[0], local[1]+1), "Categories")
    saida = set_text_pos(wk, ( next_alpha(saida[0]), saida[1]), "Bootstrap 95% CI K (per categ.)")
    saida = set_text_pos(wk, ( next_alpha(saida[0]), saida[1]), "Bootstrap 95% CI K max (per categ.)")
    saida = set_text_pos(wk, ( next_alpha(saida[0]), saida[1]), "Cohen's d between K and K max (per categ.)")
    saida = set_text_pos(wk, ( next_alpha(saida[0]), saida[1]), "K mean (per categ.)")
    saida = set_text_pos(wk, ( next_alpha(saida[0]), saida[1]), "Kmax mean (per categ.)")

    saida = set_text_pos(wk, ( next_alpha(saida[0]), saida[1]), "Bootstrap 95% CI Bias (per categ.)")
    saida = set_text_pos(wk, ( next_alpha(saida[0]), saida[1]), "Bootstrap 95% CI Bias max (per categ.)")
    saida = set_text_pos(wk, ( next_alpha(saida[0]), saida[1]), "Bias mean (per categ.)")

    saida = set_text_pos(wk, ( next_alpha(saida[0]), saida[1]), "Bootstrap 95% CI Prevalence (per categ.)")
    saida = set_text_pos(wk, ( next_alpha(saida[0]), saida[1]), "Bootstrap 95% CI Prevalence max (per categ.)")
    saida = set_text_pos(wk, ( next_alpha(saida[0]), saida[1]), "Prevalence mean (per categ.)")
    
    for cat in dic['ls_cat']:
        ci_k     = dic[cat]['kappa']["ci_m"] #np.percentile(ames,[100*(1-confidence)/2,100*(1-(1-confidence)/2)])
        ci_k_max = dic[cat]['kappa']["ci_max"]
        d_k_max = dic[cat]['kappa']["d"]
        k_mean = calcula_mean(dic[cat]['kappa']["d_ls_m"])
        k_mean_max = calcula_mean(dic[cat]['kappa']["d_ls_max"])
        
        ci_b     = dic[cat]['vies']["ci_m"] #np.percentile(ames,[100*(1-confidence)/2,100*(1-(1-confidence)/2)])
        ci_b_max = dic[cat]['vies']["ci_max"]
        b_mean   = calcula_mean(dic[cat]['vies']["d_ls_m"])

        ci_p     = dic[cat]['prevalencia']["ci_m"] #np.percentile(ames,[100*(1-confidence)/2,100*(1-(1-confidence)/2)])
        ci_p_max = dic[cat]['prevalencia']["ci_max"]
        p_mean   = calcula_mean(dic[cat]['prevalencia']["d_ls_m"])

        if cat == 'Catalog':
            cat = "Overall catalog"
        
        if cat == "Undefined (frames that are not marked)":
            cat = "*Unmarked"

        saida = set_text_pos(wk, ( local[0], saida[1]+1), cat)

        saida = set_text_pos(wk, ( next_alpha(saida[0]), saida[1]), f'{ci_k[0]} -/ {ci_k[1]}')
        saida = set_text_pos(wk, ( next_alpha(saida[0]), saida[1]), f'{ci_k_max[0]} -/ {ci_k_max[1]}')
        saida = set_text_pos(wk, ( next_alpha(saida[0]), saida[1]), d_k_max)
        saida = set_text_pos(wk, ( next_alpha(saida[0]), saida[1]), k_mean)
        saida = set_text_pos(wk, ( next_alpha(saida[0]), saida[1]), k_mean_max)
        

        saida = set_text_pos(wk, ( next_alpha(saida[0]), saida[1]), f'{ci_b[0]} -/ {ci_b[1]}')
        saida = set_text_pos(wk, ( next_alpha(saida[0]), saida[1]), f'{ci_b_max[0]} -/ {ci_b_max[1]}')
        saida = set_text_pos(wk, ( next_alpha(saida[0]), saida[1]), b_mean)

        saida = set_text_pos(wk, ( next_alpha(saida[0]), saida[1]), f'{ci_p[0]} -/ {ci_p[1]}')
        saida = set_text_pos(wk, ( next_alpha(saida[0]), saida[1]), f'{ci_p_max[0]} -/ {ci_p_max[1]}')
        saida = set_text_pos(wk, ( next_alpha(saida[0]), saida[1]), p_mean)
    
    saida = set_text_pos(wk, ( local[0], saida[1]+2), """Cohen's d between the K and Kmax allows an estimate of the distance between the means of the distributions in SD (e.g. d=2 indicates that there is a distance of 2 SD between K and Kmax distributions). The higher the d value, the higher the possibility of improvement in the HO’s performance (e.g., through more training). """)
    saida = set_text_pos(wk, ( local[0], saida[1]+1), """The 95% CI of K and Kmax can be used to test for significant distances between them: if they don't overlap, it is possible to affirm that they are significantly different, assuming a 5% error of type I in this conclusion """)
    
    saida = set_text_pos(wk, ( local[0], saida[1]+2), """The Prevalence index (P) indicates the homogeneity of the frequencies of the categories on which the transcriptions agree """)
    saida = set_text_pos(wk, ( local[0], saida[1]+1), """TThe higher the P-value, the more the measured K can be undervalued in the performance of the observer, less more reliable the measure K are. """)
    
    saida = set_text_pos(wk, ( local[0], saida[1]+2), """Bias (B) indicates the homogeneity of frequencies at which transcriptions disagree """)
    saida = set_text_pos(wk, ( local[0], saida[1]+1), """In contrast to P, the higher the B, the more the observed K value overestimates the real agreement between the transcriptions, less more reliable the measure K are. """)

    saida = set_text_pos(wk, ( local[0], saida[1]+2), """More info go to https://github.com/EthoWatcher/Reliability""")


    return saida


def create_excel_file(data, path):
    workbook = xlsxwriter.Workbook(path)
    worksheet = workbook.add_worksheet()

    mat_a  = data['medido']['catalogo_var']['matriz_concordancia']
    ls_cat = data['ls_cat_txt']

    local_1 = ("A",1)

    s = escreve_info_doc(worksheet, local_1, data, False)

    local = ("H", 10)

    
    # la1           = escreve_cabecalho(worksheet, ("C", 3), data)
    la            = set_text(worksheet, local, "Agreement matrix of Cohen's Kappa: Frequency")
    saida   = creta_matriz_confusao(worksheet, local, deepcopy(mat_a), ls_cat)

    def convert_matrix_percent(mat_2):
        mat_c = mat_2.copy()
        soma = 0
        for linha in mat_c:
            for celula in linha:
                soma = soma + celula
        
        for i,linha in enumerate(mat_c):
            for j,celula in enumerate(linha):
                mat_c[i][j] = celula /soma
        
        return mat_c

    saida =(saida[0], saida[1] +2 )
    ma_percentage = convert_matrix_percent(deepcopy(mat_a))
    la            = set_text(worksheet, saida, "Agreement matriz of Cohen's Kappa: percent")
    last_letter_3   = creta_matriz_confusao(worksheet, saida, ma_percentage, ls_cat)


    # last_letter_1 = set_descricao(worksheet, (local[0], last_letter[1]+2) , data['medido']['catalogo_var'])


    # # la            = set_text(worksheet, (next_alpha(next_alpha(last_letter[0])), local[1]), "Maximum Agreement from measured data")
    # # last_letter_2 = creta_matriz_confusao(worksheet, (next_alpha(next_alpha(last_letter[0])), local[1]),
    # #                                     data['medido']['catalogo_var_max']['matriz_concordancia'], ls_cat)

    # # last_letter_3 = set_descricao(worksheet, (next_alpha(next_alpha(last_letter[0])), last_letter_2[1]+2) , data['medido']['catalogo_var_max'])
    # last_letter_3 = last_letter_1

    ## categories resume
    last_letter_7 = (local[0], last_letter_3[1]-1)

    last_letter_8 = resumo_data_medido(worksheet, last_letter_7, data)
    last_letter_9 = resumo_bootstrap(worksheet, (last_letter_8[0], last_letter_8[1]+2), data)

    # path_image = path[:path.rindex("\\")+1] + "custom_hipotese_1.png"
    # path_image = "./"
    # if "\\" in path:
        # path_image = path[:path.rindex("\\")+1]

    # path_image = path_image + "custom_hipotese_1.png"
    path_image = path + '.txt.png'
    last_letter_10 = set_image_pos(worksheet, (local[0], last_letter_9[1]), path_image )

    last_letter_10 = set_text(worksheet, (local[0], last_letter_10[1]+1), 
    """A summary of the K, P, B and the K-Kmax distance for the overall 
    catalog and single behavioral categories for the replicas 
    obtained by the BS algorithms. The average K values (black vertical bars) 
    and their respective confidence intervals (black horizontal bars) are 
    represented with the respective Kmax averages (red vertical lines) and their 
    confidence intervals (red horizontal lines). d = Cohen's d between Kmax and 
    K in Standard deviations. (*) indicates that K and K max are significantly 
    different (p<0.05; according to [1][2]). The grey rectangles in this graph 
    indicate the K level according to the benchmark of [3] for K so that P indicates 
    K<0 (poor agreement), S for K of 0.01-0.2 (slight agreement); F for K of 0.21-
    0.04 (fair agreement); M for K of 0.41-0.6 (moderate agreement); S for K of 
    0.61-0.80 (substantial agreement); A for K of 0.81-1 (almost perfect 
    agreement).In the B graph, the average bias (or B) of the BS replicas values 
    (black vertical bars) and their respective confidence intervals (black 
    horizontal bars) are represented. In the P graph, the average prevalence (or P) 
    of the BS replicas values (black vertical bars) and their respective confidence 
    intervals (black horizontal bars) are represented.

    References:
    - [1] Austin PC, Hux JE. A brief note on overlapping confidence intervals. J 
    Vasc Surg. 2002 Jul;36(1):194-5. doi: 10.1067/mva.2002.125015. PMID: 
    12096281
    - [2] Cumming, G. (2009). Inference by eye: Reading the overlap of 
    independent confidence intervals. Statistics in medicine, 28(2), 205-220
    - [3]  Landis, J. R., & Koch, G. G. (1977). The measurement of observer 
    agreement for categorical data. biometrics, 159-174.
    """)
    # for i in range(len(data['medido']['list_kappa_cat'])):
    #     last_letter_7 = create_cate(worksheet, (local[0], last_letter_7[1]), data, i)


    # # bootstrap resume
    # last_letter_8 = (local[0], last_letter_7[1] + 4)

    # dt = get_descritores_max(False, data)
    # dt_max = get_descritores_max(True, data)

    # s     = creat_cabecalho(worksheet, (next_alpha(last_letter_8[0]), last_letter_8[1] - 1 ))
    # saida = set_var(worksheet, last_letter_8, "Parameter estimated:  ")
    # saida = set_wt(worksheet, (next_alpha(saida[0]), saida[1] ), dt['observada'])
    # saida = set_wt(worksheet, (next_alpha(saida[0]), saida[1] ), dt['acaso'])
    # saida = set_wt(worksheet, (next_alpha(saida[0]), saida[1] ), dt['vies'])
    # saida = set_wt(worksheet, (next_alpha(saida[0]), saida[1] ), dt['prevalencia'])
    # saida = set_wt(worksheet, (next_alpha(saida[0]), saida[1] ), dt['kappa'])


    # saida = set_var(worksheet, (last_letter_8[0], last_letter_8[1]+1), "Maximum parameter estimated: ")
    # saida = set_wt(worksheet, (next_alpha(saida[0]), saida[1] ), dt_max['observada'])
    # saida = set_wt(worksheet, (next_alpha(saida[0]), saida[1] ), dt_max['acaso'])
    # saida = set_wt(worksheet, (next_alpha(saida[0]), saida[1] ), dt_max['vies'])
    # saida = set_wt(worksheet, (next_alpha(saida[0]), saida[1] ), dt_max['prevalencia'])
    # saida = set_wt(worksheet, (next_alpha(saida[0]), saida[1] ), dt_max['kappa'])


    # saida = resume_d_cohen(worksheet, (local[0], saida[1]+3), dt, dt_max)

    
    workbook.close()
    print(f"Writing csv {path}")