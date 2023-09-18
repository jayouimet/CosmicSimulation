#include "F4DMatrix3.h"

namespace F4DEngine {
   F4DMatrix3::F4DMatrix3() 
   {
      for (int i = 0; i < 9; i++)
      {
         data[i] = 0.0f;
      }
   }
   F4DMatrix3::F4DMatrix3(float m0, float m3, float m6, float m1, float m4, float m7, float m2, float m5, float m8)
   {
      data[0] = m0;
      data[3] = m3;
      data[6] = m6;

      data[1] = m1;
      data[4] = m4;
      data[7] = m7;

      data[2] = m2;
      data[5] = m5;
      data[8] = m8;
   }
   F4DMatrix3::F4DMatrix3(const F4DMatrix3& m)
   {
      data[0] = m.data[0];
      data[3] = m.data[3];
      data[6] = m.data[6];

      data[1] = m.data[1];
      data[4] = m.data[4];
      data[7] = m.data[7];

      data[2] = m.data[2];
      data[5] = m.data[5];
      data[8] = m.data[8];
   }
   F4DMatrix3::~F4DMatrix3()
   {
   }
   F4DMatrix3& F4DMatrix3::operator=(const F4DMatrix3& m)
   {
      data[0] = m.data[0];
      data[3] = m.data[3];
      data[6] = m.data[6];

      data[1] = m.data[1];
      data[4] = m.data[4];
      data[7] = m.data[7];

      data[2] = m.data[2];
      data[5] = m.data[5];
      data[8] = m.data[8];
      return *this;
   }
   F4DMatrix3 F4DMatrix3::operator+(const F4DMatrix3& m) const
   {
      F4DMatrix3 n;
      n.data[0] = data[0] + m.data[0];
      n.data[3] = data[3] + m.data[3];
      n.data[6] = data[6] + m.data[6];

      n.data[1] = data[1] + m.data[1];
      n.data[4] = data[4] + m.data[4];
      n.data[7] = data[7] + m.data[7];

      n.data[2] = data[2] + m.data[2];
      n.data[5] = data[5] + m.data[5];
      n.data[8] = data[8] + m.data[8];
      return n;
   }
   void F4DMatrix3::operator+=(const F4DMatrix3& m)
   {
      data[0] += m.data[0];
      data[3] += m.data[3];
      data[6] += m.data[6];

      data[1] += m.data[1];
      data[4] += m.data[4];
      data[7] += m.data[7];

      data[2] += m.data[2];
      data[5] += m.data[5];
      data[8] += m.data[8];
   }
   F4DMatrix3 F4DMatrix3::operator*(const F4DMatrix3& m) const
   {
      return F4DMatrix3(
         data[0] * m.data[0] + data[3] * m.data[1] + data[6] * m.data[2],
         data[0] * m.data[3] + data[3] * m.data[4] + data[6] * m.data[5],
         data[0] * m.data[6] + data[3] * m.data[7] + data[6] * m.data[8],
         
         data[1] * m.data[0] + data[4] * m.data[1] + data[7] * m.data[2],
         data[1] * m.data[3] + data[4] * m.data[4] + data[7] * m.data[5],
         data[1] * m.data[6] + data[4] * m.data[7] + data[7] * m.data[8],
         
         data[2] * m.data[0] + data[5] * m.data[1] + data[8] * m.data[2],
         data[2] * m.data[3] + data[5] * m.data[4] + data[8] * m.data[5],
         data[2] * m.data[6] + data[5] * m.data[7] + data[8] * m.data[8]
      );
   }
   void F4DMatrix3::operator*=(const F4DMatrix3& m)
   {
      float temp1;
      float temp2;
      float temp3;

      temp1 = data[0] * m.data[0] + data[3] * m.data[1] + data[6] * m.data[2];
      temp2 = data[0] * m.data[3] + data[3] * m.data[4] + data[6] * m.data[5];
      temp3 = data[0] * m.data[6] + data[3] * m.data[7] + data[6] * m.data[8];

      data[0] = temp1;
      data[3] = temp2;
      data[6] = temp3;

      temp1 = data[1] * m.data[0] + data[4] * m.data[1] + data[7] * m.data[2];
      temp2 = data[1] * m.data[3] + data[4] * m.data[4] + data[7] * m.data[5];
      temp3 = data[1] * m.data[6] + data[4] * m.data[7] + data[7] * m.data[8];

      data[1] = temp1;
      data[4] = temp2;
      data[7] = temp3;

      temp1 = data[2] * m.data[0] + data[5] * m.data[1] + data[8] * m.data[2];
      temp2 = data[2] * m.data[3] + data[5] * m.data[4] + data[8] * m.data[5];
      temp3 = data[2] * m.data[6] + data[5] * m.data[7] + data[8] * m.data[8];

      data[2] = temp1;
      data[5] = temp2;
      data[8] = temp3;
   }
   F4DMatrix3 F4DMatrix3::operator*(const float s) const
   {
      return F4DMatrix3(
         data[0] * s, data[3] * s, data[6] * s,
         data[1] * s, data[4] * s, data[7] * s, 
         data[2] * s, data[5] * s, data[8] * s
      );
   }
   void F4DMatrix3::operator*=(const float s)
   {
      data[0] *= s; 
      data[3] *= s; 
      data[6] *= s;

      data[1] *= s; 
      data[4] *= s; 
      data[7] *= s;

      data[2] *= s; 
      data[5] *= s; 
      data[8] *= s;
   }
   F4DVector3 F4DMatrix3::operator*(const F4DVector3& v) const
   {
      return F4DVector3(
         data[0] * v.x + data[3] * v.y + data[6] * v.z, 
         data[1] * v.x + data[4] * v.y + data[7] * v.z, 
         data[2] * v.x + data[5] * v.y + data[8] * v.z
      );
   }
   F4DMatrix3 F4DMatrix3::getInverseOfMatrix() const
   {
      F4DMatrix3 result;
      result.setMatrixAsInverseOfGivenMatrix(*this);
      return result;
   }
   F4DMatrix3 F4DMatrix3::getTransposeOfMatrix() const
   {
      F4DMatrix3 result;
      result.setMatrixAsTransposeOfGivenMatrix(*this);
      return result;
   }
   void F4DMatrix3::invertMatrix()
   {
      setMatrixAsInverseOfGivenMatrix(*this);
   }
   std::string F4DMatrix3::toString()
   {
      std::string res = "";

      res += "[" + std::to_string(data[0]) + "," + std::to_string(data[3]) + "," + std::to_string(data[6]) + ",\n";
      res += std::to_string(data[1]) + "," + std::to_string(data[4]) + "," + std::to_string(data[7]) + ",\n";
      res += std::to_string(data[2]) + "," + std::to_string(data[5]) + "," + std::to_string(data[8]) + "]\n";
      
      return res;
   }
   void F4DMatrix3::setMatrixAsIdentityMatrix()
   {
      data[0] = 1.0f;
      data[3] = 0.0f;
      data[6] = 0.0f;

      data[1] = 0.0f;
      data[4] = 1.0f;
      data[7] = 0.0f;

      data[2] = 0.0f;
      data[5] = 0.0f;
      data[8] = 1.0f;
   }
   void F4DMatrix3::setMatrixAsInverseOfGivenMatrix(const F4DMatrix3& m)
   {
      float m0, m1, m2, m3, m4, m5, m6, m7, m8;

      m0 = m.data[4] * m.data[8] - m.data[7] * m.data[5];
      m1 = -(m.data[1] * m.data[8] - m.data[7] * m.data[2]);
      m2 = m.data[1] * m.data[5] - m.data[4] * m.data[2];

      m3 = -(m.data[3] * m.data[8] - m.data[5] * m.data[6]);
      m4 = m.data[0] * m.data[8] - m.data[6] * m.data[2];
      m5 = -(m.data[0] * m.data[5] - m.data[3] * m.data[2]);

      m6 = m.data[3] * m.data[7] - m.data[4] * m.data[6];
      m7 = -(m.data[0] * m.data[7] - m.data[1] * m.data[6]);
      m8 = m.data[0] * m.data[4] - m.data[3] * m.data[1];

      float invd = 1 / (m.data[0] * m0 + m.data[3] * m1 + m.data[6] * m2);

      data[0] = m0 * invd;
      data[1] = m1 * invd;
      data[2] = m2 * invd;

      data[3] = m3 * invd;
      data[4] = m4 * invd;
      data[5] = m5 * invd;

      data[6] = m6 * invd;
      data[7] = m7 * invd;
      data[8] = m8 * invd;
   }
   void F4DMatrix3::setMatrixAsTransposeOfGivenMatrix(const F4DMatrix3& m)
   {
      data[0] = m.data[0];
      data[3] = m.data[1];
      data[6] = m.data[2];

      data[1] = m.data[3];
      data[4] = m.data[4];
      data[7] = m.data[5];

      data[2] = m.data[6];
      data[5] = m.data[7];
      data[8] = m.data[8];
   }
   F4DVector3 F4DMatrix3::transformVectorByMatrix(const F4DVector3& v) const
   {
      return (*this) * v;
   }
   void F4DMatrix3::transposeMatrix()
   {
      setMatrixAsTransposeOfGivenMatrix(*this);
   }
}