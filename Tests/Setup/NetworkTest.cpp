#include <QtTest>
#include "../ForwardDeclaration.h"
#include <iostream>

using namespace OSSIA;
using namespace OSSIA::Toolkit;

class NetworkTest : public QObject
{
    Q_OBJECT

private Q_SLOTS:

    /*! test life cycle and accessors functions */
    void test_basic()
    {
        //! \todo test clone()
    }
};

QTEST_APPLESS_MAIN(NetworkTest)

#include "NetworkTest.moc"