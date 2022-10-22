import json

import matplotlib.pyplot as plt
import matplotlib.gridspec as gridspec
import matplotlib.cm as cm
import numpy as np

import extrai_descritor as ed
import escreve_xlsx as es

def get_dados(path):
    # with open(path + ".txt", 'r') as file:
    with open(path, 'r') as file:
        text = file.read()
    
    text = text.replace("\'", "\"")
    text = text.replace("nan", "\"nan\"")
    data = json.loads(text)
    return data
# data


def test_ci_separado(ci_m, ci_max):
    # ca = comeca antes
    # cd = comeca depois
    # ta = termina antes
    r_menor_ca_ta = ci_m[1]   < ci_max[0]
    r_menor_cd_td = ci_max[1] < ci_m[0]
#     r_menor_ca_ta = ci_m[0] <= ci_max[0] and ci_max[1] >= ci_m[1]
#     r_menor_cd_ta = ci_m[0] >= ci_max[0] and ci_max[1] >= ci_m[1]
    
#     r_menor_ca_td = ci_m[0] <= ci_max[0] and ci_max[1] <= ci_m[1]
#     r_menor_cd_td = ci_m[0] >= ci_max[0] and ci_max[1] <= ci_m[1]
    return r_menor_ca_ta or r_menor_cd_td


def cret_line(valor):
    def creat_lvl(valor):
        return lambda x: valor

    return [creat_lvl(valor)(x) for x in range(2)]

def g_measure(i):
    return [i, i + 0.5]

def g_kappa_ax(dic, i, ax_s,  cat):
#     fig, ax = plt.subplots(1)
#     ax_s = ax
    
    con_m   = dic[cat]['kappa']["ci_m"] #np.percentile(ames,[100*(1-confidence)/2,100*(1-(1-confidence)/2)])
    con_max = dic[cat]['kappa']["ci_max"]
    
    d = dic[cat]['kappa']["d"]
    k = np.mean(con_m)
    k_max = np.mean(con_max)
    
#     k     = dic[cat]['kappa']["d_measured_m"]
#     k_max = dic[cat]['kappa']["d_measured_max"]
    
#     y_pos.append(i)
    
    generate_ci_m    =  [0.25, 0.25]# cret_line(i)
    generate_ci_max  = [0.75, 0.75]
    
    generate_measure = [0, 1] #g_measure(i) #[0.2, 0.4] #cre_generate(i)
    
#     generate_ci =  [0, 0]# cret_line(i)
#     generate_measure = [0, 0.4] #g_measure(i) #[0.2, 0.4] #cre_generate(i)
    
#     print(g_measure)
    tamanho = 4 
    if(i==1):
        ax_s.plot(con_m, generate_ci_m, label = "CI Kappa (K)", color= "black", linewidth=tamanho, alpha=0.9)
        ax_s.plot(con_max, generate_ci_max, label = "CI max Kappa (Kmax)", color ="red", linewidth=tamanho, alpha=0.9)
        
        ax_s.plot([k, k], generate_measure, label = "Sample max Kappa", color= "black", linewidth=4.0)
        ax_s.plot([k_max, k_max], generate_measure,label = "Sample max Kappa", color= "red", linewidth=4.0)
        
    else:
        ax_s.plot(con_m, generate_ci_m, color= "black", linewidth=tamanho, alpha=0.9)
        ax_s.plot(con_max, generate_ci_max, color ="red", linewidth=tamanho, alpha=0.9)
        
        ax_s.plot([k, k], generate_measure, color= "black", linewidth=4.0)
        ax_s.plot([k_max, k_max], generate_measure, color= "red", linewidth=4.0)
    
    
    r_separado = test_ci_separado(con_m, con_max)
    s = ""
    if r_separado:
