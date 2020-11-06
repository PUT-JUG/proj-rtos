# Wstęp do programowania obiektowego

## Biblioteka standardowa:

### Przechowywanie tekstu:

Biblioteka standardowa C++ udostępnia wyspecjalizowany typ do przechowywania tekstu. Oferuje on funkcje ułatwiające posługiwanie się ciągami znaków. Przyjrzyj się fragmentowi kodu poniżej:

```cpp
// tworzenie zmiennych przechowujących napisy
string s1 = "Hello";
string s2 = "world";
// wyswietlanie
cout << s1 << " " << s2 << "!" << endl;
// laczenie stringow
string s3 = s1 + " " + s2 + "!";
cout << s3 << endl;
```
Dołączyć należy nagłówek `<string>`. Typ ten jest w pełni kompatybilny ze strumieniami, np. `cin`, `cout`.

Szczegółowy opis:

https://docs.google.com/document/d/1BqjPnThxld-uuXN3Lh5Gk5kmpaAcQ5zmAC6FP1hhgAE/

Dokumentacja:

http://www.cplusplus.com/reference/string/string/

### Kolekcje:

W C++, kolekcją lub kontenerem jest struktura danych, która grupuje elementy (wartości) takiego samego typu.
Aby skorzystać z kontenera konieczne jest załączenie odpowiedniej biblioteki systemowej:

```cpp
#include <collection_name>
```

Najczęściej wykorzystywane kontenery to `vector` oraz `list`. Utworzenie kontenera następuje przez stworzenie zmiennej o typie `typ_kontenera<typ_elementu>`.

Wektor zapewnia losowy dostęp do dowolnego elementu, jednak usuwanie i dodawanie elelementów w różnych miejscach może być kosztowne czasowo. Przykłady użycia:

```cpp
// rozne mozliwosci tworzenia vectorow
vector<int> v1;               // vector pusty
vector<float> v2(5, -1.0);    // 5 elementow o wartosciach -1
vector<int> v4{ 0, -12, 53 }; // nowy vector z elementami o wartosciach 0, -12, 53

cout << v4[1] << endl;        // do poszczegolnych elementow mozemy odwolywac sie tak jak do tablicy

cout << v4.size() << endl;
v4.push_back(1);              //dodaje element do konca wektora
cout << v4.size() << endl;
```

Lista zapewnia możliwość dodawania i usuwania elementów w dowolnych miejscach, jednak przeglądanie listy zawsze odbywa się “po kolei”. Przykłady użycia:
```cpp
// rozne sposoby tworzenia list
list<int> l1;                 // lista pusta
list<float> l2(5, -1.0);      // lista z 5 elementami o wartosciach -1
list<int> l4{ 5, 6, 7, 8 };   // lista z czterema wartosciami - 5, 6, 7, 8
l4.push_front(100);           // dodaje element na poczatku listy
```


Aby przejrzeć listę możemy wykorzystać iteratory - specjalny typ wskaźników na poszczególne elementy:
```cpp
for (auto itr = l4.begin(); itr != l4.end(); itr++) {
    cout << *itr << endl;                
}
```

Dla kolekcji możliwe jest także używanie skróconego zapisu do przeglądania:
```cpp
for(int num : l4) {
    cout << num << endl;                
}
```

Przy przekazywaniu kontenera do funkcji warto użyć referencji (np. `void funkcja(vector<int> &parametr)`) aby uniknąć kopiowania całego kontenera w pamięci.

Szczegółowy opis kontenerów:

https://docs.google.com/document/d/1FHCbT4CQDwPJYqGo5htaAJNrdc6Q48l83Nw9ozKlvHc/

Dokumentacja:

http://www.cplusplus.com/reference/stl/

### ❗️Zadanie❗️

Napisz funkcję, która wyświetli wszystkie elementy znajdujące się w przekazanym do niej wektorze liczb całkowitych.

## Struktury:

Struktura danych to zbiór kilku zmiennych (nazywanych w strukturze polem) zgrupowanych pod jedną nazwą. Sposób definiowania struktury danych przedstawiono poniżej:

```cpp
struct struct_type {
    member_type1 member_name1;
    member_type2 member_name2;
    member_type3 member_name3;
};
```
gdzie:
`struct_type` to nazwa **typu** tworzonej struktury,
`member_type` to typ pojedynczego pola (np. `int`, `double`, …),
`member_name` to nazwa danego pola.

Przykład stworzenia struktury:

```cpp
struct pet {
    string name;
    int age;
    double weight;
};
```
Powyższy kod deklaruje nowy **typ** (jak `int`, czy `double`) - o nazwie `pet`, który zawiera trzy pola - nazwę (`name`, typu `string`), wiek (`age`, typu `int`) oraz wagę (`weight`, typu `double`). Dzięki zastosowaniu struktury powstaje logiczne powiązanie tych trzech wartości.

