# Ultimation

In dem Projekt wird Ultimate Tic-Tac-Toe als Webapplication programmiert in C++. Das [Webtoolkit (wt)](https://www.webtoolkit.eu/wt) Framework wird zum Anzeigen und bearbeiten von HTTP Anfragen verwendet. 

## Grundsätzliche Code-Regeln
### Nesting
**Es wird nicht genestet!**  Mit Nesting meint man ineinander versachtelte Statements zum Beispiel  
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
Ich kann verstehen, wenn man ausversehen in solchen einem Code Abschnitt endet, nach dem man ein Feature implementiert hat, trotzdem wird es als schlechter Code in diesem Repository angesehen und muss aus der Branche entfernt werden, bevor Sie mit mein gemerged werden kann.

Wie man so was auflöst und weitere Informationen gibt es [hier](https://www.youtube.com/watch?v=CFRhGnuXG-4).

### try-catch 
**Try-catch ist eine Programm interne debugging Methode und kein verbessertes if oder switch tool.** Try-catch darf benutzt werden, aber nur für das, wofür man es vorgesehen hat **Debugging**. Ein andere Verwendung bedeutet, dass die Branch nicht mit main gemerged werden darf und das einiges schief gelaufen ist, weil du sehr schlechten Code hast. 

### templates 
**Verboten** An diesem Projekt arbeiten Personen die C++ lernen auf die man etwas Rücksicht nehmen sollte. Zusätslich erschweren [templates](https://en.cppreference.com/w/cpp/language/templates) die Nachvollziehbarkeit bei Fehlern und wenn man die Verwendung übertreibt, hat keiner mehr einen Überblick. 

### Namensgebung
Es ist ein schweres Thema, versucht euch aber Mühe zu geben und Namen so zu vergeben, dass jemand der neu ist, sofort weiß was gemeint ist. [Hilfe?](https://www.youtube.com/watch?v=-J3wNP6u5YU)
Das gleiche gilt für Funktionen- und Methodennamen. Versuch einfache und sofort versändliche Namen zu vergeben. 

### Facade Pattern 
Bei der Strukturierung und Planung eines neuen Features sollte auf den Einhaltung des [Facade-Pattern](https://www.ionos.de/digitalguide/websites/web-entwicklung/was-ist-das-facade-pattern/) geachtet werden. 

Im Grunde einfache Klassen Interface, die man schnell und leicht weiß und sieht was gemacht wird, ohne wissen zu müssen, wie es funktioniert. Man könnte sagen:"Keep it simple"(für den anwender). 

### Tests 
Wie dir bereits aufgefallen ist, gibt es in diesem Repository Tests. Allgemeine Tests (cmake) und (demnächst) selbstgeschriebene Unit Tests. Damit der Code gut getestet werden kann, bin ich dir sehr dankbar, wenn du noch auf [Dependency Injektion ](https://www.youtube.com/watch?v=J1f5b4vcxCQ&pp=ygUUZGVwZW5kZW5jeSBpbmplY3Rpb24%3D) achten kannst. ** Persönlich ** finde ich macht es die Verwendung der Klassen auch einfacher, da man zu übersichtlicheren und strukturierteren Code „gezwungen“ wird.

## (Ansprech-)Personen 
Bei Fragen oder Problemen findest du für den Entsprechenden Bereich eine Ansprechperson an die du direkt schreiben oder verlinken kannst. 

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
- 3 Reviews
- Ein Eintrag im Wiki

Sind die drei Vorausetzungen gegeben stehet einem Merge nichts mehr im Weg. Yuhu!!!!

Im folgenden wir auf die einzelnen Vorausetzungen im Deteil eingegangen. 

### Erfüllung der Grundsätzliche Code-Regeln
Das Ziel der Code-Regeln ist guten und leicht verständlichen, test-und debbugbaren Code zu schaffen. Werden die Regeln nicht eingehalten verstöst der Code wahrscheinlich gegen min. eine der drei Ziele. Der Code ist dann das was zumindestens hier als "schlechter" Code angesehen wird und "schlechter" Code wird nicht mit main gemerged, damit andere und du selber eine leichtere Zeit haben. 

### 3 Reviews
Die Reviews sind dafür da um sicher zu gehen das die Code-Regeln eingehalten werden und das andere Probleme(z. B. Sicherheitslücken oder Schnittstellenkomplikationen mit anderen Klassen) und Bugs möglichst vor dem Merge behoben werden können. Warum 3? Keine Anhung, warum nicht?

### Ein Eintrag im Wiki
Der Wiki Eintrag soll es leichter machen sich in neu Teile des Programms einzuarbeiten und die Entscheidungen die gefällt wurden nachvollziehbarer zu machen. Bei der Erstellung sollte erst in 2-3 Sätzen kurz erleutert werden was sich für den Spieler ändert und danach ausführlich wie das ganze Technisch umgesetzt wird.
