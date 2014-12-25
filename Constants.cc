#include "Constants.h"

const double Constants::Pi = 3.14159265358979323846264;
const double Constants::c = 2.99792458e+8;
const double Constants::Tesla_to_inner = (1.0e+4/4.8032068e-10)*0.01*(1.0e+6);
const double Constants::VoltsPerM_to_inner = 1.0/((1.6021773e-19)*(8.98755179e+9));
const double Constants::permeability = 4*3.14159265358979323846264*1.0e-007;
const double Constants::electron_mass = 0.510998910e-3;
const double Constants::electron_charge = -1.0;
const double Constants::proton_mass = 0.938272013;
const double Constants::proton_charge = +1.0;

Constants::Constants(){}

Constants::~Constants(){}
