/*
 * agn_feedback.h
 *
 *  Created on: 14Jun.,2017
 *      Author: clagos
 */

#ifndef INCLUDE_AGN_FEEDBACK_H_
#define INCLUDE_AGN_FEEDBACK_H_


#include <memory>
#include <string>
#include <vector>

#include "cosmology.h"
#include "options.h"
#include "components.h"

namespace shark {

class AGNFeedbackParameters {

public:
	AGNFeedbackParameters(const Options &options);

	double mseed;
	double mhalo_seed;
	double alpha_cool;
	double f_edd;
	double f_smbh;
	double v_smbh;
	double tau_fold;
	double accretion_eff_cooling;
	double kappa_agn;
	double nu_smbh;
	double mass_thresh;

	enum AGNFeedbackModel {
		CROTON16 = 0,
		BOWER06
	};

	AGNFeedbackModel model;
};


class AGNFeedback {

public:
	AGNFeedback(AGNFeedbackParameters parameters, std::shared_ptr<Cosmology> cosmology);

	/**
	 * All input quantities should be in comoving units.
	 */

	void plant_seed_smbh(Halo &halo);
	double eddington_luminosity(double mbh);
	double accretion_rate_hothalo_smbh(double Lcool, double mbh);
	double agn_bolometric_luminosity(double macc);
	double smbh_growth_starburst(double mgas, double vvir);
	double smbh_accretion_timescale(Galaxy &galaxy, double z);
	double accretion_rate_hothalo_smbh_limit(double mheatrate, double vvir);

	// TODO: move this to private when possible
	AGNFeedbackParameters parameters;

private:
	std::shared_ptr<Cosmology> cosmology;
};

} //end namespace shark


#endif /* INCLUDE_AGN_FEEDBACK_H_ */
