#include <iostream>
#include <vector>
#include <fstream>
#include "particle.hpp"
#include "verlet.hpp"

int main() {
    int N = 10;   // Número de partículas deben ser 10
    double dt = 0.001; // debería ser 0.001
    int steps = 30000; // deben ser 30 mil
    std::vector<Particle1D> particles(N);

    // condiciones iniciales
    // ejemplo para N = 5
    std::vector<double> pos_init = {0.0, 0.8, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0,7.5, 10.0 };//Esto se modifica a gusto
    for(int i = 0; i < N; i++){
        particles[i].x =pos_init[i]; 
        particles[i].v = 0.0; // es correcto
    }

    std::ofstream file("trayectoria1D.dat");
    //file << "N = " << particles.size() << "\n";

    for(int i=0; i < steps; i++){
        velocityVerlet1D(particles, dt);

        //----Escribiendo el frame ----
        file << "\n";
        //file << particles.size()<<"\n";
        file << "t = " << i*dt << "\n";

        for(size_t j = 0; j < particles.size(); j++){
            file << j << " "
                 << particles[j].x << " "
                 << 0.0 << " "
                 << 0.0 << "\n";  // z=0
        }
    }

    file.close();
    return 0;
}