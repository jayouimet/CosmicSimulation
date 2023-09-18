#ifndef MATH_F4DMATRIX_H_
#define MATH_F4DMATRIX_H_

#include <string>
#include "F4DVector3.h"

namespace F4DEngine {
	class F4DMatrix3 {
	private:
	public:
		float data[9] = { 0.0f };
		// Constructors
		F4DMatrix3 ();
		F4DMatrix3 (float m0, float m3, float m6, float m1, float m4, float m7, float m2, float m5, float m8);
		// Copy constructor
		F4DMatrix3(const F4DMatrix3& m);
		// Destructor
		~F4DMatrix3 ();
		// Operators overload
		// With other matrix
		F4DMatrix3& operator=(const F4DMatrix3& m);
		F4DMatrix3 operator+(const F4DMatrix3& m) const;
		void operator+=(const F4DMatrix3& m);
		F4DMatrix3 operator*(const F4DMatrix3& m) const;
		void operator*=(const F4DMatrix3& m);
		// With float
		F4DMatrix3 operator*(const float s) const;
		void operator*=(const float s);
		// With vector
		F4DVector3 operator*(const F4DVector3& v) const;
		// Methods
		F4DMatrix3 getInverseOfMatrix() const;
		F4DMatrix3 getTransposeOfMatrix() const;
		void transposeMatrix();

		void invertMatrix();
		void setMatrixAsIdentityMatrix();
		void setMatrixAsInverseOfGivenMatrix(const F4DMatrix3& m);
		void setMatrixAsTransposeOfGivenMatrix(const F4DMatrix3& m);
		F4DVector3 transformVectorByMatrix(const F4DVector3& v) const;

		std::string toString();
	};
}

#endif