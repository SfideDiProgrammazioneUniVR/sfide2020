
__author__      = "Filippo Mantovan"
__copyright__   = "Pachbe"
'''
python3 ./thanos.py 1.in

Definition:
Dati due piante X Y thanos preferisce quello con popolazione strettamente maggiore
N è il totale dei giorni nell'universo
vuole minimizzare il numero di persone che uccide

output: 1 ne basta uccidere uno, o thanos si uccide

OUTPUT:
numero persone minime da uccidere se thanos riesci a creare il perfect universe
1 se thanos non riesce e uccide se stesso

INPUT:
numero pianeti
poppianeta_i

'''
import fileinput

file = fileinput.input()

pianeti = file.readline().strip()
pianeti = int(pianeti)
popolazioni = file.readline().strip().split()

#Conversione in int
for i in range (0,len(popolazioni)):
    popolazioni[i] = int(popolazioni[i])

popolazioni = popolazioni[::-1]


return_1 = False
killed = 0

for i in range (0, len(popolazioni)-1):

    if popolazioni[i] < popolazioni[i+1]:
        killed += popolazioni[i+1] - (popolazioni[i] - 1)
        popolazioni[i+1] = popolazioni[i] - 1

        if popolazioni[i+1] < 0:
            return_1 = True

for i in range (0, len(popolazioni)-1):
    if popolazioni[i] == popolazioni[i+1]:
        return_1 = True

if return_1:
    print(1)
else:
    print(killed)
