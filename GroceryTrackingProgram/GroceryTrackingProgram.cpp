#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>

class ItemAnalyzer {
private:
    std::unordered_map<std::string, int> itemFrequency;

public:
    // Function to count frequency of items
    std::unordered_map<std::string, int> count_frequency(const std::vector<std::string>& items) {
        std::unordered_map<std::string, int> frequency;
        for (const auto& item : items) {
            frequency[item]++;
        }
        return frequency;
    }

    // Function to print frequency as a list
    void print_frequency_list(const std::unordered_map<std::string, int>& frequency) {
        for (const auto& pair : frequency) {
            std::cout << pair.first << " " << pair.second << std::endl;
        }
    }
    //Function to write frequency to file
    void write_frequency_to_file(const std::unordered_map<std::string, int>& frequency) {
        std::ofstream file("frequency.dat");
        if (file.is_open()) {
            for (const auto& pair : frequency) {
                file << pair.first << " " << pair.second << std::endl;
            }
            file.close();
            std::cout << "Data written to frequency.dat successfully." << std::endl;
        }
        else {
            std::cout << "Unable to open frequency.dat for writing." << std::endl;
        }
    }
    // Function to print frequency as a histogram
    void print_frequency_histogram(const std::unordered_map<std::string, int>& frequency) {
        for (const auto& pair : frequency) {
            std::cout << pair.first << " ";
            for (int i = 0; i < pair.second; ++i) {
                std::cout << "*";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    std::vector<std::string> items = {
        "Spinach", "Radishes", "Broccoli", "Peas", "Cranberries", "Broccoli", "Potatoes", "Cucumbers", "Radishes",
        "Cranberries", "Peaches", "Zucchini", "Potatoes", "Cranberries", "Cantaloupe", "Beets", "Cauliflower",
        "Cranberries", "Peas", "Zucchini", "Peas", "Onions", "Potatoes", "Cauliflower", "Spinach", "Radishes",
        "Onions", "Zucchini", "Cranberries", "Peaches", "Yams", "Zucchini", "Apples", "Cucumbers", "Broccoli",
        "Cranberries", "Beets", "Peas", "Cauliflower", "Potatoes", "Cauliflower", "Celery", "Cranberries", "Limes",
        "Cranberries", "Broccoli", "Spinach", "Broccoli", "Garlic", "Cauliflower", "Pumpkins", "Celery", "Peas",
        "Potatoes", "Yams", "Zucchini", "Cranberries", "Cantaloupe", "Zucchini", "Pumpkins", "Cauliflower", "Yams",
        "Pears", "Peaches", "Apples", "Zucchini", "Cranberries", "Zucchini", "Garlic", "Broccoli", "Garlic",
        "Onions", "Spinach", "Cucumbers", "Cucumbers", "Garlic", "Spinach", "Peaches", "Cucumbers", "Broccoli",
        "Zucchini", "Peas", "Celery", "Cucumbers", "Celery", "Yams", "Garlic", "Cucumbers", "Peas", "Beets", "Yams",
        "Peas", "Apples", "Peaches", "Garlic", "Celery", "Garlic", "Cucumbers", "Garlic", "Apples", "Celery",
        "Zucchini", "Cucumbers", "Onions"
    };
    ItemAnalyzer analyzer;

    // Count frequency of items
    std::unordered_map<std::string, int> frequency = analyzer.count_frequency(items);

    // Write frequency data to file (backup)
    analyzer.write_frequency_to_file(frequency);

    while (true) {
        std::cout << "\nMenu:\n";
        std::cout << "1. Search for an item\n";
        std::cout << "2. Print frequency of all items\n";
        std::cout << "3. Print frequency as a histogram\n";
        std::cout << "4. Exit\n";

        std::string choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == "1") {
            std::string search_item;
            std::cout << "Enter the item to search for: ";
            std::cin >> search_item;
            std::unordered_map<std::string, int> frequency = analyzer.count_frequency(items);
            std::cout << "Frequency of '" << search_item << "': " << frequency[search_item] << std::endl;
        }
        else if (choice == "2") {
            std::unordered_map<std::string, int> frequency = analyzer.count_frequency(items);
            analyzer.print_frequency_list(frequency);
        }
        else if (choice == "3") {
            std::unordered_map<std::string, int> frequency = analyzer.count_frequency(items);
            analyzer.print_frequency_histogram(frequency);
        }
        else if (choice == "4") {
            std::cout << "Exiting the program..." << std::endl;
            break;
        }
        else {
            std::cout << "Invalid choice. Please enter a valid option (1-4)." << std::endl;
        }
    }

    return 0;
}