#         s="(*) p<0.05 m={},\nmax= {}".format(con_m, con_max)
        s="(*)"
    
    r_novo_t = "Undefined (frames that are not marked)" == cat
    if r_novo_t:
        cat = "Frames unmarked"
    
    r_novo_t = "Catalog" == cat
    if r_novo_t:
        cat = "Overall catalog"
    
    string = "{}\nd= {:.2f}, K= {:.2f}, Kmax = {:.2f} {} ".format(cat,  d, k, k_max, s)
        
    ax_s.set_title(string, fontsize=14, loc='left')
    ax_s.set_yticks([])
    ax_s.set_ylim([0, 1])
    ax_s.set_xlim([-0.1, 1])
    ax_s.axvspan(0, -0.1, alpha=0.6, color='#46757d', label = "Poor (<0.00)")
    text = ax_s.text(-0.05, 0.5, "P")
    
    ax_s.axvspan(0, 0.2, alpha=0.4, color='#728255', label = "Sligh (0.00 - 0.20)")
    text = ax_s.text(0.1, 0.5, "S")
    
    ax_s.axvspan(0.2, 0.4, alpha=0.4, color='#46757d', label = "Fair (0.21 - 0.40)")
    text = ax_s.text(0.3, 0.5, "F")
    
    ax_s.axvspan(0.4, 0.6, alpha=0.4, color='#728255', label = "Moderate (0.41 - 0.6)")
    text = ax_s.text(0.5, 0.5, "M")
    
    ax_s.axvspan(0.6, 0.8, alpha=0.4, color='#46757d', label = "Substantial (0.61 - 0.8)")
    text = ax_s.text(0.7, 0.5, "S")
    
    ax_s.axvspan(0.8, 1, alpha=0.4, color='#728255', label = "Almost perfect (0 - 1)")
    text = ax_s.text(0.9, 0.5, "A")
    
    return ax_s

def g_vies_ax(dic, i, ax_s,  cat):
#     fig, ax = plt.subplots(1)
#     ax_s = ax
    
    con_m   = dic[cat]['vies']["ci_m"] #np.percentile(ames,[100*(1-confidence)/2,100*(1-(1-confidence)/2)])
    con_max = dic[cat]['vies']["ci_max"]
    
    d = dic[cat]['vies']["d"]
    k = np.mean(con_m)
    k_max = np.mean(con_max)
    
#     k     = dic[cat]['vies']["d_measured_m"]
#     k_max = dic[cat]['vies']["d_measured_max"]
    
#     y_pos.append(i)
    
    generate_ci_m    =  [0.25, 0.25]# cret_line(i)
    generate_ci_max  = [0.75, 0.75]
    
    generate_measure = [0, 1] #g_measure(i) #[0.2, 0.4] #cre_generate(i)
    
#     generate_ci =  [0, 0]# cret_line(i)
#     generate_measure = [0, 0.4] #g_measure(i) #[0.2, 0.4] #cre_generate(i)
    
#     print(g_measure)
    if(i==1):
        ax_s.plot(con_m, generate_ci_m, label = "CI Kappa (K)", color= "black", linewidth=12.0, alpha=0.5)
#         ax_s.plot(con_max, generate_ci_max, label = "CI max Kappa (Kmax)", color ="red", linewidth=12.0, alpha=0.5)
        
        ax_s.plot([k, k], generate_measure, label = "Sample max Kappa", color= "black", linewidth=4.0)
#         ax_s.plot([k_max, k_max], generate_measure,label = "Sample max Kappa", color= "red", linewidth=4.0)
        
    else:
        ax_s.plot(con_m, generate_ci_m, color= "black", linewidth=12.0, alpha=0.5)
#         ax_s.plot(con_max, generate_ci_max, color ="red", linewidth=12.0, alpha=0.5)
        
        ax_s.plot([k, k], generate_measure, color= "black", linewidth=4.0)
#         ax_s.plot([k_max, k_max], generate_measure, color= "red", linewidth=4.0)
    
  
#     inicio = -0.2
#     fim = 1
#     cores_l = np.linspace(inicio, fim, 256)
#     cmap = cm.get_cmap('plasma')
#     for a, x in enumerate(cores_l, 1):
#         c = cmap((x-inicio)/fim)
#         ax_s.axvspan(cores_l[a-1], a, alpha=0.1, color=c)

    
    r_separado = test_ci_separado(con_m, con_max)
    s = ""
    if r_separado:
