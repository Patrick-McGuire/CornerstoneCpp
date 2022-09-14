#include <iostream>
#include "vector"

/**
 * Struct to allow passing sets of random numbers around, and allow for hardcoding for debug
 */
struct RandomNums {
    uint8_t num1 = 0;
    uint8_t num2 = 0;
    uint8_t num3 = 0;
};

// Constants
// Possible variable outputs
const char *firstAdjectives[] = {"POWERFUL", "SPARKLING", "MAJESTIC"};
const char *secondAdjectives[] = {"BRILLIANT", "RESILIENT"};
const char *nouns[] = {"PIRATE", "MASTERMIND", "CREATION"};

/**
 * Create 3 random numbers based on a seed
 * @param seed Random seed
 * @return RandomNums struct containing the numbers
 */
RandomNums createRandom(int seed) {
    // "Random" number creation
    // Seed from the given seed
    srand(seed);
    // Generate the random numbers and save them
    RandomNums nums;                    // Struct defined above
    nums.num1 = rand() % 200 + 1;       // (1 - 200)
    nums.num2 = rand() % 200 + 1;
    nums.num3 = rand() % 200 + 1;
    return nums;
}

/**
 * Asks the user for a seed and then create 3 random numbers
 * @return RandomNums struct containing the numbers
 */
RandomNums createRandom() {
    // Get the user's input
    std::cout << "Please enter a number: " << std::endl;
    int seed;
    std::cin >> seed;
    // Do the actual number generation
    return createRandom(seed);
}

/**
 * Prints out the desired output for the assigment based on the 3 desired words
 * @param a1 Adjective 1
 * @param a2 Adjective 2
 * @param n Noun
 */
void printMessage(const char *a1, const char *a2, const char *n) {
    // This just prints all 3 words inside of the provided sentence format
    std::cout << "You are a " << a1 << ", " << a2 << ", " << n << "." << std::endl;
}

/**
 * Determines and prints the desired assignment logic
 * @param nums Random numbers to base logic on
 */
void generateMessage(RandomNums nums, bool debug = false) {
    // Sequence determination
    /*
     * I am using a neat trick here to avoid using if statements, though it's a bit harder to follow
     * I declared a array of strings for each of the sets of possible words (at top)
     * The index in the can be expressed as the sum of the boolean conditions times there index for each step. Ex:
     * 0 * (boolean condition for index 0) + 1 * (boolean condition for index 1) + 2 * (boolean condition for index 2)
     *
     * I did this just for fun, it's not necessarily something I would do in real code, but it's a neat exercise
     */
    const char *a1 = firstAdjectives[(nums.num1 >= 34 && nums.num1 <= 66) + 2 * (nums.num1 > 66)];        // hehe fancy
    const char *a2 = secondAdjectives[nums.num1 > nums.num3 && nums.num3 < 120];      // de morgan's law
    const char *n = nouns[(nums.num1 <= nums.num2) + (nums.num1 % 4 != 0 && nums.num1 <= nums.num2)];
    // Print
    if (debug) {
        std::cout << '(' << int(nums.num1) << ", " << int(nums.num2) << ", " << int(nums.num3) << "): ";
    }
    printMessage(a1, a2, n);
}

/**
 * Runs test cases to show that my code works
 */
void runTests() {
    // This runs a bunch of test cases to show that the code does in fact work

    // Show random number generation works
    std::cout << "\nRandom number tests" << std::endl;
    int minN = 201;
    int maxM = -1;
    // Calculate min/max from a bunch of numbers
    for (int i = 0; i < 10000; i++) {
        RandomNums demo = createRandom(i);          // Using i as the seed here though I don't really need to
        // Track min/max of all values
        minN = std::min(minN, int(demo.num1));
        minN = std::min(minN, int(demo.num2));
        minN = std::min(minN, int(demo.num3));
        maxM = std::max(maxM, int(demo.num1));
        maxM = std::max(maxM, int(demo.num2));
        maxM = std::max(maxM, int(demo.num3));
        // Only print the first 20 to prevent flooding the screen
        if (i < 20) {
            std::cout << int(demo.num1) << ", " << int(demo.num2) << ", " << int(demo.num3) << std::endl;
        }
    }
    // Print result of test
    std::cout << "Max: " << maxM << ", Min: " << minN << std::endl;

    // Run logic tests
    std::cout << "Running tests defined in run tests function" << std::endl;

    // Testing set of words individually
    // Here we are just defining a bunch of test cases, only testing one of the sets of words at a time
    std::vector<RandomNums> tests;      // Store all test cases
    tests.reserve(14);               // I am a stickler for memory
    // First adj test cases
    tests.push_back({33, 0, 0});     // less than 34
    tests.push_back({34, 0, 0});     // On bound 34 to 66
    tests.push_back({40, 0, 0});     // In range 34 to 66
    tests.push_back({66, 0, 0});     // On bound 34 to 66
    tests.push_back({67, 0, 0});     // Greater than 66
    // Second adj test cases
    tests.push_back({0, 0, 120});   // 3 On bound 120
    tests.push_back({0, 0, 200});   // 3 > 120
    tests.push_back({4, 0, 5});     // 3 > 1
    tests.push_back({5, 0, 5});     // 3 = 1
    tests.push_back({6, 0, 5});     // 3 < 1
    // Noun test cases
    tests.push_back({3, 2, 0});     // 1 > 2
    tests.push_back({4, 4, 0});     // 1 = 2 && divs by 4
    tests.push_back({5, 5, 0});     // 1 = 2 && not divs by 4
    tests.push_back({4, 5, 0});     // 1 < 2 && divs by 4
    tests.push_back({3, 4, 0});     // 1 < 2 && not divs by 4

    // Run all of the cases
    for (auto el : tests) {
        generateMessage(el, true);
    }
}


int main() {
    // Random demonstration
    generateMessage(createRandom());

    // Run test cases if desired
    runTests();
    return 0;
}
