#!/usr/bin/python3
import sys

__author__ = 'Amedeo Zampieri'

fin = open('presenze.md', 'r')

new_file_content = ''

fnomi_presenti = open('filenomi_presenti.txt', 'r')

nomi_presenti = []

presente        = ' X          |' #Linea da aggiungere in caso di presenza
non_presente    = '            |'

#formatto la data correttamente
data = ' ' + sys.argv[1] + ' |'

for nome in fnomi_presenti.readlines():
    nome = nome.strip()

    if nome[0] == '#':
        continue

    nomi_presenti.append(nome)

#Leggo le prime due righe inutili per il nostro scopo
line = fin.readline()
new_file_content += line
line = fin.readline()
new_file_content += line


#Aggiorno con la data della nuova lezione
line = fin.readline()
line = line[0:-1] + data + '\n'
new_file_content += line

#Aggiungo la riga di dash
line = fin.readline()
new_file_content += line[0:-1] + ' ---------- |\n'

#Leggo le restanti 
for line in fin.readlines():

    line = line[0:-1]             #tolgo il \n finale
    s_line = line.split('|')[1].strip()    #faccio un trim

    if s_line in nomi_presenti:
        print(s_line, 'presente')
        new_file_content += line + presente + '\n'

    else:
        print(s_line, 'non presente')
        new_file_content += line + non_presente + '\n'

fin.close()

fout = open('presenze.md', 'w')
fout.write(new_file_content)
fout.close()



