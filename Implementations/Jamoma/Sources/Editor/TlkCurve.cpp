/*!
 * \file TlkCurve.cpp
 *
 * \author Clément Bossut
 * \author Théo de la Hogue
 *
 * This code is licensed under the terms of the "CeCILL-C"
 * http://www.cecill.info
 */

#include "Editor/TlkCurve.h"

namespace OSSIA {
  
template <typename T>
class TlkCurve<T>::Impl {
  
public:
  
  Impl() {};
  
  Impl(const Impl & other) = default;
  ~Impl() = default;
  
};

template <typename T>
TlkCurve<T>::TlkCurve() :
Curve<T>(),
pimpl(new Impl)
{}

template <typename T>
TlkCurve<T>::TlkCurve(const TlkCurve & other) :
pimpl(new Impl(*(other.pimpl)))
{}

template <typename T>
TlkCurve<T>::~TlkCurve()
{
  delete pimpl;
}

template <typename T>
TlkCurve<T>& TlkCurve<T>::operator= (const TlkCurve & other)
{
  delete pimpl;
  pimpl = new Impl(*(other.pimpl));
  return *this;
}
    
template <typename T>
bool TlkCurve<T>::setValueAt(double abscissa, T value)
{
  // todo : if there is a point change the value else add a point
  return false;
}

// explicit instantiation for double
template class TlkCurve<double>;

}
