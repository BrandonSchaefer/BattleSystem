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

#ifndef UNIT_GROUP
#define UNIT_GROUP

#include "Unit.h"

#include <list>

namespace battle_system
{

class UnitGroup
{
public:
  typedef std::list<Unit::Ptr>::iterator       iterator;
  typedef std::list<Unit::Ptr>::const_iterator const_iterator;

  UnitGroup() = default;

  void AddUnit(Unit::Ptr const& unit);
  void RemoveUnit(UnitGroup::iterator const& unit);
  void RemoveUnit(Unit::Ptr const& unit);

  iterator begin();
  iterator end();

  const_iterator cbegin() const;
  const_iterator cend() const;

  size_t Size()  const;
  bool   Empty() const;

private:
  std::list<Unit::Ptr> units_;
};

} // namespace battle_system

#endif // UNIT_GROUP
