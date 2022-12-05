
#ifndef __EQUATIONS_HPP__
#define __EQUATIONS_HPP__

#include <functional>

float dichotomy(std::function<float(float)> f, float a, float b, float epsilon = .0001f);
float newton(std::function<float(float)> f, std::function<float(float)> fd, float x, float epsilon = .0001f);
float bruteForce(std::function<float(float)> f, float a, float b, float step = .0002f);

#endif
