# Unreal Engine – Lernportfolio

Eine Sammlung kleiner Unreal-Engine-Übungsprojekte rund um interaktive Objekte einer Küchen- und Restaurantumgebung.

**Verwendete Version:** Unreal Engine 5.8.4

> **Projektstatus:** Lernprojekt im Aufbau. Die Sammlung zeigt einzelne Funktionen aus meinen aktuellem Lernstand –> kein fertiges Spiel. Weitere Medien und Dokumentationen werden ergänzt.

## Projekte im Überblick

| Bereich | Inhalt | Dokumentation |
| --- | --- | --- |
| Interaktions-Interface | Gemeinsame Schnittstelle für Interaktionen mit Actors und ihren Komponenten | [BPI_Interactable](Interact/ReadMe_Interact.md) |
| Fritteuse | Bedienbare Schalter, Kontrollleuchten, Türen, Heizstäbe und Fettablasser | [BP_Fritteuse](Fritteuse/ReadMe_Fritteuse.md) |
| Fritteusenkorb | Aufnehmen, Tragen und Ablegen mit Physik- und Kollisionssteuerung sowie ergänzendem Gittermaterial | [BP_FritteuseKorb](FritteusenKorb/ReadMe_FritteusenKorb.md) |
| Kühlschrank | Zwei bedienbare Türen, Temperaturanzeige und eine einfache Temperaturberechnung in C++ | [BP_DoppelKuehlSchrank](Kuehlschrank/ReadMe_Kuehlschrank.md) |
| Spülmaschine | Animierte Haubenbewegung und rotierende Waschblätter | [BP_SpuelMaschine](Spuelmaschine/ReadMe_Spuelmaschine.md) |

## Technische Schwerpunkte

- **Blueprints:** Ereignisgesteuerte Logik, Bedingungen und Zustandswechsel
- **Interfaces:** Einheitlicher Einstiegspunkt über `BPI_Interactable` und `Interact`
- **Komponenten:** Unterschiedliche Bauteile eines Actors erkennen und gezielt ansteuern
- **Animation:** Bewegungen mit Timelines, Interpolation und eigenen Drehpunkten
- **Physik:** Kollision und Physiksimulation beim Aufnehmen und Ablegen umschalten
- **Materialien:** Gittertextur mit Alphamaske und skalierten UV-Koordinaten
- **C++ und Blueprint:** Temperaturberechnung in C++ mit im Blueprint zugänglichen Variablen

## Einblick in den C++-Anteil

Beim Kühlschrank werden Blueprint und C++ kombiniert: Der Blueprint übernimmt die Interaktion, Türanimation und Temperaturanzeige. Die Klasse `ALogic_Kuehlschrank` berechnet die Temperaturänderung abhängig vom übergebenen Türzustand.

Die Implementierung sammelt Frame-Zeit über `DeltaTime`, passt die Temperatur in Intervallen an und begrenzt die Werte auf einen vorgegebenen Bereich.

- [C++-Implementierung](Kuehlschrank/Logic_Kuehlschrank.cpp)
- [Klassendeklaration und Blueprint-Variablen](Kuehlschrank/Logic_Kuehlschrank.h)
- [Ausführliche Kühlschrank-Dokumentation](Kuehlschrank/ReadMe_Kuehlschrank.md)

## Aufbau des Repositories

- [Interact](Interact/) – Dokumentation des gemeinsamen Blueprint-Interfaces
- [Fritteuse](Fritteuse/) – Blueprint-Export und Dokumentation der Fritteuse
- [FritteusenKorb](FritteusenKorb/) – Blueprint- und Material-Export sowie Dokumentation des Korbs
- [Kuehlschrank](Kuehlschrank/) – Blueprint-Export, C++-Dateien und Dokumentation des Kühlschranks
- [Spuelmaschine](Spuelmaschine/) – Blueprint-Export und Dokumentation der Spülmaschine

Die jeweiligen Projektbeschreibungen enthalten Screenshots und Abschnitte für Videos. Noch nicht verfügbare Videos sind als Platzhalter gekennzeichnet.

## Was dieses Repository zeigt

Mein Ziel ist es, kleine Funktionen umzusetzen, ihre Zusammenhänge zu verstehen und die Ergebnisse nachvollziehbar zu dokumentieren. Im Mittelpunkt stehen interaktive Abläufe, die Verwaltung von Zuständen und das Zusammenspiel verschiedener Unreal-Engine-Bausteine.

Die Beispiele sind bewusst überschaubar. Sie sollen meinen bisherigen Lernfortschritt sichtbar machen und eine Grundlage für weitere Übungen sowie Gespräche im Rahmen meiner Praktikumssuche bieten.

## Verwendung und Grenzen

Dieses Repository ist eine **Portfolio-Dokumentation**, kein vollständiges, direkt startbares Unreal-Engine-Projekt.

Die Text-Exporte machen Blueprint- und Materialgraphen lesbar, ersetzen aber nicht die ursprünglichen Assets oder eine vollständige Projektstruktur. Für eine lauffähige Übernahme werden unter anderem die passenden Meshes, Texturen, das Interaktionssystem und die jeweiligen Abhängigkeiten benötigt. Details stehen in den einzelnen Projektbeschreibungen.

Die C++-Dateien gehören zu einem Unreal-Modul mit dem Export-Makro `SPIELWIESE_API`. Sie sind keine eigenständig ausführbare Anwendung.
