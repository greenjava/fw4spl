/* ***** BEGIN LICENSE BLOCK *****
 * FW4SPL - Copyright (C) IRCAD, 2009-2018.
 * Distributed under the terms of the GNU Lesser General Public License (LGPL) as
 * published by the Free Software Foundation.
 * ****** END LICENSE BLOCK ****** */

#pragma once

#include "ioPacs/config.hpp"

#include <fwGui/editor/IEditor.hpp>

#include <fwPacsIO/data/PacsConfiguration.hpp>
#include <fwPacsIO/SeriesEnquirer.hpp>

#include <boost/filesystem/path.hpp>

#include <QComboBox>
#include <QLineEdit>
#include <QObject>
#include <QPointer>
#include <QPushButton>
#include <QSpinBox>
#include <QWidget>

namespace ioPacs
{

/**
 * @brief   This editor service is used to edit a pacs configuration
 */
class IOPACS_CLASS_API SPacsConfigurationEditor : public QObject,
                                                  public ::fwGui::editor::IEditor
{
Q_OBJECT;

public:

    fwCoreServiceClassDefinitionsMacro( (SPacsConfigurationEditor)( ::fwGui::editor::IEditor ) );
    /**
     * @brief Constructor
     */
    IOPACS_API SPacsConfigurationEditor() noexcept;

    /**
     * @brief Destructor
     */
    IOPACS_API virtual ~SPacsConfigurationEditor() noexcept;

private:
    IOPACS_API void modifiedNotify(::fwPacsIO::data::PacsConfiguration::sptr pacsConfiguration);

private Q_SLOTS:
    /// Slot called for pinging the pacs
    IOPACS_API void pingPacs();

    /// Slot called for changing the local application title
    IOPACS_API void localApplicationTitleChanged();

    /// Slot called for changing the pacs host name
    IOPACS_API void pacsHostNameChanged();

    /// Slot called for changing the pacs application title
    IOPACS_API void pacsApplicationTitleChanged();

    /**
     * @brief Slot called for changing the pacs application port
     * @param[in] value Pacs application port
     */
    IOPACS_API void pacsApplicationPortChanged(int value);

    /// Slot called for changing the move application title
    IOPACS_API void moveApplicationTitleChanged();

    /**
     * @brief Slot called for changing the move application port
     * @param[in] value Move application port
     */
    IOPACS_API void moveApplicationPortChanged(int value);

    /**
     * @brief Slot called for changing the retrieve method
     * @param[in] index Retrieve method index
     */
    IOPACS_API void retrieveMethodChanged(int index);

protected:

    /**
     * @brief Configuring method. This method is used to configure the service.
     *
     * XML configuration sample:
       @code{.xml}
       <service uid="pacsConfigurationEditor" impl="::ioPacs::SPacsConfigurationEditor"
         autoConnect="yes">
       </service>
       @endcode
     */
    IOPACS_API virtual void configuring() override;

    /// Override
    IOPACS_API virtual void starting() override;

    /// Override
    IOPACS_API virtual void stopping() override;

    /// Override
    IOPACS_API void updating() override;

    /// Override
    IOPACS_API void info(std::ostream& _sstream ) override;

    /// Local application title
    QPointer< QLineEdit > m_localApplicationTitleWidget;

    /// Pacs host name
    QPointer< QLineEdit > m_pacsHostNameWidget;

    /// Pacs application title
    QPointer< QLineEdit > m_pacsApplicationTitleWidget;

    /// Pacs application port
    QPointer< QSpinBox > m_pacsApplicationPortWidget;

    /// Move application title
    QPointer< QLineEdit > m_moveApplicationTitleWidget;

    /// Move application port
    QPointer< QSpinBox > m_moveApplicationPortWidget;

    /// Retrieve method
    QPointer< QComboBox > m_retrieveMethodWidget;

    /// Test button
    QPointer< QPushButton > m_pingPacsButtonWidget;

};

} // namespace ioPacs
