= Dokumentace k webové aplikaci
== Cíl projektu
Cílem projektu je vytvořit webovou aplikaci pro řízení a zobrazení časomíry s podporou offline režimu. Backend zajišťuje datové operace a API, frontend poskytuje uživatelské rozhraní přístupné i bez připojení k internetu.

== Technologie
- *Backend:* Node.js, Express, TypeScript
- *Database:* PostgreSQL
- *ORM:* Prisma
- *Frontend:* Vue 3 (TypeScript, Vite)
- *Offline:* 

== Architektura systému
=== Popis architektury
Architektura je rozdělena na frontend (uživatelské rozhraní postavené na Vue.js s možností offline provozu) a backend (serverová REST API v Node.js/Express s databází PostgreSQL).
Komunikace mezi částmi probíhá pomocí protokolu HTTP ve formátu JSON.
=== Havní vrstvy
- *Prezentační:* Vue.js SPA, která zajišťuje UI a interakci s uživatelem.
- *Aplikační:* Express API, které zpracovává požadavky, validuje data, řeší autentizaci a přístup k datům.
- *Datová:* PostgreSQL databáze spravovaná přes ORM (Prisma).
=== Blokové schéma
