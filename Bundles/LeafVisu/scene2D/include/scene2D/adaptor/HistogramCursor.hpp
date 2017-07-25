/* ***** BEGIN LICENSE BLOCK *****
 * FW4SPL - Copyright (C) IRCAD, 2009-2017.
 * Distributed under the terms of the GNU Lesser General Public License (LGPL) as
 * published by the Free Software Foundation.
 * ****** END LICENSE BLOCK ****** */

#ifndef __SCENE2D_ADAPTOR_HISTOGRAMCURSOR_HPP__
#define __SCENE2D_ADAPTOR_HISTOGRAMCURSOR_HPP__

#include "scene2D/config.hpp"

#include <fwRenderQt/data/Viewport.hpp>
#include <fwRenderQt/IAdaptor.hpp>

#include <QGraphicsTextItem>

namespace scene2D
{
namespace adaptor
{

/**
 * @brief IAdaptor implementation to show a cursor on histogram pointed by mouse.
 *
 * Configuration example:
 *
   @code{.xml}
   <service uid="histogram" type="::scene2D::adaptor::HistogramCursor">
       <in key="histogram" uid="histogramUID" />
       <in key="point" uid="pointUID" />
       <config xAxis="xAxis" yAxis="yAxis" color="gray" opacity="0.25" zValue="5"/>
   </service>
   @endcode
 *
 * \b xAxis     : see ::fwRenderQt::IAdaptor
 * \b yAxis     : see ::fwRenderQt::IAdaptor
 * \b zValue    : see ::fwRenderQt::IAdaptor
 * \b color     : inner color
 * \b borderColor : border color, default value is gray
 * \b opacity   : from 0.0 to 1.0, default value is 0.8
 *
 */
class HistogramCursor : public ::fwRenderQt::IAdaptor
{

public:
    fwCoreServiceClassDefinitionsMacro( (HistogramCursor)(::fwRenderQt::IAdaptor) );

    SCENE2D_API HistogramCursor() noexcept;
    SCENE2D_API virtual ~HistogramCursor() noexcept;

    SCENE2D_API ::fwServices::IService::KeyConnectionsMap getAutoConnections() const;

protected:
    SCENE2D_API void configuring();
    SCENE2D_API void doStart();
    SCENE2D_API void doUpdate();
    SCENE2D_API void doSwap();
    SCENE2D_API void doStop();

    SCENE2D_API void processInteraction( ::fwRenderQt::data::Event& _event );

    /// Color used for graphic item's inner color
    QPen m_color;

    /// Color used for graphic item's border color
    QPen m_borderColor;

    /// Opacity
    float m_opacity;

    // A graphics item that is located onto hsitogram's upper border and moves along this border
    // according to the position of mouse's cursor. The goal of this graphical index is to show
    // the associated value within the histogram pointed buy this index.
    QGraphicsEllipseItem* m_index;

    /// Coordinates of the current event.
    ::fwRenderQt::data::Coord m_coord;

    ///
    float m_pointSize;

    /// The layer.
    QGraphicsItemGroup* m_layer;
};

}   // namespace adaptor
}   // namespace scene2D

#endif  // __SCENE2D_ADAPTOR_HISTOGRAMCURSOR_HPP__

