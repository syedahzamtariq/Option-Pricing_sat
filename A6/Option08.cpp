#include <iostream>
#include <cmath>
#include "Option08.h"
#include "BinomialTreeModel02.h"
#include "BinLattice02.h"

using namespace std;

namespace fre {
    Option::~Option() {}

    double Call::Payoff(double z) const {
        if (z > K) return z - K;
        return 0.0;
    }

    double Put::Payoff(double z) const {
        if (z < K) return K - z;
        return 0.0;
    }

    double OptionCalculation::PriceByCRR(const BinomialTreeModel &Model) {
        double q = Model.RiskNeutProb();
        int N = pOption->GetN();
        vector<double> Price(N + 1);

        for (int i = 0; i <= N; i++) {
            Price[i] = pOption->Payoff(Model.CalculateAssetPrice(N, i));
        }

        for (int n = N - 1; n >= 0; n--) {
            for (int i = 0; i <= n; i++) {
                Price[i] = (q * Price[i + 1] + (1 - q) * Price[i]) / Model.GetR();
            }
        }

        return Price[0];
    }

    double OptionCalculation::PriceByCRR(const BinomialTreeModel &Model, BinLattice<double> &PriceTree, BinLattice<double> &MoneyPositionTree, BinLattice<double> &StockPositionTree) {
        double q = Model.RiskNeutProb();
        int N = pOption->GetN();
        PriceTree.SetN(N);
        MoneyPositionTree.SetN(N);
        StockPositionTree.SetN(N);

        double ContVal = 0;
        double delta = 0;
        double moneyposition = 0;

        for (int i = 0; i <= N; i++) {
            PriceTree.SetNode(N, i, pOption->Payoff(Model.CalculateAssetPrice(N, i)));
            MoneyPositionTree.SetNode(N, i, 0);
            StockPositionTree.SetNode(N, i, 0);
        }

        for (int n = N - 1; n >= 0; n--) {
            for (int i = 0; i <= n; i++) {
                ContVal = (q * PriceTree.GetNode(n + 1, i + 1) + (1 - q) * PriceTree.GetNode(n + 1, i)) / Model.GetR();
                PriceTree.SetNode(n, i, ContVal);
                delta = (PriceTree.GetNode(n + 1, i + 1) - PriceTree.GetNode(n + 1, i)) / (Model.CalculateAssetPrice(n + 1, i + 1) - Model.CalculateAssetPrice(n + 1, i));
                StockPositionTree.SetNode(n, i, delta);
                moneyposition = (PriceTree.GetNode(n + 1, i) - StockPositionTree.GetNode(n, i) * Model.CalculateAssetPrice(n + 1, i)) / Model.GetR();
                MoneyPositionTree.SetNode(n, i, moneyposition);
            }
        }

        return PriceTree.GetNode(0, 0);
    }

    double OptionCalculation::PriceBySnell(const BinomialTreeModel &Model, BinLattice<double> &PriceTree, BinLattice<bool> &StoppingTree) {
        double q = Model.RiskNeutProb();
        int N = pOption->GetN();
        PriceTree.SetN(N);

        double ContVal = 0;

        for (int i = 0; i <= N; i++) {
            PriceTree.SetNode(N, i, pOption->Payoff(Model.CalculateAssetPrice(N, i)));
            StoppingTree.SetNode(N, i, 1);
        }

        for (int n = N - 1; n >= 0; n--) {
            for (int i = 0; i <= n; i++) {
                ContVal = (q * PriceTree.GetNode(n + 1, i + 1) + (1 - q) * PriceTree.GetNode(n + 1, i)) / Model.GetR();
                PriceTree.SetNode(n, i, pOption->Payoff(Model.CalculateAssetPrice(n, i)));
                StoppingTree.SetNode(n, i, 1);

                if (ContVal > PriceTree.GetNode(n, i)) {
                    PriceTree.SetNode(n, i, ContVal);
                    StoppingTree.SetNode(n, i, 0);
                } else if (PriceTree.GetNode(n, i) == 0.0) {
                    StoppingTree.SetNode(n, i, 0);
                }
            }
        }

        return PriceTree.GetNode(0, 0);
    }
}
