#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include "particle.hpp"
#include "verlet.hpp"

int main() {
    constexpr double PI = 3.14159265358979323846;
    int N = 10;   // Número de partículas deben ser 10
    double dt = 0.001; // debería ser 0.001
    int steps = 30000; // deben ser 30 mil
    std::vector<Particle2D> particles(N);

    // condiciones iniciales
    // ejemplo para N = 5
    std::vector<double> pos_init_x(N);
    std::vector<double> pos_init_y(N);
    std::vector<double> theta(N);
    for(int i = 0; i < N; i++){
        theta[i]= 2.0 * PI * i / N;
    }
    for (int k = 0; k < N; k++){
        pos_init_x[k] = 4.0 * cos(theta[k]);
        pos_init_y[k] = 4.0 * sin(theta[k]);
    }
    //POR DEFINIR NO CORRER

    for(int i = 0; i < N; i++){
        particles[i].x =pos_init_x[i]; 
        particles[i].y =pos_init_y[i];
        particles[i].vx = 0.0; // es correcto
        particles[i].vy = 0.0;
    }

    std::ofstream file("trayectoria2Dring.dat");
    //file << "N = " << particles.size() << "\n";
    file << "t = " << 0 << "\n";
    for(int h = 0; h < N; h++){
        file << h <<" "
             << particles[h].x << " "
             << particles[h].y << " "
             << 0.0 << "\n";
    }
    for(int i=0; i < steps; i++){
        velocityVerlet2D(particles, dt);

        //----Escribiendo el frame ----
        file << "\n";
        //file << particles.size()<<"\n";
        file << "t = " << (i+1)*dt << "\n";

        for(size_t j = 0; j < particles.size(); j++){
            file << j << " "
                 << particles[j].x << " "
                 << particles[j].y << " "
                 << 0.0 << "\n";  // z=0
        }
    }

    file.close();
    return 0;
}