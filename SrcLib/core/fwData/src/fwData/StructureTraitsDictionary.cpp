/* ***** BEGIN LICENSE BLOCK *****
 * FW4SPL - Copyright (C) IRCAD, 2009-2011.
 * Distributed under the terms of the GNU Lesser General Public License (LGPL) as
 * published by the Free Software Foundation.
 * ****** END LICENSE BLOCK ****** */

#include <boost/bind.hpp>

#include <fwCore/base.hpp>
#include <fwTools/ClassRegistrar.hpp>

#include <fwData/Factory.hpp>

#include "fwData/registry/macros.hpp"
#include "fwData/StructureTraitsDictionary.hpp"

fwDataRegisterMacro( ::fwData::StructureTraitsDictionary );

namespace fwData
{
//------------------------------------------------------------------------------

StructureTraitsDictionary::StructureTraitsDictionary ()
{}


//------------------------------------------------------------------------------

StructureTraitsDictionary::~StructureTraitsDictionary ()
{
}

//------------------------------------------------------------------------------

StructureTraits::sptr StructureTraitsDictionary::getStructure(std::string type)
{
    OSLM_ASSERT("Structure of type '" << type << "' not found", m_structureTraitsMap.find(type) != m_structureTraitsMap.end());
    return m_structureTraitsMap[type];
}

//------------------------------------------------------------------------------

void StructureTraitsDictionary::addStructure(StructureTraits::sptr structureTraits)
{
    std::string type = structureTraits->getType();
    StructureTraits::StructureClass structClass = structureTraits->getClass();
    std::string attachment = structureTraits->getAttachmentType();
    FW_RAISE_IF("Structure of type '" << type << "' already exist", m_structureTraitsMap.find(type) != m_structureTraitsMap.end());
    FW_RAISE_IF("Structure of class '" << structClass << "' can not have attachment",
            !(attachment.empty() || structClass == StructureTraits::LESION || structClass == StructureTraits::FUNCTIONAL) );
    FW_RAISE_IF("Structure attachment '" << attachment << "' not found in dictionary",
            !(attachment.empty() || m_structureTraitsMap.find(attachment) != m_structureTraitsMap.end() ) );
    FW_RAISE_IF("Structure attachment '" << attachment << "' must be of class ORGAN",
            !(attachment.empty() || m_structureTraitsMap[attachment]->getClass() == StructureTraits::ORGAN ) );
    FW_RAISE_IF("Structure must have at least one category",
            structureTraits->getCategories().empty());
    FW_RAISE_IF("Wrong structure type '" << type<< "', a type cannot contain space" , structureTraits->getType().find(" ") != std::string::npos );


    m_structureTraitsMap[type] = structureTraits;
}

//------------------------------------------------------------------------------

std::vector<std::string> StructureTraitsDictionary::getStructureTypeNames() const
{
    std::vector<std::string> vectNames;
    std::transform( m_structureTraitsMap.begin(), m_structureTraitsMap.end(),
            std::back_inserter(vectNames),
            ::boost::bind(& StructureTraitsMapType::value_type::first,_1) );
    return vectNames;
}

//------------------------------------------------------------------------------


} // namespace fwData


