/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** ExceptionTest
*/

#include <iostream>
#include "RaytracerException.hpp"

static void throw_test(void)
{
    throw Raytracer::RaytracerException("Throwing error");
}

int main(void)
{
    std::cout << "--------EXCEPTION TEST----------" << std::endl;
    try {
        throw_test();
    } catch (const std::exception &err) {
        std::cout << err.what() << std::endl;
    }
    std::cout << "--------EXCEPTION TEST----------" << std::endl;
}
