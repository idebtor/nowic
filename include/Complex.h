//Complex.h

#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
using std::istream;
using std::ostream;

class Complex {
	private:
		double real;
		double imaginary;
      
	public:
		Complex();  //default constructor
		Complex(double, double); //constructor
		~Complex();//destructor
		
        //adding two complex numbers
		Complex add(const Complex &) const; 
		Complex operator +(const Complex &) const ;
        Complex operator +(double) const;
        //adding two complex number and update the original complex number
        void operator +=(Complex &);

        //subtracting two complex numbers
		Complex subtract(const Complex &) const; 
        Complex operator-(const Complex &) const;

        //copy a complex number
        void copy(const Complex &);
        void operator=(const Complex &);
        void operator=(const double);
                                             
        //compare two complex numbers
        bool operator==(Complex &) const;

		void print();    //print complex number format
		
		double getReal() const;//getters
		double getImaginary() const;
		
		void setReal(double);  //setters
		void setImaginary(double);

	friend istream & operator>>(istream &, Complex &); //overloading input stream operator
	friend ostream & operator<<(ostream &, const Complex &); //overloading output stream operator
};  //end of class


Complex operator+(double realNumber, Complex & right) ;

#endif