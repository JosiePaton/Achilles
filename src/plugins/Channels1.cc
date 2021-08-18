#include "plugins/Channels1.hh"
#include "ATOOLS/Phys/Flavour.H"

using namespace PHASIC;
using namespace ATOOLS;

void C1_0::GeneratePoint(std::vector<Vec4D> &p, const std::vector<double> &ran) const {
    CE.TChannelMomenta(p[0],p[1],p[2],p[3],s2,s3,0.,m_alpha,m_ctmax,m_ctmin,m_amct,0,ran[0],ran[1]);
}

double C1_0::GenerateWeight(const std::vector<Vec4D> &p, std::vector<double> &ran) const {
    double wt = CE.TChannelWeight(p[0],p[1],p[2],p[3],0.,m_alpha,m_ctmax,m_ctmin,m_amct,0,ran[0],ran[1]);
    if (wt!=0.) wt = 1.0/wt/pow(2.*M_PI,2*3.-4.);
    return wt;
}

void C1_1::GeneratePoint(std::vector<Vec4D> &p, const std::vector<double> &ran) const {
    double tmass201 = Flavour((kf_code)(23)).Mass();
    CE.TChannelMomenta(p[0],p[1],p[2],p[3],s2,s3,tmass201,m_alpha,m_ctmax,m_ctmin,m_amct,0,ran[0],ran[1]);
}

double C1_1::GenerateWeight(const std::vector<Vec4D> &p, std::vector<double> &ran) const {
    double tmass201 = Flavour((kf_code)(23)).Mass();
    double wt = CE.TChannelWeight(p[0],p[1],p[2],p[3],tmass201,m_alpha,m_ctmax,m_ctmin,m_amct,0,ran[0],ran[1]);
    if (wt!=0.) wt = 1.0/wt/pow(2.*M_PI,2*3.-4.);
    return wt;
}