#pragma once
namespace fre{
    class DefInt{
        private:
            double a;
            double b;
            double (*Function)(double x);
        
        public:
            DefInt(double aInput, double bInput, double (*functionInput)(double x));
            double FTrapezoid(int N);
            double FSimpson(int N);
            double FH(int N);
    };
}