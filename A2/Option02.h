#pragma once

namespace fre {
		int GetInputData(int& N, double& K);
		//pricing European option
		double * PriceByCRR(double S0, double U, double D, double R, int N, double K,double (*Payoff)(double z, double K));
		//computing Call Payoff
		double CallPayoff(double z, double K);
		//computing Put Payoff
		double PutPayoff(double z, double K);
		//computing digital call payoff
		double DigitCallPayoff(double z, double K);
		//computing digital put payoff
		double DigitPutPayoff(double z, double K);

	
}

	