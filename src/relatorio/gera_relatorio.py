
# https://github.com/jmcnamara/XlsxWriter
import argparse
import json
import xlsxwriter

# python gera_relatorio.py  ./demo2.xlsx {\"name\":\"joao\"} 
# python gera_relatorio.py ./sss.xlsx "{\"teste\":[0 , 0 , 0 , 0 , 0 , 0 , 1 , 1 , 1 , 1 , 2 , 2 , 2]}"
"""
    python gera_relatorio.py ./sss1.xlsx "{'teste':[0 , 0 , 0 , 0 , 0 , 0 , 1 , 1 , 1 , 1 , 2 , 2 , 2], 's': [12]}"
    python gera_relatorio.py ./sss1.xlsx "{'teste':[0 , 0 , 0 , 0 , 0 , 0 , 1 , 1 , 1 , 1 , 2 , 2 , 2]}"
    
"""
# 


parser = argparse.ArgumentParser(description="teste" )
# parser.add_argument("r", type=int, help="Radius")
# parser.add_argument("h", type=int, help="h")
parser.add_argument("path", help="some_Text")
parser.add_argument("t", help="some_Text")
args = parser.parse_args()



if __name__ == '__main__':
    # print(cilinder(args.r,args.h))
    text = args.t
    print(text)
    text = text.replace("\'", "\"")
    s = json.loads(text)
    print(s)

    
    workbook = xlsxwriter.Workbook(args.path)
    worksheet = workbook.add_worksheet()

    worksheet.write('A1', "bbbb")
    worksheet.write('A1', s['medido']['catalogo_var']['observada'])

    workbook.close()
