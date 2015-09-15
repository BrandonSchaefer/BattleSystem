//-*- Mode: C++; indent-tabs-mode: nil; tab-width: 2 -*-
/* * Copyright (C) 2015 Brandon Schaefer
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License version 3 as
* published by the Free Software Foundation.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*
* Authored by: Brandon Schaefer <brandontschaefer@gmail.com>
*/

#ifndef RANDOM_NUMBER_GENERATOR
#define RANDOM_NUMBER_GENERATOR

#include <memory>
#include <random>

namespace battle_system
{

class RandomNumberGenerator
{
public:
  typedef std::shared_ptr<RandomNumberGenerator> Ptr;

  RandomNumberGenerator(unsigned seed);

  unsigned Generate(int min, int max);

private:
  std::mt19937 random_number_generator_;
};

} // namespace battle_system

#endif // RANDOM_NUMBER_GENERATOR