#         s="(*) p<0.05 m={},\nmax= {}".format(con_m, con_max)
        s="(*)"
        
    string = "B = {:.2f}".format(k)
        
    ax_s.set_title(string, fontsize=14, loc='left')
#     ax_s.set_title("Bias", fontsize=14)
    ax_s.set_yticks([])
    ax_s.set_ylim([0, 1])
    ax_s.set_xlim([0, 1])
    
    
    ax_s.set_xticks([0, 1])
    ax_s.set_xticklabels(["0\nReliable", "1\nUnreliable\n(Overvalued)"], fontsize=12) # rotation=65
#     ax_s.axvspan(0, -0.4, alpha=0.6, color='#581845', label = "Poor (<0.00)")
#     ax_s.axvspan(0, 0.2, alpha=0.4, color='#900C3F', label = "Sligh (0.00 - 0.20)")
#     ax_s.axvspan(0.2, 0.4, alpha=0.4, color='#C70039', label = "Fair (0.21 - 0.40)")
#     ax_s.axvspan(0.4, 0.6, alpha=0.4, color='#FF5733', label = "Moderate (0.41 - 0.6)")
#     ax_s.axvspan(0.6, 0.8, alpha=0.4, color='#FFC300', label = "Substantial (0.61 - 0.8)")
#     ax_s.axvspan(0.8, 1, alpha=0.4, color='#DAF7A6', label = "Almost perfect (0 - 1)")
#     plt.subplots_adjust( wspace=1, hspace=2)
    
    return ax_s

def g_prevalencia_ax(dic, i, ax_s,  cat):
#     fig, ax = plt.subplots(1)
#     ax_s = ax
    
    con_m   = dic[cat]['prevalencia']["ci_m"] #np.percentile(ames,[100*(1-confidence)/2,100*(1-(1-confidence)/2)])
    con_max = dic[cat]['prevalencia']["ci_max"]
    
    d = dic[cat]['prevalencia']["d"]
    k = np.mean(con_m)
    k_max = np.mean(con_max)
    
#     k     = dic[cat]['prevalencia']["d_measured_m"]
#     k_max = dic[cat]['prevalencia']["d_measured_max"]
    
#     y_pos.append(i)
    
    generate_ci_m    =  [0.25, 0.25]# cret_line(i)
    generate_ci_max  = [0.75, 0.75]
    
    generate_measure = [0, 1] #g_measure(i) #[0.2, 0.4] #cre_generate(i)
    
#     generate_ci =  [0, 0]# cret_line(i)
#     generate_measure = [0, 0.4] #g_measure(i) #[0.2, 0.4] #cre_generate(i)
    
#     print(g_measure)
    if(i==1):
        ax_s.plot(con_m, generate_ci_m, label = "CI Kappa (K)", color= "black", linewidth=12.0, alpha=0.5)
#         ax_s.plot(con_max, generate_ci_max, label = "CI max Kappa (Kmax)", color ="red", linewidth=12.0, alpha=0.5)
        
        ax_s.plot([k, k], generate_measure, label = "Sample max Kappa", color= "black", linewidth=4.0)
#         ax_s.plot([k_max, k_max], generate_measure,label = "Sample max Kappa", color= "red", linewidth=4.0)
        
    else:
        ax_s.plot(con_m, generate_ci_m, color= "black", linewidth=12.0, alpha=0.5)
#         ax_s.plot(con_max, generate_ci_max, color ="red", linewidth=12.0, alpha=0.5)
        
        ax_s.plot([k, k], generate_measure, color= "black", linewidth=4.0)
#         ax_s.plot([k_max, k_max], generate_measure, color= "red", linewidth=4.0)
    
    
    r_separado = test_ci_separado(con_m, con_max)
    s = ""
    if r_separado:
#         s="(*) p<0.05 m={},\nmax= {}".format(con_m, con_max)
        s="(*)"
        
    string = "P = {:.2f}".format(k)
        
    ax_s.set_title(string, fontsize=14, loc='left')
    
