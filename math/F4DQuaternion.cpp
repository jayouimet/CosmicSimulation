#include "F4DQuaternion.h"
#include "Constants.h"

namespace F4DEngine {
   F4DQuaternion::F4DQuaternion():s(0.0f),v(F4DVector3()){}

   F4DQuaternion::F4DQuaternion(float uS, F4DVector3& uV):s(uS),v(uV){}

   F4DQuaternion::F4DQuaternion(const F4DQuaternion& q):s(q.s),v(q.v){}

   F4DQuaternion::~F4DQuaternion()
   {
   }

   F4DQuaternion& F4DQuaternion::operator=(const F4DQuaternion& q)
   {
      s = q.s;
      v = q.v;
      return *this;
   }
   F4DQuaternion F4DQuaternion::operator+(const F4DQuaternion& q) const
   {
      float scalar = s + q.s;
      F4DVector3 vector = v + q.v;
      return F4DQuaternion(scalar, vector);
   }
   void F4DQuaternion::operator+=(const F4DQuaternion& q)
   {
      s += q.s;
      v += q.v;
   }
   F4DQuaternion F4DQuaternion::operator-(const F4DQuaternion& q) const
   {
      float scalar = s - q.s;
      F4DVector3 vector = v - q.v;
      return F4DQuaternion(scalar, vector);
   }
   void F4DQuaternion::operator-=(const F4DQuaternion& q)
   {
      s -= q.s;
      v -= q.v;
   }
   F4DQuaternion F4DQuaternion::operator*(const F4DQuaternion& q) const
   {
      float scalar = s * q.s - v.dot(q.v);
      F4DVector3 vec = q.v * s + v * q.s + v.cross(q.v);
      return F4DQuaternion(scalar, vec);
   }
   void F4DQuaternion::operator*=(const F4DQuaternion& q)
   {
      (*this) = multiply(q);
   }
   F4DQuaternion F4DQuaternion::operator*(const float scalar) const
   {
      float sca = s * scalar;
      F4DVector3 vec = v * scalar;
      return F4DQuaternion(sca, vec);
   }
   void F4DQuaternion::operator*=(const float scalar)
   {
      s *= scalar;
      v *= scalar;
   }
   F4DQuaternion F4DQuaternion::conjugate()
   {
      float scalar = s;
      F4DVector3 vector = v * (-1);
      return F4DQuaternion(scalar, vector);
   }
   void F4DQuaternion::convertToUnitNormQuaternion()
   {
      float angle = DegreesToRad(s);
      v.normalize();
      s = cosf(angle * 0.5f);
      v = v * sinf(angle * 0.5f);
   }
   F4DQuaternion F4DQuaternion::inverse()
   {
      float absoluteValue = norm();
      absoluteValue *= absoluteValue;
      absoluteValue = 1 / absoluteValue;
      F4DQuaternion con = conjugate();
      float scalar = con.s * absoluteValue;
      F4DVector3 vector = con.v * absoluteValue;
      return F4DQuaternion(scalar, vector);
   }
   F4DQuaternion F4DQuaternion::multiply(const F4DQuaternion& q) const
   {
      float scalar = s * q.s - v.dot(q.v);
      F4DVector3 vec = q.v * s + v * q.s + v.cross(q.v);
      return F4DQuaternion(scalar, vec);
   }
   float F4DQuaternion::norm()
   {
      float scalar = s * s;
      float vector = v * v;
      return sqrt(scalar + vector);
   }
   void F4DQuaternion::normalize()
   {
      float normValue = norm();
      if (normValue == 0) return;
      normValue = 1 / normValue;
      s *= normValue;
      v *= normValue;
   }
}
