#ifndef VERLET_HPP
#define VERLET_HPP

#include <vector>
#include "particle.hpp"
void computeAccelerations(const std::vector<Particle>& particles,
                          std::vector<double>& acc);
void velocityVerlet(std::vector<Particle> &particles, double dt);
//std::vec..bla bla bla es el sistema de N partículas, & se pasa por ref no se copia memoria Estos es la interfaz del integrador
#endif