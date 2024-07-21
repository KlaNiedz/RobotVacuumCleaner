# 104.1 Robot sprzatajacy


***

## Temat
Robot sprzątający "Benek"

## Cel projektu
Naszym celem projektu jest stworzenie robota sprzątającego, który posiada sterowanie autonomiczne oraz ręczne. Jego zadaniem jest sprzątnięcie całego pomieszczenia i ominięcie przeszkód.
Po zakończeniu sprzątania lub wyładowaniu baterii "Benek" wraca do stacji ładującej. 

## Działanie robota
Robot ma funckję odkurzania. Dzięki czujnikom robot omija przeszkody i optymalnie przemieszcza się po pomieszczeniu. W razie wykrcia przeszkody, robot ją omija i kontynuuje swoją pracę.
W momencie wyczerpania baterii lub przepełnienia filtra "Benek" wraca na stację ładującą, ładuje się/opróżnia filtr i kontynuuje pracę od miejsca w którym ją przerwał.
Po sprzątnięciu całego pokoju robot wraca do stacji ładującej.

## Podział klas
1. Robot
2. Czujnik 
3. Bateria
4. Filtr
5. Mapa
6. Przeszkoda
7. Położenie

### 1.Robot (położenie, bateria, filtr, stan, czujniki)
Klasa Robot odpowiada za poruszanie się Benka (zawiera jego obecne położenie), monitoruje stan baterii i filtra. Jego ruch determinowany jest sygnałami podawanymi przez czujniki.
Atrybut stan zawiera informacje o tym czy robot jest w trybie pracy czy spoczynku.

### 2.Czujnik 
Jest to klasa odpowiedzialna za badanie otoczenia Benka i przesyłania klasie Robot informacji. 
W tej klasie zastosujemy dziedzczenie, za pomocą którego zainnicujemy rózne rodzaje czujników, np. czujnik po bokach robota - potrzebny do omijania przeszkód; czujnik odległości - informuje jak daleko Benek może pojechać;

### 3.Bateria (pojemność)
W trakcie pracy robota atrybut tej klasy jest stale zmniejszany. Gdy osiągnie 10% robot przerywa pracę i wraca do stacji ładującej. 

### 4.Filtr (pojemność)
Filtr działa analogicznie do Baterii. Podczas pracy robota jego zapełnieie się zwiększa. Kiedy zapełnienie osiągnie stan 95%, robot wraca do stacji ładującej, gdzie resetuje zapełnienie.

### 5.Mapa (długość, szerokość, przeszkody, położenie_stacji)
Zawiera informacje o wielkości terenu do sprzątania i położenia wszystkich przeszkód oraz stacji ładującej. Stacja ładująca jest obiektem klasy Położenie.

### 6.Przeszkoda (położenie, szerokość, długość)
Jest to klasa przechowująca położenie przeszkody oraz ile zajmuje miejsca na mapie.

### 7.Położenie (x, y)
Klasa zawierająca 2 atrybuty informujące o położeniu danego obiektu. Z tej klasy korzysta wiele innych klas np. robot, przeszkoda. 

## Podział obowiązków
Piotr - Czujnik
Klaudia - Mapa
Julia -  Przeszkoda, Położenie, Filtr, Bateria
Robot - razem

## Docelowe działanie programu
Na początku skupimy się na poprawnej implmentacji funkcji oraz komunikacji między klasami. W początkowych fazach pracy zajmiemy się sterowanym ręcznie ruchem robota oraz wykrywaniem przeszkód.
Natomiast docelowym założeniem jest wyświetlanie się mapy trasy robota, który ma również tryb automatyczny.

## Autorzy
Klaudia Niedziałkowska, Julia Kiełbik, Piotr Kozłowski

