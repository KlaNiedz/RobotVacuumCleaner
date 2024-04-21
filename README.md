# 104.1 Robot sprzatajacy


***

## Temat
Robot sprz�taj�cy "Benek"

## Cel projektu
Naszym celem projektu jest stworzenie robota sprz�taj�cego, kt�ry posiada sterowanie autonomiczne oraz r�czne. Jego zadaniem jest sprz�tni�cie ca�ego pomieszczenia i omini�cie przeszk�d.
Po zako�czeniu sprz�tania lub wy�adowaniu baterii "Benek" wraca do stacji �aduj�cej. 

## Dzia�anie robota
Robot ma funckj� odkurzania. Dzi�ki czujnikom robot omija przeszkody i optymalnie przemieszcza si� po pomieszczeniu. W razie wykrcia przeszkody, robot j� omija i kontynuuje swoj� prac�.
W momencie wyczerpania baterii lub przepe�nienia filtra "Benek" wraca na stacj� �aduj�c�, �aduje si�/opr�nia filtr i kontynuuje prac� od miejsca w kt�rym j� przerwa�.
Po sprz�tni�ciu ca�ego pokoju robot wraca do stacji �aduj�cej.

## Podzia� klas
1. Robot
2. Czujnik 
3. Bateria
4. Filtr
5. Mapa
6. Przeszkoda
7. Po�o�enie

# 1.Robot (po�o�enie, bateria, filtr, stan, czujniki)
Klasa Robot odpowiada za poruszanie si� Benka (zawiera jego obecne po�o�enie), monitoruje stan baterii i filtra. Jego ruch determinowany jest sygna�ami podawanymi przez czujniki.
Atrybut stan zawiera informacje o tym czy robot jest w trybie pracy czy spoczynku.

# 2.Czujnik 
Jest to klasa odpowiedzialna za badanie otoczenia Benka i przesy�ania klasie Robot informacji. 
W tej klasie zastosujemy dziedzczenie, za pomoc� kt�rego zainnicujemy r�zne rodzaje czujnik�w, np. czujnik po bokach robota - potrzebny do omijania przeszk�d; czujnik odleg�o�ci - informuje jak daleko Benek mo�e pojecha�;

# 3.Bateria (pojemno��)
W trakcie pracy robota atrybut tej klasy jest stale zmniejszany. Gdy osi�gnie 10% robot przerywa prac� i wraca do stacji �aduj�cej. 

# 4.Filtr (pojemno��)
Filtr dzia�a analogicznie do Baterii. Podczas pracy robota jego pojemno�� si� zmniejsza. Kiedy pojemno�� osi�gnie stan 5%, robot wraca do stacji �aduj�cej, gdzie resetuje pojemno��.
Przez podobie�stwo do baterii rozwa�ymy dziedziczenie.

# 5.Mapa (d�ugo��, szeroko��, przeszkody, po�o�enie_stacji)
Zawiera informacje o wielko�ci terenu do sprz�tania i po�o�enia wszystkich przeszk�d oraz stacji �aduj�cej. Stacja �aduj�ca jest obiektem klasy Po�o�enie.

# 6.Przeszkoda (po�o�enie, szeroko��, d�ugo��)
Jest to klasa przechowuj�ca po�o�enie przeszkody oraz ile zajmuje miejsca na mapie.

# 7.Po�o�enie (x, y)
Klasa zawieraj�ca 2 atrybuty informuj�ce o po�o�eniu danego obiektu. Z tej klasy korzysta wiele innych klas np. robot, przeszkoda. 

## Podzia� obowi�zk�w
Piotr - Czujnik
Klaudia - Mapa
Julia -  Przeszkoda, Po�o�enie, Filtr, Bateria
Robot - razem

## Docelowe dzia�anie programu
Na pocz�tku skupimy si� na poprawnej implmentacji funkcji oraz komunikacji mi�dzy klasami. W pocz�tkowych fazach pracy zajmiemy si� sterowanym r�cznie ruchem robota oraz wykrywaniem przeszk�d.
Natomiast docelowym za�o�eniem jest wy�wietlanie si� mapy trasy robota, kt�ry ma r�wnie� tryb automatyczny.

## Autorzy
Klaudia Niedzia�kowska, Julia Kie�bik, Piotr Koz�owski

