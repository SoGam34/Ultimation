# Ultimation

In dem Projekt wird Ultimate Tic-Tac-Toe als Webapplication programmiert in C++. Das [Webtoolkit (wt)](https://www.webtoolkit.eu/wt) Framework wird zum Anzeigen und bearbeiten von HTTP Anfragen verwendet. 

## Grundsätzliche Code-Regeln
### Nesting
**Es wird nicht genestet!**  Mit Nesting meint man ineinander verschachtelte Statements, zum Beispiel : 
```
for(...)
{
    if(...)
    {
        if(...)
        {
            if(...)
            {
                irgendwas;
            }
        }
    }
}
```
Ich kann verstehen, wenn man ausversehen in solchen einem Code Abschnitt endet, nachdem man ein Feature implementiert hat.Trotzdem wird es in diesem Repository als schlechter Code angesehen und muss aus der Branche entfernt werden, bevor Sie mit main gemerged werden kann.

Wie man so was auflöst und weitere Informationen gibt es [hier](https://www.youtube.com/watch?v=CFRhGnuXG-4).

### try-catch 
**Try-catch ist eine Programm interne debugging Methode und kein verbessertes if oder switch tool.** Try-catch darf benutzt werden, aber nur für das, wofür man es vorgesehen hat **Debugging**. Ein andere Verwendung bedeutet, dass die Branch nicht mit main gemerged werden darf und das einiges schief gelaufen ist, weil du sehr schlechten Code hast. 

### templates 
**Verboten** An diesem Projekt arbeiten Personen die C++ lernen auf die man etwas Rücksicht nehmen sollte. Zusätzlich erschweren [templates](https://en.cppreference.com/w/cpp/language/templates) die Nachvollziehbarkeit bei Fehlern und wenn man die Verwendung übertreibt, hat keiner mehr einen Überblick. 

### Namens konventionen

Bitte gebt euch Mühe beim vergeben von Namen und wählt beschreibende Namen. Wenn der Name dadurch länger aber Verständlicher wird ist das in Ordnung(dafür haben wir IDEs). Im folgenden gibt es einige strukturelle Vereinbarungen. Die Vereinbarungen helfen vieleicht bei der Namensgebung und sollen vor allem die Leserlichkeit des Codes erhöhen. 

 - Konstanten 
    werden immer groß geschrieben und einzelen Wörter werden mit _ (Unterstrich) getrennt. ``` const int EINE_KONSTANTE; ```

 - Grundsätzlich werden Variablen am Anfang klein und in CamelCase geschrieben. ``` int eineVariable;  ```

 - Klassen
   - Klassennamen am Anfang groß schreiben.  ``` class EineKlasse; ```
   - Die Membervariablen werden am Anfag großgeschrieben, ansonsten wie normale Variablen. ``` private: int MemberVariable;  ``` 
   - Übergabe Parameter verden wie normale Variabelen geschrieben und sollten genauso heißen wie die Member Variable der sie zugewiesen werden. 
     ```c++ 
     class TestClasse {
        private: 
          int Test;
        public: 
          void setTest(int test)
          {
            Test = test;
          } 
     };
      ```
   - Methoden immer klein Anfangen und danach CamelCase. Bei der Benennung von Funktionen sollte man immer der Struktur Verb, Adjektive und Nomen folgen. Bsp.: processRequest(), selectAllUserData(), getGreenColor(); 

 - Prefixes 
   - Bei einer Referenz wird immer ein r_ vor die Variable geschrieben. 
   - Bei einem Intellegenten Zeiger ein s_ vor die Variable geschrieben. 
   - Bei einem rohen Zeiger ein p_ vor die Variable geschrieben. 
   ```c++
      int& r_ichBinEineReferenz;
      std::unique_ptr<int> s_ichBinEinIntelligenterZeiger{std::make_unique<int>()};
      int* p_ichBinEinRoherZeiger; 
     ```

     
### Facade Pattern 
Bei der Strukturierung und Planung eines neuen Features sollte auf den Einhaltung des [Facade-Pattern](https://www.ionos.de/digitalguide/websites/web-entwicklung/was-ist-das-facade-pattern/) geachtet werden. 

Im Grunde einfache Klassen Interface, die man schnell und leicht weiß und sieht, was gemacht wird, ohne wissen zu müssen, wie es funktioniert. Man könnte sagen:"Keep it simple"(für den Anwender). 

### Tests 
Demnächst soll es selbstgeschriebene Unit Tests geben. Damit der Code gut getestet werden kann, bin ich dir sehr dankbar, wenn du noch auf [Dependency Injektion ](https://www.youtube.com/watch?v=J1f5b4vcxCQ&pp=ygUUZGVwZW5kZW5jeSBpbmplY3Rpb24%3D) achten kannst. ** Persönlich ** finde ich macht es die Verwendung der Klassen auch einfacher, da man zu übersichtlicheren und strukturierteren Code „gezwungen“ wird.

## (Ansprech-)Personen 
Bei Fragen oder Problemen findest du für den entsprechenden Bereich eine Ansprechperson, an die du direkt schreiben oder verlinken kannst. 

- SoGam34 - Projektleiter und generelle Anlaufstelle
- Yantron - Zustandig für das Frontend
- FabianHaag474 - Zustandig für das Backend
- 0cin05 - Texte 

## Setup 
### Unix Basierte Systeme 
- Kompiler: g++ Version 11.2
- Wt instlation
  - cmake 3.22 und höher
  - boost v1.78
  - [Installationsanleitung](https://www.webtoolkit.eu/wt/doc/reference/html/InstallationUnix.html)

### Windows 
- Hier sind die entsprechenden Mitglieder selbst noch am Einrichten 

## Pull Request 
Damit eine Pull Request gemerged wird müssen einige Voraussetzungen erfüllt sein. Die Vorausetzungen sind:
- Erfüllung der Grundsätzlichen Code-Regeln
- Ein Eintrag im Wiki

Sind die zwei Vorausetzungen gegeben stehet einem Merge nichts mehr im Weg. Yuhu!!!!

Im folgenden wir auf die einzelnen Vorausetzungen im Deteil eingegangen. 

### Erfüllung der Grundsätzliche Code-Regeln
Das Ziel der Code-Regeln ist guten und leicht verständlichen, test-und debbugbaren Code zu schaffen. Werden die Regeln nicht eingehalten, verstößt der Code wahrscheinlich gegen min. eine der zwei Ziele. Der Code ist dann das was zumindestens hier als "schlechter" Code angesehen wird und "schlechter" Code wird nicht mit main gemerged, damit andere und du selber eine leichtere Zeit haben. 

### Ein Eintrag im Wiki
Der Wiki Eintrag soll es leichter machen sich in neu Teile des Programms einzuarbeiten und die Entscheidungen die gefällt wurden nachvollziehbarer machen. Bei der Erstellung sollte erst in 2-3 Sätzen kurz erläutert werden was sich für den Spieler ändert und danach ausführlich wie das ganze Technisch umgesetzt wird.
