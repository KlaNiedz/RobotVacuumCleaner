# 104.1 Robot sprzatajacy


***

## Temat
Robot sprz¹taj¹cy "Benek"

## Cel projektu
Naszym celem projektu jest stworzenie robota sprz¹taj¹cego, który posiada sterowanie autonomiczne oraz rêczne. Jego zadaniem jest sprz¹tniêcie ca³ego pomieszczenia i ominiêcie przeszkód.
Po zakoñczeniu sprz¹tania lub wy³adowaniu baterii "Benek" wraca do stacji ³aduj¹cej. 

## Dzia³anie robota
Robot ma funckjê odkurzania. Dziêki czujnikom robot omija przeszkody i optymalnie przemieszcza siê po pomieszczeniu. W razie wykrcia przeszkody, robot j¹ omija i kontynuuje swoj¹ pracê.
W momencie wyczerpania baterii lub przepe³nienia filtra "Benek" wraca na stacjê ³aduj¹c¹, ³aduje siê/opró¿nia filtr i kontynuuje pracê od miejsca w którym j¹ przerwa³.
Po sprz¹tniêciu ca³ego pokoju robot wraca do stacji ³aduj¹cej.

## Podzia³ klas
1. Robot
2. Czujnik 
3. Bateria
4. Filtr
5. Mapa
6. Przeszkoda
7. Po³o¿enie

# 1.Robot (po³o¿enie, bateria, filtr, stan, czujniki)
Klasa Robot odpowiada za poruszanie siê Benka (zawiera jego obecne po³o¿enie), monitoruje stan baterii i filtra. Jego ruch determinowany jest sygna³ami podawanymi przez czujniki.
Atrybut stan zawiera informacje o tym czy robot jest w trybie pracy czy spoczynku.

# 2.Czujnik 
Jest to klasa odpowiedzialna za badanie otoczenia Benka i przesy³ania klasie Robot informacji. 
W tej klasie zastosujemy dziedzczenie, za pomoc¹ którego zainnicujemy rózne rodzaje czujników, np. czujnik po bokach robota - potrzebny do omijania przeszkód; czujnik odleg³oœci - informuje jak daleko Benek mo¿e pojechaæ;

# 3.Bateria (pojemnoœæ)
W trakcie pracy robota atrybut tej klasy jest stale zmniejszany. Gdy osi¹gnie 10% robot przerywa pracê i wraca do stacji ³aduj¹cej. 

# 4.Filtr (pojemnoœæ)
Filtr dzia³a analogicznie do Baterii. Podczas pracy robota jego pojemnoœæ siê zmniejsza. Kiedy pojemnoœæ osi¹gnie stan 5%, robot wraca do stacji ³aduj¹cej, gdzie resetuje pojemnoœæ.
Przez podobieñstwo do baterii rozwa¿ymy dziedziczenie.

# 5.Mapa (d³ugoœæ, szerokoœæ, przeszkody, po³o¿enie_stacji)
Zawiera informacje o wielkoœci terenu do sprz¹tania i po³o¿enia wszystkich przeszkód oraz stacji ³aduj¹cej. Stacja ³aduj¹ca jest obiektem klasy Po³o¿enie.

# 6.Przeszkoda (po³o¿enie, szerokoœæ, d³ugoœæ)
Jest to klasa przechowuj¹ca po³o¿enie przeszkody oraz ile zajmuje miejsca na mapie.

# 7.Po³o¿enie (x, y)
Klasa zawieraj¹ca 2 atrybuty informuj¹ce o po³o¿eniu danego obiektu. Z tej klasy korzysta wiele innych klas np. robot, przeszkoda. 

## Podzia³ obowi¹zków
Piotr - Czujnik
Klaudia - Mapa
Julia -  Przeszkoda, Po³o¿enie, Filtr, Bateria
Robot - razem

## Docelowe dzia³anie programu
Na pocz¹tku skupimy siê na poprawnej implmentacji funkcji oraz komunikacji miêdzy klasami. W pocz¹tkowych fazach pracy zajmiemy siê sterowanym rêcznie ruchem robota oraz wykrywaniem przeszkód.
Natomiast docelowym za³o¿eniem jest wyœwietlanie siê mapy trasy robota, który ma równie¿ tryb automatyczny.

## Autorzy
Klaudia Niedzia³kowska, Julia Kie³bik, Piotr Koz³owski

