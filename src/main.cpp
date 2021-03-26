#include <iostream>

#include "VulkanTest.h"

int main() {

    VulkanTest test;

    try {
        test.start();
    } catch (const std::exception& ex) {
        std::cerr << ex.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;

}