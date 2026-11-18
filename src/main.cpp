#include "raytracer/hello.hpp"
#include "math/vector.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
    std::string name = (argc > 1) ? argv[1] : "World";

    std::cout << "========================================\n";
    std::cout << raytracer::get_greeting(name) << "\n";
    std::cout << "========================================\n\n";

    std::cout << raytracer::get_project_info() << "\n\n";

    // Demonstration of our new Vector class
    raytracer::Vector v1(1.0, 2.0, 3.0);
    raytracer::Vector v2(4.0, 5.0, 6.0);
    raytracer::Vector sum = v1.add(v2);

    std::cout << "Demo Vector addition:\n";
    std::cout << "  v1 = (" << v1.x() << ", " << v1.y() << ", " << v1.z() << ")\n";
    std::cout << "  v2 = (" << v2.x() << ", " << v2.y() << ", " << v2.z() << ")\n";
    std::cout << "  v1.add(v2) = (" << sum.x() << ", " << sum.y() << ", " << sum.z() << ")\n\n";

    std::cout << "Project bootstrapped successfully! Ready for raytracing development.\n";
    return 0;
}
