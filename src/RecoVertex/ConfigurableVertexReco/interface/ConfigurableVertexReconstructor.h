#ifndef _ConfigurableVertexReconstructor_H_
#define _ConfigurableVertexReconstructor_H_

#include "RecoVertex/VertexPrimitives/interface/VertexReconstructor.h"
#include "RecoVertex/ConfigurableVertexReco/interface/AbstractConfReconstructor.h"
#include <string>
#include <map>

/**
 *  Wrap any VertexFitter into the VertexReconstructor interface
 */

class ConfigurableVertexReconstructor : public VertexReconstructor
{
  public:
    ConfigurableVertexReconstructor ( const edm::ParameterSet & );
    ConfigurableVertexReconstructor ( const ConfigurableVertexReconstructor & o );
    ~ConfigurableVertexReconstructor();

    std::vector < TransientVertex > vertices ( const std::vector < reco::TransientTrack > & ) const;
    std::vector < TransientVertex > vertices ( const std::vector < reco::TransientTrack > &, const GlobalPoint & seed ) const;

    std::vector < TransientVertex > vertices ( const std::vector < reco::TransientTrack > &,
        const reco::BeamSpot & ) const;
    std::vector < TransientVertex > vertices ( const std::vector < reco::TransientTrack > &,
        const std::vector < reco::TransientTrack > &, const reco::BeamSpot & ) const;
    std::vector < TransientVertex > vertices ( const std::vector < reco::TransientTrack > &,
	const std::vector < reco::TransientTrack > &, const reco::BeamSpot &,
	const reco::TransientTrack & ) const;
    std::vector < TransientVertex > vertices ( const std::vector < reco::TransientTrack > &,
	const reco::BeamSpot &,
        const reco::TransientTrack & ) const;

    ConfigurableVertexReconstructor * clone () const;

  private:
    AbstractConfReconstructor * theRector;
};

#endif
