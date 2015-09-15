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

#include "UnitGroup.h"

namespace battle_system
{

void UnitGroup::AddUnit(Unit::Ptr const& unit)
{
  units_.push_back(unit);
}

void UnitGroup::RemoveUnit(UnitGroup::iterator const& unit)
{
  units_.erase(unit);
}

void UnitGroup::RemoveUnit(Unit::Ptr const& unit)
{
  units_.remove(unit);
}

UnitGroup::iterator UnitGroup::begin()
{
  return units_.begin();
}

UnitGroup::iterator UnitGroup::end()
{
  return units_.end();
}

UnitGroup::const_iterator UnitGroup::cbegin() const
{
  return units_.cbegin();
}

UnitGroup::const_iterator UnitGroup::cend() const
{
  return units_.cend();
}

bool UnitGroup::Empty() const
{
  return units_.empty();
}

size_t UnitGroup::Size() const
{
  return units_.size();
}

} // namespace battle_system
