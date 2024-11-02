#include <iostream>
#include <map>
#include <vector>
#include <tuple>
#include <limits>

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

    if (villagerData.size() >= 10) {
        cout << "Too many villagers";
        return -1;
    }

    while (true) {
        cout << "\033[2J\033[1;1H";
        cout << "=== MENU ===";
        cout << "Choose (1-6)";
        for(int i = 1; i <= 6; i++)
            cout << i;

        int choice;
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input.\n";
            continue;
        }
        if (choice < 1 || choice > 6) {
            cout << "Invalid choice.\n";
            continue;
        }

        switch (choice) {
            case 1: {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                string name;
                getline(cin, name);
                cin.clear();
                if (villagerData.size() >= 10) {
                    cout << "Maximum number of villagers reached.\n";
                    continue;
                }

                string species, catchphrase;
                int friendship;
                
                cout << "Enter villager name: ";
                getline(cin, name);
                
                if (name.empty()) {
                    cout << "Name cannot be empty.\n";
                    continue;
                }

                cout << "Enter friendship level (0-10): ";
                if(!(cin >> friendship) || friendship < 0 || friendship > 10) {
                    cout << "Invalid friendship level.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }
                
                cout << "Enter species: ";
                cin.get(species);
                if(!isalpha(species))
                    continue;
                
                cout << "Enter catchphrase: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, catchphrase);
                if(catchphrase.empty() || catchphrase.length() > 15) {
                    cout << "Invalid catchphrase length.\n";
                    continue;
                }
                
                if(villagerData.find(name) != villagerData.end()) {
                    cout << "Villager already exists. Updating data...\n";
                }
                villagerData[name] = make_tuple(friendship, species, catchphrase);
                cout << name << " added successfully.\n";
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
            case 6:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice.\n";
                break;
        }
    }
        for (auto it = villagerData.begin(); it != villagerData.end(); it++) {
        auto [f, s, c] = it->second;
        cout << it->first << f << s << c;
    }

    for(auto v : villagerData)
        if(v.second == NULL)
            villagerData.erase(v);

    return 0;
}


