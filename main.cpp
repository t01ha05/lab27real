#include <iostream>
#include <map>
#include <vector>
#include <tuple>

using namespace std;

int main() {
    // declarations
    map<string, vector<string>> villagerColors;
    map<string, tuple<int, string, string>> villagerData;

    // insert elements into the map
    // note how the right-hand side of the assignment are the vector elements
    villagerColors["Audie"] = {"Orange", "Yellow", "Red"};
    villagerColors["Raymond"] = {"Black", "Gray", "White"};
    villagerColors.insert({"Marshal", {"Blue", "White", "Black"}});

    // access the map using a range-based for loop
    cout << "Villagers and their favorite colors (range-based for loop):" << endl;
    for (auto pair : villagerColors) {
        cout << pair.first << ": ";
        for (auto color : pair.second)
            cout << color << " ";
        cout << endl;
    }

    // access the map using iterators
    cout << "\nVillagers and their favorite colors (iterators):" << endl;
    for (map<string, vector<string>>::iterator it = villagerColors.begin(); 
                                               it != villagerColors.end(); ++it) {
        cout << it->first << ": ";
        for (auto color : it->second) {
            cout << color << " ";
        }
        cout << endl;
    }

    // delete an element
    villagerColors.erase("Raymond");

    // search for an element using .find() to avoid errors
    string searchKey = "Audie";
    auto it = villagerColors.find(searchKey);
    if (it != villagerColors.end()) {  // the iterator points to beyond the end of the map
                                       // if searchKey is not found
        cout << "\nFound " << searchKey << "'s favorite colors: ";
        for (auto color : it->second)  // range loop to traverse the value/vector
            cout << color << " ";
        cout << endl;
    } else
        cout << endl << searchKey << " not found." << endl;

    // report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << villagerColors.size() << endl;
    villagerColors.clear();
    cout << "Size after clear: " << villagerColors.size() << endl;

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
                if (friendship < 0 || friendship > 10) {
                    cout << "Invalid friendship level\n";
                    break;
                }
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
                villagerColors.erase(name);
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
        }
    }

    return 0;
}


