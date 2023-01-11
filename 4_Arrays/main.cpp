#include <iostream>
#include <string>
#include <algorithm>

std::string &modify(std::string &name);     // Not really necessary
std::string &modify(std::string &name) {
    // Check if there is a vowel in the string. This is kinda fancy, so trust me, it works!
    if (std::find_if(name.begin(), name.end(), [](char c) { return (0x2208222 >> (c & 0x1f)) & 0x1; }) == name.end())
        // Populate a random vowel if no vowels are present in the code
        name[rand() % name.size()] = "aeiouy"[rand() % 6];
    return name;
}

int main() {
    // Seed random number generator
    srand(time(nullptr));
    // Declare variables
    char b = 0;
    std::string name;
    // Get a valid input
    while (!(b == 'l' || b == 's')) {
        std::cout << "enter l or s to generate name long or short word\n";
        std::cin >> b;
    }
    // Populate the string with random charters
    for (int i = 0; i < (b == 'l' ? 6 : (b == 's' ? 3 : 0)); i++)
        name += (char) (rand() % 26 + 'a');     // Random ascii charter between a and z
    // Print out the name, and print out the modified name to ensure presence of a vowel
    std::cout << "original: " << name << std::endl << "modified: " << modify(name) << std::endl;
    return 0;
}