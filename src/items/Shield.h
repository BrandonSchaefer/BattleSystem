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

#ifndef SHIELD_H
#define SHIELD_H

#include "Item.h"

namespace battle_system
{

struct ShieldInfo
{
  int shield_bonus;
};

class Shield : public Item
{
public:
  typedef std::shared_ptr<Shield> Ptr;

  Shield(ShieldInfo const& shield, ItemInfo const& info);
  virtual ~Shield() override = default;

  int ShieldBonus() const;

private:
  int shield_bonus_;
};

} // namespace battle_system

#endif // SHIELD_H