#     ax_s.set_title("Prevalence", fontsize=14)
    ax_s.set_yticks([])
    ax_s.set_ylim([0, 1])
    ax_s.set_xlim([0, 1])
    
    
#     inicio = -0.2
#     fim = 1
#     cores_l = np.linspace(inicio, fim, 256)
    
#     cmap = cm.get_cmap('plasma')
    
    
#     for a, x in enumerate(cores_l, 1):
#         c = cmap(((fim - x) + inicio)/fim)
#         ax_s.axvspan(cores_l[a-1], a, alpha=0.1, color=c)

    
    
    ax_s.set_xticks([0, 1])
    ax_s.set_xticklabels(["0\nReliable","1\nUnreliable\n(Undervalued)"], fontsize=12) # rotation=65
    
    
#     ax_s.axvspan(-0.2, 1, alpha=0.6, color='#581845', label = "Poor (<0.00)")
#     ax_s.axvspan(0, 0.2, alpha=0.4, color='#900C3F', label = "Sligh (0.00 - 0.20)")
#     ax_s.axvspan(0.2, 0.4, alpha=0.4, color='#C70039', label = "Fair (0.21 - 0.40)")
#     ax_s.axvspan(0.4, 0.6, alpha=0.4, color='#FF5733', label = "Moderate (0.41 - 0.6)")
#     ax_s.axvspan(0.6, 0.8, alpha=0.4, color='#FFC300', label = "Substantial (0.61 - 0.8)")
#     ax_s.axvspan(0.8, 1, alpha=0.4, color='#DAF7A6', label = "Almost perfect (0 - 1)")
#     plt.subplots_adjust( wspace=1, hspace=2)
    
    return ax_s



def plot_figure(path, dic, ls_cat_ordenada, space, n_image):
    fig = plt.figure()
    if space < 4:
        space = 4
        
    fig.set_size_inches(space*1.4, space*3)

    gs0 = gridspec.GridSpec(space, 1, figure=fig)

    plt.tight_layout(pad=1)
    for i, cat in enumerate(ls_cat_ordenada, 0):
        gs00 = gs0[i].subgridspec(16, 9)
        
        kappa = fig.add_subplot(gs00[0:6, 0:])
        g_kappa_ax(dic, i, kappa, cat)
        
        
    #     plt.subplots_adjust( wspace=1, hspace=10)

        bias_lado = fig.add_subplot(gs00[13:, 0:4])
        g_vies_ax(dic, i, bias_lado, cat)
        
        prevalence_baixo = fig.add_subplot(gs00[13:,5:])
        g_prevalencia_ax(dic, i, prevalence_baixo, cat)
        
        
    

    plt.subplots_adjust( wspace=1.3, hspace=1)
    plt.tight_layout(pad=1)
    print(path)
    

    path_image = "./"
    if "\\" in path:
        path_image = path[:path.rindex("\\")+1]
    # path_image = "./"
    # format_axes(fig)
    # plt.savefig('teste.png',  bbox_extra_artists=(lgd,), bbox_inches='tight')
    path_image = path + '.png'
    plt.savefig(path_image, bbox_inches='tight')
    # plt.show()
    print(f"saving figure in {path_image}")


def plot_graphe(path):
    data = get_dados(path)
    dic = ed.get_descritores(data)
    dt =     es.get_descritores_max(False, data)
    dt_max = es.get_descritores_max(True, data)


    def map_d(cat):
        return dic[cat]['kappa']['d']

    ls_cat_ordenada = list(zip(dic['ls_cat'], map(map_d, dic['ls_cat'])))
    ls_cat_ordenada.sort(key=lambda a: a[1])
    print(ls_cat_ordenada)
    ls_cat_ordenada = list(map(lambda x: x[0], ls_cat_ordenada))
    print(ls_cat_ordenada)


    space = len(data["ls_cat_txt"])
    plot_figure(path, dic, ls_cat_ordenada, space, 1)



    
