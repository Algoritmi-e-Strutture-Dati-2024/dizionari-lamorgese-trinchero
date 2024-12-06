int main() {
    // Test del dizionario esteso con linear probing
    DizionarioEsteso<int> dizionario;

    dizionario.inserisci("chiave1", 17);
    dizionario.inserisci("chiave2", 33);
    dizionario.inserisci("chiave3", 77);

    std::cout << "Recupera chiave1: " << dizionario.recupera("chiave1") << "\n";
    std::cout << "Appartiene chiave2? " << (dizionario.appartiene("chiave2") ? "Sì" : "No") << "\n";

    dizionario.cancella("chiave2");

    std::cout << "Appartiene chiave2 dopo cancellazione? " << (dizionario.appartiene("chiave2") ? "Sì" : "No") << "\n";
    
    // Aggiunta di una collisione
    dizionario.inserisci("chiave4", 88);
    dizionario.inserisci("4chiave", 89);

    dizionario.stampa();

    return 0;
}
