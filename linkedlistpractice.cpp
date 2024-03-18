#include <iostream>
#include <unordered_map> // Include the header for unordered_map

// Define the Animal struct
struct Animal {
    std::string name;
    std::string species;
    int age;

    Animal(std::string n, std::string s, int a) : name(n), species(s), age(a) {}
};

// Define the Zoo class to manage animals
class Zoo {
private:
    std::unordered_map<std::string, Animal*> animalMap; // Using unordered_map for constant-time access

public:
    // Constructor
    Zoo() {}

    // Destructor
    ~Zoo() {
        // Iterate through the animalMap and delete all Animal objects
        for (auto& pair : animalMap) {
            delete pair.second;
        }
    }

    // Add a new animal to the zoo
    void addAnimal(Animal* animal) {
        // Insert the animal into the unordered_map with its name as the key
        animalMap[animal->name] = animal;
    }

    // Display all animals in the zoo
    void displayAnimals() {
        std::cout << "Animals in the zoo:\n";
        // Iterate through the unordered_map and print information about each animal
        for (auto& pair : animalMap) {
            std::cout << "Name: " << pair.second->name << ", Species: " << pair.second->species << ", Age: " << pair.second->age << std::endl;
        }
    }
};

int main() {
    // Create a Zoo object
    Zoo zoo;

    // Add some animals to the zoo
    zoo.addAnimal(new Animal("Simba", "Lion", 5));
    zoo.addAnimal(new Animal("Baloo", "Bear", 8));
    zoo.addAnimal(new Animal("Shere Khan", "Tiger", 7));

    // Display all animals in the zoo
    zoo.displayAnimals();

    return 0;
}
/*Data Structure Improvement:

I replaced the linked list data structure with std::unordered_map for managing animals in the zoo. std::unordered_map provides constant-time access to elements based on their key, which in this case is the name of the animal. This improves the efficiency of adding and accessing animals in the zoo.
Constructor and Destructor:

Added a constructor and destructor to the Zoo class. The destructor ensures that memory allocated for Animal objects is properly freed when the Zoo object is destroyed, preventing memory leaks.
Adding Animals to the Zoo:

The addAnimal method now inserts the Animal object into the animalMap unordered_map using the animal's name as the key. This allows for efficient lookup and retrieval of animals based on their name.
Displaying Animals in the Zoo:

The displayAnimals method iterates through the animalMap unordered_map and prints information about each animal, including its name, species, and age.
Overall, by using std::unordered_map instead of a linked list, we've improved the efficiency of managing animals in the zoo, particularly in terms of insertion, retrieval, and deletion operations. This demonstrates how different data structures can be explored and tested to optimize performance in the "Zookeeper's Challenge" project.
*/




