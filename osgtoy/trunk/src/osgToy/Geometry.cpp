// $Id$
// $URL$
// Copyright 2011 Mike Weiblen http://mew.cx/
// OpenSceneGraph Public License (OSGPL)

#include <osgToy/Geometry.h>

#include <osg/Vec2>
#include <osg/Vec3>
#include <osg/Vec4>
#include <osg/StateSet>
#include <osg/Math>
#include <osg/Notify>


/////////////////////////////////////////////////////////////////////////////
// Geometry

osgToy::Geometry::Geometry( unsigned int numVerts )
{
    setVertexArray( new osg::Vec3Array( numVerts ) );
    setColorArray( new osg::Vec4Array(1) );
    setOverallColor( osg::Vec4(1,1,1,1) );
}

void osgToy::Geometry::setOverallColor( const osg::Vec4& color )
{
    osg::Vec4Array& c( * dynamic_cast<osg::Vec4Array*>(getColorArray()) );
    c[0] = color;
    setColorBinding( osg::Geometry::BIND_OVERALL );
}

/////////////////////////////////////////////////////////////////////////////
// Quad

osgToy::Quad::Quad( float width, float height ) : Geometry(4)
{
    const float w( width / 2 );
    const float h( height / 2 );

    osg::Vec3Array& v( * dynamic_cast<osg::Vec3Array*>(getVertexArray()) );
    v[0] = osg::Vec3( -w, -h, 0 );
    v[1] = osg::Vec3( -w,  h, 0 );
    v[2] = osg::Vec3(  w, -h, 0 );
    v[3] = osg::Vec3(  w,  h, 0 );

    addPrimitiveSet( new osg::DrawArrays(osg::PrimitiveSet::QUADS, 0, v.size()) );
}

void osgToy::Quad::setTexture( int texUnit )
{
    setTexCoordArray( texUnit, new osg::Vec2Array(4) );

    osg::Vec2Array& t( * dynamic_cast<osg::Vec2Array*>(getTexCoordArray(texUnit)) );
    t[0] = osg::Vec2( 0,0 );
    t[1] = osg::Vec2( 0,1 );
    t[2] = osg::Vec2( 1,0 );
    t[3] = osg::Vec2( 1,1 );
}



/////////////////////////////////////////////////////////////////////////////

osgToy::Lines::Lines()
{
    osg::StateSet* ss( getOrCreateStateSet() );
    ss->setMode( GL_LIGHTING, osg::StateAttribute::OFF );
    addPrimitiveSet( new osg::DrawArrays( osg::PrimitiveSet::LINES, 0, 0 ) );
}

void osgToy::Lines::addLine( const osg::Vec3& a, const osg::Vec3& b )
{
    osg::Vec3Array& v( * dynamic_cast<osg::Vec3Array*>(getVertexArray()) );
    v.push_back( a );
    v.push_back( b );

    osg::DrawArrays& da( * dynamic_cast<osg::DrawArrays*>(getPrimitiveSet(0)) );
    da.setCount( v.size() );

    dirtyDisplayList();
    dirtyBound();
}

/////////////////////////////////////////////////////////////////////////////

void osgToy::WireBox::create( const osg::Vec3& min, const osg::Vec3& max )
{
    const osg::Vec3 nnx( min.x(), min.y(), max.z() );
    const osg::Vec3 nxn( min.x(), max.y(), min.z() );
    const osg::Vec3 nxx( min.x(), max.y(), max.z() );
    const osg::Vec3 xnn( max.x(), min.y(), min.z() );
    const osg::Vec3 xnx( max.x(), min.y(), max.z() );
    const osg::Vec3 xxn( max.x(), max.y(), min.z() );

    addLine( min, xnn );
    addLine( min, nxn );
    addLine( min, nnx );
    addLine( max, nxx );
    addLine( max, xnx );
    addLine( max, xxn );
    addLine( xnn, xxn );
    addLine( xnn, xnx );
    addLine( nxn, xxn );
    addLine( nxn, nxx );
    addLine( nnx, xnx );
    addLine( nnx, nxx );
}


osgToy::WireFrustum::WireFrustum( float fovy, float aspect, float zNear, float zFar )
{
    const double tanfovy( tan( osg::DegreesToRadians(fovy/2) ) );
    const double tanfovx( tanfovy * aspect );

    const double nNear( -zFar );
    const double tNear( tanfovy * nNear );
    const double bNear( -tNear );
    const double rNear( tanfovx * nNear );
    const double lNear( -rNear );

    const double fFar( -zNear );
    const double tFar( tanfovy * fFar );
    const double bFar( -tFar );
    const double rFar( tanfovx * fFar );
    const double lFar( -rFar );

    const osg::Vec3 nnn( lNear, bNear, nNear );
    const osg::Vec3 nnx( lFar,  bFar,  fFar  );
    const osg::Vec3 nxn( lNear, tNear, nNear );
    const osg::Vec3 nxx( lFar,  tFar,  fFar  );
    const osg::Vec3 xnn( rNear, bNear, nNear );
    const osg::Vec3 xnx( rFar,  bFar,  fFar  );
    const osg::Vec3 xxn( rNear, tNear, nNear );
    const osg::Vec3 xxx( rFar,  tFar,  fFar  );

    addLine( nnn, xnn );
    addLine( nnn, nxn );
    addLine( nnn, nnx );
    addLine( xxx, nxx );
    addLine( xxx, xnx );
    addLine( xxx, xxn );
    addLine( xnn, xxn );
    addLine( xnn, xnx );
    addLine( nxn, xxn );
    addLine( nxn, nxx );
    addLine( nnx, xnx );
    addLine( nnx, nxx );
}

// vim: set sw=4 ts=8 et ic ai:
