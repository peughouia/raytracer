#include "raytracer/hello.hpp"
#include <sstream>

namespace raytracer {

std::string get_greeting(const std::string& name) {
    return "Hello, " + name + "! Welcome to the Raytracer project.";
}

std::string get_project_info() {
    std::ostringstream oss;
    oss << "Raytracer v0.1.0\n"
        << "Standard: C++20\n"
        << "Architecture: Cross-platform (Linux / macOS / Windows)";
    return oss.str();
}

} // namespace raytracer
