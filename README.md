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
Wie dir bereits aufgefallen ist, gibt es in diesem Repository Tests. Allgemeine Tests (Super Linter und CodeQL) und (demnächst) selbstgeschriebene Unit Tests. Damit der Code gut getestet werden kann, bin ich dir sehr dankbar, wenn du noch auf [Dependency Injektion ](https://www.youtube.com/watch?v=J1f5b4vcxCQ&pp=ygUUZGVwZW5kZW5jeSBpbmplY3Rpb24%3D) achten kannst. ** Persönlich ** finde ich macht es die Verwendung der Klassen auch einfacher, da man zu übersichtlicheren und strukturierteren Code „gezwungen“ wird.

## Personen 
Bei Fragen oder Problemen findest du für den Entsprechenden Bereich eine Ansprechperson an die du direkt schreiben  oder verlinken kannst. 

SoGam34 - Projektleiter und generelle anlaufstelle
Yantron - Zustandig für das Frontend
FabianHaag474 - Zustandig für das Backend
0cin05 - Texte 

## Setup 
Wie unser Setup aussieht findest du hier, da wir es selber noch nicht wissen, sind wir für Vorschlage offen. 

