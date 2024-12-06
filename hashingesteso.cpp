#include <iostream>

template <typename T>
class DizionarioEsteso {
private:
    static const int TABLE_SIZE = 10; // Dimensione della tabella hash
    struct Entry {
        std::string key;
        T value;
        bool isOccupied = false; // Indica se lo slot è occupato
    };

    Entry table[TABLE_SIZE]; // Tabella hash

    // Funzione hash che somma i valori ASCII dei caratteri della chiave
    int hashFunction(const std::string& key) const {
        int hash = 0;
        for (char ch : key) {
            hash += static_cast<int>(ch);
        }
        return hash % TABLE_SIZE;
    }

    // Funzione per trovare una posizione per l'inserimento in caso di collisione
    int findSlot(int index, const std::string& key= false) const {
        int i = 1;
        if (doubleHashing) {
            // Double hashing
            int hash2 = 7 - (hashFunction(key) % 7); // Funzione di secondario hashing (esempio semplice)
            int newIndex = (index + i * hash2) % TABLE_SIZE;
            while (table[newIndex].isOccupied && table[newIndex].key != key) {
                i++;
                newIndex = (index + i * hash2) % TABLE_SIZE;
            }
            return newIndex;
        } 
    }

public:
    // Metodo per aggiungere una coppia chiave-valore
    void inserisci(const std::string key, const T value = false) {
        int index = hashFunction(key);

        if (table[index].isOccupied) {
            std::cout << "Collision detected at index " << index << ". Finding new slot...\n";
            index = findSlot(index, key, doubleHashing);
        }

        table[index].key = key;
        table[index].value = value;
        table[index].isOccupied = true;
        std::cout << "Inserted key: " << key << " at index " << index << "\n";
    }

    // Metodo per cancellare una coppia dato il valore della chiave
    void cancella(const std::string key, bool doubleHashing = false) {
        int index = hashFunction(key);
        if (table[index].isOccupied && table[index].key == key) {
            table[index].isOccupied = false;
            std::cout << "Deleted key: " << key << " at index " << index << "\n";
        } else {
            std::cout << "Key " << key << " not found for deletion.\n";
        }
    }

    // Metodo per ottenere il valore associato a una chiave
    T recupera(const std::string key, bool doubleHashing = false) const {
        int index = hashFunction(key);
        if (table[index].isOccupied && table[index].key == key) {
            return table[index].value;
        }

        // Se la posizione originale è occupata, cerca nel caso di collisione
        index = findSlot(index, key, doubleHashing);
        if (table[index].isOccupied && table[index].key == key) {
            return table[index].value;
        }
        return T(); // Se la chiave non esiste, restituisce un valore di tipo T (di default 0 o vuoto)
    }

    // Metodo per verificare se una chiave è presente nel dizionario
    bool appartiene(const std::string key, bool doubleHashing = false) const {
        int index = hashFunction(key);
        if (table[index].isOccupied && table[index].key == key) {
            return true;
        }

        // Se la posizione originale è occupata, cerca nel caso di collisione
        index = findSlot(index, key, doubleHashing);
        return table[index].isOccupied && table[index].key == key;
    }

    // Metodo per stampare il contenuto del dizionario
    void stampa() const {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            if (table[i].isOccupied) {
                std::cout << "Index " << i << ": " << table[i].key << " => " << table[i].value << "\n";
            }
        }
    }
};
