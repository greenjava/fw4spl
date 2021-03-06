/* ***** BEGIN LICENSE BLOCK *****
 * FW4SPL - Copyright (C) IRCAD, 2009-2015.
 * Distributed under the terms of the GNU Lesser General Public License (LGPL) as
 * published by the Free Software Foundation.
 * ****** END LICENSE BLOCK ****** */

#ifndef __FWITKIO_UT_IMAGECONVERSIONTEST_HPP__
#define __FWITKIO_UT_IMAGECONVERSIONTEST_HPP__

#include <cppunit/extensions/HelperMacros.h>
#include <fwServices/macros.hpp>
#include <fwRuntime/EConfigurationElement.hpp>

#include <fwData/Image.hpp>


namespace fwItkIO
{
namespace ut
{

class ImageConversionTest : public CPPUNIT_NS::TestFixture
{
CPPUNIT_TEST_SUITE( ImageConversionTest );
CPPUNIT_TEST( testConversion );
CPPUNIT_TEST( stressTest );
CPPUNIT_TEST( testConversion2D );
CPPUNIT_TEST_SUITE_END();

public:
    // interface
    void setUp();
    void tearDown();
    // fonctions de tests
    void testConversion();
    void stressTest();
    void testConversion2D();

    static void roundSpacing(::fwData::Image::sptr image);

    template< class TYPE >
    void stressTestForAType();

};

} //namespace ut
} //namespace fwItkIO

#include "ImageConversionTest.hxx"

#endif // __FWITKIO_UT_IMAGECONVERSIONTEST_HPP__
