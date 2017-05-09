//
// Common exception definitions
//
// ICRAR - International Centre for Radio Astronomy Research
// (c) UWA - The University of Western Australia, 2017
// Copyright by UWA (in the framework of the ICRAR)
// All rights reserved
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston,
// MA 02111-1307  USA
//

#ifndef SHARK_EXCEPTIONS_H
#define SHARK_EXCEPTIONS_H

#include <stdexcept>
#include <string>

namespace shark {

/**
 * An exception indicating that invalid data has been encountered
 */
class invalid_data : public std::runtime_error {
public:
	invalid_data(const std::string &what) : std::runtime_error(what) {};
};


/**
 * An exception indicating that invalid data has been encountered
 */
class math_error: public std::runtime_error {
public:
	math_error(const std::string &what) : std::runtime_error(what) {};
};

}  // namespace shark

#endif // SHARK_EXCEPTIONS_H