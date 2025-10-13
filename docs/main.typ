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
Požární sport, s jeho hlubokými kořeny a širokou základnou především v prostředí sborů dobrovolných hasičů, představuje v České republice a okolních zemích významný sportovní i společenský fenomén. Disciplíny jako běh na 100 metrů s překážkami, štafeta 4x100 metrů a především královská disciplína – požární útok – jsou charakteristické svou dynamikou, rychlostí a vysokými nároky na precizní koordinaci celého týmu. V prostředí, kde o vítězství či porážce rozhodují setiny sekundy, hraje přesné a spolehlivé měření času naprosto klíčovou roli. Kvalitní časomíra je nejen základním předpokladem pro regulérnost soutěže, ale také nástrojem pro hodnocení výkonnosti a motivaci sportovců.

Současný trh sice nabízí řadu profesionálních časoměrných systémů, ty jsou však často finančně nákladné a jejich komplexnost přesahuje potřeby a možnosti lokálních soutěží pořádaných dobrovolnými hasiči. Na druhé straně spektra stojí jednoduchá, často amatérsky vyvinutá řešení, která mohou trpět nedostatky ve spolehlivosti, přesnosti nebo uživatelském komfortu. Chybí zde cenově dostupný, flexibilní a moderní systém, který by byl modulární a snadno přizpsobitelný specifickým potřebám jednotlivých disciplín požárního sportu, od měření startu a cíle až po detekci nástřiku terčů v požárním útoku.

Cílem této diplomové práce je proto navrhnout, implementovat a v reálných podmínkách ověřit modulární měřicí systém pro časomíru požárního sportu. Jádrem navrhovaného řešení bude využití moderní bezdrátové komunikační technologie ESP-NOW, která umožňuje rychlou a energeticky nenáročnou komunikaci mezi jednotlivými měřicími moduly a centrální jednotkou. Architektura systému bude postavena na principu decentralizovaných koncových jednotek (např. startovní pistole, fotobuňky, terče), které komunikují s centrálním hubem. Ten data agreguje a přeposílá na měřicí server, kde je zpracovává aplikace pro časoměřiče. Tento přístup zajistí vysokou flexibilitu a škálovatelnost celého systému.

Práce je rozdělena do několika logických celků. V teoretické části je provedena rešerše existujících časoměrných systémů používaných v různých sportovních odvětvích a jsou analyzovány dostupné technologie s ohledem na jejich vhodnost pro specifické podmínky požárního sportu. Praktická část se detailně věnuje návrhu architektury celého systému, včetně hardwarového osazení jednotlivých modulů a softwarového řešení. Následuje popis implementace firmwaru pro koncové měřicí moduly, software pro řídicí hub a vývoj serverové aplikace s uživatelským rozhraním pro správu závodu. Zvláštní pozornost je věnována zajištění spolehlivosti a integrity přenášených dat. V závěrečné části práce je popsán proces experimentálního testování funkčnosti systému v reálných podmínkách a jsou zhodnoceny dosažené výsledky.

Výstupem práce bude plně funkční prototyp, který představuje cenově dostupnou, spolehlivou a uživatelsky přívětivou alternativu ke stávajícím řešením a má potenciál výrazně zkvalitnit úroveň měření času na soutěžích v požárním sportu.
