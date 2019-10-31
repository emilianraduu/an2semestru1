# Simple Web Server

Proiect la materia Retele de Calculatoare ce consta intr-un server web implementat prin socketi ce rezolva cerintele clientilor in mod concurent.

## Read Me!

Instructiuni pentru folosirea, testarea si compilarea proiectului.

### Inainte de a compila!

Inainte de a compila trebuie facute configurari in fisierul config.txt. 
Cel mai important aspect este modificarea adresei serverului (unde o sa se afle fisierele ce vor fi accesate de browser).
In fisierul config.txt modificati linia 2:

```
Locatie: /Users/Emilian/Documents/site 
```
Dupa textul "Locatie: " introduceti adresa absoluta de pe sistemul dumneavoastra ca in exemplul de mai sus.
Este foarte important ca la finalul adresei sa fie un spatiu!
Programul nu va rula daca adresa nu este cea de pe sistemul pe care va rula serverul / daca nu este un spatiu la finalul liniei.

Urmatoarea linie ce poate fi modificata este:
```
Port: 8001
```

Unde portul poate fi orice alta valoare. Poate fi lasat nemodificat, insa trebuie specificat in adresa din browser pentru a se putea accesa sub forma :
```
localhost:8001 | localhost:<Port>
```

Alte modificari:
```
Index index.html 
```
(un spatiu la sfarsitul liniei) daca se doreste ca pagina default pe care o furninzeaza serverul sa fie alta.
Se va modifica "index.html" cu orice alt fisier cu extensia .txt sau .html
### Compilare

1. Compilare

```
$gcc simpleWeb.c -o simpleWeb.bin
```

2. Rulare

```
$./simpleWeb.bin
```


3. Conectare (in browser)

```
localhost:<Port>
```

## Verificarea functionarii

Serverul accepta apelul de fisiere .html/.txt.
Daca este introdusa o adresa dupa port
```
localhost:8001/index.html
```
Serverul va furniza fisierul specificat (daca exista, in caz contrar va afisa eroarea 404), iar daca nu exista specificat nici un fisier serverul va furniza fisierul default stabilit in config.txt.

Se mai pot testa urmatoarele fisiere:
```
/google.png | /page.html | /1.txt | /bg.jpg 
```
Insa se mai pot adauga orice alte fisiere .html, .txt, .png, .jpg in folderul "site" (sau orice alt nume definit in config.txt la "Locatie:")

## Realizat cu

* [VSC](https://code.visualstudio.com) - IDE-ul utilizat
* [C](http://www.cplusplus.com) - limbajul de programare
* [HTTP 1.1 Protocol](https://www.w3.org/Protocols/rfc2616/rfc2616.html) - protocolul de transfer

## Autor

* **Radu Emilian** - *Simple Web Server*
# SimpleWebServer
