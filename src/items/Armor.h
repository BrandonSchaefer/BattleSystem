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

#ifndef ARMOR_H
#define ARMOR_H

#include "Item.h"

namespace battle_system
{

struct ArmorInfo
{
  int base_ac;
};

class Armor : public Item
{
public:
  typedef std::shared_ptr<Armor> Ptr;

  Armor(ArmorInfo const& armor, ItemInfo const& info);
  virtual ~Armor() override = default;

  int BaseAC() const;

private:
  int base_ac_;

};

} // namespace battle_system

#endif // ARMOR_H
