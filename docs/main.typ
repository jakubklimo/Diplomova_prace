#import "template/template.typ": *

#show: tultemplate2.with(
  title: (
    cs: "Modulární měřicí systém pro časomíru požárního sportu", 
    en: "Modular Timing System for Firefighting Sports Competitions"
    ),
  author: "Bc. Jakub Klimo",
  author_pronouns: "masculine",
  supervisor: "Ing. Jan Kolaja, Ph.D.",
  programme: (cs: ""),
  abstract: (
    cs: "", 
    en: ""
    ),
  keywords: (
    cs: ("", ""), 
    en: ("", "")
    ),
)

#heading(level: 1, numbering: none)[Úvod]

Požární sport se v České republice, i za jejími hranicemi, těší dlouholeté tradici a široké členské základně, především mezi sbory dobrovolných hasičů. Nejde jen o sportovní disciplíny, ale je to bezesporu významný společenský fenomén, který propojuje generace a udržuje tradice. Disciplíny jako běh na 100 metrů s překážkami, štafeta 4x100 metrů a především královská disciplína – požární útok – jsou charakteristické svou dynamikou, rychlostí a vysokými nároky na precizní koordinaci celého týmu. V prostředí, kde o výsledku rozhodují setiny sekundy, je přesné měření času zcela zásadní. Kvalitní časomíra zajišťuje férovost soutěže, umožňuje objektivní srovnání výkonů a zároveň motivuje sportovce ke zlepšování.

Současný trh sice nabízí řadu profesionálních časoměrných systémů, ty jsou však často finančně nákladné a jejich komplexnost přesahuje potřeby a možnosti lokálních soutěží pořádaných dobrovolnými hasiči. Na druhé straně spektra stojí jednoduchá, často amatérsky vyvinutá řešení, která mohou trpět nedostatky ve spolehlivosti, přesnosti nebo uživatelském komfortu. Chybí zde cenově dostupný, flexibilní a moderní systém, který by byl modulární a snadno přizpsobitelný specifickým potřebám jednotlivých disciplín požárního sportu, od měření startu a cíle až po detekci nástřiku terčů v požárním útoku.

Cílem této diplomové práce je proto navrhnout, implementovat a v reálných podmínkách ověřit modulární měřicí systém pro časomíru požárního sportu. Jádrem navrhovaného řešení bude využití moderní bezdrátové komunikační technologie ESP-NOW, která umožňuje rychlou a energeticky nenáročnou komunikaci mezi jednotlivými měřicími moduly a centrální jednotkou. Systém je navržen tak, aby byl tvořen několika samostatnými měřicími jednotkami, například startovní pistolí, fotobuňkami nebo terči. Data z jednotlivých měřících jednotek proudí do centrální jednotky, která je shromažďuje, vyhodnocuje a posílá do aplikace s rozhraním pro časoměřiče. Tento přístup zajistí vysokou flexibilitu a škálovatelnost celého systému.

Práce je rozdělena do několika částí. Úvodní, teoretická část se zaměřuje na přehled existujících časoměrných systémů využívaných v různých sportech a zkoumá dostupné technologie z hlediska jejich použitelnosti pro potřeby požárního sportu. Praktická část se věnuje samotnému návrhu systému – popisuje jeho strukturu, použitý hardware jednotlivých modulů i softwarové řešení. Dále je zde uveden postup tvorby firmwaru pro měřicí jednotky, programu pro centrální zařízení a vývoje serverové aplikace s uživatelským rozhraním určeným pro obsluhu závodu. Součástí práce je také část věnovaná spolehlivosti a bezpečnosti přenášených dat. Závěr shrnuje testování systému v praxi a hodnotí dosažené výsledky.

= Analýza současných řešení v oblasti sportovní časomíry

Přesné a spolehlivé měření času je základem každé sportovní soutěže. Při návrhu moderního systému pro potřeby požárního sportu je proto důležité nejprve pochopit principy a technologie, na kterých stojí současné profesionální i amatérské časoměrné systémy. Tato kapitola se zaměřuje na přehled existujících řešení, jejich silné a slabé stránky a hodnotí, do jaké míry jsou využitelné pro vývoj modulárního, cenově dostupného a odolného systému.

Postupně se zaměříme na základní principy měření času a představíme technologie, které se ve sportovním prostředí běžně používají – od startovních pistolí a fotobuněk až po pokročilé transpondérové systémy a způsoby přenosu dat. Následně bude pozornost věnována specifickým požadavkům požárního sportu, jenž se vyznačuje vysokými nároky na odolnost zařízení, jednoduchou instalaci a možnost snadného rozšíření systému. Tyto rozdíly často způsobují, že univerzální časoměrné systémy v praxi nevyhovují. Závěrem kapitoly budou shrnuty poznatky z provedené rešerše a na jejich základě budou navrženy vhodné technologie a postupy pro další vývoj, především s důrazem na využití komunikačního protokolu ESP-NOW.

== Principy a kategorie sportovní časomíry

== Přehled technologií v časoměrných systémech

== Specifika a požadavky časomíry v požárním sportu

== Zhodnocení a výběr vhodných technologií pro navrhovaný systém