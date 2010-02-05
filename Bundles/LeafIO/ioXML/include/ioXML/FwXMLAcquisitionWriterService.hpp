#ifndef _IOXML_FWXMLACQUISITIONWRITERSERVICE_HPP_
#define _IOXML_FWXMLACQUISITIONWRITERSERVICE_HPP_

#include <string>
#include <boost/filesystem/path.hpp>

#include <io/IWriter.hpp>

#include "ioXML/config.hpp"


namespace fwData
{
    class Acquisition;
}


namespace ioXML
{

class IOXML_CLASS_API FwXMLAcquisitionWriterService : public ::io::IWriter
{

public :
    fwCoreServiceClassDefinitionsMacro ( (FwXMLAcquisitionWriterService)(::io::IWriter::Baseclass) ) ;

    /**
     * @brief   constructor
     *
     */
    IOXML_API FwXMLAcquisitionWriterService() throw();

    /**
     * @brief   destructor
     */
    IOXML_API virtual ~FwXMLAcquisitionWriterService() throw();

    /// Override
    IOXML_API virtual void configuring() throw(::fwTools::Failed) ;

    /// Override
    IOXML_API virtual void starting() throw(::fwTools::Failed);

    /// Override
    IOXML_API virtual void stopping() throw(::fwTools::Failed);

    /// Override
    IOXML_API void updating() throw(::fwTools::Failed);

    /// Override
    IOXML_API virtual void updating( ::boost::shared_ptr< const ::fwServices::ObjectMsg > _msg ) throw(::fwTools::Failed) {} ;

    /// Override
    IOXML_API void info(std::ostream &_sstream ) ;

    /// Override
    IOXML_API std::string getCfgExtensionPoint() ;

    /// Override
    IOXML_API virtual std::string getPersistanceId() ;


    /// Override
    IOXML_API virtual void configureWithIHM();

private :

    void saveAcquisition( const ::boost::filesystem::path inrFileDir, ::boost::shared_ptr< ::fwData::Acquisition > _pAcquisition );

    bool isAnFwxmlArchive( const ::boost::filesystem::path filePath );
    void manageZipAndSaveAcquisition( const ::boost::filesystem::path inrFileDir, ::fwData::Acquisition::sptr _pAcquisition );
    ::boost::filesystem::path correctFileFormat( const ::boost::filesystem::path _filePath ) const;

    bool m_bServiceIsConfigured;

    ::boost::filesystem::path m_fsAcquisitionPath;

};

} // namespace ioXML

#endif //_IOXML_FWXMLACQUISITIONWRITERSERVICE_HPP_
