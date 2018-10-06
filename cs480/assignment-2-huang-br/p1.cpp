#include <iostream>
int main() {
double circle_area;
double circle_circum;
double pi;
double r;
double sphere_surf_area;
circle_area = pi*r*r;
circle_circum = pi*2*r;
pi = 3.1415;
r = 8.0;
sphere_surf_area = 4*pi*r*r;
std::cout << "circle_area: " << circle_area<< std::endl;
std::cout << "circle_circum: " << circle_circum<< std::endl;
std::cout << "pi: " << pi<< std::endl;
std::cout << "r: " << r<< std::endl;
std::cout << "sphere_surf_area: " << sphere_surf_area<< std::endl;
return 0;
}
