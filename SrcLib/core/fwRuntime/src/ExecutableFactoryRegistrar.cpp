/* ***** BEGIN LICENSE BLOCK *****
 * FW4SPL - Copyright (C) IRCAD, 2009-2015.
 * Distributed under the terms of the GNU Lesser General Public License (LGPL) as
 * published by the Free Software Foundation.
 * ****** END LICENSE BLOCK ****** */

#include "fwRuntime/ExecutableFactoryRegistrar.hpp"

#include "fwRuntime/Bundle.hpp"
#include "fwRuntime/Runtime.hpp"



namespace fwRuntime
{



ExecutableFactoryRegistrar::ExecutableFactoryRegistrar( std::shared_ptr< ExecutableFactory > factory )
{
    // Pre-condition
    SLM_ASSERT("No bundle bundle currently loaded", Bundle::getLoadingBundle() != 0 );

    // Retrieves the bundle that is currently loading.
    std::shared_ptr< Bundle >  loadingBundle( Bundle::getLoadingBundle() );
    Runtime* runtime( Runtime::getDefault() );

    // Stores the factory into that bundle and the default runtime instance.
    loadingBundle->addExecutableFactory( factory );
    runtime->addExecutableFactory( factory );
}



} // namespace fwRuntime
