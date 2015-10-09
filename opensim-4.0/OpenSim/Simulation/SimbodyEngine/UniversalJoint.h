#ifndef OPENSIM_UNIVERSAL_JOINT_H_
#define OPENSIM_UNIVERSAL_JOINT_H_
/* -------------------------------------------------------------------------- *
 *                      OpenSim:  UniversalJoint.h                            *
 * -------------------------------------------------------------------------- *
 * The OpenSim API is a toolkit for musculoskeletal modeling and simulation.  *
 * See http://opensim.stanford.edu and the NOTICE file for more information.  *
 * OpenSim is developed at Stanford University and supported by the US        *
 * National Institutes of Health (U54 GM072970, R24 HD065690) and by DARPA    *
 * through the Warrior Web program.                                           *
 *                                                                            *
 * Copyright (c) 2005-2012 Stanford University and the Authors                *
 * Author(s): Tim Dorn                                                        *
 *                                                                            *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may    *
 * not use this file except in compliance with the License. You may obtain a  *
 * copy of the License at http://www.apache.org/licenses/LICENSE-2.0.         *
 *                                                                            *
 * Unless required by applicable law or agreed to in writing, software        *
 * distributed under the License is distributed on an "AS IS" BASIS,          *
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.   *
 * See the License for the specific language governing permissions and        *
 * limitations under the License.                                             *
 * -------------------------------------------------------------------------- */

// INCLUDE
#include "Joint.h"

namespace OpenSim {

//=============================================================================
//=============================================================================
/**

A class implementing a Universal joint. The underlying implementation
in Simbody is a SimTK::MobilizedBody::Universal.
Universal provides two DoF: rotation about the x axis of the joint frames,
followed by a rotation about the new y axis. The joint is badly behaved when the
second rotation is near 90 degrees. 

\image html universalJoint.gif

@author Tim Dorn
 */
class OSIMSIMULATION_API UniversalJoint : public Joint {
OpenSim_DECLARE_CONCRETE_OBJECT(UniversalJoint, Joint);

    /** Specify the Coordinates of the UniversalJoint */
    CoordinateIndex rx{ constructCoordinate(Coordinate::MotionType::Rotational) };
    CoordinateIndex ry{ constructCoordinate(Coordinate::MotionType::Rotational) };

public:
    /** Use Joint's constructors. @see Joint */
    using Joint::Joint;

protected:
    void extendAddToSystem(SimTK::MultibodySystem& system) const override;
//=============================================================================
};  // END of class UniversalJoint
//=============================================================================
//=============================================================================

} // end of namespace OpenSim

#endif // OPENSIM_UNIVERSAL_JOINT_H_
