#ifndef MATH_F4DQUATERNION_H_
#define MATH_F4DQUATERNION_H_


#define _USE_MATH_DEFINES
#include <math.h>
#include "F4DVector3.h"

namespace F4DEngine {
   class F4DQuaternion {
   private:
   public:
      // Scalar
      float s;
      // Vector
      F4DVector3 v;
      // Constructor
      F4DQuaternion();
      F4DQuaternion(float uS, F4DVector3& uV);
      // Copy constructor
      F4DQuaternion(const F4DQuaternion& q);
      // Destructor
      ~F4DQuaternion();
      // Operator overload
      F4DQuaternion& operator=(const F4DQuaternion& q);
      F4DQuaternion operator+(const F4DQuaternion& q) const;
      void operator+=(const F4DQuaternion& q);
      F4DQuaternion operator-(const F4DQuaternion& q) const;
      void operator-=(const F4DQuaternion& q);
      F4DQuaternion operator*(const F4DQuaternion& q) const;
      void operator*=(const F4DQuaternion& q);

      F4DQuaternion operator*(const float scalar) const;
      void operator*=(const float scalar);

      // Methods
      F4DQuaternion conjugate();
      void convertToUnitNormQuaternion();
      F4DQuaternion inverse();
      F4DQuaternion multiply(const F4DQuaternion& q) const;
      float norm();
      void normalize();
   };
}

#endif