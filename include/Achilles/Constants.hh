#ifndef CONSTANTS_HH
#define CONSTANTS_HH

#include "Achilles/Units.hh"

namespace achilles {

namespace Constant {
    // Fundamental constants (Exact as of pdg2019)
    constexpr double C = 2.99792458e8_m / 1_s;
    constexpr double H = 6.62607015e-34_J * 1_s;
    constexpr double HBAR = H/(2*M_PI);
    constexpr double HBARC = HBAR*C;
    constexpr double HBARC2 = HBARC*HBARC*10; // mb MeV^2
    constexpr double NAVOGADRO = 6.02214076e23; // mol^-1 
    // constexpr double HBARC = 197.3269804_fm * 1_MeV;
    // constexpr double HBARC2 = 0.3893793721_mb * 1_GeV * 1_GeV;

    // Masses
    constexpr double mp = 938.27208816_MeV;
    constexpr double mn = 939.56542054_MeV;
    constexpr double mN = (mp + mn) / 2.0;
    constexpr double AMU = 931.49410248_MeV;
    constexpr double mN2 = mN*mN;
    constexpr double mpip = 139.57018_MeV;
    constexpr double mpi0 = 134.9764_MeV;
    constexpr double meta = 548.0_MeV;
    

    // EW parameters
    constexpr double GF = 1.1663787e-5 / 1.0_GeV / 1.0_GeV;
    constexpr double MZ = 91.1876_GeV;
    constexpr double MW = 80.359_GeV;
    constexpr double GAMZ = 2.4952_GeV;
    constexpr double GAMW = 2.0895_GeV;
    constexpr double cos2w = MW*MW/MZ/MZ;
    constexpr double sin2w = 1 - cos2w;
    //const double alpha = sqrt(2.0)*MW*MW*GF*sin2w/M_PI;
    const double alpha = 1./137.;
    const double ee = sqrt(4*M_PI*alpha);
    const double cw = sqrt(cos2w);
    const double sw = sqrt(sin2w);
}

}

#endif
