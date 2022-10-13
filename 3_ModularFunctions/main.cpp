#include <iostream>
#include <cmath>

/**
 * Track constants for associating user input with shape types
 */
enum Shape : int {
    CUBE = 0,
    PYRAMID = 1,
    SPHERE = 2,
    CONE = 3,
    CYLINDER = 4,
};

/**
 * Calculate the volume of a cube
 * @param h side length
 * @param w  side length
 * @return volume
 */
double cubeVolume(double h, double w);

/**
 * Calculate the volume of a pyramid
 * @param h height
 * @param w base length
 * @return volume
 */
double pyramidVolume(double h, double w);

/**
 * Calculate the volume of a sphere
 * @param h diameter
 * @param w diameter
 * @return volume
 */
double sphereVolume(double h, double w);

/**
 * Calculate the volume of a cone
 * @param h height
 * @param w diameter
 * @return volume
 */
double coneVolume(double h, double w);

/**
 * Calculate the volume of a cylinder
 * @param h height
 * @param w diameter
 * @return volume
 */
double cylinderVolume(double h, double w);

int main() {
    // Variable declarations
    double height, width, volume = 0;
    int type;

    // Request w/h inputs
    std::cout << "Enter width: " << std::endl;
    std::cin >> width;
    std::cout << "Enter height: " << std::endl;
    std::cin >> height;
    std::cout << "Width: " << width << ", Height: " << height << std::endl;
    // Request type
    std::cout << "Enter shape type (0 = cube, 1 = pyramid, 2 = sphere, 3 = cone, 4 = cylinder): " << std::endl;
    std::cin >> type;

    // Type cases
    switch (type) {
        case CUBE:
            // If it's a CUBE
            volume = cubeVolume(height, width);
            break;
        case PYRAMID:
            // If it's a PYRAMID
            volume = pyramidVolume(height, width);
            break;
        case SPHERE:
            // If it's a SPHERE
            volume = sphereVolume(height, width);
            break;
        case CONE:
            // If it's a CONE
            volume = coneVolume(height, width);
            break;
        case CYLINDER:
            // If it's a CYLINDER
            volume = cylinderVolume(height, width);
            break;
        default:
            // Bad input
            std::cout << "Invalid shape type :(" << std::endl;
    }

    // Print out the result
    std::cout << "Volume: " << volume << std::endl;
    return 0;
}


double cubeVolume(double h, double w) {
    return w * h * h;       // Cube volume formula
}

double pyramidVolume(double h, double w) {
    return (w * w * h) / 3.0;       // Pyramid volume formula
}

double sphereVolume(double h, double w) {
    return (4.0 / 3.0) * M_PI * (w / 2) * (w / 2) * (w / 2);       // Sphere volume formula
}

double coneVolume(double h, double w) {
    return (M_PI * (w / 2) * (w / 2) * h) / 3;       // Cone volume formula
}

double cylinderVolume(double h, double w) {
    return M_PI * (w / 2) * (w / 2) * h;       // Cylinder volume formula
}