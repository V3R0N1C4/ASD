# SortedArray

`SortedArray` è una struttura dati che mantiene una collezione di elementi sempre ordinata. È pensata per l'uso in C e offre operazioni tipiche:

- Mantiene gli elementi ordinati al momento dell'inserimento.
- Inserimento: inserisce l'elemento nella posizione corretta (compatta/shift degli elementi).
- Rimozione: rimuove per valore o indice e compatta l'array.
- Ricerca: ricerca binaria per trovare presenza/indice.
- Accesso: accesso per indice O(1).
- Informazioni: lunghezza e capacità, con ridimensionamento dinamico.

API C tipica:
- `sorted_array_create`
- `sorted_array_destroy`
- `sorted_array_insert`
- `sorted_array_remove`
- `sorted_array_find`
- `sorted_array_get`
- `sorted_array_size`

Complessità (tipiche):
- Ricerca: O(log n)
- Inserimento / Rimozione: O(n) worst-case
- Accesso per indice: O(1)