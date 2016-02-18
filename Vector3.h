#ifndef INC_Vector3_H
#define INC_Vector3_H

#include <iomanip>
#include <string>
#include <sstream>
#include <istream>
#include <iostream>
using namespace std;


class Vector3{
public:
	inline Vector3();
	inline Vector3(double d);
	inline Vector3(double a0, double b0, double c0);
	inline Vector3(const Vector3 &a);

	inline Vector3(const double *a);

	inline Vector3 &set(double a0, double b0, double c0);

	inline Vector3 &set(const Vector3 &v);
	inline Vector3 &set(const double d);
	inline Vector3 &set(const double *v);

	inline Vector3 &operator=(const Vector3 &v);
	inline Vector3 &operator=(const double d);
	inline Vector3 &operator=(const double *a);

	inline int operator==(const Vector3 &v) const;
	inline int operator!=(const Vector3 &v) const;
	inline int operator==(double d) const;
	inline int operator!=(double d) const;

	inline Vector3 &operator+=(double d);
	inline Vector3 &operator-=(double d);
	inline Vector3 &operator*=(double d);
	inline Vector3 &operator/=(double d);

	inline Vector3 &operator+=(const Vector3 &v);
	inline Vector3 &operator-=(const Vector3 &v);
	inline Vector3 &operator*=(const Vector3 &v);
	inline Vector3 &operator/=(const Vector3 &v);
	inline double length(const Vector3 &v);
	inline void normalize(Vector3 &a);

	inline Vector3 setMinTo1();

	inline double dot(const Vector3 &v, const Vector3 &b);
	inline Vector3 cross(const Vector3 &v);

	//string toString();

	union{
		struct{
			double a, b, c;
		};
		struct{
			double x, y, z;
		};
		double elements[3];
	};
};


inline Vector3 operator-(const Vector3 &v);

inline Vector3 operator+(const Vector3 &v, const Vector3 &u);
inline Vector3 operator-(const Vector3 &v, const Vector3 &u);

inline Vector3 operator+(const Vector3 &v, double b);
inline Vector3 operator-(const Vector3 &v, double b);
inline Vector3 operator*(const Vector3 &v, double b);
inline Vector3 operator/(const Vector3 &v, double b);

inline Vector3 operator+(double a, const Vector3 &u);
inline Vector3 operator-(double a, const Vector3 &u);
inline Vector3 operator*(double a, const Vector3 &u);

inline double length(const Vector3 &v);
inline double lengthSq(const Vector3 &v);
inline void normalize(Vector3 &v);

inline double dot(const Vector3 &v, const Vector3 &u);
inline Vector3 cross(const Vector3 &v, const Vector3 &u);

inline Vector3 rotate(double angle, Vector3 axis, Vector3 v);

inline ostream& operator<< (ostream &ostr, Vector3 &vec);

inline Vector3::Vector3() {
	a = b = c = 0.0;
}

inline Vector3::Vector3(double d) {
	a = b = c = d;
}

inline Vector3::Vector3(double a0, double b0, double c0) {
	a = a0;
	b = b0;
	c = c0;
}

inline Vector3::Vector3(const Vector3 &v) {
	a = v.a;
	b = v.b;
	c = v.c;
}

inline Vector3::Vector3(const double *v) {
	a = v[0];
	b = v[1];
	c = v[2];
}


//-------------------------------------------------------------------


inline Vector3 &Vector3::set(double a0, double b0, double c0) {
	a = a0;
	b = b0;
	c = c0;
	return (*this);
}

inline Vector3 &Vector3::set(double d) {
	a = b = c = d;
	return (*this);
}

inline Vector3 &Vector3::set(const Vector3 &v) {
	a = v.a;
	b = v.b;
	c = v.c;
	return (*this);
}

inline Vector3 &Vector3::set(const double *v) {
	a = v[0];
	b = v[1];
	c = v[2];
	return (*this);
}

inline Vector3 operator-(const Vector3 &v) {
	return Vector3(-v.a, -v.b, -v.c);
}


inline Vector3 &Vector3::operator=(const Vector3 &v) {
	return set(v);
}

inline Vector3 &Vector3::operator=(const double *v) {
	return set(v);
}

inline Vector3 &Vector3::operator=(const double d) {
	return set(d);
}

inline Vector3 Vector3::setMinTo1(){
	Vector3 tmp(*this);

	double min = a;
	int i = 0;
	if (b < min){
		min = b;
		i = 1;
	}
	if (c < min){
		min = c;
		i = 2;
	}

	if (i == 0)
		tmp.a = 1.0;
	else if (i == 1)
		tmp.b = 1.0;
	else if (i == 2)
		tmp.c = 1.0;

	return tmp;
}

