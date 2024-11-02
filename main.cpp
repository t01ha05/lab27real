/*
 * Title: Villager Friendship Management
 * Description: This program manages villager data, including friendship level, species, and catchphrase,
 *              using a menu-driven interface. Users can add, delete, search, and modify friendship levels 
 *              for villagers stored in a map with a tuple data structure.
 * Author: Talha Ahmed
 * Lab: 27
 * Class: COMSC-210
 */

#include <iostream>
#include <map>
#include <tuple>
#include <string>

using namespace std;

int main() {
    // Store villager information using a map: name -> (friendship level, species, catchphrase)
    map<string, tuple<int, string, string>> villagerData;

    while (true) {
        // Display menu options to user
        cout << "\nMenu:\n"
             << "1. Add Villager\n"
             << "2. Delete Villager\n"
             << "3. Increase Friendship\n"
             << "4. Decrease Friendship\n"
             << "5. Search for Villager\n"
             << "6. Exit\n"
             << "Enter your choice: ";
        
        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                // Add a new villager with their details
                string name, species, catchphrase;
                int friendship;
                cout << "Enter villager name: ";
                cin >> name;
                cout << "Enter friendship level (0-10): ";
                cin >> friendship;
                cout << "Enter species: ";
                cin >> species;
                cout << "Enter catchphrase: ";
                cin >> catchphrase;

                // Store villager data in the map
                villagerData[name] = make_tuple(friendship, species, catchphrase);
                cout << name << " added.\n";
                break;
            }
            case 2: {
                // Remove a villager from the map
                string name;
                cout << "Enter villager name to delete: ";
                cin >> name;
                villagerData.erase(name);
                cout << name << " deleted.\n";
                break;
            }
            case 3: {
                // Increase friendship level (max 10)
                string name;
                cout << "Enter villager name to increase friendship: ";
                cin >> name;
                if (villagerData.count(name) > 0) {
                    auto& [friendship, species, catchphrase] = villagerData[name];
                    friendship = min(friendship + 1, 10);  // Ensure friendship doesn't exceed 10
                    cout << name << "'s friendship increased.\n";
                } else {
                    cout << name << " not found.\n";
                }
                break;
            }
            case 4: {
                // Decrease friendship level (min 0)
                string name;
                cout << "Enter villager name to decrease friendship: ";
                cin >> name;
                if (villagerData.count(name) > 0) {
                    auto& [friendship, species, catchphrase] = villagerData[name];
                    friendship = max(friendship - 1, 0);  // Ensure friendship doesn't go below 0
                    cout << name << "'s friendship decreased.\n";
                } else {
                    cout << name << " not found.\n";
                }
                break;
            }
            case 5: {
                // Search and display villager information
                string name;
                cout << "Enter villager name to search: ";
                cin >> name;
                if (villagerData.count(name) > 0) {
                    auto& [friendship, species, catchphrase] = villagerData[name];
                    cout << "Villager details:\n"
                         << name << " [" << friendship << ", " << species << ", " << catchphrase << "]\n";
                } else {
                    cout << name << " not found.\n";
                }
                break;
            }
            case 6:
                // Exit the program
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice.\n";
                break;
        }

        // Display all villagers and their information after each operation
        cout << "\nCurrent Villager Data:\n";
        // Loop through map using structured binding
        for (const auto& [name, data] : villagerData) {
            const auto& [friendship, species, catchphrase] = data;
            cout << name << " [" << friendship << ", " << species << ", " << catchphrase << "]\n";
        }
    }
} 


