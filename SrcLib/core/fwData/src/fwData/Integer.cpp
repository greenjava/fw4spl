/* ***** BEGIN LICENSE BLOCK *****
 * FW4SPL - Copyright (C) IRCAD, 2009-2012.
 * Distributed under the terms of the GNU Lesser General Public License (LGPL) as
 * published by the Free Software Foundation.
 * ****** END LICENSE BLOCK ****** */

#include "fwData/registry/macros.hpp"

#include "fwData/Object.hpp"
#include "fwData/GenericField.hpp"
#include "fwData/Integer.hpp"


fwDataRegisterMacro( ::fwData::Integer );

namespace fwData
{
//------------------------------------------------------------------------------

Integer::Integer(::fwData::Object::Key key ) throw()
{}

//------------------------------------------------------------------------------

Integer::~Integer() throw()
{}

//------------------------------------------------------------------------------

void Integer::shallowCopy( Integer::csptr _source )
{
    this->fieldShallowCopy( _source );
    m_value = _source->m_value;
}

//------------------------------------------------------------------------------

void Integer::deepCopy( Integer::csptr _source )
{
    this->fieldDeepCopy( _source );
    m_value = _source->m_value;
}

} // namespace fwData
