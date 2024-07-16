#include "Config.hpp"
#include "ErrorHandling.hpp"
#include "MainMenu.hpp"

int main(void)
{
    try
    {

        std::ifstream file;
        std::string line;
        file.open("Engine/src/shaders/vertex.txt");
        while (std::getline(file, line))
        {
            std::cout << "line: " << line << std::endl;
        }

        Engine::MainMenu mainMenu;
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            glfwTerminate();
            return 84;
        }

        glClearColor(0.5f, 0.5f, 0.75f, 1.0f);

        while (!glfwWindowShouldClose(mainMenu._window))
        {
            glfwPollEvents();
            glClear(GL_COLOR_BUFFER_BIT);
            glfwSwapBuffers(mainMenu._window);
        }
        glfwTerminate();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 84;
    }
    return 0;
}
