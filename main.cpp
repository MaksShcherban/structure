    #include <iostream>
    #include <Windows.h>
    #include <string>
    using namespace std;

    struct Country
    {
        string name;
        string capital;
        string language;
        int population;
        int area;
        string monetaryUnit;
        float exchangeRate;
        string stateSystem;
    };

    void printElemArray(Country countries[], int element, int size) {
        if (element >= 0 && element < size) {
            cout << "Country: " << countries[element].name << endl;
            cout << "Capital: " << countries[element].capital << endl;
            cout << "Language: " << countries[element].language << endl;
            cout << "Population: " << countries[element].population << endl;
            cout << "Area: " << countries[element].area << endl;
            cout << "Monetary unit: " << countries[element].monetaryUnit << endl;
            cout << "Exchange rate: " << countries[element].exchangeRate << endl;
            cout << "State system: " << countries[element].stateSystem << endl;
        } else {
            cout << "Write correct element" << endl;
        }
    }

    void printAllArray(Country countries[], int size, int el) {
        for ( el; el < size; el++) {
            cout << "Country: " << countries[el].name << endl;
            cout << "Capital: " << countries[el].capital << endl;
            cout << "Language: " << countries[el].language << endl;
            cout << "Population: " << countries[el].population << endl;
            cout << "Area: " << countries[el].area << endl;
            cout << "Monetary unit: " << countries[el].monetaryUnit << endl;
            cout << "Exchange rate: " << countries[el].exchangeRate << endl;
            cout << "State system: " << countries[el].stateSystem << endl;
            cout << "----------------------------" << endl;
        }
    }

    void addElemInArray(Country*& countries, int& size) {
        Country* newCountries = new Country[size + 1];
        for (int i = 0; i < size; i++) {
            newCountries[i] = countries[i];
        }               
        cout << "Enter country name: ";
        cin.ignore();
        getline(cin, newCountries[size].name);
        cout << "Enter capital: ";
        getline(cin, newCountries[size].capital);
        cout << "Enter language: ";
        getline(cin, newCountries[size].language);
        cout << "Enter population: ";
        cin >> newCountries[size].population;
        cout << "Enter area: ";
        cin >> newCountries[size].area;
        cout << "Enter monetary unit: ";
        cin.ignore();
        getline(cin, newCountries[size].monetaryUnit);
        cout << "Enter exchange rate: ";
        cin >> newCountries[size].exchangeRate;
        cout << "Enter state system: ";
        cin.ignore();
        getline(cin, newCountries[size].stateSystem);

        delete[] countries;
        countries = newCountries;
        size++;
    }

    void sortArrayToArea(Country countries[], int size){
        for (int startIndex = 0; startIndex < size - 1; ++startIndex)
        {
            int smallestIndex = startIndex;
            for (int currentIndex = startIndex + 1; currentIndex < size; ++currentIndex)
            {
                if (countries[currentIndex].area < countries[smallestIndex].area)
                    smallestIndex = currentIndex;
            }
            swap(countries[startIndex], countries[smallestIndex]);
        }
        for ( int el = 0; el < size; el++) {
            
            cout << "Country: " << countries[el].name << endl;
            cout << "Capital: " << countries[el].capital << endl;
            cout << "Language: " << countries[el].language << endl;
            cout << "Population: " << countries[el].population << endl;
            cout << "Area: " << countries[el].area << endl;
            cout << "Monetary unit: " << countries[el].monetaryUnit << endl;
            cout << "Exchange rate: " << countries[el].exchangeRate << endl;
            cout << "State system: " << countries[el].stateSystem << endl;
            cout << "----------------------------" << endl;
        }
    }
    void sortArrayToPopulation(Country countries[], int size){
        for (int startIndex = 0; startIndex < size - 1; ++startIndex)
        {
            int smallestIndex = startIndex;
            for (int currentIndex = startIndex + 1; currentIndex < size; ++currentIndex)
            {
                if (countries[currentIndex].population < countries[smallestIndex].population)
                    smallestIndex = currentIndex;
            }
            swap(countries[startIndex], countries[smallestIndex]);
        }
        for ( int el = 0; el < size; el++) {
            
            cout << "Country: " << countries[el].name << endl;
            cout << "Capital: " << countries[el].capital << endl;
            cout << "Language: " << countries[el].language << endl;
            cout << "Population: " << countries[el].population << endl;
            cout << "Area: " << countries[el].area << endl;
            cout << "Monetary unit: " << countries[el].monetaryUnit << endl;
            cout << "Exchange rate: " << countries[el].exchangeRate << endl;
            cout << "State system: " << countries[el].stateSystem << endl;
            cout << "----------------------------" << endl;
        }
    }

    void replaceElem(Country countries[], int size) {
        int elem;
        cout << "Enter the number of the element you want to replace: ";
        cin >> elem;
        elem -= 1; // Перетворюємо введений номер у відповідний індекс масиву

        if (elem >= 0 && elem < size) {
            cout << "Enter new data for the country:" << endl;
            cout << "Enter country name: ";
            cin.ignore();
            getline(cin, countries[elem].name);
            cout << "Enter capital: ";
            getline(cin, countries[elem].capital);
            cout << "Enter language: ";
            getline(cin, countries[elem].language);
            cout << "Enter population: ";
            cin >> countries[elem].population;
            cout << "Enter area: ";
            cin >> countries[elem].area;
            cout << "Enter monetary unit: ";
            cin.ignore();
            getline(cin, countries[elem].monetaryUnit);
            cout << "Enter exchange rate: ";
            cin >> countries[elem].exchangeRate;
            cout << "Enter state system: ";
            cin.ignore();
            getline(cin, countries[elem].stateSystem);
            cout << "Element replaced successfully." << endl;
            printElemArray(countries, elem, size);
        } else {
            cout << "Invalid element number." << endl;
        }
    }

    void deleteAllElements(Country*& countries, int& size) {
        delete[] countries;  // Звільняємо пам'ять, зайняту масивом
        countries = nullptr; // Вказуємо на нуль, щоб уникнути непередбачуваної поведінки
        size = 0;            
        cout<< "Delete Succses" << endl;
    }

    void deleteElements(Country*& countries, int& size, int elem) {
        if (elem < 1 || elem > size) {
            cout << "Invalid element number." << endl;
            return;
        }
        elem -= 1; // Перетворюємо введений номер у відповідний індекс масиву
        Country* newCountries = new Country[size - 1];
        // Копіюємо всі елементи до того, який видаляємо
        for (int i = 0; i < elem; ++i) {
            newCountries[i] = countries[i];
        }
        // Копіюємо всі елементи після того, який видаляємо
        for (int i = elem + 1; i < size; ++i) {
            newCountries[i - 1] = countries[i];
        }
        delete[] countries; // Звільняємо пам'ять старого масиву
        countries = newCountries; // Вказуємо на новий масив
        size--; // Зменшуємо розмір масиву
        cout << "Element deleted successfully." << endl;
    }

    int main() {
        int size = 7;
        Country* countries = new Country[size]{
            {"Ukraine", "Kyiv", "Ukrainian", 52000000, 603628, "hrivna", 41.5, "Republic"},
            {"France", "Paris", "French", 67000000, 551695, "euro", 1.0, "Republic"},
            {"Japan", "Tokyo", "Japanese", 125800000, 377975, "yen", 144.5, "Constitutional monarchy"},
            {"Brazil", "Brasilia", "Portuguese", 213000000, 8515767, "real", 5.2, "Federal Republic"},
            {"Canada", "Ottawa", "English, French", 38000000, 9976140, "Canadian dollar", 1.4, "Constitutional monarchy"},
            {"Australia", "Canberra", "English", 25600000, 7692024, "Australian dollar", 1.5, "Constitutional monarchy"},
            {"South Africa", "Pretoria", "Afrikaans, English", 60000000, 1219090, "rand", 19.1, "Republic"}
        };
        
        bool running = true; // Змінна для управління циклом

        while (running) {
            int p_menu;
            cout << "----------------------------" << endl;
            cout << "1. Print element array" << endl;
            cout << "2. Print all elements array from a given element" << endl;
            cout << "3. Add element in array" << endl;
            cout << "4. Print and sort array to area" << endl;
            cout << "5. Print and sort array to population" << endl;
            cout << "6. Replace element in array" << endl;
            cout << "7. Remove element in index" << endl;
            cout << "8. Remove all array" << endl;
            cout << "9. Exit program" << endl;
            cout << "Print number" << endl;

            cin >> p_menu;
            switch (p_menu) {
                case 1: {
                    int elem;
                    cout << "Write element" << endl;
                    cin >> elem;
                    elem -= 1;
                    printElemArray(countries, elem, size);
                    break;
                }
                case 2: {
                    int el;
                    cout<< "Write number element: "<< endl;
                    cin >> el;
                    el -=1;
                    printAllArray(countries,size, el);
                    break;
                }
                case 3: {
                    addElemInArray(countries, size);
                    // Демонстрація нового елементу
                    cout << "Newly added element:" << endl;
                    printElemArray(countries, size - 1, size);
                    break;
                }
                case 4: {
                    sortArrayToArea(countries,size);
                break;
                }
                case 5: {
                    sortArrayToPopulation(countries,size);
                break;
                }
                case 6: {
                    replaceElem(countries, size);
                break;
                }
                case 7: {
                    int elem;
                    cout<< "Enter element for delete" << endl;
                    cin>> elem;
                    deleteElements(countries,size,elem);
                break;
                }
                case 8: {
                deleteAllElements(countries,size);
                break;
                }
                case 9: {
                    running = false; // Завершуємо цикл
                    break;
                }
                default: {
                    cout << "Invalid option, please try again." << endl;
                    break;
                }
            }
        }

        delete[] countries; // Очищення пам'яті
        return 0;
    }
