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

#include "RandomNumberGenerator.h"

#include <stdio.h>

namespace battle_system
{

RandomNumberGenerator::RandomNumberGenerator(unsigned seed)
  : random_number_generator_(seed)
{
}

// FIXME Sometimes it just returns the same number over and over again....
unsigned RandomNumberGenerator::Generate(int min, int max)
{
  return random_number_generator_() % (max - min + 1) + min;
}

} // namespace battle_system
