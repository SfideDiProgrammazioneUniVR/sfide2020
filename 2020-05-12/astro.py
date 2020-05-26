import fileinput

class Daytime:
    '''
    Classe per la gestione semplice e comoda della somma e del confronto fra orari.
    È comoda perché implementa una ciclicità settimanale.
    Da notare che il giorno non è limitato a 7 per evitare dei casi limite dove
    nel while principale del programma potrebbe accadere che il momento in cui una
    stella brilla sia sempre minore dell'altro.
    '''

    days_dict = {0: 'Saturday', 1 : 'Sunday', 2 : 'Monday', 3 : 'Tuesday', 4 : 'Wednesday', 5 : 'Thursday', 6: 'Friday'}

    def __init__(self, h, m, d=0):
        self.days = d
        self.hours = h
        self.minutes = m

    def __add__(self, other):
        '''
        Classica somma fra due orari. Non c'è overflow dei giorni!
        Vengono quindi mantenuti anche oltre al settimo.
        '''

        m = self.minutes + other.minutes
        h = d = 0

        if m >= 60:
            m = m % 60
            h = 1

        h += self.hours + other.hours

        if h >= 24:
            h = h % 24
            d = 1

        d = (d + other.days + self.days)

        return Daytime(d=d, h=h, m=m)

    def __str__(self):
        '''
        Nella visualizzazione mi interessa la stringa col nome del giorno,
        quindi utilizzo il dizionario per ottenerlo.
        '''
        return Daytime.days_dict[self.days % 7] + '\n' + str(self.hours).zfill(2) + ':' + str(self.minutes).zfill(2)

    def __lt__(self, other):
        '''
        Nel minore ho bisogno di sapere il numero di giorni esatti, poiché se causassi
        l'overflow dei giorni facendoli tornare a 0 potrei avere problemi.
        '''
        s = self.days * 24 * 60 + self.hours * 60 + self.minutes
        o = other.days * 24 * 60 + other.hours * 60 + other.minutes

        return s < o

    def __eq__(self, other):
        '''
        Nell'equals invece considero uguali due giorni con lo stesso nome, a prescindere
        che siano o meno della stessa "settimana"
        '''
        s = (self.days % 7) * 24 * 60 + self.hours * 60 + self.minutes
        o = (other.days % 7) * 24 * 60 + other.hours * 60 + other.minutes
        if s == o:
            return True
        return False

    def __hash__(self):
        '''
        È necessario che l'hash sia congruente con l'equals, quindi utilizzo
        lo stesso ragionamento.
        '''
        return hash(self.days % 7) ^ hash(self.hours) ^ hash(self.minutes)

fin = fileinput.input()

timestar1 = fin.readline().strip().split(':')
timestar2 = fin.readline().strip().split(':')

timestar1 = Daytime(int(timestar1[0]), int(timestar1[1]))
timestar2 = Daytime(int(timestar2[0]), int(timestar2[1]))

intervalstar1 = fin.readline().strip().split(':')
intervalstar1 = Daytime(int(intervalstar1[0]), int(intervalstar1[1]))
intervalstar2 = fin.readline().strip().split(':')
intervalstar2 = Daytime(int(intervalstar2[0]), int(intervalstar2[1]))

shines1 = set()
shines2 = set()

t1 = timestar1
t2 = timestar2
'''
Finché non ho visto tutti i possibili lampeggi di entrambe le stelle
ne cerco uno in comune. Mantengo i lampeggi in un set per comodità.
Proseguo sempre con la stella con il tempo di lampeggio più basso, in modo
da fare una ricerca in qualche modo ordinata, evitando di trovare così lampeggi
in comune ma con data non minima.
'''
while t1 not in shines1 or t2 not in shines2:
    if t1 < t2:
        shines1.add(t1)
        t1 = t1 + intervalstar1

    elif t2 < t1:
        shines2.add(t2)
        t2 = t2 + intervalstar2
    
    else:
        print(t1)
        break

if t1 != t2:
    print('Never')

