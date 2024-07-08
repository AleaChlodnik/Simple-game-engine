#include "ErrorHandling.hpp"
#include "MainMenu.hpp"

namespace Engine {

MainMenu::MainMenu()
{
    GLFWwindow* window;

    if (!glfwInit()) {
        throw GLFWInitException();
        glfwTerminate();
        return;
    }
    window = glfwCreateWindow(640, 480, "Main Menu", NULL, NULL);
    glfwMakeContextCurrent(window);

    this->_window = window;
}

MainMenu::~MainMenu()
{
    glfwDestroyWindow(this->_window);
    this->_window = nullptr;
}

} // namespace Engine