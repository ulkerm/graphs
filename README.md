[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/uOQJyWdv)
# SWO3-Übungen - WS 2023/24 - Übung 3

Stellen Sie für jede Aufgabe ein passendes `Makefile` oder `CMakeLists.txt` zur Verfügung. Idealerweise nutzen Sie dazu Standard-Targets wie `make all`, `make run` oder `make test`.

## 1. Repräsentation von Graphen (src/graphs)

Hinweis: Es werden nur Graphen mit einer fixen Anzahl von n Knoten betrachtet, d.h. die Anzahl der Knoten kann nicht wachsen oder schrumpfen und muss von Anfang an bekannt sein. Als “Knotennamen” können deshalb die ganzzahligen Werte von (z.B.) 0 bis n-1 dienen.

**a.** Entwickeln Sie einen abstrakten Datentyp (in Form eines Moduls `graph_m.c`, wobei m für matrix steht) zur Verwaltung eines gewichteten gerichteten Graphen mit n Knoten, wobei intern zur Repräsentation eine Adjazenzmatrix verwendet wird.

**b.** Entwickeln Sie einen abstrakten Datentyp (in Form eines Moduls `graph_l.c`, wobei l für list steht) zur Verwaltung eines gewichteten gerichteten Graphen mit n Knoten, wobei zur Repräsentation intern eine Adjazenzliste verwendet wird.

Die Mindestfunktionalität umfasst in beiden Fällen:

1. das Erzeugen eines neuen Graphen mit dem Parameter n,
2. das Eintragen neuer Kanten zwischen Knoten mit Gewicht w,
3. das Abfragen des Gewichtes zwischen zwei Knoten s und t,
4. das Löschen von Kanten zwischen Knoten s und t,
5. das Ausgeben der internen Darstellung des Graphen in geeigneter Form und
6. das Freigeben eines Graphen.

Achten Sie darauf, dass beide Datenstrukturen „austauschbar“ sind – indem beide Implementierungen die gleiche Schnittstelle `graph.h` erfüllen und durch binden („linken“) die eine oder die andere Implementierung eingebunden werden kann.

Schreiben Sie ein Testprogramm für beide Datentypen, in dem Sie den Graphen aus der Abbildung unten aufbauen und die interne Darstellung ausgeben. Sie können dabei beliebige positive Kantengewichte annehmen. Testen Sie auch die Möglichkeit, eine Kante zu löschen.

![Graph](/doc/graph.png)

So könnte die Schnittstelle in `graph.h` anfangs aussehen. Ein wichtiges Detail dabei ist, dass das `struct graph` nur deklariert, jedoch nicht definiert wird, was Sie dann in der konkreten Implementierung erst machen können.

```c
struct graph;
typedef struct graph graph_t;

graph_t* graph_create(int n);
void graph_free(graph_t *g);

void graph_insert_edge(graph_t *g, int source, int target, double weight);
void graph_remove_edge(graph_t *g, int source, int target);

bool graph_has_edge(graph_t *g, int source, int target)
double graph_get_weight(graph_t *g, int source, int target);

void graph_print(graph_t *g);
```

## 2. Graphen-Algorithmen (ebenfalls src/graphs)

Erweitern Sie die Schnittstelle in `graph.h` sowie beide Implementierungen nach eigenem Ermessen um die Realisierung der nun folgenden weiteren Funktionalität implementierungs unabhängig zu ermöglichen, also nur abhängig von der allgemeinen Schnittstelle `graph.h`. Halten Sie dazu diese Schnittstelle möglichst klein und allgemein.

Erstellen Sie zwei neue Dateien `graph_algs.h` und `graph_algs.c` in der Sie folgende Funktionen zur Verfügung stellen:

**a.** Erzeugung des invertierten Graphen (Alle Kanten werden umgedreht)

**b.** Berechnen von Statistiken zum Graphen wo der Grad, also die Anzahl Verbindungen pro Knoten, analysiert wird:

- minimaler Grad,
- maximaler Grad,
- durchschnittlicher Grad.

**c.** Ausgeben eines ASCII-Histogramms mit der Anzahl der Vorkommen der einzelnen Grade.

Die Schnittstelle dieser Algorithmen könnte z.B. so aussehen:

```c
graph_t* graph_invert(graph_t *g);

int graph_min_degree(graph_t *g);
int graph_max_degree(graph_t *g);
double graph_avg_degree(graph_t *g);

void graph_print_degree_histogram(graph_t *g);
```

### Hinweise

1. Geben Sie für alle Ihre Lösungen immer eine Lösungsidee an.
2. Dokumentieren und testen Sie Ihre Programme ausführlich.
