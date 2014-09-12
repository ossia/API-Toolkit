/*!
 * \file TlkCurve.h
 *
 * \author Clément Bossut
 * \author Théo de la Hogue
 *
 * This code is licensed under the terms of the "CeCILL-C"
 * http://www.cecill.info
 */

#ifndef TLK_CURVE_H_
#define TLK_CURVE_H_

#include "Editor/Curve.h"

namespace OSSIA {

template <typename T>
class TlkCurveSegment;

template <typename T>
    class TlkCurve : public Curve<T> {

public:

  // Constructors, destructor, assignment
  TlkCurve();
  TlkCurve(const TlkCurve&);
  ~TlkCurve();
  TlkCurve & operator= (const TlkCurve&);
  
  // Computation
  bool setValueAt(double, T); // Between 0. and 1.

  // pimpl idiom
private:
  class Impl;
  Impl * pimpl;

};

}

#endif /* TLK_CURVE_H_ */
