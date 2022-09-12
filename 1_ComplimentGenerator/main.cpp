#include <iostream>
#include "vector"

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

RandomNums createRandom(int seed) {
    // Random number creation
    srand(seed);
    RandomNums nums;
    nums.num1 = rand() % 200 + 1;
    nums.num2 = rand() % 200 + 1;
    nums.num3 = rand() % 200 + 1;
    return nums;
}

RandomNums createRandom() {
    std::cout << "Please enter a number: " << std::endl;
    int seed;
    std::cin >> seed;
    return createRandom(seed);
}


void printMessage(const char *a1, const char *a2, const char *n) {
    std::cout << "You are a " << a1 << ", " << a2 << ", " << n << "." << std::endl;
}

void generateMessage(RandomNums nums) {
    // Sequence determination
    const char *a1 = firstAdjectives[(nums.num1 >= 34 && nums.num1 <= 66) + 2 * (nums.num1 > 66)];        // hehe fancy
    const char *a2 = secondAdjectives[nums.num1 > nums.num3 && nums.num3 != 120];      // Demorgan
    const char *n = nouns[(nums.num1 <= nums.num2) + (nums.num1 % 4 == 0)];
    // Output
    printMessage(a1, a2, n);
}

void runTests() {
    // Testing each individually
    std::vector<RandomNums> tests;
    tests.reserve(20);
    // First adj
    tests.push_back({33, 0, 0});     // less than 34
    tests.push_back({34, 0, 0});     // On bound 34 to 66
    tests.push_back({40, 0, 0});     // In range 34 to 66
    tests.push_back({66, 0, 0});     // On bound 34 to 66
    tests.push_back({67, 0, 0});     // Greater than 66
    // Second adj
    tests.push_back({0, 0, 120});   // 3 = 120
    tests.push_back({4, 0, 5});     // 3 > 1
    tests.push_back({5, 0, 5});     // 3 = 1
    tests.push_back({6, 0, 5});     // 3 < 1
    // Noun
    tests.push_back({3, 2, 0});     // 1 > 2
    tests.push_back({4, 4, 0});     // 1 = 2 && divs by 4
    tests.push_back({5, 5, 0});     // 1 = 2 && not divs by 4
    tests.push_back({4, 5, 0});     // 1 < 2 && divs by 4
    tests.push_back({3, 4, 0});     // 1 < 2 && not divs by 4

    for (auto el : tests) {
        generateMessage(el);
    }
}

bool test = true;
int main() {
    // Random demonstration
    generateMessage(createRandom());

    if (test) {
        // Show random works
        std::cout << "\nRandom number tests" << std::endl;
        int minN = 201;
        int maxM = -1;
        for(int i = 0; i < 1000; i++) {
            RandomNums demo = createRandom(i);
            minN = std::min(minN, int(demo.num1));
            minN = std::min(minN, int(demo.num2));
            minN = std::min(minN, int(demo.num3));
            maxM = std::max(maxM, int(demo.num1));
            maxM = std::max(maxM, int(demo.num2));
            maxM = std::max(maxM, int(demo.num3));
            if(i < 20) {
                std::cout << int(demo.num1) << ", " << int(demo.num2) << ", " << int(demo.num3) << std::endl;
            }
        }
        std::cout << "Max: " << maxM << ", Min: " << minN << std::endl;

        // Run logic tests
        std::cout << "Running tests defined in run tests function" << std::endl;
        runTests();
    }
    return 0;
}
