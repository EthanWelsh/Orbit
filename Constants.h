#ifndef CONSTANTS_ORBIT
#define CONSTANTS_ORBIT

class Constants {
public:
  Constants();
  ~Constants();

  //Pi
  const static double PI;

  //Speed of light in m/sec
  const static double c;

  //Magnetic field strength
  //To convert from Tesla to H/e in 1/m^2
  const static double Tesla_to_inner;

  //Convert from Volts/m to E in 1/m^2
  const static double VoltsPerM_to_inner;

  //Magnetic permeability
  const static double permeability;

  //Electron mass in GeV
  const static double electron_mass;

  //Charge of electron
  const static double electron_charge;

  //Proton mass in GeV
  const static double proton_mass;

  //Charge of proton
  const static double proton_charge;
}

#endif
