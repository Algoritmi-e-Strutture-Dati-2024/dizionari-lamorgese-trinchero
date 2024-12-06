#include <iostream>

template <typename T>
class DizionarioEsteso : public Dizionario<T> {
public:
    // Metodo per cancellare una coppia dato il valore della chiave
    void cancella(const std::string key) {
        int index = hashFunction(key);

        if (table[index].isOccupied && table[index].key == key) {
            table[index].isOccupied = false;
        } else {
            std::cerr << "Key " << key << " not found for deletion.\n";
        }
    }

    // Metodo per verificare se una chiave è presente nel dizionario
    bool appartiene(const std::string key) const {
        int index = hashFunction(key);

        return (table[index].isOccupied && table[index].key == key);
    }
};
