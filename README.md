# Ultimation

In dem Projekt wird Ultimat Tik Tak Toe als Webaplication programmiert in c++. Das [Webtoolkit (wt)](https://www.webtoolkit.eu/wt) Framework wird zum anzeigen und bearbeiten von HTTP Anfragen verwendet. 

## Grundsätsliche Code-Regeln
### Nesting
**Es wird nicht genestet!**  Mit Nesting meint man ineinander versachtelte Statments zum Beispiel  
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
Ich kann verstehen, wenn man ausversehen in so einem Code Abschnitt endet nach dem man ein Feature implementiert hat, trotzdem wird es als schlechter Code in diesem Repo angesehen und muss aus der Branche entfernt werden bevor Sie mit mein gemerged werden kann.

Wie man so was auflöst und mehr informationen gibt es [hier](https://www.youtube.com/watch?v=CFRhGnuXG-4).

### try-catch 
**Try-catch ist eine Programm interne debugging Methode und kein verbessertes if oder switch tool.** Try-catch darf benutzt werden aber nur für das wofür man es vorgesehen hat **Debugging**. Ein andere Verwendung bedeutet das die Branch nicht mit main gemerged werden darf und das einiges schief gelaufen ist infolge dessen du sehr schlechten Code hast. 

### templets 
**Verboten** An diesem Projekt arbeiten Personen die c++ lernen auf die man etwas rücksicht nehmen sollte. Zusätslich erschweren [templets](https://en.cppreference.com/w/cpp/language/templates) die nachvollziehbarkeit bei Fehlern und wenn man die Verwendung übertreibt hat keiner mehr ein überblick über das was passiert. 

### Namensgebung
Es ist ein schweres Thema versucht euch aber Mühe zu geben und Namen so zu vergeben das jemand der neu ist sofort weiß was gemeint ist. [Hilfe?](https://www.youtube.com/watch?v=-J3wNP6u5YU)
Das gleiche gilt für Funktions und Methoden Namen. Versuch einfache und sofort versändliche Namen zu vergeben. 

### Facade Pattern 
Wenn das System komplexer wird sollte der [Facade-Pattern](https://www.ionos.de/digitalguide/websites/web-entwicklung/was-ist-das-facade-pattern/) zu rate gezogen werden. 


