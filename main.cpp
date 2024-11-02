#include <iostream>
#include <map>
#include <tuple>
#include <string>

using namespace std;
int main() {
    map<string, tuple<int, string, string>> villagerData;

    while (true) {
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

                villagerData[name] = make_tuple(friendship, species, catchphrase);
                cout << name << " added.\n";
                break;
            }
            case 2: {
                string name;
                cout << "Enter villager name to delete: ";
                cin >> name;
                villagerData.erase(name);
                cout << name << " deleted.\n";
                break;
            }
            case 3: {
                string name;
                cout << "Enter villager name to increase friendship: ";
                cin >> name;
                if (villagerData.count(name) > 0) {
                    auto& [friendship, species, catchphrase] = villagerData[name];
                    friendship = min(friendship + 1, 10);
                    cout << name << "'s friendship increased.\n";
                } else {
                    cout << name << " not found.\n";
                }
                break;
            }
            case 4: {
                string name;
                cout << "Enter villager name to decrease friendship: ";
                cin >> name;
                if (villagerData.count(name) > 0) {
                    auto& [friendship, species, catchphrase] = villagerData[name];
                    friendship = max(friendship - 1, 0);
                    cout << name << "'s friendship decreased.\n";
                } else {
                    cout << name << " not found.\n";
                }
                break;
            }
            case 5: {
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
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice.\n";
                break;
        }

        // Print the current villager data
        cout << "\nCurrent Villager Data:\n";
        for (const auto& [name, data] : villagerData) {
            const auto& [friendship, species, catchphrase] = data;
            cout << name << " [" << friendship << ", " << species << ", " << catchphrase << "]\n";
        }
    }

    return 0;
}


