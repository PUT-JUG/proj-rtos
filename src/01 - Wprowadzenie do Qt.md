# Wprowadzenie do Qt

## Biblioteka Qt

*Qt* to potężna biblioteka, która umożliwia pisanie przenośnych (kompilujących się i działających na wielu platformach) aplikacji bazujących na tym samym kodzie.

Głównym założeniem jest obsługa interfejsu okienkowego, jednak dla zapewnienia kompatybilności, twórcy Qt zaimplementowali ponownie funkcjonalność dostępną w bibliotece standardowej (np. napisy: `QString`, kolekcje: `QVector`, `QList`, obsługę wątków czy plików), a także wiele dodatkowej, bardziej rozbudowanej - m.in. wygodną obsługę sieci.

Podstawowym językiem wykorzystywanym przez Qt jest C++ wraz z ich własnym preprocesorem (MOC - Meta-Object Compiler), który umożliwia zrobienie rzeczy, które byłyby trudne z wykorzystaniem "czystego" C++, takich jak mechanizm sygnałów i slotów, który umożliwia m.in. łatwe połączenie warstwy graficznej (interfejsu) z kodem.

Dostarczane jest także środowisko, które ułatwia wykorzystanie biblioteki i tworzenie aplikacji okienkowych - *Qt Creator*.

### Instalacja środowiska, wprowadzenie inne przydatne materiały:

http://jug.put.poznan.pl/lab-ie-2/pl/

### Wprowadzenie

Korzystając z instrukcji *Lab 10 - Qt - wstęp do GUI* z powyższego odnośnika, stwórz pierwszą aplikację okienkową i zapoznaj się z mechanizmem sygnałów i slotów.

## ❗️Zadania❗️

### 1. Kalkulator

Napisz program kalkulator, który będzie wykonywał podstawowe operacje matematyczne na dwóch podanych liczbach.
W interfejsie umieść dwa pola tekstowe (`lineEdit`) do wprowadzenia liczb oraz przyciski `+`, `-`, `*`, `/`.
Wynik umieszczaj w trzecim polu tekstowym, oznaczonym jako tyko do odczytu.

### 2. Pobieranie parametrów zadań

Zaprojektuj formę przechowywania informacji o zbiorze zadań w RTOS.
Zaimplementuj ją w przykładowej aplikacji Qt Widgets.
Dodaj elementy interfejsu pozwalające na wprowadzenie dowolnego zbioru zadań oraz przycisk pozwalający na ich wyświetlenie parametrów wszystkich wprowadzonych do tej pory zadań (na początek np. w konsoli).

### 3. Wykresy w Qt

Do wyświetlania wykresów w Qt można użyć ręcznego rysowania po “płótnie” (obiekty typu `QGraphicsView`/`QGraphicsScene`), bibliotek zewnętrznych (np. `QCustomPlot`, `QWT`) lub wbudowanego `QtCharts`.
`QtCharts` nie jest instalowane domyślnie, podczas instalacji możemy zaznaczyć je jako opcję w wybranej wersji frameworku. Po instalacji możliwe jest dodanie QtCharts przez narzędzie `MaintenanceTool.exe` znajdujące się w katalogu instalacyjnym Qt. Wybieramy kolejno: *Next*, *Skip*, *Add or remove components*, szukamy w drzewku zainstalowanej wersji Qt, zaznaczamy *Qt Charts* i zatwierdzamy.

#### QtCharts

Aby uruchomić przykładowy program wykorzystujący QtCharts do narysowania wykresu słupkowego:
W pliku .pro projektu dodaj słowo charts do makra QT:

```
QT += core gui charts
```

Dodaj do interfejsu głównego okna obiekt Vertical Layout (QVBoxLayout) i nazwij go `plots`.
W konstruktorze głównego okna dodaj następujący kod:
```cpp
QCandlestickSet * bar; // pojedynczy slupek
QCandlestickSeries* series = new QCandlestickSeries(); // seria slupkow
series->setBodyWidth(0.9);

bar = new QCandlestickSet(0, 1.0, 0, 1.0, 0);
series->append(bar);
bar = new QCandlestickSet(0, 0.2, 0, 0.2, 1);
series->append(bar);
bar = new QCandlestickSet(0, 0.0, 0, 0.0, 2);
series->append(bar);
bar = new QCandlestickSet(0, 1.0, 0, 1.0, 3);
series->append(bar);

QChart *chart = new QChart(); // tworzy wykres
chart->addSeries(series); // dodaje serie slupkow
chart->setAnimationOptions(QChart::SeriesAnimations); // super animacja

QList<QString> labels = {"0", "1", "2", "3"}; // etykiety dla osi poziomej
chart->createDefaultAxes(); // tworzy osie
qobject_cast<QBarCategoryAxis *>(chart->axes(Qt::Horizontal).at(0))->setCategories(labels); // ustawia etykiety osi poziomej
qobject_cast<QValueAxis *>(chart->axisY())->setTickCount(2); // usuwa wartosci posrednie z osi Y

chart->legend()->setVisible(false); // usuwa legende

QChartView *chartView = new QChartView(chart); // tworzy widok wykresu
chartView->setRenderHint(QPainter::Antialiasing);

ui->plots->addWidget(chartView); // dodaje wykres do layoutu "plots"
```

Dodaj też niezbędne pliki nagłówkowe oraz makro włączające przestrzeń nazw QtCharts:
```cpp
#include <QtCharts/QChartView>
#include <QtCharts/QValueAxis>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QCandlestickSet>
#include <QtCharts/QCandlestickSeries>

QT_CHARTS_USE_NAMESPACE
```
Spróbuj zmodyfikować przykład tak, by możliwe było wykorzystanie go do wyświetlenia diagramu Gantt’a.

***
Autor: *Jakub Tomczyński*
