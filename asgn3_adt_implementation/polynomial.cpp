#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Polynomial{
    private:
        double* _coefficients;
        int _length;
    
    public:
        Polynomial(const int length){
            _length = length;
            _coefficients = new double[length];

            for(int i = 0;i<_length;i++){
                _coefficients[i] = 0.0;
            }
        }

        Polynomial(const int length, const double coefficients[]){
            _length = length;
            _coefficients = new double[length];

            for(int i = 0;i<_length;i++){
                _coefficients[i] = coefficients[i];
            }
        }

        ~Polynomial(){
            delete [] _coefficients; //Exceptions has occured unknown signal
        }

        int length(){
            return _length;
        }

        void setCoefficient(int index, double val){
            _coefficients[index] = val; 
        }

        double getCoefficient(int index){
            return _coefficients[index];
        }

        double eval(const double x){
            double sum = 0.0;
            for(int i = 0;i< _length;i++){
                sum+=_coefficients[i]*pow(x, i);
            }

            return sum;
        }

        // double integrate(const double x){
        //     double integral = 0.0;
        //     for(int i = 0;i< _length;i++){
        //         integral+=_coefficients[i]*pow(x, i+1)/(i+1.0);
        //     }

        //     return integral;
        // }

        // double derivative(const double x){
        //     double deri = 0.0;
        //     for(int i = 1;i< _length;i++){
        //         deri+=_coefficients[i]*pow(x, i-1)*i;
        //     }

        //     return deri;
        // }

        Polynomial operator+(Polynomial &poly){
            Polynomial addition(max(_length, poly.length()));
            for(int i = 0;i<max(_length, poly.length()); i++){
                if(i>=_length && i< poly.length()){
                    addition.setCoefficient(i, poly.getCoefficient(i));
                }
                else if(i<_length && i>=poly.length()){
                    addition.setCoefficient(i, _coefficients[i]);
                }
                else{
                    addition.setCoefficient(i,poly.getCoefficient(i) +  _coefficients[i]);
                }
                
            }
            return addition;
        }

        Polynomial operator-(Polynomial &poly){
            Polynomial subtraction = (max(_length, poly.length()));
            for(int i = 0;i<max(_length, poly.length()); i++){
                if(i>=_length && i< poly.length()){
                    subtraction.setCoefficient(i, -1*poly.getCoefficient(i));
                }
                else if(i<_length && i>=poly.length()){
                    subtraction.setCoefficient(i, _coefficients[i]);
                }
                else{
                    subtraction.setCoefficient(i,  _coefficients[i]- poly.getCoefficient(i));
                }
                
            }
            return subtraction;
        }

        Polynomial operator*(Polynomial &poly){ //why constant arguments can't access member functions?
            int size = _length*poly.length();
            Polynomial multi(size);

            for(int i  = 0 ;i< _length; i++){
                for(int j = 0; j< poly.length();j++){
                    multi.setCoefficient(i+j, multi.getCoefficient(i+j) + _coefficients[i]*poly.getCoefficient(j));
                }
            }
            return multi;
        }

        friend ostream& operator<<(ostream &out, const Polynomial &polynomial){ //error for destructor is here: caused by no presence of '&' ib polynomial
            for(int i = 0;i<polynomial._length;i++){
                if(i==0){
                    out << polynomial._coefficients[i] << ' ';
                    continue;
                } 

                if(polynomial._coefficients[i]==0.0){
                    continue;
                }

                out << "+ " << polynomial._coefficients[i] << "*x^" << i << ' ';
            }
            out << endl;
            return out;
        }

};

int main(){
    double arr[] = {2.0,7.0,3.0, 8.0};
    double arr2[] = {7.0,3.0, 8.0};

    Polynomial poly1(4, arr);
    Polynomial poly2(3, arr2);

    cout << poly1;
    cout << poly2;

    Polynomial multiplication = poly1 * poly2;
    cout << multiplication;

    Polynomial addition1 = poly1 + poly2;
    Polynomial addition2 = poly2 + poly1;

    cout << addition1;
    cout <<addition2;

    Polynomial sub1 = poly1 - poly2;
    Polynomial sub2 = poly2 - poly1;

    cout << sub1;
    cout << sub2;

    double one  = poly1.eval(1.0);
    cout << one; 

    return 1;
}