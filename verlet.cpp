#include "verlet.hpp"
#include <cmath>

void computeAccelerations(const std::vector<Particle>& particles,
                          std::vector<double>& acc) //Nos toca calcular por aparte las aceleraciones para no todo meterlo en el verlet
{
    int N = particles.size();

    // Trampa armónica
    for(int i = 0; i < N; i++)
        acc[i] = -particles[i].x;

    // Interacción por pares
    for(int i = 0; i < N; i++){
        for(int j = i+1; j < N; j++){

            double dx = particles[i].x - particles[j].x; // Vector relativo
            double r2 = dx*dx; // Norma cuadrado del vector relativo
            double rcut2 = 16;
            if (r2 < rcut2){
                double f = 12.0 * dx / std::pow(r2,7); // spft-core luego de la derivada da elevado a la 14
                acc[i] += f;// fuerza que ejerce j sobre i
                acc[j] -= f;// línea que hace que no tengamos cálculos duplicados, fuerza que recibe j de i por tecera ley de newton
            }
            
        }
    }
}

void velocityVerlet(std::vector<Particle>& particles, double dt)
{
    int N = particles.size();
    std::vector<double> acc(N);

    computeAccelerations(particles, acc); // Calculamos aceleración en configuración "inicial"
    for(int i = 0; i < N; i++){
        particles[i].v += 0.5 * acc[i] * dt;// afectamos la velocidad de la partícula
        particles[i].x += particles[i].v * dt;// corregimos la posición 
    }

    computeAccelerations(particles, acc); // Calculamos la aceleración con la nueva configuración de posiciones

    for(int i = 0; i < N; i++){
        particles[i].v += 0.5 * acc[i] * dt; // Nueva velocidad de la partícula
    }
}