Odwołanie do poszczególnych pól odbywa się za pomocą operatora `.` (bądź `->`, jeśli odwołujemy się przez wskaźnik na strukturę):

Przykład użycia:

```cpp
pet moje_zwierzatko;
cin >> moje_zwierzatko.name;
moje_zwierzatko.age = 10;
moje_zwierzatko.weight = 3.5;

pet zwierzatko_kolegi = {"Pimpus", 99, 1.0};
cout << zwierzatko_kolegi.name << endl;
```

Szczegółowy opis:

https://docs.google.com/document/d/1vpNSOhQV_OUtg4TmRppj3k1QYYZVWPRML9LA3AGk5x4/

### ❗️Zadanie❗️

Zaprojektuj strukturę Osoba przechowującą informacje: imię, nazwisko, wiek, waga, wzrost. W programie głównym utwórz trzy obiekty powyższego typu przy czym dwa z nich wypełnij danymi w kodzie programu, a trzecią danymi wczytanymi od użytkownika.

Dodaj wszystkie stworzone obiekty do wektora.

Na końcu stwórz funkcję która wyświetli strukturę tego typu i użyj jej do wyświetlenia stworzonych obiektów, iterując się przez wszystkie elementy wektora.

## Klasy:

Klasy są rozwinięciem idei struktur o możliwość dodania do nich **metod** (funkcji należących do klasy, które wykonywane są na danym obiekcie). W praktyce, w C++ każda struktura jest jednocześnie klasą. Zwyczajowo nazwy klas zapisujemy z wielkiej litery.

Przeniesienie powyższego przykładu struktury na klasę wyglądałoby następująco:

```cpp
class Pet {
public:
    string name;
    int age;
    double weight;
};
```
Użycie klas może wyglądać identycznie jak w przypadku struktur:

```cpp
Pet moje_zwierzatko;
cin >> moje_zwierzatko.name;
moje_zwierzatko.age = 10; // itd.
```
Dodanie do klasy metody wyświetlającej informacje:

```cpp
class Pet {
public:
    string name;
    int age;
    double weight;
    void print() {
        cout << "Imie: " << name << endl;
        cout << "Wiek: " << age << endl;
        cout << "Masa: " << weight << endl;
    }
};
```

I wywołanie metody:

```cpp
Pet zwierzatko;
zwierzatko.name = "Sven";
zwierzatko.age = 15;
zwierzotko.weight = 410.5;
zwierzatko.print();
```

Zwróć uwagę na słowo kluczowe `public`. Oznacza ono, że pola i metody umieszczone pod nim są dostępne dla programisty “spoza klasy”. Pozostałe poziomy dostępu to `private` i `protected`. Zwyczajowo wszystkie pola przechowujące informacje o klasie są chronione, a dostęp do nich odbywa się przez odpowiednie metody. Dzięki temu osoba projektująca klasę ma pełną kontrolę nad tym, co programista jej używający umieści w poszczególnych polach. Dodatkowo, klasy mogą mieć kostruktor i destruktor, czyli specjalne metody wywoływane w momencie tworzenia i usuwania obiektu. Mogą one być przydatne np. w nadawaniu domyślnych wartości.

```cpp
class Pet {
public:
     Pet() { // domyslny konstruktor
           name = "Bezimienny";
           age = 0;
           weight = 3.14;
     }
     void print() {
           cout << "Imie: " << name << endl;
           cout << "Wiek: " << age << endl;
           cout << "Masa: " << weight << endl;
     }
private:
    string name;
    int age;
    double weight;
};
```

Przy takiej kostrukcji klasy niemożliwa jest bezpośrednia modyfikacja pól klasy “z zewnątrz”:
```cpp
Pet zwierz;
zwierz.age = 100; // nie skompiluje sie!
```
### ❗️Zadanie❗️

Dodaj do klasy metodę `set_age(int new_age)`, która pozwoli na zmodyfikowanie wartości pola age. Uniemożliw wpisanie wartości mniejszych od 0.

Gdybyśmy chcieli rozdzielić klasę na plik nagłówkowy (`.h`) i źródłowy (`.cpp`), całość wygląda następująco:

**Pet.h**:
```cpp
#pragma once

// includes etc.

class Pet {
public:
    Pet();
    void print();
private:
    string name;
    int age;
    double weight;
};
```

**Pet.cpp**:
```cpp

#include "Pet.h"

Pet::Pet() {
    name = "Bezimienny";
    age = 0;
    weight = 3.14;
}
void Pet::print() {
    cout << "Imie: " << name << endl;
    cout << "Wiek: " << age << endl;
    cout << "Masa: " << weight << endl;
}
```

Szczegółowy opis:

Dodatkowe materiały: http://jug.put.poznan.pl/lab-psio/

***
Autor: *Jakub Tomczyński*