//-------------------------------------------------------------------

inline int Vector3::operator==(const Vector3 &v) const {
	return ((a == v.a) && (b == v.b) && (c == v.c));
}

inline int Vector3::operator!=(const Vector3 &v) const {
	return ((a != v.a) || (b != v.b) || (c != v.c));
}

inline int Vector3::operator==(double d) const {
	return ((a == d) && (b == d) && (c == d));
}

inline int Vector3::operator!=(double d) const {
	return ((a != d) || (b != d) || (c != d));
}

//-------------------------------------------------------------------

inline Vector3 &Vector3::operator+=(double d) {
	a += d;
	b += d;
	c += d;
	return (*this);
}

inline Vector3 &Vector3::operator-=(double d) {
	a -= d;
	b -= d;
	c -= d;
	return (*this);
}

inline Vector3 &Vector3::operator*=(double d) {
	a *= d;
	b *= d;
	c *= d;
	return (*this);
}

inline Vector3 &Vector3::operator/=(double d) {
	a /= d;
	b /= d;
	c /= d;
	return (*this);
}

inline Vector3 &Vector3::operator+=(const Vector3 &v) {
	a += v.a;
	b += v.b;
	c += v.c;
	return (*this);
}

inline Vector3 &Vector3::operator-=(const Vector3 &v) {
	a -= v.a;
	b -= v.b;
	c -= v.c;
	return (*this);
}

inline Vector3 &Vector3::operator*=(const Vector3 &v) {
	a *= v.a;
	b *= v.b;
	c *= v.c;
	return (*this);
}

//-------------------------------------------------------------------

inline Vector3 operator+(const Vector3 &v, const Vector3 &u) {
	return Vector3(v.a + u.a, v.b + u.b, v.c + u.c);
}

inline Vector3 operator-(const Vector3 &v, const Vector3 &u) {
	return Vector3(v.a - u.a, v.b - u.b, v.c - u.c);
}

inline Vector3 operator+(const Vector3 &v, double b){
	return Vector3(v.a + b, v.b + b, v.c + b);
}

inline Vector3 operator-(const Vector3 &v, double b){
	return Vector3(v.a - b, v.b - b, v.c - b);
}

inline Vector3 operator*(const Vector3 &v, double b){
	return Vector3(v.a * b, v.b * b, v.c * b);
}

inline Vector3 operator/(const Vector3 &v, double b){
	return Vector3(v.a / b, v.b / b, v.c / b);
}

inline Vector3 operator+(double a, const Vector3 &u){
	return Vector3(a + u.a, a + u.b, a + u.c);
}

inline Vector3 operator-(double a, const Vector3 &u){
	return Vector3(a - u.a, a - u.b, a - u.c);
}

inline Vector3 operator*(double a, const Vector3 &u){
	return Vector3(a * u.a, a * u.b, a * u.c);
}

inline double length(const Vector3 &v) {
	return sqrt(v.a * v.a + v.b * v.b + v.c * v.c);
}

inline double lengthSq(const Vector3 &v) {
	return v.a * v.a + v.b * v.b + v.c * v.c;
}

inline void normalize(Vector3 &v) {
	register double m = length(v);
	if (m != 0.0) v *= (1 / m);
}

inline double dot(const Vector3 &v, const Vector3 &u) {
	return (v.a * u.a + v.b * u.b + v.c * u.c);
}

inline Vector3 cross(const Vector3 &v, const Vector3 &u) {
	//return Vector3(v.b * u.c - v.c * u.b, 
	//			 v.c * u.a - v.a * u.c,
	//			 v.a * u.b - v.b * u.a);

	Vector3 result(v.b * u.c - v.c * u.b,
		v.c * u.a - v.a * u.c,
		v.a * u.b - v.b * u.a);
	return result;
}

inline Vector3 rotate(double angle, Vector3 axis, Vector3 v){
	return Vector3(0.0);
}

/*string Vector3::toString(){
ostringstream ostr;

ostr << "<" << x << " " << y << " " << z << ">";

return ostr.str();
}*/

inline ostream& operator<< (ostream &ostr, Vector3 &vec){
	ostr << "<" << vec.x << " " << vec.y << " " << vec.z << ">";
	return ostr;
}

inline istream& operator>> (istream &istr, Vector3 &vec){
	//istr >> "<" >> vec.x >> vec.y >> vec.z >> ">";
	char pat[1024];
	istr >> setw(strlen("<") + 1) >> pat >> vec.x >> vec.y >> vec.z >> setw(strlen(">") + 1) >> pat;
	return istr;
}

#endif