/* ***** BEGIN LICENSE BLOCK *****
 * FW4SPL - Copyright (C) IRCAD, 2017.
 * Distributed under the terms of the GNU Lesser General Public License (LGPL) as
 * published by the Free Software Foundation.
 * ****** END LICENSE BLOCK ****** */

#include "fwServices/IOperator.hpp"

#include <fwCom/Signal.hxx>

namespace fwServices
{

//-----------------------------------------------------------------------------

const ::fwCom::Signals::SignalKeyType IOperator::s_COMPUTED_SIG = "computed";

//-----------------------------------------------------------------------------

IOperator::IOperator()
{
    m_sigComputed = newSignal<ComputedSignalType>(s_COMPUTED_SIG);
}

//-----------------------------------------------------------------------------

IOperator::~IOperator()
{
}

//-----------------------------------------------------------------------------

}
