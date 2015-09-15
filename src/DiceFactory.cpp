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

#include "DiceFactory.h"

#include <chrono>

namespace battle_system
{

DiceFactory::DiceFactory()
  : random_number_generator_(std::make_shared<RandomNumberGenerator>(
                             std::chrono::high_resolution_clock::now().time_since_epoch().count()))
{
}

Dice DiceFactory::CreateDice(int rolls, int die, int mod) const
{
  return Dice(random_number_generator_, {rolls, die, mod});
}

} // namespace battle_system
