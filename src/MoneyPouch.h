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

#ifndef MONEY_POUCH_H
#define MONEY_POUCH_H

#include "items/Item.h"

namespace battle_system
{

enum MoneyType
{
  COPPER,
  SILVER,
  ELECTRUM,
  GOLD,
  PLATINUM,
  Size,
};

class MoneyPouch
{
public:
  MoneyPouch();

  void AddMoney    (int amount, MoneyType const& type);
  int WithdrawMoney(int amount, MoneyType const& type);
  int CheckBalance (MoneyType const& type) const;

private:
  int money_[MoneyType::Size + 1];
};

} // namespace battle_system

#endif // MONEY_POUCH_H
