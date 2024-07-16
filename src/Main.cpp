#include "Config.hpp"
#include "ErrorHandling.hpp"
#include "MainMenu.hpp"

unsigned int makeModule(const std::string &filePath, unsigned int moduleType)
{
    std::ifstream file;
    std::stringstream bufferedLines;
    std::string line;

    file.open(filePath);

    if (!file.is_open()) {
        throw Engine::FileException();
    }

    while (std::getline(file, line)) {
        bufferedLines << line << std::endl;
    }

    std::string source = bufferedLines.str();
    const char *shaderSource = source.c_str();

    bufferedLines.str("");
    file.close();

    unsigned int shaderModule = glCreateShader(moduleType);
    glShaderSource(shaderModule, 1, &shaderSource, NULL);
    glCompileShader(shaderModule);

    int status;
    glGetShaderiv(shaderModule, GL_COMPILE_STATUS, &status);
    if (!status) {
        char errorLog[1024];
        glGetShaderInfoLog(shaderModule, 1024, NULL, errorLog);
        std::cout << "Error! Shader Module compilation failed:\n" << errorLog << std::endl;
    }
    return shaderModule;
}

unsigned int makeShader(const std::string &vertFilePath, const std::string &fragFilePath)
{
    std::vector<unsigned int> modules;

    modules.push_back(makeModule(vertFilePath, GL_VERTEX_SHADER));
    modules.push_back(makeModule(fragFilePath, GL_FRAGMENT_SHADER));

    unsigned int shader = glCreateProgram();

    for (unsigned int shaderModule : modules) {
        glAttachShader(shader, shaderModule);
    }

    glLinkProgram(shader);

    int status;
    glGetProgramiv(shader, GL_LINK_STATUS, &status);
    if (!status) {
        char errorLog[1024];
        glGetProgramInfoLog(shader, 1024, NULL, errorLog);
        std::cout << "Error! Shader linkage failed:\n" << errorLog << std::endl;
    }

    for (unsigned int shaderModule : modules) {
        glDeleteShader(shaderModule);
    }
    return shader;
}

int main(void)
{
    try
    {
        Engine::MainMenu mainMenu;
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            glfwTerminate();
            return 84;
        }

        glClearColor(0.5f, 0.5f, 0.75f, 1.0f);

        int width, height;
        glfwGetFramebufferSize(mainMenu._window, &width, &height);
        glViewport(0, 0, width, height);

        unsigned int shader = makeShader("src/shaders/vertex.txt", "src/shaders/fragment.txt");

        while (!glfwWindowShouldClose(mainMenu._window))
        {
            glfwPollEvents();
            glClear(GL_COLOR_BUFFER_BIT);
            glUseProgram(shader);
            glfwSwapBuffers(mainMenu._window);
        }
        glDeleteProgram(shader);
        glfwTerminate();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 84;
    }
    return 0;
}
